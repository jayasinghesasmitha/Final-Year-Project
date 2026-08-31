`timescale 1ns/1ps
module ifmap_buffer #(
    parameter integer DEPTH = 128,
    parameter integer DATA_W = 8
)(
    input wire clk,
    input wire wr_en,
    input wire [$clog2(DEPTH)-1:0] wr_addr,
    input wire signed [DATA_W-1:0] wr_data,
    input wire [$clog2(DEPTH)-1:0] rd_addr,
    output reg signed [DATA_W-1:0] rd_data
);
    reg signed [DATA_W-1:0] mem [0:DEPTH-1];
    always @(posedge clk) begin
        if (wr_en) mem[wr_addr] <= wr_data;
        rd_data <= mem[rd_addr];
    end
endmodule
