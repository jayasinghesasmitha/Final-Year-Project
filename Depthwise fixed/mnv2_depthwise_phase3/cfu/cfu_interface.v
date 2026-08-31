`timescale 1ns/1ps

module cfu_interface (
    input wire clk,
    input wire rst,

    input wire        cfu_valid,
    input wire [3:0]  cfu_cmd,
    input wire [31:0] cfu_data,

    output wire        cfu_resp_valid,
    output wire [31:0] cfu_data_out,
    output wire        cfu_busy,
    output wire        cfu_done
);

    mnv2_depthwise_cfu u_cfu (
        .clk(clk),
        .rst(rst),
        .cmd_valid(cfu_valid),
        .cmd(cfu_cmd),
        .data_in(cfu_data),
        .resp_valid(cfu_resp_valid),
        .data_out(cfu_data_out),
        .busy(cfu_busy),
        .done(cfu_done)
    );
endmodule
