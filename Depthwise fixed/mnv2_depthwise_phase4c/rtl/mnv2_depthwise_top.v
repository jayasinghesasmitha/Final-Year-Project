`timescale 1ns/1ps

module mnv2_depthwise_top #(
    parameter integer H=4,
    parameter integer W=4,
    parameter integer CIN=8,
    parameter integer CEXP=24,
    parameter integer COUT=16,
    parameter integer DATA_W=8,
    parameter integer ACC_W=32
)(
    input wire clk,
    input wire rst,
    input wire start,
    output reg busy,
    output reg done,

    input wire ifmap_wr_en,
    input wire [6:0] ifmap_wr_addr,
    input wire signed [DATA_W-1:0] ifmap_wr_data,

    input wire exp_wr_en,
    input wire [7:0] exp_wr_addr,
    input wire signed [DATA_W-1:0] exp_wr_data,

    input wire dw_wr_en,
    input wire [7:0] dw_wr_addr,
    input wire signed [DATA_W-1:0] dw_wr_data,

    input wire proj_wr_en,
    input wire [8:0] proj_wr_addr,
    input wire signed [DATA_W-1:0] proj_wr_data,

    input wire [7:0] out_rd_addr,
    output reg signed [ACC_W-1:0] out_rd_data
);

    localparam integer IFMAP_N = H*W*CIN;
    localparam integer EXP_W_N = CEXP*CIN;
    localparam integer DW_W_N = CEXP*9;
    localparam integer PROJ_W_N = COUT*CEXP;
    localparam integer EXP_N = H*W*CEXP;
    localparam integer DW_N = H*W*CEXP;
    localparam integer OUT_N = H*W*COUT;

    // Explicit memories.
    reg signed [DATA_W-1:0] ifmap_mem [0:IFMAP_N-1];
    reg signed [DATA_W-1:0] exp_w_mem [0:EXP_W_N-1];
    reg signed [DATA_W-1:0] dw_w_mem [0:DW_W_N-1];
    reg signed [DATA_W-1:0] proj_w_mem [0:PROJ_W_N-1];

    reg signed [ACC_W-1:0] expanded_mem [0:EXP_N-1];
    reg signed [ACC_W-1:0] dw_mem [0:DW_N-1];
    reg signed [ACC_W-1:0] output_mem [0:OUT_N-1];

    integer i;
    integer rr, cc, k;
    integer spatial;
    integer exp_ch;
    integer dw_ch;
    integer out_ch;
    integer tap;
    integer acc;
    integer in_idx;
    integer exp_idx;
    integer dw_idx;
    integer proj_idx;
    integer out_idx;
    integer neighbor_idx;

    localparam S_IDLE = 0;
    localparam S_EXP  = 1;
    localparam S_DW   = 2;
    localparam S_PROJ = 3;
    localparam S_DONE = 4;

    reg [2:0] state;
    integer exp_input_ch;
    integer dw_tap_count;
    integer proj_input_ch;

    integer cur_row;
    integer cur_col;
    integer cur_spatial;
    integer cur_exp_ch;
    integer cur_dw_ch;
    integer cur_out_ch;

    // Host writes are always available when the accelerator is idle.
    always @(posedge clk) begin
        if (rst) begin
            busy <= 0;
            done <= 0;
            out_rd_data <= 0;
            state <= S_IDLE;

            exp_input_ch <= 0;
            dw_tap_count <= 0;
            proj_input_ch <= 0;

            cur_row <= 0;
            cur_col <= 0;
            cur_spatial <= 0;
            cur_exp_ch <= 0;
            cur_dw_ch <= 0;
            cur_out_ch <= 0;
        end else begin
            done <= 0;

            // Explicit input/weight loading. Never allow writes while computing.
            if (!busy) begin
                if (ifmap_wr_en && (ifmap_wr_addr < IFMAP_N))
                    ifmap_mem[ifmap_wr_addr] <= ifmap_wr_data;

                if (exp_wr_en && (exp_wr_addr < EXP_W_N))
                    exp_w_mem[exp_wr_addr] <= exp_wr_data;

                if (dw_wr_en && (dw_wr_addr < DW_W_N))
                    dw_w_mem[dw_wr_addr] <= dw_wr_data;

                if (proj_wr_en && (proj_wr_addr < PROJ_W_N))
                    proj_w_mem[proj_wr_addr] <= proj_wr_data;
            end

            // Synchronous output read port.
            if (!busy && (out_rd_addr < OUT_N))
                out_rd_data <= output_mem[out_rd_addr];

            case (state)

                S_IDLE: begin
                    busy <= 0;

                    if (start) begin
                        busy <= 1;
                        state <= S_EXP;

                        cur_row <= 0;
                        cur_col <= 0;
                        cur_spatial <= 0;
                        cur_exp_ch <= 0;
                        cur_dw_ch <= 0;
                        cur_out_ch <= 0;

                        exp_input_ch <= 0;
                        dw_tap_count <= 0;
                        proj_input_ch <= 0;
                    end
                end

                // One Expansion MAC per clock.
                S_EXP: begin
                    in_idx = cur_spatial*CIN + exp_input_ch;
                    exp_idx = cur_spatial*CEXP + cur_exp_ch;
                    acc = 0;

                    if (exp_input_ch == 0)
                        acc = $signed(ifmap_mem[in_idx]) *
                              $signed(exp_w_mem[cur_exp_ch*CIN + exp_input_ch]);
                    else
                        acc = expanded_mem[exp_idx] +
                              $signed(ifmap_mem[in_idx]) *
                              $signed(exp_w_mem[cur_exp_ch*CIN + exp_input_ch]);

                    if (exp_input_ch == CIN-1) begin
                        expanded_mem[exp_idx] <= acc;
                        exp_input_ch <= 0;

                        if (cur_exp_ch == CEXP-1) begin
                            cur_exp_ch <= 0;
                            cur_dw_ch <= 0;
                            dw_tap_count <= 0;
                            state <= S_DW;
                        end else begin
                            cur_exp_ch <= cur_exp_ch + 1;
                        end
                    end else begin
                        expanded_mem[exp_idx] <= acc;
                        exp_input_ch <= exp_input_ch + 1;
                    end
                end

                // One Depthwise MAC per clock.
                S_DW: begin
                    rr = cur_row + (dw_tap_count / 3) - 1;
                    cc = cur_col + (dw_tap_count % 3) - 1;

                    if ((rr >= 0) && (rr < H) && (cc >= 0) && (cc < W)) begin
                        neighbor_idx = (rr*W + cc)*CEXP + cur_dw_ch;

                        if (dw_tap_count == 0)
                            acc = expanded_mem[neighbor_idx] *
                                  $signed(dw_w_mem[cur_dw_ch*9 + dw_tap_count]);
                        else
                            acc = dw_mem[cur_spatial*CEXP + cur_dw_ch] +
                                  expanded_mem[neighbor_idx] *
                                  $signed(dw_w_mem[cur_dw_ch*9 + dw_tap_count]);
                    end else begin
                        if (dw_tap_count == 0)
                            acc = 0;
                        else
                            acc = dw_mem[cur_spatial*CEXP + cur_dw_ch];
                    end

                    if (dw_tap_count == 8) begin
                        dw_mem[cur_spatial*CEXP + cur_dw_ch] <= acc;
                        dw_tap_count <= 0;

                        if (cur_dw_ch == CEXP-1) begin
                            cur_dw_ch <= 0;
                            cur_out_ch <= 0;
                            proj_input_ch <= 0;
                            state <= S_PROJ;
                        end else begin
                            cur_dw_ch <= cur_dw_ch + 1;
                        end
                    end else begin
                        dw_mem[cur_spatial*CEXP + cur_dw_ch] <= acc;
                        dw_tap_count <= dw_tap_count + 1;
                    end
                end

                // One Projection MAC per clock.
                S_PROJ: begin
                    dw_idx = cur_spatial*CEXP + proj_input_ch;
                    proj_idx = cur_out_ch*CEXP + proj_input_ch;
                    out_idx = cur_spatial*COUT + cur_out_ch;

                    if (proj_input_ch == 0)
                        acc = dw_mem[dw_idx] *
                              $signed(proj_w_mem[proj_idx]);
                    else
                        acc = output_mem[out_idx] +
                              dw_mem[dw_idx] *
                              $signed(proj_w_mem[proj_idx]);

                    if (proj_input_ch == CEXP-1) begin
                        output_mem[out_idx] <= acc;
                        proj_input_ch <= 0;

                        if (cur_out_ch == COUT-1) begin
                            cur_out_ch <= 0;

                            if (cur_col == W-1) begin
                                cur_col <= 0;

                                if (cur_row == H-1) begin
                                    cur_row <= 0;
                                    cur_spatial <= 0;
                                    busy <= 0;
                                    done <= 1;
                                    state <= S_DONE;
                                end else begin
                                    cur_row <= cur_row + 1;
                                    cur_spatial <= (cur_row + 1)*W;
                                    cur_exp_ch <= 0;
                                    exp_input_ch <= 0;
                                    state <= S_EXP;
                                end
                            end else begin
                                cur_col <= cur_col + 1;
                                cur_spatial <= cur_spatial + 1;
                                cur_exp_ch <= 0;
                                exp_input_ch <= 0;
                                state <= S_EXP;
                            end
                        end else begin
                            cur_out_ch <= cur_out_ch + 1;
                        end
                    end else begin
                        output_mem[out_idx] <= acc;
                        proj_input_ch <= proj_input_ch + 1;
                    end
                end

                S_DONE: begin
                    // One-cycle terminal state. A new start can be issued from IDLE.
                    state <= S_IDLE;
                    busy <= 0;
                end

                default: begin
                    state <= S_IDLE;
                    busy <= 0;
                end
            endcase
        end
    end

endmodule
