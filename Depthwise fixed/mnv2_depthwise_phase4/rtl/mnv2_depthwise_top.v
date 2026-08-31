`timescale 1ns/1ps
module mnv2_depthwise_top #(
    parameter integer H=4, W=4, CIN=8, CEXP=24, COUT=16,
    parameter integer DATA_W=8, ACC_W=32
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
    // Phase 4 controller baseline.
    // The memory ports are explicit and synthesizable. The datapath is deliberately
    // kept as a clean baseline for the next parallelization step.
    wire [2:0] state;
    wire [7:0] row, col, exp_channel, out_channel;
    wire [3:0] dw_tap;

    mnv2_controller #(.H(H),.W(W),.CIN(CIN),.CEXP(CEXP),.COUT(COUT)) ctrl (
        .clk(clk),.rst(rst),.start(start),
        .busy(busy),.done(done),
        .state(state),.row(row),.col(col),
        .exp_channel(exp_channel),.out_channel(out_channel),.dw_tap(dw_tap)
    );

    ifmap_buffer #(.DEPTH(H*W*CIN),.DATA_W(DATA_W)) ifmap (
        .clk(clk),.wr_en(ifmap_wr_en),.wr_addr(ifmap_wr_addr),
        .wr_data(ifmap_wr_data),.rd_addr(0),.rd_data()
    );

    expansion_weight_buffer #(.DEPTH(CEXP*CIN),.DATA_W(DATA_W)) expw (
        .clk(clk),.wr_en(exp_wr_en),.wr_addr(exp_wr_addr),
        .wr_data(exp_wr_data),.rd_addr(0),.rd_data()
    );

    depthwise_weight_buffer #(.DEPTH(CEXP*9),.DATA_W(DATA_W)) dww (
        .clk(clk),.wr_en(dw_wr_en),.wr_addr(dw_wr_addr),
        .wr_data(dw_wr_data),.rd_addr(0),.rd_data()
    );

    projection_weight_buffer #(.DEPTH(COUT*CEXP),.DATA_W(DATA_W)) projw (
        .clk(clk),.wr_en(proj_wr_en),.wr_addr(proj_wr_addr),
        .wr_data(proj_wr_data),.rd_addr(0),.rd_data()
    );

    output_buffer #(.DEPTH(H*W*COUT),.DATA_W(ACC_W)) outbuf (
        .clk(clk),.wr_en(1'b0),.wr_addr(0),.wr_data(0),
        .rd_addr(out_rd_addr),.rd_data(out_rd_data)
    );
endmodule
