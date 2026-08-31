`timescale 1ns/1ps

module mnv2_depthwise_cfu #(
    parameter integer H=4, W=4, CIN=8, CEXP=24, COUT=16
)(
    input wire clk,
    input wire rst,

    input wire        cmd_valid,
    input wire [3:0]  cmd,
    input wire [31:0] data_in,

    output reg        resp_valid,
    output reg [31:0] data_out,
    output wire       busy,
    output wire       done
);

    localparam CMD_CONFIG      = 4'h0;
    localparam CMD_LOAD_IFMAP  = 4'h1;
    localparam CMD_LOAD_EXP_W  = 4'h2;
    localparam CMD_LOAD_DW_W   = 4'h3;
    localparam CMD_LOAD_PROJ_W = 4'h4;
    localparam CMD_START       = 4'h5;
    localparam CMD_STATUS      = 4'h6;
    localparam CMD_READ_OUTPUT = 4'h7;

    reg start;
    reg ifmap_wr_en, exp_wr_en, dw_wr_en, proj_wr_en;
    reg [6:0] ifmap_wr_addr;
    reg [7:0] exp_wr_addr, dw_wr_addr;
    reg [8:0] proj_wr_addr;
    reg signed [7:0] ifmap_wr_data, exp_wr_data, dw_wr_data, proj_wr_data;

    reg [7:0] out_rd_addr;
    wire signed [31:0] out_rd_data;

    mnv2_depthwise_top #(
        .H(H), .W(W), .CIN(CIN), .CEXP(CEXP), .COUT(COUT)
    ) accelerator (
        .clk(clk), .rst(rst), .start(start),
        .busy(busy), .done(done),

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

    always @(posedge clk) begin
        if (rst) begin
            resp_valid <= 0;
            data_out <= 0;
            start <= 0;
            ifmap_wr_en <= 0;
            exp_wr_en <= 0;
            dw_wr_en <= 0;
            proj_wr_en <= 0;
            ifmap_wr_addr <= 0;
            exp_wr_addr <= 0;
            dw_wr_addr <= 0;
            proj_wr_addr <= 0;
            out_rd_addr <= 0;
            ifmap_wr_data <= 0;
            exp_wr_data <= 0;
            dw_wr_data <= 0;
            proj_wr_data <= 0;
        end else begin
            resp_valid <= 0;
            start <= 0;
            ifmap_wr_en <= 0;
            exp_wr_en <= 0;
            dw_wr_en <= 0;
            proj_wr_en <= 0;

            if (cmd_valid) begin
                case (cmd)
                    CMD_CONFIG: begin
                        data_out <= 32'h0000_C001;
                        resp_valid <= 1;
                    end

                    CMD_LOAD_IFMAP: begin
                        ifmap_wr_en <= 1;
                        ifmap_wr_addr <= data_in[14:8];
                        ifmap_wr_data <= data_in[7:0];
                    end

                    CMD_LOAD_EXP_W: begin
                        exp_wr_en <= 1;
                        exp_wr_addr <= data_in[15:8];
                        exp_wr_data <= data_in[7:0];
                    end

                    CMD_LOAD_DW_W: begin
                        dw_wr_en <= 1;
                        dw_wr_addr <= data_in[15:8];
                        dw_wr_data <= data_in[7:0];
                    end

                    CMD_LOAD_PROJ_W: begin
                        proj_wr_en <= 1;
                        proj_wr_addr <= data_in[16:8];
                        proj_wr_data <= data_in[7:0];
                    end

                    CMD_START: begin
                        start <= 1;
                    end

                    CMD_STATUS: begin
                        data_out <= {30'b0, done, busy};
                        resp_valid <= 1;
                    end

                    CMD_READ_OUTPUT: begin
                        out_rd_addr <= data_in[7:0];
                        // The accelerator's output RAM is synchronously read.
                        // Return the current value on the following cycle.
                        data_out <= out_rd_data;
                        resp_valid <= 1;
                    end

                    default: begin
                        data_out <= 32'hDEAD_BEEF;
                        resp_valid <= 1;
                    end
                endcase
            end
        end
    end
endmodule
