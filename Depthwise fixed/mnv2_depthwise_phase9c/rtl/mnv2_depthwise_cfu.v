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

    input wire cmd_valid,
    output wire cmd_ready,

    input wire [2:0] cmd_payload_function_id,
    input wire [31:0] cmd_payload_inputs_0,
    input wire [31:0] cmd_payload_inputs_1,

    output reg rsp_valid,
    input wire rsp_ready,
    output reg [31:0] rsp_payload_outputs_0
);

    wire busy;
    wire done;

    reg start;

    reg ifmap_wr_en;
    reg [6:0] ifmap_wr_addr;
    reg signed [7:0] ifmap_wr_data;

    reg exp_wr_en;
    reg [7:0] exp_wr_addr;
    reg signed [7:0] exp_wr_data;

    reg dw_wr_en;
    reg [7:0] dw_wr_addr;
    reg signed [7:0] dw_wr_data;

    reg proj_wr_en;
    reg [8:0] proj_wr_addr;
    reg signed [7:0] proj_wr_data;

    reg [7:0] out_rd_addr;
    wire signed [31:0] out_rd_data;

    reg read_pending;


    // ============================================================
    // ACCELERATOR
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
    // COMMAND HANDSHAKE
    // ============================================================
    //
    // A new command is accepted only when:
    //
    //   1. CFU is not in reset
    //   2. There is no outstanding response
    //   3. There is no outstanding output read
    //
    // ============================================================

    assign cmd_ready =
        !reset &&
        !rsp_valid &&
        !read_pending;


    // ============================================================
    // CONTROL
    // ============================================================

    always @(posedge clk) begin

        // --------------------------------------------------------
        // RESET
        // --------------------------------------------------------

        if (reset) begin

            rsp_valid <= 1'b0;
            rsp_payload_outputs_0 <= 32'd0;

            start <= 1'b0;

            ifmap_wr_en <= 1'b0;
            exp_wr_en <= 1'b0;
            dw_wr_en <= 1'b0;
            proj_wr_en <= 1'b0;

            ifmap_wr_addr <= 7'd0;
            exp_wr_addr <= 8'd0;
            dw_wr_addr <= 8'd0;
            proj_wr_addr <= 9'd0;

            ifmap_wr_data <= 8'sd0;
            exp_wr_data <= 8'sd0;
            dw_wr_data <= 8'sd0;
            proj_wr_data <= 8'sd0;

            out_rd_addr <= 8'd0;
            read_pending <= 1'b0;

        end

        // --------------------------------------------------------
        // NORMAL OPERATION
        // --------------------------------------------------------

        else begin

            // ----------------------------------------------------
            // Default: all one-cycle control pulses inactive
            // ----------------------------------------------------

            start <= 1'b0;

            ifmap_wr_en <= 1'b0;
            exp_wr_en <= 1'b0;
            dw_wr_en <= 1'b0;
            proj_wr_en <= 1'b0;


            // ----------------------------------------------------
            // Complete an existing response
            // ----------------------------------------------------

            if (rsp_valid && rsp_ready) begin
                rsp_valid <= 1'b0;
            end


            // ----------------------------------------------------
            // Complete a pending output read
            // ----------------------------------------------------

            if (read_pending) begin

                rsp_payload_outputs_0 <=
                    out_rd_data;

                rsp_valid <= 1'b1;

                read_pending <= 1'b0;

            end


            // ----------------------------------------------------
            // Accept a new command
            // ----------------------------------------------------

            if (cmd_valid && cmd_ready) begin

                case (cmd_payload_function_id)

                    // =================================================
                    // FUNCTION 0 : LOAD IFMAP
                    // =================================================

                    3'd0: begin

                        ifmap_wr_en <= 1'b1;

                        ifmap_wr_addr <=
                            cmd_payload_inputs_0[6:0];

                        ifmap_wr_data <=
                            cmd_payload_inputs_1[7:0];

                        rsp_payload_outputs_0 <= 32'd0;

                        rsp_valid <= 1'b1;

                    end


                    // =================================================
                    // FUNCTION 1 : LOAD EXPANSION WEIGHT
                    // =================================================

                    3'd1: begin

                        exp_wr_en <= 1'b1;

                        exp_wr_addr <=
                            cmd_payload_inputs_0[7:0];

                        exp_wr_data <=
                            cmd_payload_inputs_1[7:0];

                        rsp_payload_outputs_0 <= 32'd0;

                        rsp_valid <= 1'b1;

                    end


                    // =================================================
                    // FUNCTION 2 : LOAD DEPTHWISE WEIGHT
                    // =================================================

                    3'd2: begin

                        dw_wr_en <= 1'b1;

                        dw_wr_addr <=
                            cmd_payload_inputs_0[7:0];

                        dw_wr_data <=
                            cmd_payload_inputs_1[7:0];

                        rsp_payload_outputs_0 <= 32'd0;

                        rsp_valid <= 1'b1;

                    end


                    // =================================================
                    // FUNCTION 3 : LOAD PROJECTION WEIGHT
                    // =================================================

                    3'd3: begin

                        proj_wr_en <= 1'b1;

                        proj_wr_addr <=
                            cmd_payload_inputs_0[8:0];

                        proj_wr_data <=
                            cmd_payload_inputs_1[7:0];

                        rsp_payload_outputs_0 <= 32'd0;

                        rsp_valid <= 1'b1;

                    end


                    // =================================================
                    // FUNCTION 4 : START
                    // =================================================
                    //
                    // START is accepted only when accelerator is
                    // idle.
                    //
                    // start is a one-cycle pulse.
                    //
                    // =================================================

                    3'd4: begin

                        if (!busy) begin
                            start <= 1'b1;
                        end

                        rsp_payload_outputs_0 <= 32'd0;

                        rsp_valid <= 1'b1;

                    end


                    // =================================================
                    // FUNCTION 5 : STATUS
                    // =================================================
                    //
                    // bit 0 = busy
                    // bit 1 = done
                    //
                    // =================================================

                    3'd5: begin

                        rsp_payload_outputs_0 <= {
                            30'd0,
                            done,
                            busy
                        };

                        rsp_valid <= 1'b1;

                    end


                    // =================================================
                    // FUNCTION 6 : READ OUTPUT
                    // =================================================
                    //
                    // First clock:
                    //     capture address
                    //
                    // Next clock:
                    //     return output_mem[address]
                    //
                    // =================================================

                    3'd6: begin

                        out_rd_addr <=
                            cmd_payload_inputs_0[7:0];

                        read_pending <= 1'b1;

                    end


                    // =================================================
                    // INVALID FUNCTION
                    // =================================================

                    default: begin

                        rsp_payload_outputs_0 <= 32'd0;

                        rsp_valid <= 1'b1;

                    end

                endcase

            end

        end

    end

endmodule