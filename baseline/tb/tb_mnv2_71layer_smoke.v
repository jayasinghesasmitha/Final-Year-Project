`timescale 1ns/1ps

module tb_mnv2_71layer_smoke;
    reg clk;
    reg rst;
    reg start;
    wire done;
    wire busy;
    wire [9:0] class_index;

    always #5 clk = ~clk;

    mnv2_71layer_ref #(
        .DEBUG(1)
    ) dut (
        .clk         (clk),
        .rst         (rst),
        .start       (start),
        .busy        (busy),
        .done        (done),
        .class_index (class_index)
    );

    initial begin
        clk   = 1'b0;
        rst   = 1'b1;
        start = 1'b0;

        #100;
        rst = 1'b0;

        // Verify that generated/image.hex is really loaded.
        #20;
        $display("==============================================");
        $display("IMAGE MEMORY CHECK");
        $display("act_mem[0] = %02x", dut.act_mem[0]);
        $display("act_mem[1] = %02x", dut.act_mem[1]);
        $display("act_mem[2] = %02x", dut.act_mem[2]);
        $display("act_mem[3] = %02x", dut.act_mem[3]);
        $display("act_mem[4] = %02x", dut.act_mem[4]);
        $display("act_mem[5] = %02x", dut.act_mem[5]);
        $display("==============================================");

        #20;
        start = 1'b1;
        #10;
        start = 1'b0;

        wait(done == 1'b1);

        $display("==============================================");
        $display("MobileNetV2 71-op simulation completed");
        $display("Predicted ImageNet class index = %0d", class_index);
        $display("==============================================");
        $finish;
    end
endmodule
