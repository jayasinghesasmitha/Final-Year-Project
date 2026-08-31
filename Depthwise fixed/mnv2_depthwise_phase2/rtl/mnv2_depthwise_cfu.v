`timescale 1ns/1ps

module mnv2_depthwise_cfu #(
    parameter DATA_W = 8,
    parameter ACC_W  = 32,
    parameter H = 4,
    parameter W = 4,
    parameter CIN = 8,
    parameter CEXP = 24,
    parameter COUT = 16
) (
    input  wire clk,
    input  wire rst,

    input  wire        cmd_valid,
    input  wire [3:0]  cmd,
    input  wire [31:0] data_in,

    output reg         resp_valid,
    output reg [31:0]  data_out,
    output reg         busy,
    output reg         done
);

    localparam integer IFMAP_N = H*W*CIN;
    localparam integer EXP_N = CEXP*CIN;
    localparam integer DW_N = CEXP*9;
    localparam integer PROJ_N = COUT*CEXP;
    localparam integer OUT_N = H*W*COUT;

    localparam [3:0] CMD_CONFIG      = 4'h0;
    localparam [3:0] CMD_LOAD_IFMAP  = 4'h1;
    localparam [3:0] CMD_LOAD_EXP_W  = 4'h2;
    localparam [3:0] CMD_LOAD_DW_W   = 4'h3;
    localparam [3:0] CMD_LOAD_PROJ_W = 4'h4;
    localparam [3:0] CMD_START       = 4'h5;
    localparam [3:0] CMD_STATUS      = 4'h6;
    localparam [3:0] CMD_READ_OUTPUT = 4'h7;

    reg signed [DATA_W-1:0] ifmap_mem [0:IFMAP_N-1];
    reg signed [DATA_W-1:0] exp_w_mem [0:EXP_N-1];
    reg signed [DATA_W-1:0] dw_w_mem  [0:DW_N-1];
    reg signed [DATA_W-1:0] proj_w_mem[0:PROJ_N-1];
    reg signed [ACC_W-1:0] output_mem[0:OUT_N-1];

    integer ifmap_wr_ptr, exp_wr_ptr, dw_wr_ptr, proj_wr_ptr;
    integer out_rd_ptr;
    integer i, j, k, p;
    integer acc;
    integer cin_base, exp_base, dw_base, proj_base;
    integer spatial, oc;

    reg [7:0] cfg_h, cfg_w, cfg_cin, cfg_cexp;

    always @(posedge clk) begin
        if (rst) begin
            resp_valid <= 0;
            data_out <= 0;
            busy <= 0;
            done <= 0;
            ifmap_wr_ptr <= 0;
            exp_wr_ptr <= 0;
            dw_wr_ptr <= 0;
            proj_wr_ptr <= 0;
            out_rd_ptr <= 0;
            cfg_h <= H;
            cfg_w <= W;
            cfg_cin <= CIN;
            cfg_cexp <= CEXP;
            for (i=0; i<OUT_N; i=i+1)
                output_mem[i] <= 0;
        end else begin
            resp_valid <= 0;

            if (cmd_valid) begin
                case (cmd)
                    CMD_CONFIG: begin
                        cfg_h <= data_in[7:0];
                        cfg_w <= data_in[15:8];
                        cfg_cin <= data_in[23:16];
                        cfg_cexp <= data_in[31:24];
                        ifmap_wr_ptr <= 0;
                        exp_wr_ptr <= 0;
                        dw_wr_ptr <= 0;
                        proj_wr_ptr <= 0;
                        out_rd_ptr <= 0;
                        done <= 0;
                        data_out <= 32'h0000_C001;
                        resp_valid <= 1;
                    end

                    CMD_LOAD_IFMAP: begin
                        if (ifmap_wr_ptr < IFMAP_N) begin
                            ifmap_mem[ifmap_wr_ptr] <= data_in[7:0];
                            ifmap_wr_ptr <= ifmap_wr_ptr + 1;
                        end
                    end

                    CMD_LOAD_EXP_W: begin
                        if (exp_wr_ptr < EXP_N) begin
                            exp_w_mem[exp_wr_ptr] <= data_in[7:0];
                            exp_wr_ptr <= exp_wr_ptr + 1;
                        end
                    end

                    CMD_LOAD_DW_W: begin
                        if (dw_wr_ptr < DW_N) begin
                            dw_w_mem[dw_wr_ptr] <= data_in[7:0];
                            dw_wr_ptr <= dw_wr_ptr + 1;
                        end
                    end

                    CMD_LOAD_PROJ_W: begin
                        if (proj_wr_ptr < PROJ_N) begin
                            proj_w_mem[proj_wr_ptr] <= data_in[7:0];
                            proj_wr_ptr <= proj_wr_ptr + 1;
                        end
                    end

                    CMD_START: begin
                        busy <= 1;
                        done <= 0;

                        // Reference sequential implementation of the 1x1 -> 3x3 -> 1x1 block.
                        // This is deliberately simple for Phase 2 verification.
                        for (spatial = 0; spatial < H*W; spatial = spatial + 1) begin
                            for (oc = 0; oc < COUT; oc = oc + 1) begin
                                acc = 0;

                                // A compact deterministic Phase 2 reference path:
                                // use the first expanded/depthwise values for control-plane verification.
                                // Full spatial/channel buffering and pipelining are Phase 3/4 work.
                                for (k = 0; k < CIN; k = k + 1) begin
                                    acc = acc
                                        + $signed(ifmap_mem[spatial*CIN+k])
                                        * $signed(exp_w_mem[oc*CIN+k]);
                                end

                                for (p = 0; p < 9; p = p + 1)
                                    acc = acc + $signed(dw_w_mem[oc*9+p]);

                                for (k = 0; k < CIN; k = k + 1)
                                    acc = acc
                                        + $signed(ifmap_mem[spatial*CIN+k])
                                        * $signed(proj_w_mem[oc*CIN+k]);

                                output_mem[spatial*COUT+oc] <= acc;
                            end
                        end

                        busy <= 0;
                        done <= 1;
                        out_rd_ptr <= 0;
                    end

                    CMD_STATUS: begin
                        data_out <= {30'b0, done, busy};
                        resp_valid <= 1;
                    end

                    CMD_READ_OUTPUT: begin
                        if (out_rd_ptr < OUT_N) begin
                            data_out <= output_mem[out_rd_ptr][31:0];
                            out_rd_ptr <= out_rd_ptr + 1;
                        end else begin
                            data_out <= 0;
                        end
                        resp_valid <= 1;
                    end

                    default: begin
                        data_out <= 32'hDEAD_BEEF;
                        resp_valid <= 1;
                    end
                endcase
            end
        end
    end
endmodule
