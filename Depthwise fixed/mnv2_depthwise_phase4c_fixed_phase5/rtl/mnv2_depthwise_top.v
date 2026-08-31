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
    // IFMAP loading interface
    // ------------------------------------------------------------
    input wire                    ifmap_wr_en,
    input wire [6:0]              ifmap_wr_addr,
    input wire signed [DATA_W-1:0] ifmap_wr_data,

    // ------------------------------------------------------------
    // Expansion weight loading interface
    // ------------------------------------------------------------
    input wire                    exp_wr_en,
    input wire [7:0]              exp_wr_addr,
    input wire signed [DATA_W-1:0] exp_wr_data,

    // ------------------------------------------------------------
    // Depthwise weight loading interface
    // ------------------------------------------------------------
    input wire                    dw_wr_en,
    input wire [7:0]              dw_wr_addr,
    input wire signed [DATA_W-1:0] dw_wr_data,

    // ------------------------------------------------------------
    // Projection weight loading interface
    // ------------------------------------------------------------
    input wire                    proj_wr_en,
    input wire [8:0]              proj_wr_addr,
    input wire signed [DATA_W-1:0] proj_wr_data,

    // ------------------------------------------------------------
    // Output read interface
    // ------------------------------------------------------------
    input wire [7:0] out_rd_addr,
    output reg signed [ACC_W-1:0] out_rd_data
);

    // ============================================================
    // Memory sizes
    // ============================================================

    localparam integer IFMAP_SIZE = H * W * CIN;
    localparam integer EXP_W_SIZE = CEXP * CIN;
    localparam integer DW_W_SIZE  = CEXP * 9;
    localparam integer PROJ_W_SIZE = COUT * CEXP;

    localparam integer EXP_SIZE = H * W * CEXP;
    localparam integer DW_SIZE  = H * W * CEXP;
    localparam integer OUT_SIZE = H * W * COUT;

    // ============================================================
    // Memories
    // ============================================================

    reg signed [DATA_W-1:0] ifmap_mem [0:IFMAP_SIZE-1];

    reg signed [DATA_W-1:0] exp_weight_mem [0:EXP_W_SIZE-1];

    reg signed [DATA_W-1:0] dw_weight_mem [0:DW_W_SIZE-1];

    reg signed [DATA_W-1:0] proj_weight_mem [0:PROJ_W_SIZE-1];

    reg signed [ACC_W-1:0] expanded_mem [0:EXP_SIZE-1];

    reg signed [ACC_W-1:0] depthwise_mem [0:DW_SIZE-1];

    reg signed [ACC_W-1:0] output_mem [0:OUT_SIZE-1];

    // ============================================================
    // FSM
    // ============================================================

    localparam [2:0]
        STATE_IDLE  = 3'd0,
        STATE_EXP   = 3'd1,
        STATE_DW    = 3'd2,
        STATE_PROJ  = 3'd3,
        STATE_DONE  = 3'd4;

    reg [2:0] state;

    // ============================================================
    // Current position
    // ============================================================

    integer row_cnt;
    integer col_cnt;

    integer spatial_idx;

    // ============================================================
    // Expansion counters
    // ============================================================

    integer exp_channel;
    integer input_channel;

    // ============================================================
    // Depthwise counters
    // ============================================================

    integer dw_channel;
    integer dw_tap;

    // ============================================================
    // Projection counters
    // ============================================================

    integer output_channel;
    integer projection_channel;

    // ============================================================
    // Explicit accumulators
    // ============================================================

    reg signed [ACC_W-1:0] expansion_acc;
    reg signed [ACC_W-1:0] depthwise_acc;
    reg signed [ACC_W-1:0] projection_acc;

    // ============================================================
    // Temporary calculation variables
    // ============================================================

    integer input_index;
    integer expansion_index;
    integer depthwise_index;
    integer projection_index;
    integer output_index;

    integer neighbour_index;

    integer neighbour_row;
    integer neighbour_col;

    integer multiply_result;

    integer i;

    // ============================================================
    // Main sequential process
    // ============================================================

    always @(posedge clk) begin

        // --------------------------------------------------------
        // RESET
        // --------------------------------------------------------

        if (rst) begin

            busy <= 1'b0;
            done <= 1'b0;

            state <= STATE_IDLE;

            out_rd_data <= 0;

            row_cnt <= 0;
            col_cnt <= 0;
            spatial_idx <= 0;

            exp_channel <= 0;
            input_channel <= 0;

            dw_channel <= 0;
            dw_tap <= 0;

            output_channel <= 0;
            projection_channel <= 0;

            expansion_acc <= 0;
            depthwise_acc <= 0;
            projection_acc <= 0;

            // ----------------------------------------------------
            // Deterministically initialize intermediate memories.
            // This is mainly important for simulation.
            // ----------------------------------------------------

            for (i = 0; i < EXP_SIZE; i = i + 1)
                expanded_mem[i] <= 0;

            for (i = 0; i < DW_SIZE; i = i + 1)
                depthwise_mem[i] <= 0;

            for (i = 0; i < OUT_SIZE; i = i + 1)
                output_mem[i] <= 0;

        end

        // --------------------------------------------------------
        // NORMAL OPERATION
        // --------------------------------------------------------

        else begin

            // DONE is a one-cycle pulse.
            done <= 1'b0;

            // ====================================================
            // HOST MEMORY LOADING
            // ====================================================

            // Loading is allowed only while accelerator is idle.

            if (!busy && state == STATE_IDLE) begin

                if (ifmap_wr_en) begin
                    if (ifmap_wr_addr < IFMAP_SIZE)
                        ifmap_mem[ifmap_wr_addr] <= ifmap_wr_data;
                end

                if (exp_wr_en) begin
                    if (exp_wr_addr < EXP_W_SIZE)
                        exp_weight_mem[exp_wr_addr] <= exp_wr_data;
                end

                if (dw_wr_en) begin
                    if (dw_wr_addr < DW_W_SIZE)
                        dw_weight_mem[dw_wr_addr] <= dw_wr_data;
                end

                if (proj_wr_en) begin
                    if (proj_wr_addr < PROJ_W_SIZE)
                        proj_weight_mem[proj_wr_addr] <= proj_wr_data;
                end

            end

            // ====================================================
            // OUTPUT READ PORT
            // ====================================================
            //
            // This is deliberately independent of the FSM.
            //
            // The host can read results whenever computation is
            // finished.
            //
            // The value is sampled on the clock edge.
            // ====================================================

            if (!busy) begin

                if (out_rd_addr < OUT_SIZE)
                    out_rd_data <= output_mem[out_rd_addr];

            end

            // ====================================================
            // FSM
            // ====================================================

            case (state)

                // =================================================
                // IDLE
                // =================================================

                STATE_IDLE: begin

                    busy <= 1'b0;

                    if (start) begin

                        busy <= 1'b1;

                        row_cnt <= 0;
                        col_cnt <= 0;
                        spatial_idx <= 0;

                        exp_channel <= 0;
                        input_channel <= 0;

                        dw_channel <= 0;
                        dw_tap <= 0;

                        output_channel <= 0;
                        projection_channel <= 0;

                        expansion_acc <= 0;
                        depthwise_acc <= 0;
                        projection_acc <= 0;

                        state <= STATE_EXP;

                    end

                end


                // =================================================
                // EXPANSION
                // =================================================
                //
                // For every expanded channel:
                //
                //     sum over CIN input channels
                //
                // One multiplication is performed per clock.
                // =================================================

                STATE_EXP: begin

                    busy <= 1'b1;

                    input_index =
                        spatial_idx * CIN +
                        input_channel;

                    expansion_index =
                        spatial_idx * CEXP +
                        exp_channel;

                    multiply_result =
                        $signed(ifmap_mem[input_index]) *
                        $signed(
                            exp_weight_mem[
                                exp_channel * CIN +
                                input_channel
                            ]
                        );

                    // --------------------------------------------
                    // Last input channel
                    // --------------------------------------------

                    if (input_channel == CIN - 1) begin

                        expanded_mem[expansion_index] <=
                            expansion_acc + multiply_result;

                        // Reset accumulator for next expansion
                        // channel.
                        expansion_acc <= 0;

                        input_channel <= 0;

                        // ----------------------------------------
                        // Last expansion channel
                        // ----------------------------------------

                        if (exp_channel == CEXP - 1) begin

                            exp_channel <= 0;

                            dw_channel <= 0;
                            dw_tap <= 0;

                            depthwise_acc <= 0;

                            state <= STATE_DW;

                        end

                        else begin

                            exp_channel <=
                                exp_channel + 1;

                        end

                    end

                    // --------------------------------------------
                    // More input channels
                    // --------------------------------------------

                    else begin

                        expansion_acc <=
                            expansion_acc +
                            multiply_result;

                        input_channel <=
                            input_channel + 1;

                    end

                end


                // =================================================
                // DEPTHWISE
                // =================================================
                //
                // 3x3 kernel.
                //
                // Padding = zero.
                //
                // One multiplication per clock.
                // =================================================

                STATE_DW: begin

                    busy <= 1'b1;

                    // --------------------------------------------
                    // Calculate neighbour coordinates.
                    //
                    // tap mapping:
                    //
                    // 0 1 2
                    // 3 4 5
                    // 6 7 8
                    // --------------------------------------------

                    neighbour_row =
                        row_cnt +
                        (dw_tap / 3) -
                        1;

                    neighbour_col =
                        col_cnt +
                        (dw_tap % 3) -
                        1;

                    // --------------------------------------------
                    // Valid image coordinate
                    // --------------------------------------------

                    if ((neighbour_row >= 0) &&
                        (neighbour_row < H) &&
                        (neighbour_col >= 0) &&
                        (neighbour_col < W)) begin

                        neighbour_index =
                            (neighbour_row * W +
                             neighbour_col) * CEXP +
                             dw_channel;

                        multiply_result =
                            $signed(
                                expanded_mem[neighbour_index]
                            ) *
                            $signed(
                                dw_weight_mem[
                                    dw_channel * 9 +
                                    dw_tap
                                ]
                            );

                    end

                    // --------------------------------------------
                    // Outside image = zero padding
                    // --------------------------------------------

                    else begin

                        multiply_result = 0;

                    end

                    // --------------------------------------------
                    // Last tap
                    // --------------------------------------------

                    if (dw_tap == 8) begin

                        depthwise_mem[
                            spatial_idx * CEXP +
                            dw_channel
                        ] <=
                            depthwise_acc +
                            multiply_result;

                        depthwise_acc <= 0;

                        dw_tap <= 0;

                        // ----------------------------------------
                        // Last depthwise channel
                        // ----------------------------------------

                        if (dw_channel == CEXP - 1) begin

                            dw_channel <= 0;

                            output_channel <= 0;
                            projection_channel <= 0;

                            projection_acc <= 0;

                            state <= STATE_PROJ;

                        end

                        else begin

                            dw_channel <=
                                dw_channel + 1;

                        end

                    end

                    // --------------------------------------------
                    // More taps
                    // --------------------------------------------

                    else begin

                        depthwise_acc <=
                            depthwise_acc +
                            multiply_result;

                        dw_tap <=
                            dw_tap + 1;

                    end

                end


                // =================================================
                // PROJECTION
                // =================================================
                //
                // For each output channel:
                //
                //     sum over CEXP channels
                //
                // One multiplication per clock.
                // =================================================

                STATE_PROJ: begin

                    busy <= 1'b1;

                    depthwise_index =
                        spatial_idx * CEXP +
                        projection_channel;

                    projection_index =
                        output_channel * CEXP +
                        projection_channel;

                    output_index =
                        spatial_idx * COUT +
                        output_channel;

                    multiply_result =
                        $signed(
                            depthwise_mem[depthwise_index]
                        ) *
                        $signed(
                            proj_weight_mem[projection_index]
                        );

                    // --------------------------------------------
                    // Last expanded channel
                    // --------------------------------------------

                    if (projection_channel == CEXP - 1) begin

                        output_mem[output_index] <=
                            projection_acc +
                            multiply_result;

                        projection_acc <= 0;

                        projection_channel <= 0;

                        // ----------------------------------------
                        // Last output channel
                        // ----------------------------------------

                        if (output_channel == COUT - 1) begin

                            output_channel <= 0;

                            // ------------------------------------
                            // Last column
                            // ------------------------------------

                            if (col_cnt == W - 1) begin

                                col_cnt <= 0;

                                // --------------------------------
                                // Last row
                                // --------------------------------

                                if (row_cnt == H - 1) begin

                                    row_cnt <= 0;

                                    spatial_idx <= 0;

                                    busy <= 1'b0;

                                    done <= 1'b1;

                                    state <= STATE_DONE;

                                end

                                // --------------------------------
                                // Next row
                                // --------------------------------

                                else begin

                                    row_cnt <=
                                        row_cnt + 1;

                                    col_cnt <= 0;

                                    spatial_idx <=
                                        spatial_idx + 1;

                                    exp_channel <= 0;
                                    input_channel <= 0;

                                    expansion_acc <= 0;

                                    state <= STATE_EXP;

                                end

                            end

                            // ------------------------------------
                            // Next column
                            // ------------------------------------

                            else begin

                                col_cnt <=
                                    col_cnt + 1;

                                spatial_idx <=
                                    spatial_idx + 1;

                                exp_channel <= 0;
                                input_channel <= 0;

                                expansion_acc <= 0;

                                state <= STATE_EXP;

                            end

                        end

                        // ----------------------------------------
                        // Next output channel
                        // ----------------------------------------

                        else begin

                            output_channel <=
                                output_channel + 1;

                        end

                    end

                    // --------------------------------------------
                    // More expanded channels
                    // --------------------------------------------

                    else begin

                        projection_acc <=
                            projection_acc +
                            multiply_result;

                        projection_channel <=
                            projection_channel + 1;

                    end

                end


                // =================================================
                // DONE
                // =================================================

                STATE_DONE: begin

                    busy <= 1'b0;

                    state <= STATE_IDLE;

                end


                // =================================================
                // SAFETY
                // =================================================

                default: begin

                    state <= STATE_IDLE;

                    busy <= 1'b0;

                    done <= 1'b0;

                end

            endcase

        end

    end

endmodule