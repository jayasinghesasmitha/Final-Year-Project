`timescale 1ns/1ps

module tb_mnv2_depthwise_phase5_cfu;

    localparam H=4, W=4, CIN=8, CEXP=24, COUT=16;

    reg clk=0;
    always #5 clk=~clk;

    reg rst=1;
    reg cmd_valid=0;
    reg [3:0] cmd=0;
    reg [31:0] data_in=0;

    wire resp_valid;
    wire [31:0] data_out;
    wire busy, done;

    mnv2_depthwise_cfu dut (
        .clk(clk), .rst(rst),
        .cmd_valid(cmd_valid), .cmd(cmd), .data_in(data_in),
        .resp_valid(resp_valid), .data_out(data_out),
        .busy(busy), .done(done)
    );

    task send(input [3:0] c, input [31:0] d);
        begin
            @(negedge clk);
            cmd=c;
            data_in=d;
            cmd_valid=1;
            @(negedge clk);
            cmd_valid=0;
            cmd=0;
            data_in=0;
        end
    endtask

    task load_ifmap(input integer a, input integer d);
        send(4'h1, {17'b0,a[6:0],d[7:0]});
    endtask

    task load_exp(input integer a, input integer d);
        send(4'h2, {16'b0,a[7:0],d[7:0]});
    endtask

    task load_dw(input integer a, input integer d);
        send(4'h3, {16'b0,a[7:0],d[7:0]});
    endtask

    task load_proj(input integer a, input integer d);
        send(4'h4, {15'b0,a[8:0],d[7:0]});
    endtask

    integer i, timeout;

    initial begin
        #20 rst=0;

        send(4'h0, 0);

        for (i=0;i<128;i=i+1) load_ifmap(i,1);
        for (i=0;i<192;i=i+1) load_exp(i,1);

        for (i=0;i<216;i=i+1) begin
            if ((i%9)==4) load_dw(i,1);
            else load_dw(i,0);
        end

        for (i=0;i<384;i=i+1) load_proj(i,1);

        send(4'h5,0);

        timeout=0;
        while (!done && timeout<20000) begin
            @(posedge clk);
            timeout=timeout+1;
        end

        if (!done) begin
            $display("PHASE5 FAIL: CFU computation timeout");
            $fatal;
        end

        $display("PHASE5: CFU START/DONE passed.");

        // The CFU read protocol is synchronous; allow one cycle between address and response.
        // This checks the first 16 output words through the wrapper.
        for (i=0;i<16;i=i+1) begin
            @(negedge clk);
            cmd=4'h7;
            data_in=i;
            cmd_valid=1;
            @(negedge clk);
            cmd_valid=0;
            @(posedge clk);
            #1;
            if (data_out !== 192) begin
                $display("PHASE5 FAIL: output[%0d] expected=192 actual=%0d",i,data_out);
                $fatal;
            end
        end

        $display("PHASE5 PASS: CFU interface and accelerator output verified.");
        #20 $finish;
    end
endmodule
