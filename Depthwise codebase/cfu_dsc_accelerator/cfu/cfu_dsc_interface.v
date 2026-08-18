/*******************************************************************************
 * CFU Interface Wrapper
 *
 * Standard CFU-Playground interface for VexRiscv integration.
 * Implements the RISC-V custom instruction interface.
 *
 * CFU Instruction Format (from CFU-Playground):
 *   - funct7[6:0] | rs2[4:0] | rs1[4:0] | funct3[2:0] | rd[4:0] | opcode
 *   - opcode = CUSTOM-0 (0x0B), CUSTOM-1 (0x2B), etc.
 *
 * Function IDs:
 *   - funct3 = 0: READ output channel
 *   - funct3 = 1: WRITE data/weight
 *   - funct3 = 2: EXECUTE/start computation
 *   - funct3 = 3: GET status
 ******************************************************************************/

`include "cfu_dsc_defines.v"

module cfu_dsc_interface (
    input  wire                         clk,
    input  wire                         rst_n,

    // RISC-V Custom Instruction Interface
    input  wire [2:0]                   funct3,         // Function ID
    input  wire [6:0]                   funct7,         // Extended function
    input  wire [31:0]                  rs1,            // Source register 1
    input  wire [31:0]                  rs2,            // Source register 2
    output reg  [31:0]                  rd,             // Destination register

    // CFU operation start
    input  wire                         cfu_start,
    output wire                         cfu_done,

    // Internal control interface
    output reg  [2:0]                   cfu_op,
    output reg                          cfu_op_valid,
    input  wire [3:0]                   status,

    // Data interface
    output reg  [31:0]                  data_out,
    output reg                          data_out_valid,
    input  wire [31:0]                  data_in,
    input  wire                         data_in_valid,

    // Configuration registers
    output reg  [15:0]                  cfg_height,
    output reg  [15:0]                  cfg_width,
    output reg  [15:0]                  cfg_in_channels,
    output reg  [15:0]                  cfg_exp_channels,
    output reg  [15:0]                  cfg_out_channels,

    // Read interface for output channels
    output reg  [5:0]                   read_addr,
    input  wire [`DATA_WIDTH-1:0]       read_data,
    input  wire                         read_data_valid
);

    //==========================================================================
    // CFU Done Signal
    //==========================================================================
    assign cfu_done = (status == `STATUS_DONE) || (status == `STATUS_OUTPUT_RDY);

    //==========================================================================
    // Function Decode
    //==========================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cfu_op       <= `CFU_OP_NOP;
            cfu_op_valid <= 0;
            data_out     <= 0;
            data_out_valid <= 0;
            rd           <= 0;
            read_addr    <= 0;
        end else begin
            cfu_op_valid <= 0;
            data_out_valid <= 0;

            if (cfu_start) begin
                case (funct3)
                    `CFU_FUNC_READ: begin
                        // Read output channel
                        // rs1[5:0] = channel index
                        read_addr <= rs1[5:0];
                        rd <= {{24{read_data[7]}}, read_data};
                    end

                    `CFU_FUNC_WRITE: begin
                        // Write data/weights based on funct7
                        case (funct7[2:0])
                            3'd0: begin
                                // Write IFMAP data
                                cfu_op <= `CFU_OP_LOAD_IFMAP;
                                data_out <= rs1;
                                data_out_valid <= 1;
                                cfu_op_valid <= 1;
                            end
                            3'd1: begin
                                // Write expansion weights
                                cfu_op <= `CFU_OP_LOAD_EXP_W;
                                data_out <= rs1;
                                data_out_valid <= 1;
                                cfu_op_valid <= 1;
                            end
                            3'd2: begin
                                // Write depthwise weights
                                cfu_op <= `CFU_OP_LOAD_DW_W;
                                data_out <= rs1;
                                data_out_valid <= 1;
                                cfu_op_valid <= 1;
                            end
                            3'd3: begin
                                // Write projection weights
                                cfu_op <= `CFU_OP_LOAD_PROJ_W;
                                data_out <= rs1;
                                data_out_valid <= 1;
                                cfu_op_valid <= 1;
                            end
                            3'd4: begin
                                // Write bias
                                cfu_op <= `CFU_OP_LOAD_BIAS;
                                data_out <= rs1;
                                data_out_valid <= 1;
                                cfu_op_valid <= 1;
                            end
                            default: begin
                                cfu_op <= `CFU_OP_NOP;
                            end
                        endcase
                    end

                    `CFU_FUNC_EXECUTE: begin
                        // Set parameters or start execution
                        case (funct7[2:0])
                            3'd0: begin
                                // Set configuration (height, width)
                                cfg_height <= rs1[15:0];
                                cfg_width  <= rs2[15:0];
                            end
                            3'd1: begin
                                // Set channel configuration
                                cfg_in_channels  <= rs1[15:0];
                                cfg_exp_channels <= rs2[15:0];
                            end
                            3'd2: begin
                                // Set output channels
                                cfg_out_channels <= rs1[15:0];
                            end
                            3'd7: begin
                                // Start computation
                                cfu_op <= `CFU_OP_START;
                                cfu_op_valid <= 1;
                            end
                            default: begin
                                cfu_op <= `CFU_OP_NOP;
                            end
                        endcase
                    end

                    `CFU_FUNC_STATUS: begin
                        // Return current status
                        rd <= {28'd0, status};
                    end

                    default: begin
                        cfu_op <= `CFU_OP_NOP;
                    end
                endcase
            end
        end
    end

endmodule
