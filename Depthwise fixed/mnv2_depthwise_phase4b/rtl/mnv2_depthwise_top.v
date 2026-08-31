`timescale 1ns/1ps

module mnv2_depthwise_top #(
    parameter integer H=4,
    parameter integer W=4,
    parameter integer CIN=8,
    parameter integer CEXP=24,
    parameter integer COUT=16,
    parameter integer DATA_W=8,
    parameter integer ACC_W=32
)(
    input wire clk,
    input wire rst,
    input wire start,
    output wire busy,
    output wire done,

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
    output wire signed [ACC_W-1:0] out_rd_data
);

    localparam integer IFMAP_N=H*W*CIN;
    localparam integer EXP_N=H*W*CEXP;
    localparam integer DW_N=H*W*CEXP;
    localparam integer PROJ_N=COUT*CEXP;
    localparam integer OUT_N=H*W*COUT;

    wire [2:0] state;
    wire [7:0] row, col, exp_channel, dw_channel, proj_channel;
    wire [3:0] dw_tap;
    wire [7:0] input_channel;

    mnv2_controller #(
        .H(H), .W(W), .CIN(CIN), .CEXP(CEXP), .COUT(COUT)
    ) ctrl (
        .clk(clk), .rst(rst), .start(start),
        .busy(busy), .done(done),
        .state(state),
        .row(row), .col(col),
        .exp_channel(exp_channel),
        .dw_channel(dw_channel),
        .proj_channel(proj_channel),
        .dw_tap(dw_tap),
        .input_channel(input_channel)
    );

    // Explicit memory instances. These ports are all driven.
    wire signed [DATA_W-1:0] ifmap_rd_data;
    wire signed [DATA_W-1:0] exp_w_rd_data;
    wire signed [DATA_W-1:0] dw_w_rd_data;
    wire signed [DATA_W-1:0] proj_w_rd_data;

    wire signed [ACC_W-1:0] expanded_rd_data;
    wire signed [ACC_W-1:0] dw_rd_data;

    wire [6:0] ifmap_rd_addr =
        ((row * W + col) * CIN) + input_channel;

    wire [7:0] exp_w_rd_addr =
        (exp_channel * CIN) + input_channel;

    wire [7:0] dw_w_rd_addr =
        (dw_channel * 9) + dw_tap;

    wire [8:0] proj_w_rd_addr =
        (proj_channel * CEXP) + input_channel;

    wire [7:0] expanded_rd_addr =
        ((row * W + col) * CEXP) + exp_channel;

    wire [7:0] dw_rd_addr =
        ((row * W + col) * CEXP) + dw_channel;

    ifmap_buffer #(.DEPTH(IFMAP_N),.DATA_W(DATA_W)) u_ifmap (
        .clk(clk),
        .wr_en(ifmap_wr_en),
        .wr_addr(ifmap_wr_addr),
        .wr_data(ifmap_wr_data),
        .rd_addr(ifmap_rd_addr),
        .rd_data(ifmap_rd_data)
    );

    expansion_weight_buffer #(.DEPTH(CEXP*CIN),.DATA_W(DATA_W)) u_exp_w (
        .clk(clk),
        .wr_en(exp_wr_en),
        .wr_addr(exp_wr_addr),
        .wr_data(exp_wr_data),
        .rd_addr(exp_w_rd_addr),
        .rd_data(exp_w_rd_data)
    );

    depthwise_weight_buffer #(.DEPTH(CEXP*9),.DATA_W(DATA_W)) u_dw_w (
        .clk(clk),
        .wr_en(dw_wr_en),
        .wr_addr(dw_wr_addr),
        .wr_data(dw_wr_data),
        .rd_addr(dw_w_rd_addr),
        .rd_data(dw_w_rd_data)
    );

    projection_weight_buffer #(.DEPTH(COUT*CEXP),.DATA_W(DATA_W)) u_proj_w (
        .clk(clk),
        .wr_en(proj_wr_en),
        .wr_addr(proj_wr_addr),
        .wr_data(proj_wr_data),
        .rd_addr(proj_w_rd_addr),
        .rd_data(proj_w_rd_data)
    );

    expanded_buffer #(.DEPTH(EXP_N),.DATA_W(ACC_W)) u_expanded (
        .clk(clk),
        .wr_en(1'b0),
        .wr_addr(0),
        .wr_data(0),
        .rd_addr(expanded_rd_addr),
        .rd_data(expanded_rd_data)
    );

    depthwise_output_buffer #(.DEPTH(DW_N),.DATA_W(ACC_W)) u_dw_out (
        .clk(clk),
        .wr_en(1'b0),
        .wr_addr(0),
        .wr_data(0),
        .rd_addr(dw_rd_addr),
        .rd_data(dw_rd_data)
    );

    output_buffer #(.DEPTH(OUT_N),.DATA_W(ACC_W)) u_output (
        .clk(clk),
        .wr_en(1'b0),
        .wr_addr(0),
        .wr_data(0),
        .rd_addr(out_rd_addr),
        .rd_data(out_rd_data)
    );

endmodule
