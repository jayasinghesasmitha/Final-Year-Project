`timescale 1ns/1ps

module mnv2_demo_top (
    input  wire       clk100,
    input  wire       rst,
    input  wire       start,

    output wire       done,
    output wire [9:0] class_index,
    output wire [7:0] led
);

    wire busy;

    /*
     * Synthesizable MobileNetV2 baseline accelerator.
     *
     * IMPORTANT:
     * This is deliberately NOT the old mnv2_71layer_ref module.
     * The old reference implementation contains enormous procedural
     * loops and is intended for functional simulation only.
     */
    mnv2_hw_baseline dut (
        .clk         (clk100),
        .rst         (rst),
        .start       (start),
        .busy        (busy),
        .done        (done),
        .class_index (class_index)
    );

    /*
     * LED assignment:
     *
     * LED[0] = done
     * LED[1] = busy
     * LED[2:7] = lower 6 bits of result
     */
    assign led[0] = done;
    assign led[1] = busy;
    assign led[7:2] = class_index[5:0];

endmodule