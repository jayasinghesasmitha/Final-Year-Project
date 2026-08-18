/*******************************************************************************
 * Expansion Engine Module
 *
 * Single expansion engine implementing 8-way multiply-accumulate (MAC) tree.
 * Part of the Expansion Unit with Input-Stationary dataflow.
 *
 * Architecture:
 *   - 8 parallel multipliers (INT8 x INT8 = INT16)
 *   - Adder tree to sum 8 products
 *   - 32-bit accumulator for partial sums
 *   - Processes 8 input channels per cycle
 ******************************************************************************/

`include "cfu_dsc_defines.v"

module expansion_engine (
    input  wire                         clk,
    input  wire                         rst_n,

    // Control signals
    input  wire                         start,
    input  wire                         clear_acc,      // Clear accumulator
    input  wire                         last_channel,   // Last channel in filter

    // Data inputs (8 channels)
    input  wire [`DATA_WIDTH-1:0]       ifmap_data_0,
    input  wire [`DATA_WIDTH-1:0]       ifmap_data_1,
    input  wire [`DATA_WIDTH-1:0]       ifmap_data_2,
    input  wire [`DATA_WIDTH-1:0]       ifmap_data_3,
    input  wire [`DATA_WIDTH-1:0]       ifmap_data_4,
    input  wire [`DATA_WIDTH-1:0]       ifmap_data_5,
    input  wire [`DATA_WIDTH-1:0]       ifmap_data_6,
    input  wire [`DATA_WIDTH-1:0]       ifmap_data_7,

    // Weight inputs (8 channels, broadcast to all 9 engines)
    input  wire [`DATA_WIDTH-1:0]       weight_0,
    input  wire [`DATA_WIDTH-1:0]       weight_1,
    input  wire [`DATA_WIDTH-1:0]       weight_2,
    input  wire [`DATA_WIDTH-1:0]       weight_3,
    input  wire [`DATA_WIDTH-1:0]       weight_4,
    input  wire [`DATA_WIDTH-1:0]       weight_5,
    input  wire [`DATA_WIDTH-1:0]       weight_6,
    input  wire [`DATA_WIDTH-1:0]       weight_7,

    // Output
    output reg  [`ACC_WIDTH-1:0]        acc_result,
    output reg                          result_valid
);

    //==========================================================================
    // Internal Signals
    //==========================================================================
    // Sign-extended products (16-bit for INT8 x INT8)
    wire signed [15:0] product_0;
    wire signed [15:0] product_1;
    wire signed [15:0] product_2;
    wire signed [15:0] product_3;
    wire signed [15:0] product_4;
    wire signed [15:0] product_5;
    wire signed [15:0] product_6;
    wire signed [15:0] product_7;

    // Sum of products (adder tree)
    wire signed [31:0] sum_products;

    // Registered accumulator
    reg signed [`ACC_WIDTH-1:0] accumulator;

    //==========================================================================
    // Multiplication Stage
    //==========================================================================
    assign product_0 = $signed(ifmap_data_0) * $signed(weight_0);
    assign product_1 = $signed(ifmap_data_1) * $signed(weight_1);
    assign product_2 = $signed(ifmap_data_2) * $signed(weight_2);
    assign product_3 = $signed(ifmap_data_3) * $signed(weight_3);
    assign product_4 = $signed(ifmap_data_4) * $signed(weight_4);
    assign product_5 = $signed(ifmap_data_5) * $signed(weight_5);
    assign product_6 = $signed(ifmap_data_6) * $signed(weight_6);
    assign product_7 = $signed(ifmap_data_7) * $signed(weight_7);

    //==========================================================================
    // Adder Tree (balanced tree structure)
    // Level 1: 4 adders (pairs of products)
    // Level 2: 2 adders
    // Level 3: 1 adder (final sum)
    //==========================================================================
    wire signed [16:0] sum_l1_0, sum_l1_1, sum_l1_2, sum_l1_3;
    wire signed [17:0] sum_l2_0, sum_l2_1;
    wire signed [18:0] sum_l3;

    assign sum_l1_0 = product_0 + product_1;
    assign sum_l1_1 = product_2 + product_3;
    assign sum_l1_2 = product_4 + product_5;
    assign sum_l1_3 = product_6 + product_7;

    assign sum_l2_0 = sum_l1_0 + sum_l1_1;
    assign sum_l2_1 = sum_l1_2 + sum_l1_3;

    assign sum_l3 = sum_l2_0 + sum_l2_1;

    // Sign extend to 32-bit
    assign sum_products = {{13{sum_l3[18]}}, sum_l3};

    //==========================================================================
    // Accumulator
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

    //==========================================================================
    // Output Logic
    //==========================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            acc_result   <= 32'd0;
            result_valid <= 1'b0;
        end else begin
            result_valid <= start && last_channel;
            if (start && last_channel) begin
                acc_result <= accumulator + sum_products;
            end
        end
    end

endmodule
