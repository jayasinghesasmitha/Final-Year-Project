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

    integer i, oc;
    integer expected;

    initial begin
        #20 rst=0;

        send_cmd(4'h0, {8'd24,8'd8,8'd4,8'd4});

        // All IFMAP values = 1.
        for (i=0; i<128; i=i+1)
            send_cmd(4'h1, 32'd1);

        // Expansion weights = 1.
        // Every expanded channel becomes 8 at every spatial point.
        for (i=0; i<192; i=i+1)
            send_cmd(4'h2, 32'd1);

        // Depthwise kernels = center-only 1.
        // Layout per channel: 0 0 0 / 0 1 0 / 0 0 0
        for (i=0; i<216; i=i+1) begin
            if ((i % 9) == 4)
                send_cmd(4'h3, 32'd1);
            else
                send_cmd(4'h3, 32'd0);
        end

        // Projection weights = 1.
        // Each output channel sums 24 depthwise channels.
        for (i=0; i<384; i=i+1)
            send_cmd(4'h4, 32'd1);

        send_cmd(4'h5, 0);

        if (!done) begin
            $display("CFU START FAIL");
            $fatal;
        end

        // 8 (expansion) * 1 (center depthwise) * 24 (projection) = 192.
        expected = 192;

        for (oc=0; oc<COUT; oc=oc+1) begin
            send_cmd(4'h7, 0);
            #1;
            if (data_out !== expected) begin
                $display("OUTPUT FAIL oc=%0d expected=%0d actual=%0d",
                         oc, expected, data_out);
                $fatal;
            end
        end

        $display("Phase 3 integrated datapath test passed.");
        #20 $finish;
    end
endmodule
