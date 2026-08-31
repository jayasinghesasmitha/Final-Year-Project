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
    input wire clk,
    input wire rst,
    input wire        cmd_valid,
    input wire [3:0]  cmd,
    input wire [31:0] data_in,
    output reg        resp_valid,
    output reg [31:0] data_out,
    output reg        busy,
    output reg        done
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
    integer i, j, k, r, c, e, oc, kr, kc;
    integer acc;
    integer exp_acc;
    integer dw_acc;
    integer proj_acc;
    integer spatial;
    integer rr, cc;
    integer idx;
    integer exp_base;
    integer proj_base;
    integer dw_base;
    integer out_base;

    reg signed [ACC_W-1:0] expanded [0:CEXP-1];
    reg signed [ACC_W-1:0] dw_out [0:CEXP-1];

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

                        // Phase 3 reference-integrated datapath.
                        // Each spatial point uses zero padding for the 3x3 depthwise window.
                        for (spatial = 0; spatial < H*W; spatial = spatial + 1) begin
                            r = spatial / W;
                            c = spatial % W;

                            // Expansion: CEXP independent 1x1 output channels.
                            for (e = 0; e < CEXP; e = e + 1) begin
                                exp_acc = 0;
                                exp_base = e*CIN;
                                for (k = 0; k < CIN; k = k + 1)
                                    exp_acc = exp_acc
                                      + $signed(ifmap_mem[spatial*CIN+k])
                                      * $signed(exp_w_mem[exp_base+k]);
                                expanded[e] = exp_acc;
                            end

                            // Depthwise: one 3x3 kernel per expanded channel.
                            // For Phase 3, neighboring expanded samples are taken from the
                            // corresponding spatial locations. Out-of-range coordinates are 0.
                            for (e = 0; e < CEXP; e = e + 1) begin
                                dw_acc = 0;
                                dw_base = e*9;
                                for (kr = 0; kr < 3; kr = kr + 1) begin
                                    for (kc = 0; kc < 3; kc = kc + 1) begin
                                        rr = r + kr - 1;
                                        cc = c + kc - 1;
                                        if ((rr >= 0) && (rr < H) && (cc >= 0) && (cc < W)) begin
                                            idx = rr*W + cc;
                                            // Recompute the required expansion value at the neighbor.
                                            exp_acc = 0;
                                            exp_base = e*CIN;
                                            for (k = 0; k < CIN; k = k + 1)
                                                exp_acc = exp_acc
                                                  + $signed(ifmap_mem[idx*CIN+k])
                                                  * $signed(exp_w_mem[exp_base+k]);
                                            dw_acc = dw_acc
                                              + exp_acc * $signed(dw_w_mem[dw_base+kr*3+kc]);
                                        end
                                    end
                                end
                                dw_out[e] = dw_acc;
                            end

                            // Projection: each output channel accumulates all 24 depthwise channels.
                            for (oc = 0; oc < COUT; oc = oc + 1) begin
                                proj_acc = 0;
                                proj_base = oc*CEXP;
                                for (e = 0; e < CEXP; e = e + 1)
                                    proj_acc = proj_acc
                                      + dw_out[e] * $signed(proj_w_mem[proj_base+e]);
                                output_mem[spatial*COUT+oc] <= proj_acc;
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
