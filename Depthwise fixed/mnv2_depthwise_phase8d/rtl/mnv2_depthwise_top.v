`timescale 1ns/1ps

module mnv2_depthwise_top #(
    parameter integer H       = 4,
    parameter integer W       = 4,
    parameter integer CIN     = 8,
    parameter integer CEXP    = 24,
    parameter integer COUT    = 16,
    parameter integer DATA_W  = 8,
    parameter integer ACC_W  = 32
)(
    input wire clk,
    input wire rst,
    input wire start,

    output reg busy,
    output reg done,

    // ------------------------------------------------------------
    // IFMAP loading
    // ------------------------------------------------------------

    input wire ifmap_wr_en,
    input wire [6:0] ifmap_wr_addr,
    input wire signed [DATA_W-1:0] ifmap_wr_data,

    // ------------------------------------------------------------
    // Expansion weights
    // ------------------------------------------------------------

    input wire exp_wr_en,
    input wire [7:0] exp_wr_addr,
    input wire signed [DATA_W-1:0] exp_wr_data,

    // ------------------------------------------------------------
    // Depthwise weights
    // ------------------------------------------------------------

    input wire dw_wr_en,
    input wire [7:0] dw_wr_addr,
    input wire signed [DATA_W-1:0] dw_wr_data,

    // ------------------------------------------------------------
    // Projection weights
    // ------------------------------------------------------------

    input wire proj_wr_en,
    input wire [8:0] proj_wr_addr,
    input wire signed [DATA_W-1:0] proj_wr_data,

    // ------------------------------------------------------------
    // Output read
    //
    // This is intentionally an asynchronous/combinational read.
    // The CFU can therefore request an output address and obtain
    // the corresponding result without a read-latency ambiguity.
    // ------------------------------------------------------------

    input wire [7:0] out_rd_addr,
    output reg signed [ACC_W-1:0] out_rd_data
);

    // ============================================================
    // Memory sizes
    // ============================================================

    localparam integer IFMAP_N  = H * W * CIN;
    localparam integer EXP_W_N  = CEXP * CIN;
    localparam integer DW_W_N   = CEXP * 9;
    localparam integer PROJ_W_N = COUT * CEXP;

    localparam integer EXP_N = H * W * CEXP;
    localparam integer DW_N  = H * W * CEXP;
    localparam integer OUT_N = H * W * COUT;

    // ============================================================
    // Memories
    // ============================================================

    reg signed [DATA_W-1:0] ifmap_mem [0:IFMAP_N-1];

    reg signed [DATA_W-1:0] exp_w_mem [0:EXP_W_N-1];

    reg signed [DATA_W-1:0] dw_w_mem [0:DW_W_N-1];

    reg signed [DATA_W-1:0] proj_w_mem [0:PROJ_W_N-1];

    reg signed [ACC_W-1:0] expanded_mem [0:EXP_N-1];

    reg signed [ACC_W-1:0] dw_mem [0:DW_N-1];

    reg signed [ACC_W-1:0] output_mem [0:OUT_N-1];

    // ============================================================
    // FSM
    // ============================================================

    localparam [2:0]
        S_IDLE = 3'd0,
        S_EXP  = 3'd1,
        S_DW   = 3'd2,
        S_PROJ = 3'd3,
        S_DONE = 3'd4;

    reg [2:0] state;

    // ============================================================
    // Position counters
    // ============================================================

    integer row_cnt;
    integer col_cnt;
    integer spatial_idx;

    // ============================================================
    // Expansion counters
    // ============================================================

    integer exp_ch;
    integer cin_cnt;

    // ============================================================
    // Depthwise counters
    // ============================================================

    integer dw_ch;
    integer dw_tap;

    // ============================================================
    // Projection counters
    // ============================================================

    integer out_ch;
    integer proj_ch;

    // ============================================================
    // Accumulators
    // ============================================================

    reg signed [ACC_W-1:0] exp_acc_reg;
    reg signed [ACC_W-1:0] dw_acc_reg;
    reg signed [ACC_W-1:0] proj_acc_reg;

    // ============================================================
    // Temporary variables
    // ============================================================

    integer rr;
    integer cc;

    integer if_idx;
    integer exp_idx;
    integer dw_idx;
    integer proj_idx;
    integer out_idx;
    integer neigh_idx;

    integer product;

    integer i;

    // ============================================================
    // COMBINATIONAL OUTPUT READ
    // ============================================================
    //
    // This is the important Phase-6 fix.
    //
    // The output RAM is read directly from the selected address.
    // There is no clock-cycle ambiguity between:
    //
    //     out_rd_addr
    //
    // and
    //
    //     out_rd_data
    //
    // ============================================================

    always @(*) begin

        if (out_rd_addr < OUT_N)
            out_rd_data = output_mem[out_rd_addr];
        else
            out_rd_data = 0;

    end

    // ============================================================
    // MAIN SEQUENTIAL PROCESS
    // ============================================================

    always @(posedge clk) begin

        // ========================================================
        // RESET
        // ========================================================

        if (rst) begin

            busy <= 1'b0;
            done <= 1'b0;

            state <= S_IDLE;

            row_cnt <= 0;
            col_cnt <= 0;
            spatial_idx <= 0;

            exp_ch <= 0;
            cin_cnt <= 0;

            dw_ch <= 0;
            dw_tap <= 0;

            out_ch <= 0;
            proj_ch <= 0;

            exp_acc_reg <= 0;
            dw_acc_reg <= 0;
            proj_acc_reg <= 0;

            // Initialize intermediate memories.
            for (i = 0; i < EXP_N; i = i + 1)
                expanded_mem[i] <= 0;

            for (i = 0; i < DW_N; i = i + 1)
                dw_mem[i] <= 0;

            for (i = 0; i < OUT_N; i = i + 1)
                output_mem[i] <= 0;

        end

        // ========================================================
        // NORMAL OPERATION
        // ========================================================

        else begin

            // DONE is a pulse.
            done <= 1'b0;

            // ====================================================
            // HOST MEMORY LOADS
            // ====================================================

            if (!busy && state == S_IDLE) begin

                if (ifmap_wr_en &&
                    ifmap_wr_addr < IFMAP_N) begin

                    ifmap_mem[ifmap_wr_addr] <= ifmap_wr_data;

                end

                if (exp_wr_en &&
                    exp_wr_addr < EXP_W_N) begin

                    exp_w_mem[exp_wr_addr] <= exp_wr_data;

                end

                if (dw_wr_en &&
                    dw_wr_addr < DW_W_N) begin

                    dw_w_mem[dw_wr_addr] <= dw_wr_data;

                end

                if (proj_wr_en &&
                    proj_wr_addr < PROJ_W_N) begin

                    proj_w_mem[proj_wr_addr] <= proj_wr_data;

                end

            end

            // ====================================================
            // FSM
            // ====================================================

            case (state)

                // ------------------------------------------------
                // IDLE
                // ------------------------------------------------

                S_IDLE: begin

                    busy <= 1'b0;

                    if (start) begin

                        busy <= 1'b1;

                        row_cnt <= 0;
                        col_cnt <= 0;
                        spatial_idx <= 0;

                        exp_ch <= 0;
                        cin_cnt <= 0;

                        dw_ch <= 0;
                        dw_tap <= 0;

                        out_ch <= 0;
                        proj_ch <= 0;

                        exp_acc_reg <= 0;
                        dw_acc_reg <= 0;
                        proj_acc_reg <= 0;

                        state <= S_EXP;

                    end

                end

                // ------------------------------------------------
                // EXPANSION
                // ------------------------------------------------

                S_EXP: begin

                    busy <= 1'b1;

                    if_idx =
                        spatial_idx * CIN +
                        cin_cnt;

                    exp_idx =
                        spatial_idx * CEXP +
                        exp_ch;

                    product =
                        $signed(ifmap_mem[if_idx]) *
                        $signed(
                            exp_w_mem[
                                exp_ch * CIN +
                                cin_cnt
                            ]
                        );

                    if (cin_cnt == CIN - 1) begin

                        expanded_mem[exp_idx] <=
                            exp_acc_reg + product;

                        exp_acc_reg <= 0;
                        cin_cnt <= 0;

                        if (exp_ch == CEXP - 1) begin

                            exp_ch <= 0;

                            dw_ch <= 0;
                            dw_tap <= 0;
                            dw_acc_reg <= 0;

                            state <= S_DW;

                        end
                        else begin

                            exp_ch <= exp_ch + 1;

                        end

                    end
                    else begin

                        exp_acc_reg <=
                            exp_acc_reg + product;

                        cin_cnt <=
                            cin_cnt + 1;

                    end

                end

                // ------------------------------------------------
                // DEPTHWISE
                // ------------------------------------------------

                S_DW: begin

                    busy <= 1'b1;

                    rr =
                        row_cnt +
                        (dw_tap / 3) -
                        1;

                    cc =
                        col_cnt +
                        (dw_tap % 3) -
                        1;

                    if ((rr >= 0) &&
                        (rr < H) &&
                        (cc >= 0) &&
                        (cc < W)) begin

                        neigh_idx =
                            (rr * W + cc) * CEXP +
                            dw_ch;

                        product =
                            $signed(
                                expanded_mem[neigh_idx]
                            ) *
                            $signed(
                                dw_w_mem[
                                    dw_ch * 9 +
                                    dw_tap
                                ]
                            );

                    end
                    else begin

                        // Zero padding.
                        product = 0;

                    end

                    if (dw_tap == 8) begin

                        dw_mem[
                            spatial_idx * CEXP +
                            dw_ch
                        ] <=
                            dw_acc_reg + product;

                        dw_acc_reg <= 0;
                        dw_tap <= 0;

                        if (dw_ch == CEXP - 1) begin

                            dw_ch <= 0;

                            out_ch <= 0;
                            proj_ch <= 0;
                            proj_acc_reg <= 0;

                            state <= S_PROJ;

                        end
                        else begin

                            dw_ch <= dw_ch + 1;

                        end

                    end
                    else begin

                        dw_acc_reg <=
                            dw_acc_reg + product;

                        dw_tap <=
                            dw_tap + 1;

                    end

                end

                // ------------------------------------------------
                // PROJECTION
                // ------------------------------------------------

                S_PROJ: begin

                    busy <= 1'b1;

                    dw_idx =
                        spatial_idx * CEXP +
                        proj_ch;

                    proj_idx =
                        out_ch * CEXP +
                        proj_ch;

                    out_idx =
                        spatial_idx * COUT +
                        out_ch;

                    product =
                        $signed(
                            dw_mem[dw_idx]
                        ) *
                        $signed(
                            proj_w_mem[proj_idx]
                        );

                    if (proj_ch == CEXP - 1) begin

                        output_mem[out_idx] <=
                            proj_acc_reg + product;

                        proj_acc_reg <= 0;
                        proj_ch <= 0;

                        if (out_ch == COUT - 1) begin

                            out_ch <= 0;

                            if (col_cnt == W - 1) begin

                                col_cnt <= 0;

                                if (row_cnt == H - 1) begin

                                    row_cnt <= 0;
                                    spatial_idx <= 0;

                                    busy <= 1'b0;
                                    done <= 1'b1;

                                    state <= S_DONE;

                                end
                                else begin

                                    row_cnt <=
                                        row_cnt + 1;

                                    spatial_idx <=
                                        spatial_idx + 1;

                                    exp_ch <= 0;
                                    cin_cnt <= 0;

                                    exp_acc_reg <= 0;

                                    state <= S_EXP;

                                end

                            end
                            else begin

                                col_cnt <=
                                    col_cnt + 1;

                                spatial_idx <=
                                    spatial_idx + 1;

                                exp_ch <= 0;
                                cin_cnt <= 0;

                                exp_acc_reg <= 0;

                                state <= S_EXP;

                            end

                        end
                        else begin

                            out_ch <=
                                out_ch + 1;

                        end

                    end
                    else begin

                        proj_acc_reg <=
                            proj_acc_reg + product;

                        proj_ch <=
                            proj_ch + 1;

                    end

                end

                // ------------------------------------------------
                // DONE
                // ------------------------------------------------

                S_DONE: begin

                    busy <= 1'b0;

                    state <= S_IDLE;

                end

                // ------------------------------------------------
                // SAFETY
                // ------------------------------------------------

                default: begin

                    state <= S_IDLE;
                    busy <= 1'b0;
                    done <= 1'b0;

                end

            endcase

        end

    end

endmodule