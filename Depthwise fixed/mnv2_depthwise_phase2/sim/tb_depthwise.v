`timescale 1ns/1ps

module tb_depthwise;
    localparam N = 9;
    localparam DW = 8;
    localparam AW = 32;

    reg clk = 0;
    always #5 clk = ~clk;

    reg rst = 1;
    reg start = 0;
    reg signed [N*DW-1:0] window;
    reg signed [N*DW-1:0] weights;
    reg signed [AW-1:0] bias;
    wire signed [AW-1:0] result;
    wire valid, busy;

    depthwise_unit #(.K(3), .DATA_W(DW), .ACC_W(AW)) dut (
        .clk(clk), .rst(rst), .start(start),
        .window(window), .weights(weights), .bias(bias),
        .result(result), .valid(valid), .busy(busy)
    );

    integer i;
    integer expected;
    reg signed [7:0] x[0:N-1];
    reg signed [7:0] w[0:N-1];

    initial begin
        for (i=0; i<N; i=i+1) begin
            x[i] = i + 1;
            w[i] = 1;
            window[i*DW +: DW] = x[i];
            weights[i*DW +: DW] = w[i];
        end

        bias = -3;
        expected = -3;
        for (i=0; i<N; i=i+1)
            expected = expected + x[i] * w[i];

        #20 rst = 0;
        #10 start = 1;
        #10 start = 0;

        wait(valid);
        if (result !== expected) begin
            $display("DEPTHWISE FAIL: expected=%0d actual=%0d", expected, result);
            $fatal;
        end

        $display("DEPTHWISE PASS: %0d", result);
        #20 $finish;
    end
endmodule
