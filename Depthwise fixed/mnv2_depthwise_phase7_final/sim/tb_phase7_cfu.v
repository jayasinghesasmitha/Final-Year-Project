`timescale 1ns/1ps

module tb_phase7_cfu;

    reg clk = 0;
    always #5 clk = ~clk;

    reg reset = 1;
    reg cmd_valid = 0;
    wire cmd_ready;

    reg [2:0] function_id = 0;
    reg [31:0] rs1 = 0;
    reg [31:0] rs2 = 0;

    wire rsp_valid;
    reg rsp_ready = 1;
    wire [31:0] result;

    mnv2_depthwise_cfu dut (
        .clk(clk),
        .reset(reset),
        .cmd_valid(cmd_valid),
        .cmd_ready(cmd_ready),
        .cmd_payload_function_id(function_id),
        .cmd_payload_inputs_0(rs1),
        .cmd_payload_inputs_1(rs2),
        .rsp_valid(rsp_valid),
        .rsp_ready(rsp_ready),
        .rsp_payload_outputs_0(result)
    );

    task cfu_cmd;
        input [2:0] f;
        input integer a;
        input integer d;
        begin
            @(negedge clk);
            while (!cmd_ready)
                @(negedge clk);

            function_id = f;
            rs1 = a;
            rs2 = d;
            cmd_valid = 1'b1;

            @(negedge clk);
            cmd_valid = 1'b0;

            while (!rsp_valid)
                @(posedge clk);

            @(negedge clk);
        end
    endtask

    integer i;
    integer timeout;
    integer value;

    initial begin
        $dumpfile("mnv2_depthwise_phase7.vcd");
        $dumpvars(0, tb_phase7_cfu);

        $display("============================================");
        $display("Phase 7 CFU Testbench");
        $display("============================================");

        #20;
        reset = 1'b0;

        $display("[TB] Loading IFMAP...");
        for (i=0; i<128; i=i+1)
            cfu_cmd(3'd0, i, 1);

        $display("[TB] Loading expansion weights...");
        for (i=0; i<192; i=i+1)
            cfu_cmd(3'd1, i, 1);

        $display("[TB] Loading depthwise weights...");
        for (i=0; i<216; i=i+1)
            cfu_cmd(3'd2, i, ((i % 9) == 4) ? 1 : 0);

        $display("[TB] Loading projection weights...");
        for (i=0; i<384; i=i+1)
            cfu_cmd(3'd3, i, 1);

        $display("[TB] All data loaded");
        $display("[TB] Starting...");
        cfu_cmd(3'd4, 0, 0);

        $display("[TB] Waiting for accelerator...");
        timeout = 0;

        while (timeout < 20000) begin
            cfu_cmd(3'd5, 0, 0);

            if ((result & 32'h1) == 0)
                timeout = 20000;
            else
                timeout = timeout + 1;
        end

        if ((result & 32'h1) != 0) begin
            $display("PHASE7 FAIL: accelerator timeout.");
            $fatal;
        end

        $display("[TB] Accelerator completed.");

        // Verify the datapath itself before testing the CFU read transport.
        $display("[TB] DEBUG: internal output_mem[0] = %0d",
                 $signed(dut.accelerator.output_mem[0]));
        $display("[TB] DEBUG: internal out_rd_data = %0d",
                 $signed(dut.accelerator.out_rd_data));

        $display("[TB] Reading outputs...");

        for (i=0; i<256; i=i+1) begin
            cfu_cmd(3'd6, i, 0);
            value = $signed(result);

            if (value !== 192) begin
                $display(
                    "PHASE7 FAIL: output[%0d] expected=192 actual=%0d (0x%08x)",
                    i, value, result
                );
                $fatal;
            end
        end

        $display("============================================");
        $display("PHASE7 PASS");
        $display("CFU load/start/status/read path verified.");
        $display("All 256 outputs equal 192.");
        $display("============================================");

        #20;
        $finish;
    end
endmodule
