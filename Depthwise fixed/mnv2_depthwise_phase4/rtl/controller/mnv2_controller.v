`timescale 1ns/1ps
module mnv2_controller #(
    parameter integer H=4,
    parameter integer W=4,
    parameter integer CIN=8,
    parameter integer CEXP=24,
    parameter integer COUT=16
)(
    input wire clk,
    input wire rst,
    input wire start,

    output reg busy,
    output reg done,

    output reg [2:0] state,
    output reg [7:0] row,
    output reg [7:0] col,
    output reg [7:0] exp_channel,
    output reg [7:0] out_channel,
    output reg [3:0] dw_tap
);
    localparam IDLE=0, EXP=1, DW=2, PROJ=3, DONE=4;
    reg [2:0] next_state;

    always @(*) begin
        next_state = state;
        case (state)
            IDLE: if (start) next_state = EXP;
            EXP: if (exp_channel == CEXP-1) next_state = DW;
            DW: if (dw_tap == 8) next_state = PROJ;
            PROJ: if (out_channel == COUT-1) begin
                if ((col == W-1) && (row == H-1)) next_state = DONE;
                else next_state = EXP;
            end
            DONE: next_state = IDLE;
            default: next_state = IDLE;
        endcase
    end

    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE; busy <= 0; done <= 0;
            row <= 0; col <= 0; exp_channel <= 0;
            out_channel <= 0; dw_tap <= 0;
        end else begin
            state <= next_state;
            done <= 0;

            case (state)
                IDLE: begin
                    busy <= 0;
                    if (start) begin
                        busy <= 1;
                        row <= 0;
                        col <= 0;
                        exp_channel <= 0;
                        out_channel <= 0;
                        dw_tap <= 0;
                    end
                end

                EXP: begin
                    busy <= 1;
                    if (exp_channel == CEXP-1) begin
                        exp_channel <= 0;
                        dw_tap <= 0;
                    end else exp_channel <= exp_channel + 1'b1;
                end

                DW: begin
                    busy <= 1;
                    if (dw_tap == 8) begin
                        dw_tap <= 0;
                        out_channel <= 0;
                    end else dw_tap <= dw_tap + 1'b1;
                end

                PROJ: begin
                    busy <= 1;
                    if (out_channel == COUT-1) begin
                        out_channel <= 0;
                        if (col == W-1) begin
                            col <= 0;
                            if (row == H-1) begin
                                row <= 0;
                                busy <= 0;
                                done <= 1;
                            end else row <= row + 1'b1;
                        end else col <= col + 1'b1;
                    end else out_channel <= out_channel + 1'b1;
                end

                DONE: begin
                    busy <= 0;
                end
            endcase
        end
    end
endmodule
