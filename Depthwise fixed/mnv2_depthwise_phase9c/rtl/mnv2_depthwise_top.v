`timescale 1ns/1ps

module mnv2_depthwise_top #(
    parameter integer H       = 4,
    parameter integer W       = 4,
    parameter integer CIN     = 8,
    parameter integer CEXP    = 24,
    parameter integer COUT    = 16,
    parameter integer DATA_W  = 8,
    parameter integer ACC_W   = 32
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

    // ============================================================
    // CONSTANTS
    // ============================================================

    localparam integer IFMAP_N =
        H * W * CIN;

    localparam integer EXP_W_N =
        CEXP * CIN;

    localparam integer DW_W_N =
        CEXP * 9;

    localparam integer PROJ_W_N =
        COUT * CEXP;

    localparam integer SPATIAL_COUNT =
        H * W;

    localparam integer EXP_N =
        H * W * CEXP;

    localparam integer DW_N =
        H * W * CEXP;

    localparam integer OUT_N =
        H * W * COUT;


    // ============================================================
    // MEMORIES
    // ============================================================

    reg signed [DATA_W-1:0]
        ifmap_mem [0:IFMAP_N-1];

    reg signed [DATA_W-1:0]
        exp_w_mem [0:EXP_W_N-1];

    reg signed [DATA_W-1:0]
        dw_w_mem [0:DW_W_N-1];

    reg signed [DATA_W-1:0]
        proj_w_mem [0:PROJ_W_N-1];

    reg signed [ACC_W-1:0]
        expanded_mem [0:EXP_N-1];

    reg signed [ACC_W-1:0]
        dw_mem [0:DW_N-1];

    reg signed [ACC_W-1:0]
        output_mem [0:OUT_N-1];


    // ============================================================
    // FSM
    // ============================================================
    //
    // IMPORTANT:
    //
    // Expansion MUST finish for the entire image before
    // depthwise processing begins.
    //
    // Depthwise processing requires expanded values from
    // neighboring spatial positions.
    //
    // ============================================================

    localparam [2:0]
        S_IDLE = 3'd0,
        S_EXP  = 3'd1,
        S_DW   = 3'd2,
        S_PROJ = 3'd3,
        S_DONE = 3'd4;

    reg [2:0] state;


    // ============================================================
    // COUNTERS
    // ============================================================

    integer spatial_idx;
    integer exp_ch;
    integer dw_ch;
    integer out_ch;


    // ============================================================
    // TEMPORARY VARIABLES
    // ============================================================

    integer i;
    integer j;

    integer current_row;
    integer current_col;

    integer neighbor_spatial;

    integer if_idx;
    integer exp_idx;
    integer dw_idx;
    integer proj_idx;
    integer out_idx;

    integer product;
    integer mac_sum;


    // ============================================================
    // OUTPUT READ
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

            spatial_idx <= 0;
            exp_ch <= 0;
            dw_ch <= 0;
            out_ch <= 0;


            // ----------------------------------------------------
            // Clear intermediate memories
            // ----------------------------------------------------

            for (i = 0; i < EXP_N; i = i + 1)
                expanded_mem[i] = 0;

            for (i = 0; i < DW_N; i = i + 1)
                dw_mem[i] = 0;

            for (i = 0; i < OUT_N; i = i + 1)
                output_mem[i] = 0;

        end


        // ========================================================
        // NORMAL OPERATION
        // ========================================================

        else begin

            // ====================================================
            // HOST MEMORY LOADS
            // ====================================================

            /*
             * Host writes are accepted only while the accelerator
             * is completely idle.
             */

            if (!busy && state == S_IDLE) begin

                if (ifmap_wr_en &&
                    ifmap_wr_addr < IFMAP_N) begin

                    ifmap_mem[ifmap_wr_addr] <=
                        ifmap_wr_data;

                end


                if (exp_wr_en &&
                    exp_wr_addr < EXP_W_N) begin

                    exp_w_mem[exp_wr_addr] <=
                        exp_wr_data;

                end


                if (dw_wr_en &&
                    dw_wr_addr < DW_W_N) begin

                    dw_w_mem[dw_wr_addr] <=
                        dw_wr_data;

                end


                if (proj_wr_en &&
                    proj_wr_addr < PROJ_W_N) begin

                    proj_w_mem[proj_wr_addr] <=
                        proj_wr_data;

                end

            end


            // ====================================================
            // FSM
            // ====================================================

            case (state)


                // =================================================
                // IDLE
                // =================================================

                S_IDLE: begin

                    busy <= 1'b0;
                    done <= 1'b0;


                    if (start) begin

                        busy <= 1'b1;
                        done <= 1'b0;

                        /*
                         * Start expansion from spatial position 0.
                         */

                        spatial_idx <= 0;
                        exp_ch <= 0;

                        dw_ch <= 0;
                        out_ch <= 0;

                        state <= S_EXP;

                    end

                end


                // =================================================
                // EXPANSION
                // =================================================
                //
                // Process:
                //
                // spatial 0 : exp_ch 0..23
                // spatial 1 : exp_ch 0..23
                // ...
                // spatial 15: exp_ch 0..23
                //
                // ONLY after all expansion values have been
                // generated do we enter S_DW.
                //
                // =================================================

                S_EXP: begin

                    busy <= 1'b1;

                    mac_sum = 0;


                    // ------------------------------------------------
                    // Calculate expansion MAC
                    // ------------------------------------------------

                    for (j = 0; j < CIN; j = j + 1) begin

                        if_idx =
                            spatial_idx * CIN + j;

                        exp_idx =
                            exp_ch * CIN + j;

                        product =
                            $signed(ifmap_mem[if_idx]) *
                            $signed(exp_w_mem[exp_idx]);

                        mac_sum =
                            mac_sum + product;

                    end


                    // ------------------------------------------------
                    // Store expansion result
                    // ------------------------------------------------

                    expanded_mem[
                        spatial_idx * CEXP + exp_ch
                    ] <= mac_sum;


                    // ------------------------------------------------
                    // Next expansion channel
                    // ------------------------------------------------

                    if (exp_ch == CEXP - 1) begin

                        exp_ch <= 0;


                        // --------------------------------------------
                        // Last expansion channel for this spatial
                        // --------------------------------------------

                        if (spatial_idx ==
                            SPATIAL_COUNT - 1) begin

                            /*
                             * ALL expansion values now exist.
                             *
                             * Start depthwise from spatial 0.
                             */

                            spatial_idx <= 0;
                            dw_ch <= 0;

                            state <= S_DW;

                        end

                        else begin

                            /*
                             * Move to the next spatial position
                             * while remaining in expansion.
                             */

                            spatial_idx <=
                                spatial_idx + 1;

                            exp_ch <= 0;

                        end

                    end

                    else begin

                        exp_ch <=
                            exp_ch + 1;

                    end

                end


                // =================================================
                // DEPTHWISE
                // =================================================
                //
                // At this point the COMPLETE expanded feature map
                // has already been calculated.
                //
                // Therefore all nine neighboring spatial values
                // are valid.
                //
                // =================================================

                S_DW: begin

                    busy <= 1'b1;


                    // ------------------------------------------------
                    // Current spatial coordinates
                    // ------------------------------------------------

                    current_row =
                        spatial_idx / W;

                    current_col =
                        spatial_idx % W;


                    mac_sum = 0;


                    // =================================================
                    // TAP 0 : (-1,-1)
                    // =================================================

                    if ((current_row > 0) &&
                        (current_col > 0)) begin

                        neighbor_spatial =
                            (current_row - 1) * W +
                            (current_col - 1);

                        dw_idx =
                            neighbor_spatial * CEXP +
                            dw_ch;

                        product =
                            $signed(expanded_mem[dw_idx]) *
                            $signed(
                                dw_w_mem[dw_ch * 9 + 0]
                            );

                        mac_sum =
                            mac_sum + product;

                    end


                    // =================================================
                    // TAP 1 : (-1,0)
                    // =================================================

                    if (current_row > 0) begin

                        neighbor_spatial =
                            (current_row - 1) * W +
                            current_col;

                        dw_idx =
                            neighbor_spatial * CEXP +
                            dw_ch;

                        product =
                            $signed(expanded_mem[dw_idx]) *
                            $signed(
                                dw_w_mem[dw_ch * 9 + 1]
                            );

                        mac_sum =
                            mac_sum + product;

                    end


                    // =================================================
                    // TAP 2 : (-1,+1)
                    // =================================================

                    if ((current_row > 0) &&
                        (current_col < W - 1)) begin

                        neighbor_spatial =
                            (current_row - 1) * W +
                            (current_col + 1);

                        dw_idx =
                            neighbor_spatial * CEXP +
                            dw_ch;

                        product =
                            $signed(expanded_mem[dw_idx]) *
                            $signed(
                                dw_w_mem[dw_ch * 9 + 2]
                            );

                        mac_sum =
                            mac_sum + product;

                    end


                    // =================================================
                    // TAP 3 : (0,-1)
                    // =================================================

                    if (current_col > 0) begin

                        neighbor_spatial =
                            current_row * W +
                            (current_col - 1);

                        dw_idx =
                            neighbor_spatial * CEXP +
                            dw_ch;

                        product =
                            $signed(expanded_mem[dw_idx]) *
                            $signed(
                                dw_w_mem[dw_ch * 9 + 3]
                            );

                        mac_sum =
                            mac_sum + product;

                    end


                    // =================================================
                    // TAP 4 : (0,0)
                    // =================================================

                    neighbor_spatial =
                        current_row * W +
                        current_col;

                    dw_idx =
                        neighbor_spatial * CEXP +
                        dw_ch;

                    product =
                        $signed(expanded_mem[dw_idx]) *
                        $signed(
                            dw_w_mem[dw_ch * 9 + 4]
                        );

                    mac_sum =
                        mac_sum + product;


                    // =================================================
                    // TAP 5 : (0,+1)
                    // =================================================

                    if (current_col < W - 1) begin

                        neighbor_spatial =
                            current_row * W +
                            (current_col + 1);

                        dw_idx =
                            neighbor_spatial * CEXP +
                            dw_ch;

                        product =
                            $signed(expanded_mem[dw_idx]) *
                            $signed(
                                dw_w_mem[dw_ch * 9 + 5]
                            );

                        mac_sum =
                            mac_sum + product;

                    end


                    // =================================================
                    // TAP 6 : (+1,-1)
                    // =================================================

                    if ((current_row < H - 1) &&
                        (current_col > 0)) begin

                        neighbor_spatial =
                            (current_row + 1) * W +
                            (current_col - 1);

                        dw_idx =
                            neighbor_spatial * CEXP +
                            dw_ch;

                        product =
                            $signed(expanded_mem[dw_idx]) *
                            $signed(
                                dw_w_mem[dw_ch * 9 + 6]
                            );

                        mac_sum =
                            mac_sum + product;

                    end


                    // =================================================
                    // TAP 7 : (+1,0)
                    // =================================================

                    if (current_row < H - 1) begin

                        neighbor_spatial =
                            (current_row + 1) * W +
                            current_col;

                        dw_idx =
                            neighbor_spatial * CEXP +
                            dw_ch;

                        product =
                            $signed(expanded_mem[dw_idx]) *
                            $signed(
                                dw_w_mem[dw_ch * 9 + 7]
                            );

                        mac_sum =
                            mac_sum + product;

                    end


                    // =================================================
                    // TAP 8 : (+1,+1)
                    // =================================================

                    if ((current_row < H - 1) &&
                        (current_col < W - 1)) begin

                        neighbor_spatial =
                            (current_row + 1) * W +
                            (current_col + 1);

                        dw_idx =
                            neighbor_spatial * CEXP +
                            dw_ch;

                        product =
                            $signed(expanded_mem[dw_idx]) *
                            $signed(
                                dw_w_mem[dw_ch * 9 + 8]
                            );

                        mac_sum =
                            mac_sum + product;

                    end


                    // =================================================
                    // STORE DEPTHWISE RESULT
                    // =================================================

                    dw_idx =
                        spatial_idx * CEXP +
                        dw_ch;

                    dw_mem[dw_idx] <=
                        mac_sum;


                    // =================================================
                    // NEXT DEPTHWISE CHANNEL
                    // =================================================

                    if (dw_ch == CEXP - 1) begin

                        dw_ch <= 0;


                        // --------------------------------------------
                        // Last depthwise channel for this spatial
                        // --------------------------------------------

                        if (spatial_idx ==
                            SPATIAL_COUNT - 1) begin

                            /*
                             * All depthwise values now exist.
                             *
                             * Start projection from spatial 0.
                             */

                            spatial_idx <= 0;
                            out_ch <= 0;

                            state <= S_PROJ;

                        end

                        else begin

                            /*
                             * Move to next spatial position.
                             */

                            spatial_idx <=
                                spatial_idx + 1;

                            dw_ch <= 0;

                        end

                    end

                    else begin

                        dw_ch <=
                            dw_ch + 1;

                    end

                end


                // =================================================
                // PROJECTION
                // =================================================
                //
                // Process:
                //
                // spatial 0 : output channels 0..15
                // spatial 1 : output channels 0..15
                // ...
                // spatial 15: output channels 0..15
                //
                // =================================================

                S_PROJ: begin

                    busy <= 1'b1;

                    mac_sum = 0;


                    // ------------------------------------------------
                    // Projection MAC
                    // ------------------------------------------------

                    for (j = 0; j < CEXP; j = j + 1) begin

                        dw_idx =
                            spatial_idx * CEXP + j;

                        proj_idx =
                            out_ch * CEXP + j;

                        product =
                            $signed(dw_mem[dw_idx]) *
                            $signed(proj_w_mem[proj_idx]);

                        mac_sum =
                            mac_sum + product;

                    end


                    // ------------------------------------------------
                    // Store output
                    // ------------------------------------------------

                    out_idx =
                        spatial_idx * COUT +
                        out_ch;

                    output_mem[out_idx] <=
                        mac_sum;


                    // ------------------------------------------------
                    // Next output channel
                    // ------------------------------------------------

                    if (out_ch == COUT - 1) begin

                        out_ch <= 0;


                        // --------------------------------------------
                        // Last spatial position
                        // --------------------------------------------

                        if (spatial_idx ==
                            SPATIAL_COUNT - 1) begin

                            busy <= 1'b0;
                            done <= 1'b1;

                            state <= S_DONE;

                        end

                        else begin

                            /*
                             * Move to next spatial position.
                             */

                            spatial_idx <=
                                spatial_idx + 1;

                            out_ch <= 0;

                        end

                    end

                    else begin

                        out_ch <=
                            out_ch + 1;

                    end

                end


                // =================================================
                // DONE
                // =================================================

                S_DONE: begin

                    busy <= 1'b0;
                    done <= 1'b1;


                    /*
                     * Allow another START without reloading
                     * input or weight memories.
                     */

                    if (start) begin

                        busy <= 1'b1;
                        done <= 1'b0;

                        spatial_idx <= 0;

                        exp_ch <= 0;
                        dw_ch <= 0;
                        out_ch <= 0;

                        state <= S_EXP;

                    end

                end


                // =================================================
                // DEFAULT
                // =================================================

                default: begin

                    busy <= 1'b0;
                    done <= 1'b0;

                    state <= S_IDLE;

                    spatial_idx <= 0;

                    exp_ch <= 0;
                    dw_ch <= 0;
                    out_ch <= 0;

                end

            endcase

        end

    end

endmodule