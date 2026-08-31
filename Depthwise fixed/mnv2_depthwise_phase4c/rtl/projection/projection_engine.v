`timescale 1ns/1ps
module projection_engine #(
    parameter integer CEXP=24,
    parameter integer DATA_W=8,
    parameter integer ACC_W=32
)(
    input wire clk,
    input wire rst,
    input wire start,
    input wire signed [ACC_W-1:0] data_in,
    input wire signed [DATA_W-1:0] weight_in,
    output reg signed [ACC_W-1:0] result,
    output reg done,
    output reg [$clog2(CEXP)-1:0] channel
);
    reg signed [ACC_W-1:0] acc;
    always @(posedge clk) begin
        if (rst) begin
            acc <= 0; result <= 0; done <= 0; channel <= 0;
        end else begin
            done <= 0;
            if (start) begin
                if (channel == CEXP-1) begin
                    result <= acc + data_in * weight_in;
                    acc <= 0;
                    channel <= 0;
                    done <= 1;
                end else begin
                    acc <= acc + data_in * weight_in;
                    channel <= channel + 1'b1;
                end
            end
        end
    end
endmodule
