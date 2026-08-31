`timescale 1ns/1ps

module expansion_unit #(
    parameter integer CIN = 8,
    parameter integer DATA_W = 8,
    parameter integer ACC_W = 32
) (
    input  wire                         clk,
    input  wire                         rst,
    input  wire                         start,

    input  wire signed [CIN*DATA_W-1:0] ifmap,
    input  wire signed [CIN*DATA_W-1:0] weights,
    input  wire signed [ACC_W-1:0]      bias,

    output reg  signed [ACC_W-1:0]      result,
    output reg                          valid,
    output reg                          busy
);

    integer i;
    reg signed [DATA_W-1:0] x;
    reg signed [DATA_W-1:0] w;
    reg signed [ACC_W-1:0] acc;

    always @(posedge clk) begin
        if (rst) begin
            result <= 0;
            valid  <= 1'b0;
            busy   <= 1'b0;
        end else begin
            valid <= 1'b0;

            if (start && !busy) begin
                busy = 1'b1;
                acc = bias;

                for (i = 0; i < CIN; i = i + 1) begin
                    x = ifmap[i*DATA_W +: DATA_W];
                    w = weights[i*DATA_W +: DATA_W];
                    acc = acc + x * w;
                end

                result <= acc;
                valid  <= 1'b1;
                busy   <= 1'b0;
            end
        end
    end
endmodule
