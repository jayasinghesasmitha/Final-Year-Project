/*******************************************************************************
 * Expansion Unit
 *
 * First stage of the fused DSC pipeline. Performs 1x1 pointwise convolution
 * that expands the feature map's channel depth.
 *
 * Architecture:
 *   - 9 parallel Expansion Engines (3x3 spatial tile)
 *   - Input-Stationary (IS) dataflow
 *   - Each engine: 8-way MAC tree
 *   - Post-processing: bias, requantization, ReLU
 *
 * Dataflow:
 *   - 3x3 IFMAP tile held stationary
 *   - Expansion filters streamed (8 channels per cycle)
 *   - Outputs 3x3 tile of intermediate feature map F1
 ******************************************************************************/

`include "cfu_dsc_defines.v"

module expansion_unit (
    input  wire                         clk,
    input  wire                         rst_n,

    // Control signals
    input  wire                         start,
    input  wire                         clear_acc,
    input  wire                         last_filter,
    input  wire                         last_channel,
    output reg                          output_ready,

    // IFMAP inputs (3x3 tile, all channels multiplexed)
    input  wire [`DATA_WIDTH-1:0]       ifmap_0, ifmap_1, ifmap_2,
    input  wire [`DATA_WIDTH-1:0]       ifmap_3, ifmap_4, ifmap_5,
    input  wire [`DATA_WIDTH-1:0]       ifmap_6, ifmap_7, ifmap_8,

    // Weight inputs (8 channels, broadcast to all engines)
    input  wire [`DATA_WIDTH-1:0]       weight_0, weight_1, weight_2, weight_3,
    input  wire [`DATA_WIDTH-1:0]       weight_4, weight_5, weight_6, weight_7,

    // Post-processing parameters
    input  wire signed [`ACC_WIDTH-1:0] bias,
    input  wire signed [31:0]           scale,
    input  wire signed [31:0]           zero_point,
    input  wire [4:0]                   shift_amount,

    // Outputs (3x3 tile of F1)
    output wire [`DATA_WIDTH-1:0]       f1_out_0, f1_out_1, f1_out_2,
    output wire [`DATA_WIDTH-1:0]       f1_out_3, f1_out_4, f1_out_5,
    output wire [`DATA_WIDTH-1:0]       f1_out_6, f1_out_7, f1_out_8,
    output reg                          f1_valid
);

    //==========================================================================
    // 9 Parallel Expansion Engines
    //==========================================================================
    wire [`ACC_WIDTH-1:0] exp_acc_result  [0:8];
    wire                  exp_result_valid[0:8];

    // Generate 9 expansion engines
    genvar i;
    generate
        for (i = 0; i < 9; i = i + 1) begin : exp_engines
            // Select the appropriate IFMAP pixel for this engine
            wire [`DATA_WIDTH-1:0] engine_ifmap;
            case (i)
                0: assign engine_ifmap = ifmap_0;
                1: assign engine_ifmap = ifmap_1;
                2: assign engine_ifmap = ifmap_2;
                3: assign engine_ifmap = ifmap_3;
                4: assign engine_ifmap = ifmap_4;
                5: assign engine_ifmap = ifmap_5;
                6: assign engine_ifmap = ifmap_6;
                7: assign engine_ifmap = ifmap_7;
                8: assign engine_ifmap = ifmap_8;
            endcase

            expansion_engine engine (
                .clk            (clk),
                .rst_n          (rst_n),
                .start          (start),
                .clear_acc      (clear_acc),
                .last_channel   (last_channel),

                // IFMAP data (same pixel, 8 channels multiplexed)
                .ifmap_data_0   (engine_ifmap),
                .ifmap_data_1   (engine_ifmap),
                .ifmap_data_2   (engine_ifmap),
                .ifmap_data_3   (engine_ifmap),
                .ifmap_data_4   (engine_ifmap),
                .ifmap_data_5   (engine_ifmap),
                .ifmap_data_6   (engine_ifmap),
                .ifmap_data_7   (engine_ifmap),

                // Weights (broadcast to all engines)
                .weight_0       (weight_0),
                .weight_1       (weight_1),
                .weight_2       (weight_2),
                .weight_3       (weight_3),
                .weight_4       (weight_4),
                .weight_5       (weight_5),
                .weight_6       (weight_6),
                .weight_7       (weight_7),

                .acc_result     (exp_acc_result[i]),
                .result_valid   (exp_result_valid[i])
            );
        end
    endgenerate

    //==========================================================================
    // Post-Processing Pipeline for Each Engine
    //==========================================================================
    wire [`DATA_WIDTH-1:0] pp_out  [0:8];
    wire                   pp_valid[0:8];

    generate
        for (i = 0; i < 9; i = i + 1) begin : post_process
            post_processing_unit pp_unit (
                .clk            (clk),
                .rst_n          (rst_n),
                .valid_in       (exp_result_valid[i]),
                .valid_out      (pp_valid[i]),
                .acc_in         (exp_acc_result[i]),
                .bias           (bias),
                .scale          (scale),
                .zero_point     (zero_point),
                .shift_amount   (shift_amount),
                .data_out       (pp_out[i])
            );
        end
    endgenerate

    //==========================================================================
    // Output Assignment
    //==========================================================================
    assign f1_out_0 = pp_out[0];
    assign f1_out_1 = pp_out[1];
    assign f1_out_2 = pp_out[2];
    assign f1_out_3 = pp_out[3];
    assign f1_out_4 = pp_out[4];
    assign f1_out_5 = pp_out[5];
    assign f1_out_6 = pp_out[6];
    assign f1_out_7 = pp_out[7];
    assign f1_out_8 = pp_out[8];

    // All outputs are valid when all post-processing units are done
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            f1_valid     <= 1'b0;
            output_ready <= 1'b0;
        end else begin
            f1_valid     <= pp_valid[0] && last_filter;
            output_ready <= pp_valid[0] && last_filter;
        end
    end

endmodule
