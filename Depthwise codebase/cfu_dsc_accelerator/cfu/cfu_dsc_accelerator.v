/*******************************************************************************
 * CFU DSC Accelerator - Top Level Module
 *
 * Fused Depthwise Separable Convolution Accelerator for MobileNetV2.
 * Implements: Expansion (1x1) -> Depthwise (3x3) -> Projection (1x1)
 *
 * Features:
 *   - 5-stage intra-stage pipeline
 *   - Zero intermediate buffering
 *   - 9 parallel expansion engines
 *   - 56 parallel projection engines
 *   - On-the-fly padding
 *   - CFU-Playground compatible interface
 ******************************************************************************/

`include "cfu_dsc_defines.v"

module cfu_dsc_accelerator (
    input  wire                         clk,
    input  wire                         rst_n,

    // CFU Interface
    input  wire [2:0]                   funct3,
    input  wire [6:0]                   funct7,
    input  wire [31:0]                  rs1,
    input  wire [31:0]                  rs2,
    output wire [31:0]                  rd,
    input  wire                         cfu_start,
    output wire                         cfu_done
);

    //==========================================================================
    // Internal Signals
    //==========================================================================

    // Control signals from instruction controller
    wire [2:0]                  cfu_op;
    wire                        cfu_op_valid;
    wire [3:0]                  status;

    // Configuration registers
    reg  [15:0]                 cfg_height;
    reg  [15:0]                 cfg_width;
    reg  [15:0]                 cfg_in_channels;
    reg  [15:0]                 cfg_exp_channels;
    reg  [15:0]                 cfg_out_channels;

    // Pipeline control
    wire                        exp_start, exp_clear, exp_last_filter, exp_last_channel;
    wire                        dw_start, dw_clear, dw_last_channel;
    wire                        proj_start, proj_clear, proj_last_input;
    wire                        pipeline_enable;

    // Memory control
    wire                        ifmap_wr_en, exp_w_wr_en, dw_w_wr_en, proj_w_wr_en;

    // Data paths
    wire [`DATA_WIDTH-1:0]      ifmap_wr_data;
    wire [`DATA_WIDTH-1:0]      ifmap_0, ifmap_1, ifmap_2;
    wire [`DATA_WIDTH-1:0]      ifmap_3, ifmap_4, ifmap_5;
    wire [`DATA_WIDTH-1:0]      ifmap_6, ifmap_7, ifmap_8;
    wire                        ifmap_valid;

    wire [`DATA_WIDTH-1:0]      exp_w_0, exp_w_1, exp_w_2, exp_w_3;
    wire [`DATA_WIDTH-1:0]      exp_w_4, exp_w_5, exp_w_6, exp_w_7;
    wire                        exp_w_valid;

    wire [`DATA_WIDTH-1:0]      dw_w_0, dw_w_1, dw_w_2, dw_w_3, dw_w_4;
    wire [`DATA_WIDTH-1:0]      dw_w_5, dw_w_6, dw_w_7, dw_w_8;
    wire                        dw_w_valid;

    wire [`PROJ_ENGINES*`DATA_WIDTH-1:0] proj_weights;

    // Intermediate feature maps
    wire [`DATA_WIDTH-1:0]      f1_out_0, f1_out_1, f1_out_2;
    wire [`DATA_WIDTH-1:0]      f1_out_3, f1_out_4, f1_out_5;
    wire [`DATA_WIDTH-1:0]      f1_out_6, f1_out_7, f1_out_8;
    wire                        f1_valid;

    wire [`DATA_WIDTH-1:0]      f2_out;
    wire                        f2_valid;

    wire [`PROJ_ENGINES*`DATA_WIDTH-1:0] proj_out;
    wire                        proj_valid;

    // Read interface
    wire [5:0]                  read_addr;
    wire [`DATA_WIDTH-1:0]      read_data;
    wire                        read_data_valid;

    // Post-processing parameters (from configuration)
    wire signed [`ACC_WIDTH-1:0] exp_bias;
    wire signed [31:0]           exp_scale;
    wire signed [31:0]           exp_zero_point;
    wire [4:0]                   exp_shift;

    wire signed [`ACC_WIDTH-1:0] dw_bias;
    wire signed [31:0]          dw_scale;
    wire signed [31:0]          dw_zero_point;
    wire [4:0]                  dw_shift;

    wire [`PROJ_ENGINES*`ACC_WIDTH-1:0] proj_bias_array;
    wire signed [31:0]          proj_scale;
    wire signed [31:0]          proj_zero_point;
    wire [4:0]                  proj_shift;

    //==========================================================================
    // CFU Interface
    //==========================================================================
    cfu_dsc_interface u_cfu_interface (
        .clk                (clk),
        .rst_n              (rst_n),
        .funct3             (funct3),
        .funct7             (funct7),
        .rs1                (rs1),
        .rs2                (rs2),
        .rd                 (rd),
        .cfu_start          (cfu_start),
        .cfu_done           (cfu_done),
        .cfu_op             (cfu_op),
        .cfu_op_valid       (cfu_op_valid),
        .status             (status),
        .data_out           (ifmap_wr_data),
        .data_out_valid     (),
        .data_in            (32'd0),
        .data_in_valid      (1'b0),
        .cfg_height         (cfg_height),
        .cfg_width          (cfg_width),
        .cfg_in_channels    (cfg_in_channels),
        .cfg_exp_channels   (cfg_exp_channels),
        .cfg_out_channels   (cfg_out_channels),
        .read_addr          (read_addr),
        .read_data          (read_data),
        .read_data_valid    (read_data_valid)
    );

    //==========================================================================
    // Instruction Controller
    //==========================================================================
    instruction_controller u_ic (
        .clk                (clk),
        .rst_n              (rst_n),
        .cfu_op             (cfu_op),
        .cfu_start          (cfu_op_valid),
        .status             (status),
        .in_height          (cfg_height),
        .in_width           (cfg_width),
        .in_channels        (cfg_in_channels),
        .exp_channels       (cfg_exp_channels),
        .out_channels       (cfg_out_channels),
        .exp_start          (exp_start),
        .exp_clear          (exp_clear),
        .exp_last_filter    (exp_last_filter),
        .exp_last_channel   (exp_last_channel),
        .dw_start           (dw_start),
        .dw_clear           (dw_clear),
        .dw_last_channel    (dw_last_channel),
        .proj_start         (proj_start),
        .proj_clear         (proj_clear),
        .proj_last_input    (proj_last_input),
        .ifmap_wr_en        (ifmap_wr_en),
        .exp_w_wr_en        (exp_w_wr_en),
        .dw_w_wr_en         (dw_w_wr_en),
        .proj_w_wr_en       (proj_w_wr_en),
        .pipeline_enable    (pipeline_enable),
        .output_ready       (),
        .done               ()
    );

    //==========================================================================
    // Memory Subsystem
    //==========================================================================

    // IFMAP Buffer
    ifmap_buffer u_ifmap_buf (
        .clk                (clk),
        .rst_n              (rst_n),
        .height             (cfg_height[7:0]),
        .width              (cfg_width[7:0]),
        .zero_point         (1'b0),
        .wr_en              (ifmap_wr_en),
        .wr_addr            (),
        .wr_data            (ifmap_wr_data[7:0]),
        .rd_row             (),
        .rd_col             (),
        .rd_en              (pipeline_enable),
        .window_0           (ifmap_0),
        .window_1           (ifmap_1),
        .window_2           (ifmap_2),
        .window_3           (ifmap_3),
        .window_4           (ifmap_4),
        .window_5           (ifmap_5),
        .window_6           (ifmap_6),
        .window_7           (ifmap_7),
        .window_8           (ifmap_8),
        .window_valid       (ifmap_valid)
    );

    // Expansion Filter Buffer
    expansion_filter_buffer u_exp_fbuf (
        .clk                (clk),
        .rst_n              (rst_n),
        .num_filters        (cfg_exp_channels),
        .input_channels     (cfg_in_channels),
        .wr_en              (exp_w_wr_en),
        .wr_addr            (),
        .wr_data            (ifmap_wr_data[7:0]),
        .rd_en              (pipeline_enable),
        .filter_idx         (),
        .channel_chunk      (),
        .weight_0           (exp_w_0),
        .weight_1           (exp_w_1),
        .weight_2           (exp_w_2),
        .weight_3           (exp_w_3),
        .weight_4           (exp_w_4),
        .weight_5           (exp_w_5),
        .weight_6           (exp_w_6),
        .weight_7           (exp_w_7),
        .weight_valid       (exp_w_valid),
        .ready              ()
    );

    // Depthwise Filter Buffer
    depthwise_filter_buffer u_dw_fbuf (
        .clk                (clk),
        .rst_n              (rst_n),
        .num_filters        (cfg_exp_channels),
        .wr_en              (dw_w_wr_en),
        .wr_bank            (),
        .wr_addr            (),
        .wr_data            (ifmap_wr_data[7:0]),
        .rd_en              (pipeline_enable),
        .rd_addr            (),
        .weight_0           (dw_w_0),
        .weight_1           (dw_w_1),
        .weight_2           (dw_w_2),
        .weight_3           (dw_w_3),
        .weight_4           (dw_w_4),
        .weight_5           (dw_w_5),
        .weight_6           (dw_w_6),
        .weight_7           (dw_w_7),
        .weight_8           (dw_w_8),
        .weight_valid       (dw_w_valid),
        .ready              ()
    );

    //==========================================================================
    // Compute Pipeline
    //==========================================================================

    // Stage 1-2: Expansion Unit (MAC + Quantize)
    expansion_unit u_expansion (
        .clk                (clk),
        .rst_n              (rst_n),
        .start              (exp_start),
        .clear_acc          (exp_clear),
        .last_filter        (exp_last_filter),
        .last_channel       (exp_last_channel),
        .output_ready       (),
        .ifmap_0            (ifmap_0),
        .ifmap_1            (ifmap_1),
        .ifmap_2            (ifmap_2),
        .ifmap_3            (ifmap_3),
        .ifmap_4            (ifmap_4),
        .ifmap_5            (ifmap_5),
        .ifmap_6            (ifmap_6),
        .ifmap_7            (ifmap_7),
        .ifmap_8            (ifmap_8),
        .weight_0           (exp_w_0),
        .weight_1           (exp_w_1),
        .weight_2           (exp_w_2),
        .weight_3           (exp_w_3),
        .weight_4           (exp_w_4),
        .weight_5           (exp_w_5),
        .weight_6           (exp_w_6),
        .weight_7           (exp_w_7),
        .bias               (exp_bias),
        .scale              (exp_scale),
        .zero_point         (exp_zero_point),
        .shift_amount       (exp_shift),
        .f1_out_0           (f1_out_0),
        .f1_out_1           (f1_out_1),
        .f1_out_2           (f1_out_2),
        .f1_out_3           (f1_out_3),
        .f1_out_4           (f1_out_4),
        .f1_out_5           (f1_out_5),
        .f1_out_6           (f1_out_6),
        .f1_out_7           (f1_out_7),
        .f1_out_8           (f1_out_8),
        .f1_valid           (f1_valid)
    );

    // Stage 3-4: Depthwise Unit (MAC + Quantize)
    depthwise_unit u_depthwise (
        .clk                (clk),
        .rst_n              (rst_n),
        .start              (dw_start),
        .clear_acc          (dw_clear),
        .last_channel       (dw_last_channel),
        .output_ready       (),
        .f1_window_0        (f1_out_0),
        .f1_window_1        (f1_out_1),
        .f1_window_2        (f1_out_2),
        .f1_window_3        (f1_out_3),
        .f1_window_4        (f1_out_4),
        .f1_window_5        (f1_out_5),
        .f1_window_6        (f1_out_6),
        .f1_window_7        (f1_out_7),
        .f1_window_8        (f1_out_8),
        .dw_weight_0        (dw_w_0),
        .dw_weight_1        (dw_w_1),
        .dw_weight_2        (dw_w_2),
        .dw_weight_3        (dw_w_3),
        .dw_weight_4        (dw_w_4),
        .dw_weight_5        (dw_w_5),
        .dw_weight_6        (dw_w_6),
        .dw_weight_7        (dw_w_7),
        .dw_weight_8        (dw_w_8),
        .bias               (dw_bias),
        .scale              (dw_scale),
        .zero_point         (dw_zero_point),
        .shift_amount       (dw_shift),
        .f2_out             (f2_out),
        .f2_valid           (f2_valid)
    );

    // Stage 5: Projection Unit
    projection_unit u_projection (
        .clk                (clk),
        .rst_n              (rst_n),
        .start              (proj_start),
        .clear_acc          (proj_clear),
        .last_input         (proj_last_input),
        .num_output_ch      (cfg_out_channels[7:0]),
        .output_ready       (),
        .f2_in              (f2_out),
        .proj_weights       (proj_weights),
        .bias               (),
        .scale              (proj_scale),
        .zero_point         (proj_zero_point),
        .shift_amount       (proj_shift),
        .bias_array         (proj_bias_array),
        .proj_out           (proj_out),
        .proj_valid         (proj_valid),
        .read_addr          (read_addr),
        .read_data          (read_data),
        .read_valid         (read_data_valid)
    );

    //==========================================================================
    // Configuration Registers for Post-Processing
    // In a real implementation, these would be loaded via CFU instructions
    //==========================================================================
    assign exp_bias = 32'd0;
    assign exp_scale = 32'd1;
    assign exp_zero_point = 32'd0;
    assign exp_shift = 5'd0;

    assign dw_bias = 32'd0;
    assign dw_scale = 32'd1;
    assign dw_zero_point = 32'd0;
    assign dw_shift = 5'd0;

    assign proj_scale = 32'd1;
    assign proj_zero_point = 32'd0;
    assign proj_shift = 5'd0;
    assign proj_bias_array = {`PROJ_ENGINES{32'd0}};
    assign proj_weights = {`PROJ_ENGINES{f2_out}};

endmodule
