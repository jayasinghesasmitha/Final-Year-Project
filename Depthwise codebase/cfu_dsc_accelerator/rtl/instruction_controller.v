/*******************************************************************************
 * Instruction Controller
 *
 * Orchestrates the dataflow and synchronization between all pipeline stages.
 * Manages the state machine for loading data and executing fused computation.
 *
 * States:
 *   - IDLE: Waiting for instruction
 *   - LOAD_IFMAP: Loading input feature map
 *   - LOAD_EXP_W: Loading expansion weights
 *   - LOAD_DW_W: Loading depthwise weights
 *   - LOAD_PROJ_W: Loading projection weights
 *   - LOAD_BIAS: Loading bias values
 *   - COMPUTE: Fused computation (Exp -> Dw -> Proj)
 *   - OUTPUT: Reading output channels
 ******************************************************************************/

`include "cfu_dsc_defines.v"

module instruction_controller (
    input  wire                         clk,
    input  wire                         rst_n,

    // CFU Interface
    input  wire [2:0]                   cfu_op,         // Operation code
    input  wire                         cfu_start,      // Start execution
    output reg  [3:0]                   status,         // Current status

    // Configuration inputs
    input  wire [15:0]                  in_height,
    input  wire [15:0]                  in_width,
    input  wire [15:0]                  in_channels,
    input  wire [15:0]                  exp_channels,
    input  wire [15:0]                  out_channels,

    // Control outputs to pipeline stages
    output reg                          exp_start,
    output reg                          exp_clear,
    output reg                          exp_last_filter,
    output reg                          exp_last_channel,

    output reg                          dw_start,
    output reg                          dw_clear,
    output reg                          dw_last_channel,

    output reg                          proj_start,
    output reg                          proj_clear,
    output reg                          proj_last_input,

    // Memory control
    output reg                          ifmap_wr_en,
    output reg                          exp_w_wr_en,
    output reg                          dw_w_wr_en,
    output reg                          proj_w_wr_en,

    // Data flow control
    output reg                          pipeline_enable,
    output reg                          output_ready,

    // Completion signal
    output reg                          done
);

    //==========================================================================
    // State Machine
    //==========================================================================
    localparam STATE_IDLE       = 4'd0;
    localparam STATE_LOAD_IFMAP = 4'd1;
    localparam STATE_LOAD_EXP_W = 4'd2;
    localparam STATE_LOAD_DW_W  = 4'd3;
    localparam STATE_LOAD_PROJ_W= 4'd4;
    localparam STATE_LOAD_BIAS  = 4'd5;
    localparam STATE_COMPUTE    = 4'd6;
    localparam STATE_OUTPUT     = 4'd7;
    localparam STATE_DONE       = 4'd8;

    reg [3:0] state, next_state;

    //==========================================================================
    // Internal Counters
    //==========================================================================
    reg [15:0] row_cnt;
    reg [15:0] col_cnt;
    reg [15:0] ch_cnt;
    reg [15:0] filter_cnt;
    reg [15:0] pixel_cnt;

    //==========================================================================
    // State Register
    //==========================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= STATE_IDLE;
        end else begin
            state <= next_state;
        end
    end

    //==========================================================================
    // Next State Logic
    //==========================================================================
    always @(*) begin
        next_state = state;

        case (state)
            STATE_IDLE: begin
                if (cfu_start) begin
                    case (cfu_op)
                        `CFU_OP_LOAD_IFMAP:   next_state = STATE_LOAD_IFMAP;
                        `CFU_OP_LOAD_EXP_W:   next_state = STATE_LOAD_EXP_W;
                        `CFU_OP_LOAD_DW_W:    next_state = STATE_LOAD_DW_W;
                        `CFU_OP_LOAD_PROJ_W:  next_state = STATE_LOAD_PROJ_W;
                        `CFU_OP_LOAD_BIAS:    next_state = STATE_LOAD_BIAS;
                        `CFU_OP_START:        next_state = STATE_COMPUTE;
                        default:              next_state = STATE_IDLE;
                    endcase
                end
            end

            STATE_LOAD_IFMAP: begin
                if (pixel_cnt >= in_height * in_width - 1)
                    next_state = STATE_IDLE;
            end

            STATE_LOAD_EXP_W: begin
                if (pixel_cnt >= exp_channels * in_channels - 1)
                    next_state = STATE_IDLE;
            end

            STATE_LOAD_DW_W: begin
                if (pixel_cnt >= exp_channels * 9 - 1)
                    next_state = STATE_IDLE;
            end

            STATE_LOAD_PROJ_W: begin
                if (pixel_cnt >= out_channels * exp_channels - 1)
                    next_state = STATE_IDLE;
            end

            STATE_LOAD_BIAS: begin
                next_state = STATE_IDLE;
            end

            STATE_COMPUTE: begin
                // Transition to OUTPUT when all pixels processed
                if (row_cnt >= in_height && col_cnt >= in_width)
                    next_state = STATE_OUTPUT;
            end

            STATE_OUTPUT: begin
                if (output_ready)
                    next_state = STATE_DONE;
            end

            STATE_DONE: begin
                next_state = STATE_IDLE;
            end

            default: next_state = STATE_IDLE;
        endcase
    end

    //==========================================================================
    // Output Logic and Control Signals
    //==========================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            status        <= `STATUS_IDLE;
            exp_start     <= 0;
            exp_clear     <= 0;
            exp_last_filter <= 0;
            exp_last_channel <= 0;
            dw_start      <= 0;
            dw_clear      <= 0;
            dw_last_channel <= 0;
            proj_start    <= 0;
            proj_clear    <= 0;
            proj_last_input <= 0;
            ifmap_wr_en   <= 0;
            exp_w_wr_en   <= 0;
            dw_w_wr_en    <= 0;
            proj_w_wr_en  <= 0;
            pipeline_enable <= 0;
            output_ready  <= 0;
            done          <= 0;
            row_cnt       <= 0;
            col_cnt       <= 0;
            ch_cnt        <= 0;
            filter_cnt    <= 0;
            pixel_cnt     <= 0;
        end else begin
            // Default values
            exp_start     <= 0;
            exp_clear     <= 0;
            dw_start      <= 0;
            dw_clear      <= 0;
            proj_start    <= 0;
            proj_clear    <= 0;
            ifmap_wr_en   <= 0;
            exp_w_wr_en   <= 0;
            dw_w_wr_en    <= 0;
            proj_w_wr_en  <= 0;
            output_ready  <= 0;
            done          <= 0;

            case (state)
                STATE_IDLE: begin
                    status <= `STATUS_IDLE;
                    pixel_cnt <= 0;
                end

                STATE_LOAD_IFMAP: begin
                    status <= `STATUS_LOADING;
                    ifmap_wr_en <= 1;
                    pixel_cnt <= pixel_cnt + 1;
                end

                STATE_LOAD_EXP_W: begin
                    status <= `STATUS_LOADING;
                    exp_w_wr_en <= 1;
                    pixel_cnt <= pixel_cnt + 1;
                end

                STATE_LOAD_DW_W: begin
                    status <= `STATUS_LOADING;
                    dw_w_wr_en <= 1;
                    pixel_cnt <= pixel_cnt + 1;
                end

                STATE_LOAD_PROJ_W: begin
                    status <= `STATUS_LOADING;
                    proj_w_wr_en <= 1;
                    pixel_cnt <= pixel_cnt + 1;
                end

                STATE_LOAD_BIAS: begin
                    status <= `STATUS_LOADING;
                end

                STATE_COMPUTE: begin
                    status <= `STATUS_COMPUTING;
                    pipeline_enable <= 1;

                    // Expansion stage control
                    if (ch_cnt == 0) begin
                        exp_clear <= 1;
                    end
                    exp_start <= 1;
                    exp_last_channel <= (ch_cnt >= in_channels - 8);
                    exp_last_filter <= (filter_cnt >= exp_channels - 1) &&
                                          (ch_cnt >= in_channels - 8);

                    // Depthwise stage control (delayed by 1 cycle)
                    if (ch_cnt >= 8) begin
                        dw_start <= 1;
                        dw_last_channel <= (ch_cnt >= in_channels);
                    end

                    // Projection stage control (delayed by 2 cycles)
                    if (ch_cnt >= 16) begin
                        proj_start <= 1;
                        proj_last_input <= (ch_cnt >= in_channels + 8);
                    end

                    // Update counters
                    ch_cnt <= ch_cnt + 8;
                    if (ch_cnt >= in_channels) begin
                        ch_cnt <= 0;
                        filter_cnt <= filter_cnt + 1;
                        if (filter_cnt >= exp_channels - 1) begin
                            filter_cnt <= 0;
                            col_cnt <= col_cnt + 1;
                            if (col_cnt >= in_width - 1) begin
                                col_cnt <= 0;
                                row_cnt <= row_cnt + 1;
                            end
                        end
                    end
                end

                STATE_OUTPUT: begin
                    status <= `STATUS_OUTPUT_RDY;
                    output_ready <= 1;
                end

                STATE_DONE: begin
                    status <= `STATUS_DONE;
                    done <= 1;
                    row_cnt <= 0;
                    col_cnt <= 0;
                    ch_cnt <= 0;
                    filter_cnt <= 0;
                end
            endcase
        end
    end

endmodule
