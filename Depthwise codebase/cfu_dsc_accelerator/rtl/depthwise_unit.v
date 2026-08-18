/*******************************************************************************
 * Depthwise Unit
 *
 * Second stage of the fused DSC pipeline. Performs 3x3 depthwise convolution
 * on M channels of intermediate feature map F1.
 *
 * Architecture:
 *   - Single Depthwise Engine
 *   - 9-way MAC array (3x3 filter)
 *   - No Local Reuse (NLR) dataflow
 *   - Post-processing: bias, requantization, ReLU
 *
 * Dataflow:
 *   - Fetches 3x3 spatial window from F1
 *   - Performs convolution for one output element
 *   - Discards inputs (NLR)
 *   - Outputs single element of F2
 ******************************************************************************/

`include "cfu_dsc_defines.v"

module depthwise_unit (
    input  wire                         clk,
    input  wire                         rst_n,

    // Control signals
    input  wire                         start,
    input  wire                         clear_acc,
    input  wire                         last_channel,
    output reg                          output_ready,

    // F1 input (3x3 window for single channel)
    input  wire [`DATA_WIDTH-1:0]       f1_window_0, f1_window_1, f1_window_2,
    input  wire [`DATA_WIDTH-1:0]       f1_window_3, f1_window_4, f1_window_5,
    input  wire [`DATA_WIDTH-1:0]       f1_window_6, f1_window_7, f1_window_8,

    // Depthwise weights (3x3 filter)
    input  wire [`DATA_WIDTH-1:0]       dw_weight_0, dw_weight_1, dw_weight_2,
    input  wire [`DATA_WIDTH-1:0]       dw_weight_3, dw_weight_4, dw_weight_5,
    input  wire [`DATA_WIDTH-1:0]       dw_weight_6, dw_weight_7, dw_weight_8,

    // Post-processing parameters
    input  wire signed [`ACC_WIDTH-1:0] bias,
    input  wire signed [31:0]           scale,
    input  wire signed [31:0]           zero_point,
    input  wire [4:0]                   shift_amount,

    // Output (single element of F2)
    output wire [`DATA_WIDTH-1:0]       f2_out,
    output reg                          f2_valid
);

    //==========================================================================
    // Internal Signals
    //==========================================================================
    // Signed products (INT8 x INT8 = INT16)
    wire signed [15:0] product_0, product_1, product_2;
    wire signed [15:0] product_3, product_4, product_5;
    wire signed [15:0] product_6, product_7, product_8;

    // Accumulator for depthwise convolution
    reg signed [`ACC_WIDTH-1:0] accumulator;
    wire signed [`ACC_WIDTH-1:0] dw_result;

    // Result valid signal
    reg result_valid_reg;

    //==========================================================================
    // Multiplication Stage (9 parallel multipliers)
    //==========================================================================
    assign product_0 = $signed(f1_window_0) * $signed(dw_weight_0);
    assign product_1 = $signed(f1_window_1) * $signed(dw_weight_1);
    assign product_2 = $signed(f1_window_2) * $signed(dw_weight_2);
    assign product_3 = $signed(f1_window_3) * $signed(dw_weight_3);
    assign product_4 = $signed(f1_window_4) * $signed(dw_weight_4);
    assign product_5 = $signed(f1_window_5) * $signed(dw_weight_5);
    assign product_6 = $signed(f1_window_6) * $signed(dw_weight_6);
    assign product_7 = $signed(f1_window_7) * $signed(dw_weight_7);
    assign product_8 = $signed(f1_window_8) * $signed(dw_weight_8);

    //==========================================================================
    // Adder Tree (9 inputs)
    // Level 1: 4 adders + 1 pass-through
    // Level 2: 2 adders + 1 pass-through
    // Level 3: 2 adders
    // Level 4: 1 adder (final sum)
    //==========================================================================
    wire signed [16:0] dw_sum_l1_0, dw_sum_l1_1, dw_sum_l1_2, dw_sum_l1_3;
    wire signed [16:0] dw_sum_l1_4; // Pass-through

    assign dw_sum_l1_0 = product_0 + product_1;
    assign dw_sum_l1_1 = product_2 + product_3;
    assign dw_sum_l1_2 = product_4 + product_5;
    assign dw_sum_l1_3 = product_6 + product_7;
    assign dw_sum_l1_4 = product_8;

    wire signed [17:0] dw_sum_l2_0, dw_sum_l2_1, dw_sum_l2_2;

    assign dw_sum_l2_0 = dw_sum_l1_0 + dw_sum_l1_1;
    assign dw_sum_l2_1 = dw_sum_l1_2 + dw_sum_l1_3;
    assign dw_sum_l2_2 = dw_sum_l1_4;

    wire signed [18:0] dw_sum_l3_0, dw_sum_l3_1;

    assign dw_sum_l3_0 = dw_sum_l2_0 + dw_sum_l2_1;
    assign dw_sum_l3_1 = dw_sum_l2_2;

    wire signed [19:0] dw_sum_l4;

    assign dw_sum_l4 = dw_sum_l3_0 + dw_sum_l3_1;

    // Sign extend to 32-bit
    wire signed [`ACC_WIDTH-1:0] sum_products;
    assign sum_products = {{12{dw_sum_l4[19]}}, dw_sum_l4};

    //==========================================================================
    // Accumulator (accumulates across channel groups if needed)
    // For depthwise, typically single channel operation
    //==========================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            accumulator <= 32'd0;
        end else if (clear_acc) begin
            accumulator <= 32'd0;
        end else if (start) begin
            accumulator <= accumulator + sum_products;
        end
    end

    assign dw_result = accumulator + sum_products;

    //==========================================================================
    // Result Valid Logic
    //==========================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            result_valid_reg <= 1'b0;
        end else begin
            result_valid_reg <= start && last_channel;
        end
    end

    //==========================================================================
    // Post-Processing Pipeline
    //==========================================================================
    post_processing_unit pp_unit (
        .clk            (clk),
        .rst_n          (rst_n),
        .valid_in       (result_valid_reg),
        .valid_out      (f2_valid),
        .acc_in         (dw_result),
        .bias           (bias),
        .scale          (scale),
        .zero_point     (zero_point),
        .shift_amount   (shift_amount),
        .data_out       (f2_out)
    );

    //==========================================================================
    // Output Ready Signal
    //==========================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            output_ready <= 1'b0;
        end else begin
            output_ready <= f2_valid;
        end
    end

endmodule
