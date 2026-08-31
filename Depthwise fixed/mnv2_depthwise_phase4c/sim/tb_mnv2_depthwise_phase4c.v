`timescale 1ns/1ps

module tb_mnv2_depthwise_phase4c;

    localparam H=4, W=4, CIN=8, CEXP=24, COUT=16;

    reg clk=0;
    always #5 clk=~clk;

    reg rst=1, start=0;
    reg ifmap_wr_en=0, exp_wr_en=0, dw_wr_en=0, proj_wr_en=0;
    reg [6:0] ifmap_wr_addr;
    reg [7:0] exp_wr_addr, dw_wr_addr;
    reg [8:0] proj_wr_addr;
    reg signed [7:0] ifmap_wr_data, exp_wr_data, dw_wr_data, proj_wr_data;
    reg [7:0] out_rd_addr;

    wire busy, done;
    wire signed [31:0] out_rd_data;

    mnv2_depthwise_top dut (
        .clk(clk), .rst(rst), .start(start),
        .busy(busy), .done(done),
        .ifmap_wr_en(ifmap_wr_en), .ifmap_wr_addr(ifmap_wr_addr), .ifmap_wr_data(ifmap_wr_data),
        .exp_wr_en(exp_wr_en), .exp_wr_addr(exp_wr_addr), .exp_wr_data(exp_wr_data),
        .dw_wr_en(dw_wr_en), .dw_wr_addr(dw_wr_addr), .dw_wr_data(dw_wr_data),
        .proj_wr_en(proj_wr_en), .proj_wr_addr(proj_wr_addr), .proj_wr_data(proj_wr_data),
        .out_rd_addr(out_rd_addr), .out_rd_data(out_rd_data)
    );

    task write_ifmap(input integer a, input integer d);
        begin
            @(negedge clk);
            ifmap_wr_en=1; ifmap_wr_addr=a; ifmap_wr_data=d;
            @(negedge clk);
            ifmap_wr_en=0;
        end
    endtask

    task write_exp(input integer a, input integer d);
        begin
            @(negedge clk);
            exp_wr_en=1; exp_wr_addr=a; exp_wr_data=d;
            @(negedge clk);
            exp_wr_en=0;
        end
    endtask

    task write_dw(input integer a, input integer d);
        begin
            @(negedge clk);
            dw_wr_en=1; dw_wr_addr=a; dw_wr_data=d;
            @(negedge clk);
            dw_wr_en=0;
        end
    endtask

    task write_proj(input integer a, input integer d);
        begin
            @(negedge clk);
            proj_wr_en=1; proj_wr_addr=a; proj_wr_data=d;
            @(negedge clk);
            proj_wr_en=0;
        end
    endtask

    task read_output(input integer a);
        begin
            @(negedge clk);
            out_rd_addr=a;
            @(posedge clk);
            #1;
        end
    endtask

    integer i;
    integer timeout;

    initial begin
        out_rd_addr=0;

        #20 rst=0;

        // IFMAP = 1 everywhere.
        for (i=0; i<128; i=i+1)
            write_ifmap(i,1);

        // Expansion weights = 1.
        // Each expanded value = sum of eight ones = 8.
        for (i=0; i<192; i=i+1)
            write_exp(i,1);

        // Center-only depthwise kernel.
        for (i=0; i<216; i=i+1) begin
            if ((i % 9)==4)
                write_dw(i,1);
            else
                write_dw(i,0);
        end

        // Projection weights = 1.
        // Each output = sum of 24 depthwise values = 24*8 = 192.
        for (i=0; i<384; i=i+1)
            write_proj(i,1);

        @(negedge clk);
        start=1;
        @(negedge clk);
        start=0;

        timeout=0;
        while (!done && timeout < 20000) begin
            @(posedge clk);
            timeout=timeout+1;
        end

        if (!done) begin
            $display("PHASE4C FAIL: computation timeout after %0d cycles", timeout);
            $fatal;
        end

        $display("PHASE4C: computation completed in %0d wait cycles.", timeout);

        // Check all 256 output values.
        for (i=0; i<H*W*COUT; i=i+1) begin
            read_output(i);
            if (out_rd_data !== 192) begin
                $display("PHASE4C FAIL: output[%0d] expected=192 actual=%0d",
                         i, out_rd_data);
                $fatal;
            end
        end

        $display("PHASE4C PASS: all %0d outputs equal 192.", H*W*COUT);
        #20 $finish;
    end

endmodule
