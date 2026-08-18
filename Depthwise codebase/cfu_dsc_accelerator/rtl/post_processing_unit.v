/*******************************************************************************
 * Post-Processing Unit
 *
 * Performs bias addition, requantization/dequantization, and ReLU activation.
 * Used after Expansion, Depthwise, and Projection stages.
 *
 * Operations:
 *   1. Bias addition: acc + bias (32-bit)
 *   2. Requantization: (value * scale + offset) >> shift
 *   3. ReLU: max(0, quantized_value)
 *   4. Clamp to INT8 range [-128, 127]
 ******************************************************************************/

`include "cfu_dsc_defines.v"

module post_processing_unit (
    input  wire                         clk,
    input  wire                         rst_n,

    // Control
    input  wire                         valid_in,
    output reg                          valid_out,

    // Data input (32-bit accumulator)
    input  wire signed [`ACC_WIDTH-1:0] acc_in,

    // Quantization parameters
    input  wire signed [`ACC_WIDTH-1:0] bias,           // Bias value
    input  wire signed [31:0]           scale,          // Quantization scale
    input  wire signed [31:0]           zero_point,     // Quantization zero point
    input  wire [4:0]                   shift_amount,   // Right shift amount

    // Output (INT8)
    output reg  signed [`DATA_WIDTH-1:0] data_out
);

    //==========================================================================
    // Pipeline Stage 1: Bias Addition
    //==========================================================================
    reg signed [`ACC_WIDTH-1:0] biased_value;
    reg                         valid_stage1;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            biased_value  <= 32'd0;
            valid_stage1  <= 1'b0;
        end else begin
            valid_stage1 <= valid_in;
            if (valid_in) begin
                biased_value <= acc_in + bias;
            end
        end
    end

    //==========================================================================
    // Pipeline Stage 2: Multiply by Scale
    // Using a 64-bit intermediate to avoid overflow
    //==========================================================================
    reg signed [63:0] scaled_value;
    reg               valid_stage2;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            scaled_value <= 64'd0;
            valid_stage2 <= 1'b0;
        end else begin
            valid_stage2 <= valid_stage1;
            if (valid_stage1) begin
                // Multiply biased value by scale
                scaled_value <= biased_value * scale;
            end
        end
    end

    //==========================================================================
    // Pipeline Stage 3: Add Zero Point and Shift
    //==========================================================================
    reg signed [`ACC_WIDTH-1:0] shifted_value;
    reg                        valid_stage3;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            shifted_value <= 32'd0;
            valid_stage3  <= 1'b0;
        end else begin
            valid_stage3 <= valid_stage2;
            if (valid_stage2) begin
                // Add zero point and apply shift
                shifted_value <= (scaled_value >>> shift_amount) + zero_point;
            end
        end
    end

    //==========================================================================
    // Pipeline Stage 4: ReLU and Clamp to INT8
    //==========================================================================
    wire signed [`DATA_WIDTH-1:0] clamped_value;
    wire signed [`ACC_WIDTH-1:0] relu_value;

    // ReLU: max(0, value)
    assign relu_value = (shifted_value > 0) ? shifted_value : 32'd0;

    // Clamp to INT8 range [-128, 127]
    assign clamped_value = (relu_value > 127) ? 8'sd127 :
                           (relu_value < -128) ? -8'sd128 :
                           relu_value[`DATA_WIDTH-1:0];

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            data_out  <= 8'd0;
            valid_out <= 1'b0;
        end else begin
            valid_out <= valid_stage3;
            if (valid_stage3) begin
                data_out <= clamped_value;
            end
        end
    end

endmodule
