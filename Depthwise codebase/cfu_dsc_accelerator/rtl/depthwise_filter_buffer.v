/*******************************************************************************
 * Depthwise Filter Buffer
 *
 * Stores M depthwise filters (3x3 kernels) for the Depthwise stage.
 *
 * Organization:
 *   - 9-bank parallel memory structure (matches 3x3 filter)
 *   - Each bank corresponds to one spatial position in 3x3 kernel
 *   - All 9 weights read simultaneously in single cycle
 *
 * Dataflow:
 *   - Parallel 72-bit read (9 x 8-bit)
 *   - Direct connection to Depthwise Engine
 ******************************************************************************/

`include "cfu_dsc_defines.v"

module depthwise_filter_buffer (
    input  wire                         clk,
    input  wire                         rst_n,

    // Configuration
    input  wire [15:0]                  num_filters,    // M depthwise filters

    // Write interface
    input  wire                         wr_en,
    input  wire [3:0]                   wr_bank,        // Which bank (0-8)
    input  wire [`ADDR_WIDTH-1:0]       wr_addr,        // Filter index
    input  wire [`DATA_WIDTH-1:0]       wr_data,

    // Read interface
    input  wire                         rd_en,
    input  wire [`ADDR_WIDTH-1:0]       rd_addr,        // Filter index

    // Output (9 weights, one per bank)
    output reg  [`DATA_WIDTH-1:0]       weight_0, weight_1, weight_2,
    output reg  [`DATA_WIDTH-1:0]       weight_3, weight_4, weight_5,
    output reg  [`DATA_WIDTH-1:0]       weight_6, weight_7, weight_8,
    output reg                          weight_valid,

    // Status
    output wire                         ready
);

    //==========================================================================
    // Memory Banks (9 BRAMs)
    // Each bank stores one spatial position across all filters
    // Bank 0: top-left (0,0) of all filters
    // Bank 1: top-middle (0,1) of all filters
    // ...
    // Bank 8: bottom-right (2,2) of all filters
    //==========================================================================
    reg [`DATA_WIDTH-1:0] bank [0:8][0:`DW_FILTER_DEPTH-1];

    //==========================================================================
    // Write Logic
    //==========================================================================
    always @(posedge clk) begin
        if (wr_en) begin
            bank[wr_bank][wr_addr] <= wr_data;
        end
    end

    //==========================================================================
    // Read Logic (parallel from all 9 banks)
    //==========================================================================
    reg [`ADDR_WIDTH-1:0] rd_addr_reg;
    reg                   rd_en_reg;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rd_addr_reg <= 0;
            rd_en_reg   <= 0;
        end else begin
            rd_addr_reg <= rd_addr;
            rd_en_reg   <= rd_en;
        end
    end

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            weight_0 <= 0;
            weight_1 <= 0;
            weight_2 <= 0;
            weight_3 <= 0;
            weight_4 <= 0;
            weight_5 <= 0;
            weight_6 <= 0;
            weight_7 <= 0;
            weight_8 <= 0;
            weight_valid <= 0;
        end else if (rd_en_reg) begin
            weight_0 <= bank[0][rd_addr_reg];
            weight_1 <= bank[1][rd_addr_reg];
            weight_2 <= bank[2][rd_addr_reg];
            weight_3 <= bank[3][rd_addr_reg];
            weight_4 <= bank[4][rd_addr_reg];
            weight_5 <= bank[5][rd_addr_reg];
            weight_6 <= bank[6][rd_addr_reg];
            weight_7 <= bank[7][rd_addr_reg];
            weight_8 <= bank[8][rd_addr_reg];
            weight_valid <= 1'b1;
        end else begin
            weight_valid <= 1'b0;
        end
    end

    //==========================================================================
    // Status
    //==========================================================================
    assign ready = 1'b1;

endmodule
