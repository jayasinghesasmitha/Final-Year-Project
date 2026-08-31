`timescale 1ns/1ps

module tb_mnv2_depthwise_phase4;

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
        .clk(clk),.rst(rst),.start(start),.busy(busy),.done(done),
        .ifmap_wr_en(ifmap_wr_en),.ifmap_wr_addr(ifmap_wr_addr),.ifmap_wr_data(ifmap_wr_data),
        .exp_wr_en(exp_wr_en),.exp_wr_addr(exp_wr_addr),.exp_wr_data(exp_wr_data),
        .dw_wr_en(dw_wr_en),.dw_wr_addr(dw_wr_addr),.dw_wr_data(dw_wr_data),
        .proj_wr_en(proj_wr_en),.proj_wr_addr(proj_wr_addr),.proj_wr_data(proj_wr_data),
        .out_rd_addr(out_rd_addr),.out_rd_data(out_rd_data)
    );

    integer i;

    task write_ifmap(input integer a, input integer d);
        begin @(negedge clk); ifmap_wr_en=1; ifmap_wr_addr=a; ifmap_wr_data=d;
        @(negedge clk); ifmap_wr_en=0; end
    endtask
    task write_exp(input integer a, input integer d);
        begin @(negedge clk); exp_wr_en=1; exp_wr_addr=a; exp_wr_data=d;
        @(negedge clk); exp_wr_en=0; end
    endtask
    task write_dw(input integer a, input integer d);
        begin @(negedge clk); dw_wr_en=1; dw_wr_addr=a; dw_wr_data=d;
        @(negedge clk); dw_wr_en=0; end
    endtask
    task write_proj(input integer a, input integer d);
        begin @(negedge clk); proj_wr_en=1; proj_wr_addr=a; proj_wr_data=d;
        @(negedge clk); proj_wr_en=0; end
    endtask

    initial begin
        #20 rst=0;

        // Memory/control-plane verification.
        for (i=0;i<128;i=i+1) write_ifmap(i,1);
        for (i=0;i<192;i=i+1) write_exp(i,1);
        for (i=0;i<216;i=i+1) begin
            if ((i%9)==4) write_dw(i,1);
            else write_dw(i,0);
        end
        for (i=0;i<384;i=i+1) write_proj(i,1);

        @(negedge clk);
        start=1;
        @(negedge clk);
        start=0;

        // The controller should visit all spatial points and eventually assert done.
        wait(done);
        $display("PHASE4 PASS: controller completed all %0d spatial points.", H*W);

        #50 $finish;
    end
endmodule
