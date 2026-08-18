/*******************************************************************************
 * Projection Unit
 *
 * Final stage of the fused DSC pipeline. Performs 1x1 pointwise convolution
 * that reduces (projects) expanded channels back to output depth.
 *
 * Architecture:
 *   - 56 parallel Projection Engines
 *   - Output-Stationary (OS) dataflow
 *   - Distributed LUTRAM weight buffers (one per engine)
 *   - Post-processing: bias, requantization
 *
 * Dataflow:
 *   - Single F2 element broadcast to all 56 engines
 *   - Each engine has private weight buffer
 *   - Partial sums remain stationary in engine accumulators
 *   - Final outputs written to CPU via read instructions
 ******************************************************************************/

`include "cfu_dsc_defines.v"

module projection_unit (
    input  wire                         clk,
    input  wire                         rst_n,

    // Control signals
    input  wire                         start,
    input  wire                         clear_acc,
    input  wire                         last_input,
    input  wire [`DATA_WIDTH-1:0]       num_output_ch,  // Number of active output channels (up to 56)
    output reg                          output_ready,

    // F2 input (broadcast single element from Depthwise)
    input  wire [`DATA_WIDTH-1:0]       f2_in,

    // Weights for all 56 engines (loaded sequentially)
    input  wire [`PROJ_ENGINES*`DATA_WIDTH-1:0] proj_weights,  // 56 x 8-bit

    // Post-processing parameters (broadcast to all engines)
    input  wire signed [`ACC_WIDTH-1:0] bias,           // Base bias value
    input  wire signed [31:0]           scale,
    input  wire signed [31:0]           zero_point,
    input  wire [4:0]                   shift_amount,

    // Bias array for all 56 engines
    input  wire [`PROJ_ENGINES*`ACC_WIDTH-1:0] bias_array,

    // Outputs (56 channels)
    output wire [`PROJ_ENGINES*`DATA_WIDTH-1:0] proj_out,
    output reg                                  proj_valid,

    // CPU read interface
    input  wire [5:0]                   read_addr,      // Which output channel to read
    output reg  [`DATA_WIDTH-1:0]       read_data,
    output reg                          read_valid
);

    //==========================================================================
    // Local Parameters
    //==========================================================================
    localparam ENGINES = `PROJ_ENGINES;  // 56

    //==========================================================================
    // 56 Parallel Projection Engines
    //==========================================================================
    wire [`ACC_WIDTH-1:0] proj_acc_result  [0:ENGINES-1];
    wire                  proj_result_valid[0:ENGINES-1];

    genvar i;
    generate
        for (i = 0; i < ENGINES; i = i + 1) begin : proj_engines
            projection_engine engine (
                .clk            (clk),
                .rst_n          (rst_n),
                .start          (start && (i < num_output_ch)),
                .clear_acc      (clear_acc),
                .last_input     (last_input),
                .data_in        (f2_in),
                .weight_in      (proj_weights[(i+1)*`DATA_WIDTH-1:i*`DATA_WIDTH]),
                .acc_result     (proj_acc_result[i]),
                .result_valid   (proj_result_valid[i])
            );
        end
    endgenerate

    //==========================================================================
    // Post-Processing for Each Engine
    //==========================================================================
    wire [`DATA_WIDTH-1:0] pp_out  [0:ENGINES-1];
    wire                   pp_valid[0:ENGINES-1];

    generate
        for (i = 0; i < ENGINES; i = i + 1) begin : post_process
            // Extract bias for this engine
            wire signed [`ACC_WIDTH-1:0] engine_bias;
            assign engine_bias = bias_array[(i+1)*`ACC_WIDTH-1:i*`ACC_WIDTH];

            post_processing_unit pp_unit (
                .clk            (clk),
                .rst_n          (rst_n),
                .valid_in       (proj_result_valid[i]),
                .valid_out      (pp_valid[i]),
                .acc_in         (proj_acc_result[i]),
                .bias           (engine_bias),
                .scale          (scale),
                .zero_point     (zero_point),
                .shift_amount   (shift_amount),
                .data_out       (pp_out[i])
            );
        end
    endgenerate

    //==========================================================================
    // Output Packing (56 x 8-bit)
    //==========================================================================
    generate
        for (i = 0; i < ENGINES; i = i + 1) begin : pack_outputs
            assign proj_out[(i+1)*`DATA_WIDTH-1:i*`DATA_WIDTH] = pp_out[i];
        end
    endgenerate

    //==========================================================================
    // Output Ready and Valid Signals
    //==========================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            proj_valid   <= 1'b0;
            output_ready <= 1'b0;
        end else begin
            proj_valid   <= pp_valid[0] && last_input;
            output_ready <= pp_valid[0] && last_input;
        end
    end

    //==========================================================================
    // CPU Read Interface
    // Output channel readback (for subsequent software processing)
    //==========================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            read_data  <= 8'd0;
            read_valid <= 1'b0;
        end else begin
            read_valid <= 1'b1;
            if (read_addr < ENGINES) begin
                read_data <= pp_out[read_addr];
            end else begin
                read_data <= 8'd0;
            end
        end
    end

endmodule
