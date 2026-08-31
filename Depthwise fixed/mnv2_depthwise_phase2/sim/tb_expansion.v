`timescale 1ns/1ps

module tb_expansion;
    localparam CIN = 8;
    localparam DW = 8;
    localparam AW = 32;

    reg clk = 0;
    always #5 clk = ~clk;

    reg rst = 1;
    reg start = 0;
    reg signed [CIN*DW-1:0] ifmap;
    reg signed [CIN*DW-1:0] weights;
    reg signed [AW-1:0] bias;
    wire signed [AW-1:0] result;
    wire valid, busy;

    expansion_unit #(.CIN(CIN), .DATA_W(DW), .ACC_W(AW)) dut (
        .clk(clk), .rst(rst), .start(start),
        .ifmap(ifmap), .weights(weights), .bias(bias),
        .result(result), .valid(valid), .busy(busy)
    );

    integer i;
    integer expected;
    reg signed [7:0] x[0:CIN-1];
    reg signed [7:0] w[0:CIN-1];

    initial begin
        for (i=0; i<CIN; i=i+1) begin
            x[i] = i + 1;
            w[i] = 2;
            ifmap[i*DW +: DW] = x[i];
            weights[i*DW +: DW] = w[i];
        end

        bias = 5;
        expected = 5;
        for (i=0; i<CIN; i=i+1)
            expected = expected + x[i] * w[i];

        #20 rst = 0;
        #10 start = 1;
        #10 start = 0;

        wait(valid);
        if (result !== expected) begin
            $display("EXPANSION FAIL: expected=%0d actual=%0d", expected, result);
            $fatal;
        end

        $display("EXPANSION PASS: %0d", result);
        #20 $finish;
    end
endmodule
