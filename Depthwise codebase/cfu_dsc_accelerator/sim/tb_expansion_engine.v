/*******************************************************************************
 * Expansion Engine Unit Testbench
 ******************************************************************************/

`timescale 1ns/1ps

`include "cfu_dsc_defines.v"

module tb_expansion_engine;

    parameter CLK_PERIOD = 10;

    reg                         clk;
    reg                         rst_n;
    reg                         start;
    reg                         clear_acc;
    reg                         last_channel;

    reg  [`DATA_WIDTH-1:0]      ifmap_data_0, ifmap_data_1, ifmap_data_2, ifmap_data_3;
    reg  [`DATA_WIDTH-1:0]      ifmap_data_4, ifmap_data_5, ifmap_data_6, ifmap_data_7;

    reg  [`DATA_WIDTH-1:0]      weight_0, weight_1, weight_2, weight_3;
    reg  [`DATA_WIDTH-1:0]      weight_4, weight_5, weight_6, weight_7;

    wire [`ACC_WIDTH-1:0]       acc_result;
    wire                        result_valid;

    // DUT
    expansion_engine dut (
        .clk            (clk),
        .rst_n          (rst_n),
        .start          (start),
        .clear_acc      (clear_acc),
        .last_channel   (last_channel),
        .ifmap_data_0   (ifmap_data_0),
        .ifmap_data_1   (ifmap_data_1),
        .ifmap_data_2   (ifmap_data_2),
        .ifmap_data_3   (ifmap_data_3),
        .ifmap_data_4   (ifmap_data_4),
        .ifmap_data_5   (ifmap_data_5),
        .ifmap_data_6   (ifmap_data_6),
        .ifmap_data_7   (ifmap_data_7),
        .weight_0       (weight_0),
        .weight_1       (weight_1),
        .weight_2       (weight_2),
        .weight_3       (weight_3),
        .weight_4       (weight_4),
        .weight_5       (weight_5),
        .weight_6       (weight_6),
        .weight_7       (weight_7),
        .acc_result     (acc_result),
        .result_valid   (result_valid)
    );

    // Clock
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    // Test
    initial begin
        $display("Testing Expansion Engine...");

        rst_n = 0;
        start = 0;
        clear_acc = 0;
        last_channel = 0;
        #(CLK_PERIOD * 5);
        rst_n = 1;
        #(CLK_PERIOD * 2);

        // Test case: 8 channels, all 1s * all 1s = 8
        ifmap_data_0 = 8'd1;
        ifmap_data_1 = 8'd1;
        ifmap_data_2 = 8'd1;
        ifmap_data_3 = 8'd1;
        ifmap_data_4 = 8'd1;
        ifmap_data_5 = 8'd1;
        ifmap_data_6 = 8'd1;
        ifmap_data_7 = 8'd1;

        weight_0 = 8'd1;
        weight_1 = 8'd1;
        weight_2 = 8'd1;
        weight_3 = 8'd1;
        weight_4 = 8'd1;
        weight_5 = 8'd1;
        weight_6 = 8'd1;
        weight_7 = 8'd1;

        clear_acc = 1;
        @(posedge clk);
        clear_acc = 0;

        start = 1;
        last_channel = 1;
        @(posedge clk);
        start = 0;
        last_channel = 0;

        wait(result_valid);
        $display("Result: %0d (expected: 8)", acc_result);

        #(CLK_PERIOD * 10);
        $display("Expansion Engine test complete!");
        $finish;
    end

    initial begin
        $dumpfile("expansion_engine.vcd");
        $dumpvars(0, tb_expansion_engine);
    end

endmodule
