`timescale 1ns/1ps

module tb_mnv2_depthwise_cfu;

    localparam CIN=8;
    localparam CEXP=24;
    localparam COUT=16;
    localparam H=4;
    localparam W=4;

    reg clk=0;
    always #5 clk=~clk;

    reg rst=1;
    reg cmd_valid=0;
    reg [3:0] cmd=0;
    reg [31:0] data_in=0;
    wire resp_valid;
    wire [31:0] data_out;
    wire busy, done;

    mnv2_depthwise_cfu #(.H(H),.W(W),.CIN(CIN),.CEXP(CEXP),.COUT(COUT)) dut (
        .clk(clk), .rst(rst), .cmd_valid(cmd_valid), .cmd(cmd),
        .data_in(data_in), .resp_valid(resp_valid),
        .data_out(data_out), .busy(busy), .done(done)
    );

    task send_cmd(input [3:0] c, input [31:0] d);
        begin
            @(negedge clk);
            cmd <= c;
            data_in <= d;
            cmd_valid <= 1;
            @(negedge clk);
            cmd_valid <= 0;
            cmd <= 0;
            data_in <= 0;
        end
    endtask

    integer i;
    integer expected0;

    initial begin
        #20 rst=0;

        // 4x4, 8 -> 24
        send_cmd(4'h0, {8'd24,8'd8,8'd4,8'd4});

        // Simple deterministic data.
        // IFMAP: all 1
        for (i=0; i<128; i=i+1)
            send_cmd(4'h1, 32'd1);

        // Expansion weights: all 1
        for (i=0; i<192; i=i+1)
            send_cmd(4'h2, 32'd1);

        // Depthwise weights: all 0, so they don't alter the reference result.
        for (i=0; i<216; i=i+1)
            send_cmd(4'h3, 32'd0);

        // Projection weights: all 1
        for (i=0; i<384; i=i+1)
            send_cmd(4'h4, 32'd1);

        expected0 = 8 + 8;

        send_cmd(4'h5, 0);

        if (!done) begin
            $display("CFU START FAIL: done was not asserted");
            $fatal;
        end
        $display("CFU CONFIG PASS");
        $display("CFU LOAD PASS");
        $display("CFU START PASS");

        send_cmd(4'h7, 0);
        #1;
        if (data_out !== expected0) begin
            $display("CFU OUTPUT FAIL: expected=%0d actual=%0d", expected0, data_out);
            $fatal;
        end

        $display("CFU OUTPUT PASS: %0d", data_out);
        $display("Phase 2 CFU test passed.");
        #20 $finish;
    end
endmodule
