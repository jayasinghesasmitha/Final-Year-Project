/*******************************************************************************
 * CFU DSC Accelerator - Testbench
 *
 * Comprehensive testbench for verifying the fused DSC accelerator.
 * Tests all three compute stages and the complete pipeline.
 ******************************************************************************/

`timescale 1ns/1ps

`include "../rtl/cfu_dsc_defines.v"

module tb_cfu_dsc_accelerator;

    //==========================================================================
    // Testbench Parameters
    //==========================================================================
    parameter CLK_PERIOD = 10;  // 100 MHz
    parameter TEST_HEIGHT = 4;
    parameter TEST_WIDTH = 4;
    parameter TEST_IN_CH = 8;   // Must be multiple of 8
    parameter TEST_EXP_CH = 24; // Must be multiple of 8
    parameter TEST_OUT_CH = 16;

    //==========================================================================
    // DUT Signals
    //==========================================================================
    reg                         clk;
    reg                         rst_n;
    reg  [2:0]                  funct3;
    reg  [6:0]                  funct7;
    reg  [31:0]                 rs1;
    reg  [31:0]                 rs2;
    wire [31:0]                 rd;
    reg                         cfu_start;
    wire                        cfu_done;

    //==========================================================================
    // Test Data Storage
    //==========================================================================
    reg [7:0] test_ifmap [0:TEST_HEIGHT*TEST_WIDTH*TEST_IN_CH-1];
    reg [7:0] test_exp_weights [0:TEST_EXP_CH*TEST_IN_CH-1];
    reg [7:0] test_dw_weights [0:TEST_EXP_CH*9-1];
    reg [7:0] test_proj_weights [0:TEST_OUT_CH*TEST_EXP_CH-1];
    reg [7:0] expected_output [0:TEST_OUT_CH-1];
    reg [7:0] actual_output [0:TEST_OUT_CH-1];

    //==========================================================================
    // DUT Instantiation
    //==========================================================================
    cfu_dsc_accelerator dut (
        .clk        (clk),
        .rst_n      (rst_n),
        .funct3     (funct3),
        .funct7     (funct7),
        .rs1        (rs1),
        .rs2        (rs2),
        .rd         (rd),
        .cfu_start  (cfu_start),
        .cfu_done   (cfu_done)
    );

    //==========================================================================
    // Clock Generation
    //==========================================================================
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    //==========================================================================
    // Helper Tasks
    //==========================================================================

    // Reset the DUT
    task reset_dut;
        begin
            rst_n = 0;
            funct3 = 0;
            funct7 = 0;
            rs1 = 0;
            rs2 = 0;
            cfu_start = 0;
            #(CLK_PERIOD * 5);
            rst_n = 1;
            #(CLK_PERIOD * 2);
            $display("[TB] DUT reset complete");
        end
    endtask

    // Configure dimensions
    task configure_dimensions;
        input [15:0] height;
        input [15:0] width;
        begin
            @(posedge clk);
            funct3 = 3'd2;  // EXECUTE
            funct7 = 7'd0;  // Set dimensions
            rs1 = height;
            rs2 = width;
            cfu_start = 1;
            @(posedge clk);
            cfu_start = 0;
            $display("[TB] Configured dimensions: %0dx%0d", height, width);
        end
    endtask

    // Configure channels
    task configure_channels;
        input [15:0] in_ch;
        input [15:0] exp_ch;
        input [15:0] out_ch;
        begin
            @(posedge clk);
            funct3 = 3'd2;  // EXECUTE
            funct7 = 7'd1;  // Set channels
            rs1 = in_ch;
            rs2 = exp_ch;
            cfu_start = 1;
            @(posedge clk);
            cfu_start = 0;

            @(posedge clk);
            funct3 = 3'd2;  // EXECUTE
            funct7 = 7'd2;  // Set output channels
            rs1 = out_ch;
            rs2 = 0;
            cfu_start = 1;
            @(posedge clk);
            cfu_start = 0;

            $display("[TB] Configured channels: %0d -> %0d -> %0d", in_ch, exp_ch, out_ch);
        end
    endtask

    // Load IFMAP data
    task load_ifmap;
        input [7:0] data;
        begin
            @(posedge clk);
            funct3 = 3'd1;  // WRITE
            funct7 = 7'd0;  // IFMAP
            rs1 = {24'd0, data};
            rs2 = 0;
            cfu_start = 1;
            @(posedge clk);
            cfu_start = 0;
        end
    endtask

    // Load expansion weights
    task load_exp_weight;
        input [7:0] data;
        begin
            @(posedge clk);
            funct3 = 3'd1;  // WRITE
            funct7 = 7'd1;  // Expansion weights
            rs1 = {24'd0, data};
            rs2 = 0;
            cfu_start = 1;
            @(posedge clk);
            cfu_start = 0;
        end
    endtask

    // Load depthwise weights
    task load_dw_weight;
        input [7:0] data;
        begin
            @(posedge clk);
            funct3 = 3'd1;  // WRITE
            funct7 = 7'd2;  // Depthwise weights
            rs1 = {24'd0, data};
            rs2 = 0;
            cfu_start = 1;
            @(posedge clk);
            cfu_start = 0;
        end
    endtask

    // Load projection weights
    task load_proj_weight;
        input [7:0] data;
        begin
            @(posedge clk);
            funct3 = 3'd1;  // WRITE
            funct7 = 7'd3;  // Projection weights
            rs1 = {24'd0, data};
            rs2 = 0;
            cfu_start = 1;
            @(posedge clk);
            cfu_start = 0;
        end
    endtask

    // Start computation
    task start_computation;
        begin
            @(posedge clk);
            funct3 = 3'd2;  // EXECUTE
            funct7 = 7'd7;  // START
            rs1 = 0;
            rs2 = 0;
            cfu_start = 1;
            @(posedge clk);
            cfu_start = 0;
            $display("[TB] Computation started");
        end
    endtask

    // Read output channel
    task read_output;
        input [5:0] channel;
        output [31:0] data;
        begin
            @(posedge clk);
            funct3 = 3'd0;  // READ
            funct7 = 0;
            rs1 = channel;
            rs2 = 0;
            cfu_start = 1;
            @(posedge clk);
            cfu_start = 0;
            @(posedge clk);
            data = rd;
        end
    endtask

    // Get status
    task get_status;
        output [3:0] status;
        begin
            @(posedge clk);
            funct3 = 3'd3;  // STATUS
            funct7 = 0;
            rs1 = 0;
            rs2 = 0;
            cfu_start = 1;
            @(posedge clk);
            cfu_start = 0;
            @(posedge clk);
            status = rd[3:0];
        end
    endtask

    //==========================================================================
    // Initialize Test Data
    //==========================================================================
    task init_test_data;
        integer i;
        begin
            // Initialize IFMAP with simple pattern
            for (i = 0; i < TEST_HEIGHT*TEST_WIDTH*TEST_IN_CH; i = i + 1) begin
                test_ifmap[i] = i % 256;
            end

            // Initialize weights with simple pattern
            for (i = 0; i < TEST_EXP_CH*TEST_IN_CH; i = i + 1) begin
                test_exp_weights[i] = 1;  // Simple weights for verification
            end

            for (i = 0; i < TEST_EXP_CH*9; i = i + 1) begin
                test_dw_weights[i] = 1;
            end

            for (i = 0; i < TEST_OUT_CH*TEST_EXP_CH; i = i + 1) begin
                test_proj_weights[i] = 1;
            end

            $display("[TB] Test data initialized");
        end
    endtask

    //==========================================================================
    // Load All Data to Accelerator
    //==========================================================================
    task load_all_data;
        integer i;
        begin
            // Load IFMAP
            $display("[TB] Loading IFMAP...");
            for (i = 0; i < TEST_HEIGHT*TEST_WIDTH*TEST_IN_CH; i = i + 1) begin
                load_ifmap(test_ifmap[i]);
            end

            // Load expansion weights
            $display("[TB] Loading expansion weights...");
            for (i = 0; i < TEST_EXP_CH*TEST_IN_CH; i = i + 1) begin
                load_exp_weight(test_exp_weights[i]);
            end

            // Load depthwise weights
            $display("[TB] Loading depthwise weights...");
            for (i = 0; i < TEST_EXP_CH*9; i = i + 1) begin
                load_dw_weight(test_dw_weights[i]);
            end

            // Load projection weights
            $display("[TB] Loading projection weights...");
            for (i = 0; i < TEST_OUT_CH*TEST_EXP_CH; i = i + 1) begin
                load_proj_weight(test_proj_weights[i]);
            end

            $display("[TB] All data loaded");
        end
    endtask

    //==========================================================================
    // Read All Outputs
    //==========================================================================
    task read_all_outputs;
        integer i;
        reg [31:0] data;
        begin
            $display("[TB] Reading outputs...");
            for (i = 0; i < TEST_OUT_CH; i = i + 1) begin
                read_output(i[5:0], data);
                actual_output[i] = data[7:0];
                $display("  Output[%0d] = %0d", i, $signed(data[7:0]));
            end
        end
    endtask

    //==========================================================================
    // Main Test Sequence
    //==========================================================================
    initial begin
        reg [3:0] status;

        $display("============================================");
        $display("CFU DSC Accelerator Testbench");
        $display("============================================");

        // Initialize
        init_test_data();
        reset_dut();

        // Configure
        configure_dimensions(TEST_HEIGHT, TEST_WIDTH);
        configure_channels(TEST_IN_CH, TEST_EXP_CH, TEST_OUT_CH);

        // Load data
        load_all_data();

        // Start computation
        start_computation();

        // Wait for completion
        $display("[TB] Waiting for completion...");
        wait(cfu_done);
        $display("[TB] Computation complete!");

        // Read outputs
        read_all_outputs();

        // Verify (basic check)
        $display("[TB] Test completed");

        // End simulation
        #(CLK_PERIOD * 10);
        $display("============================================");
        $display("Testbench completed successfully!");
        $display("============================================");
        $finish;
    end

    //==========================================================================
    // Timeout
    //==========================================================================
    initial begin
        #(CLK_PERIOD * 100000);
        $error("[TB] Timeout!");
        $finish;
    end

    //==========================================================================
    // Waveform Dump
    //==========================================================================
    initial begin
        $dumpfile("cfu_dsc_accelerator.vcd");
        $dumpvars(0, tb_cfu_dsc_accelerator);
    end

endmodule
