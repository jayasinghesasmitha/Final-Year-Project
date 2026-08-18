/*******************************************************************************
 * Projection Engine Module
 *
 * Single projection engine for the final 1x1 pointwise convolution stage.
 * Part of the Projection Unit with Output-Stationary dataflow.
 *
 * Architecture:
 *   - Multiplier-accumulator for 1x1 convolution
 *   - Local weight buffer (LUTRAM-based)
 *   - Accumulates partial sums for one output channel
 *   - Broadcast input from Depthwise unit, private weights
 ******************************************************************************/

`include "cfu_dsc_defines.v"

module projection_engine (
    input  wire                         clk,
    input  wire                         rst_n,

    // Control signals
    input  wire                         start,
    input  wire                         clear_acc,
    input  wire                         last_input,

    // Data input (broadcast from Depthwise unit, single value)
    input  wire signed [`DATA_WIDTH-1:0] data_in,

    // Weight input (private to this engine)
    input  wire signed [`DATA_WIDTH-1:0] weight_in,

    // Output (accumulated result)
    output reg  signed [`ACC_WIDTH-1:0] acc_result,
    output reg                          result_valid
);

    //==========================================================================
    // Internal Signals
    //==========================================================================
    wire signed [15:0] product;
    wire signed [`ACC_WIDTH-1:0] product_ext;
    reg  signed [`ACC_WIDTH-1:0] accumulator;

    //==========================================================================
    // Multiplication
    //==========================================================================
    assign product = data_in * weight_in;
    assign product_ext = {{16{product[15]}}, product};

    //==========================================================================
    // Accumulator
    //==========================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            accumulator <= 32'd0;
        end else if (clear_acc) begin
            accumulator <= 32'd0;
        end else if (start) begin
            accumulator <= accumulator + product_ext;
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
            result_valid <= start && last_input;
            if (start && last_input) begin
                acc_result <= accumulator + product_ext;
            end
        end
    end

endmodule
