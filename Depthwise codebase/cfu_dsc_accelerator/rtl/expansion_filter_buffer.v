/*******************************************************************************
 * Expansion Filter Buffer
 *
 * Stores M expansion filters (1x1xN kernels) for the Expansion stage.
 * Each filter corresponds to one output channel.
 *
 * Organization:
 *   - Single large BRAM
 *   - Filters stored sequentially
 *   - Each filter: N weights (N is multiple of 8)
 *   - Output: 8-channel (64-bit) chunks per cycle
 *
 * Dataflow:
 *   - Sequential filter loading
 *   - Broadcast 8-byte chunks to all 9 Expansion Engines
 ******************************************************************************/

`include "cfu_dsc_defines.v"

module expansion_filter_buffer (
    input  wire                         clk,
    input  wire                         rst_n,

    // Configuration
    input  wire [15:0]                  num_filters,    // M expansion filters
    input  wire [15:0]                  input_channels, // N input channels

    // Write interface
    input  wire                         wr_en,
    input  wire [`ADDR_WIDTH-1:0]       wr_addr,
    input  wire [`DATA_WIDTH-1:0]       wr_data,

    // Read interface
    input  wire                         rd_en,
    input  wire [15:0]                  filter_idx,     // Which filter to read
    input  wire [15:0]                  channel_chunk,  // Which 8-channel chunk

    // Output (8 weights broadcast to all engines)
    output reg  [`DATA_WIDTH-1:0]       weight_0, weight_1, weight_2, weight_3,
    output reg  [`DATA_WIDTH-1:0]       weight_4, weight_5, weight_6, weight_7,
    output reg                          weight_valid,

    // Status
    output wire                         ready
);

    //==========================================================================
    // Memory (BRAM)
    //==========================================================================
    reg [`DATA_WIDTH-1:0] mem [0:`EXP_FILTER_DEPTH-1];

    //==========================================================================
    // Address Calculation
    //==========================================================================
    // Filter base address = filter_idx * input_channels
    // Channel offset = channel_chunk * 8
    wire [`ADDR_WIDTH-1:0] base_addr;
    wire [`ADDR_WIDTH-1:0] rd_base_addr;

    assign base_addr = filter_idx * input_channels;
    assign rd_base_addr = base_addr + (channel_chunk << 3); // * 8

    //==========================================================================
    // Write Logic
    //==========================================================================
    always @(posedge clk) begin
        if (wr_en) begin
            mem[wr_addr] <= wr_data;
        end
    end

    //==========================================================================
    // Read Logic
    //==========================================================================
    reg [`ADDR_WIDTH-1:0] rd_addr_reg;
    reg                   rd_en_reg;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rd_addr_reg <= 0;
            rd_en_reg   <= 0;
        end else begin
            rd_addr_reg <= rd_base_addr;
            rd_en_reg   <= rd_en;
        end
    end

    // Output 8 consecutive weights
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
            weight_valid <= 0;
        end else if (rd_en_reg) begin
            weight_0 <= mem[rd_addr_reg];
            weight_1 <= mem[rd_addr_reg + 1];
            weight_2 <= mem[rd_addr_reg + 2];
            weight_3 <= mem[rd_addr_reg + 3];
            weight_4 <= mem[rd_addr_reg + 4];
            weight_5 <= mem[rd_addr_reg + 5];
            weight_6 <= mem[rd_addr_reg + 6];
            weight_7 <= mem[rd_addr_reg + 7];
            weight_valid <= 1'b1;
        end else begin
            weight_valid <= 1'b0;
        end
    end

    //==========================================================================
    // Status
    //==========================================================================
    assign ready = 1'b1; // Always ready for new requests

endmodule
