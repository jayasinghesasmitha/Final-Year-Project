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
    output reg [7:0] dw_channel,
    output reg [7:0] proj_channel,
    output reg [3:0] dw_tap,
    output reg [7:0] input_channel
);

    localparam S_IDLE=0;
    localparam S_EXP=1;
    localparam S_DW=2;
    localparam S_PROJ=3;
    localparam S_DONE=4;

    reg [2:0] next_state;

    always @(*) begin
        next_state = state;

        case (state)
            S_IDLE:
                if (start) next_state = S_EXP;

            S_EXP:
                if ((exp_channel == CEXP-1) && (input_channel == CIN-1))
                    next_state = S_DW;

            S_DW:
                if ((dw_channel == CEXP-1) && (dw_tap == 8))
                    next_state = S_PROJ;

            S_PROJ:
                if ((proj_channel == COUT-1) && (input_channel == CEXP-1)) begin
                    if ((row == H-1) && (col == W-1))
                        next_state = S_DONE;
                    else
                        next_state = S_EXP;
                end

            S_DONE:
                next_state = S_IDLE;

            default:
                next_state = S_IDLE;
        endcase
    end

    always @(posedge clk) begin
        if (rst) begin
            state <= S_IDLE;
            busy <= 0;
            done <= 0;
            row <= 0;
            col <= 0;
            exp_channel <= 0;
            dw_channel <= 0;
            proj_channel <= 0;
            dw_tap <= 0;
            input_channel <= 0;
        end else begin
            state <= next_state;
            done <= 0;

            case (state)
                S_IDLE: begin
                    busy <= 0;
                    if (start) begin
                        busy <= 1;
                        row <= 0;
                        col <= 0;
                        exp_channel <= 0;
                        dw_channel <= 0;
                        proj_channel <= 0;
                        dw_tap <= 0;
                        input_channel <= 0;
                    end
                end

                S_EXP: begin
                    busy <= 1;

                    if (input_channel == CIN-1) begin
                        input_channel <= 0;
                        if (exp_channel == CEXP-1) begin
                            exp_channel <= 0;
                            dw_channel <= 0;
                            dw_tap <= 0;
                        end else begin
                            exp_channel <= exp_channel + 1'b1;
                        end
                    end else begin
                        input_channel <= input_channel + 1'b1;
                    end
                end

                S_DW: begin
                    busy <= 1;

                    if (dw_tap == 8) begin
                        dw_tap <= 0;
                        if (dw_channel == CEXP-1) begin
                            dw_channel <= 0;
                            proj_channel <= 0;
                            input_channel <= 0;
                        end else begin
                            dw_channel <= dw_channel + 1'b1;
                        end
                    end else begin
                        dw_tap <= dw_tap + 1'b1;
                    end
                end

                S_PROJ: begin
                    busy <= 1;

                    if (input_channel == CEXP-1) begin
                        input_channel <= 0;

                        if (proj_channel == COUT-1) begin
                            proj_channel <= 0;

                            if (col == W-1) begin
                                col <= 0;
                                if (row == H-1) begin
                                    row <= 0;
                                    busy <= 0;
                                    done <= 1;
                                end else begin
                                    row <= row + 1'b1;
                                end
                            end else begin
                                col <= col + 1'b1;
                            end
                        end else begin
                            proj_channel <= proj_channel + 1'b1;
                        end
                    end else begin
                        input_channel <= input_channel + 1'b1;
                    end
                end

                S_DONE: begin
                    busy <= 0;
                end
            endcase
        end
    end
endmodule
