`timescale 1ns/1ps
module depthwise_engine #(
    parameter integer K=3,
    parameter integer DATA_W=8,
    parameter integer ACC_W=32
)(
    input wire clk,
    input wire rst,
    input wire start,
    input wire signed [DATA_W-1:0] data_in,
    input wire signed [DATA_W-1:0] weight_in,
    output reg signed [ACC_W-1:0] result,
    output reg done,
    output reg [$clog2(9)-1:0] tap
);
    reg signed [ACC_W-1:0] acc;
    always @(posedge clk) begin
        if (rst) begin
            acc <= 0; result <= 0; done <= 0; tap <= 0;
        end else begin
            done <= 0;
            if (start) begin
                if (tap == 8) begin
                    result <= acc + data_in * weight_in;
                    acc <= 0;
                    tap <= 0;
                    done <= 1;
                end else begin
                    acc <= acc + data_in * weight_in;
                    tap <= tap + 1'b1;
                end
            end
        end
    end
endmodule
