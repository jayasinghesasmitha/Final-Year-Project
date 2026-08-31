`timescale 1ns/1ps

module tb_phase6_cfu;

    localparam H    = 4;
    localparam W    = 4;
    localparam CIN  = 8;
    localparam CEXP = 24;
    localparam COUT = 16;

    localparam IFMAP_N = H * W * CIN;
    localparam EXP_N   = CEXP * CIN;
    localparam DW_N    = CEXP * 9;
    localparam PROJ_N  = COUT * CEXP;
    localparam OUT_N   = H * W * COUT;

    reg clk = 0;

    always #5 clk = ~clk;

    reg reset = 1;

    // ============================================================
    // CFU command
    // ============================================================

    reg cmd_valid = 0;

    wire cmd_ready;

    reg [2:0] function_id = 0;

    reg [31:0] rs1 = 0;
    reg [31:0] rs2 = 0;

    // ============================================================
    // CFU response
    // ============================================================

    wire rsp_valid;

    reg rsp_ready = 1;

    wire [31:0] result;

    // ============================================================
    // DUT
    // ============================================================

    mnv2_depthwise_cfu #(
        .H(H),
        .W(W),
        .CIN(CIN),
        .CEXP(CEXP),
        .COUT(COUT)
    ) dut (

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

    // ============================================================
    // Generic CFU command
    // ============================================================

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

    // ============================================================
    // Variables
    // ============================================================

    integer i;
    integer timeout;
    integer value;

    // ============================================================
    // TEST
    // ============================================================

    initial begin

        $dumpfile("mnv2_depthwise_phase6.vcd");
        $dumpvars(0, tb_phase6_cfu);

        $display("============================================");
        $display("Phase 6 CFU Testbench");
        $display("============================================");

        // ========================================================
        // RESET
        // ========================================================

        #20;

        reset = 1'b0;

        $display("[TB] Reset complete");

        // ========================================================
        // IFMAP
        // ========================================================

        $display("[TB] Loading IFMAP...");

        for (i = 0; i < IFMAP_N; i = i + 1) begin

            cfu_cmd(
                3'd0,
                i,
                1
            );

        end

        // ========================================================
        // EXPANSION WEIGHTS
        // ========================================================

        $display("[TB] Loading expansion weights...");

        for (i = 0; i < EXP_N; i = i + 1) begin

            cfu_cmd(
                3'd1,
                i,
                1
            );

        end

        // ========================================================
        // DEPTHWISE WEIGHTS
        //
        // 3x3 kernel:
        //
        // 0 0 0
        // 0 1 0
        // 0 0 0
        // ========================================================

        $display("[TB] Loading depthwise weights...");

        for (i = 0; i < DW_N; i = i + 1) begin

            if ((i % 9) == 4) begin

                cfu_cmd(
                    3'd2,
                    i,
                    1
                );

            end
            else begin

                cfu_cmd(
                    3'd2,
                    i,
                    0
                );

            end

        end

        // ========================================================
        // PROJECTION WEIGHTS
        // ========================================================

        $display("[TB] Loading projection weights...");

        for (i = 0; i < PROJ_N; i = i + 1) begin

            cfu_cmd(
                3'd3,
                i,
                1
            );

        end

        $display("[TB] All data loaded");

        // ========================================================
        // START
        // ========================================================

        $display("[TB] Starting accelerator...");

        cfu_cmd(
            3'd4,
            0,
            0
        );

        // ========================================================
        // WAIT FOR COMPLETION
        // ========================================================

        $display("[TB] Waiting for accelerator...");

        timeout = 0;

        while (timeout < 20000) begin

            cfu_cmd(
                3'd5,
                0,
                0
            );

            if ((result & 32'h00000001) == 0) begin

                timeout = 20000;

            end
            else begin

                timeout = timeout + 1;

            end

        end

        if ((result & 32'h00000001) != 0) begin

            $display(
                "PHASE6 FAIL: accelerator timeout."
            );

            $fatal;

        end

        $display(
            "[TB] Accelerator completed"
        );

        // ========================================================
        // READ ALL OUTPUTS
        // ========================================================

        $display("[TB] Reading outputs...");

        for (i = 0; i < OUT_N; i = i + 1) begin

            cfu_cmd(
                3'd6,
                i,
                0
            );

            value = $signed(result);

            if (value !== 192) begin

                $display(
                    "PHASE6 FAIL: output[%0d] expected=192 actual=%0d (0x%08x)",
                    i,
                    value,
                    result
                );

                $fatal;

            end

        end

        // ========================================================
        // PASS
        // ========================================================

        $display("============================================");
        $display("PHASE6 PASS");
        $display("CFU load/start/status/read path verified.");
        $display("All %0d outputs equal 192.", OUT_N);
        $display("============================================");

        #20;

        $finish;

    end

endmodule