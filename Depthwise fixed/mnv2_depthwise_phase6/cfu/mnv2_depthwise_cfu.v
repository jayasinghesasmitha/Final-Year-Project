`timescale 1ns/1ps

module mnv2_depthwise_cfu #(
    parameter integer H=4,
    parameter integer W=4,
    parameter integer CIN=8,
    parameter integer CEXP=24,
    parameter integer COUT=16
)(
    input wire clk,
    input wire reset,

    // ============================================================
    // CFU command interface
    // ============================================================

    input wire        cmd_valid,
    output wire       cmd_ready,

    input wire [2:0]  cmd_payload_function_id,

    input wire [31:0] cmd_payload_inputs_0,
    input wire [31:0] cmd_payload_inputs_1,

    // ============================================================
    // CFU response interface
    // ============================================================

    output reg        rsp_valid,
    input wire        rsp_ready,

    output reg [31:0] rsp_payload_outputs_0
);

    // ============================================================
    // Datapath signals
    // ============================================================

    wire busy;
    wire done;

    // ------------------------------------------------------------
    // IFMAP
    // ------------------------------------------------------------

    reg ifmap_wr_en;
    reg [6:0] ifmap_wr_addr;
    reg signed [7:0] ifmap_wr_data;

    // ------------------------------------------------------------
    // Expansion weights
    // ------------------------------------------------------------

    reg exp_wr_en;
    reg [7:0] exp_wr_addr;
    reg signed [7:0] exp_wr_data;

    // ------------------------------------------------------------
    // Depthwise weights
    // ------------------------------------------------------------

    reg dw_wr_en;
    reg [7:0] dw_wr_addr;
    reg signed [7:0] dw_wr_data;

    // ------------------------------------------------------------
    // Projection weights
    // ------------------------------------------------------------

    reg proj_wr_en;
    reg [8:0] proj_wr_addr;
    reg signed [7:0] proj_wr_data;

    // ------------------------------------------------------------
    // Start
    // ------------------------------------------------------------

    reg start;

    // ------------------------------------------------------------
    // Output read
    // ------------------------------------------------------------

    reg [7:0] out_rd_addr;

    wire signed [31:0] out_rd_data;

    // ============================================================
    // Accelerator
    // ============================================================

    mnv2_depthwise_top #(
        .H(H),
        .W(W),
        .CIN(CIN),
        .CEXP(CEXP),
        .COUT(COUT),
        .DATA_W(8),
        .ACC_W(32)
    ) accelerator (

        .clk(clk),
        .rst(reset),
        .start(start),

        .busy(busy),
        .done(done),

        .ifmap_wr_en(ifmap_wr_en),
        .ifmap_wr_addr(ifmap_wr_addr),
        .ifmap_wr_data(ifmap_wr_data),

        .exp_wr_en(exp_wr_en),
        .exp_wr_addr(exp_wr_addr),
        .exp_wr_data(exp_wr_data),

        .dw_wr_en(dw_wr_en),
        .dw_wr_addr(dw_wr_addr),
        .dw_wr_data(dw_wr_data),

        .proj_wr_en(proj_wr_en),
        .proj_wr_addr(proj_wr_addr),
        .proj_wr_data(proj_wr_data),

        .out_rd_addr(out_rd_addr),
        .out_rd_data(out_rd_data)
    );

    // ============================================================
    // Command ready
    // ============================================================

    assign cmd_ready =
        !rsp_valid &&
        !reset;

    // ============================================================
    // CFU command processor
    // ============================================================

    always @(posedge clk) begin

        // ========================================================
        // RESET
        // ========================================================

        if (reset) begin

            rsp_valid <= 1'b0;

            rsp_payload_outputs_0 <= 32'd0;

            ifmap_wr_en <= 1'b0;
            exp_wr_en <= 1'b0;
            dw_wr_en <= 1'b0;
            proj_wr_en <= 1'b0;

            start <= 1'b0;

            ifmap_wr_addr <= 0;
            exp_wr_addr <= 0;
            dw_wr_addr <= 0;
            proj_wr_addr <= 0;

            ifmap_wr_data <= 0;
            exp_wr_data <= 0;
            dw_wr_data <= 0;
            proj_wr_data <= 0;

            out_rd_addr <= 0;

        end

        // ========================================================
        // NORMAL
        // ========================================================

        else begin

            // ----------------------------------------------------
            // Default one-cycle pulses.
            // ----------------------------------------------------

            ifmap_wr_en <= 1'b0;
            exp_wr_en <= 1'b0;
            dw_wr_en <= 1'b0;
            proj_wr_en <= 1'b0;

            start <= 1'b0;

            // ----------------------------------------------------
            // Response handshake.
            // ----------------------------------------------------

            if (rsp_valid && rsp_ready)
                rsp_valid <= 1'b0;

            // ----------------------------------------------------
            // Accept command.
            // ----------------------------------------------------

            if (cmd_valid && cmd_ready) begin

                rsp_valid <= 1'b1;

                rsp_payload_outputs_0 <= 32'd0;

                case (cmd_payload_function_id)

                    // ============================================
                    // 0: LOAD IFMAP
                    // ============================================

                    3'd0: begin

                        ifmap_wr_en <= 1'b1;

                        ifmap_wr_addr <=
                            cmd_payload_inputs_0[6:0];

                        ifmap_wr_data <=
                            cmd_payload_inputs_1[7:0];

                    end

                    // ============================================
                    // 1: LOAD EXPANSION WEIGHT
                    // ============================================

                    3'd1: begin

                        exp_wr_en <= 1'b1;

                        exp_wr_addr <=
                            cmd_payload_inputs_0[7:0];

                        exp_wr_data <=
                            cmd_payload_inputs_1[7:0];

                    end

                    // ============================================
                    // 2: LOAD DEPTHWISE WEIGHT
                    // ============================================

                    3'd2: begin

                        dw_wr_en <= 1'b1;

                        dw_wr_addr <=
                            cmd_payload_inputs_0[7:0];

                        dw_wr_data <=
                            cmd_payload_inputs_1[7:0];

                    end

                    // ============================================
                    // 3: LOAD PROJECTION WEIGHT
                    // ============================================

                    3'd3: begin

                        proj_wr_en <= 1'b1;

                        proj_wr_addr <=
                            cmd_payload_inputs_0[8:0];

                        proj_wr_data <=
                            cmd_payload_inputs_1[7:0];

                    end

                    // ============================================
                    // 4: START
                    // ============================================

                    3'd4: begin

                        if (!busy) begin
                            start <= 1'b1;
                        end

                    end

                    // ============================================
                    // 5: STATUS
                    //
                    // bit 0 = busy
                    // bit 1 = done
                    // ============================================

                    3'd5: begin

                        rsp_payload_outputs_0 <=
                            {30'd0, done, busy};

                    end

                    // ============================================
                    // 6: READ OUTPUT
                    //
                    // Output read is now combinational, so the
                    // requested output is immediately available
                    // after out_rd_addr is updated.
                    // ============================================

                    3'd6: begin

                        out_rd_addr <=
                            cmd_payload_inputs_0[7:0];

                        rsp_payload_outputs_0 <=
                            out_rd_data;

                    end

                    // ============================================
                    // RESERVED
                    // ============================================

                    default: begin

                        rsp_payload_outputs_0 <=
                            32'd0;

                    end

                endcase

            end

        end

    end

endmodule