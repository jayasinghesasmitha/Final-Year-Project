/*******************************************************************************
 * IFMAP Buffer (Input Feature Map Buffer)
 *
 * 9-bank parallel memory structure for simultaneous 3x3 window access.
 * Each bank is an independent BRAM block.
 *
 * Banking Scheme:
 *   Bank = (row % 3) * 3 + (col % 3)
 *
 * This ensures any 3x3 window spans all 9 banks, enabling single-cycle read.
 *
 * Features:
 *   - On-the-fly padding logic
 *   - 9 parallel read ports
 *   - Single write port (multiplexed)
 ******************************************************************************/

`include "cfu_dsc_defines.v"

module ifmap_buffer (
    input  wire                         clk,
    input  wire                         rst_n,

    // Configuration
    input  wire [7:0]                   height,         // Feature map height
    input  wire [7:0]                   width,          // Feature map width
    input  wire                         zero_point,     // Padding value

    // Write interface
    input  wire                         wr_en,
    input  wire [`ADDR_WIDTH-1:0]       wr_addr,        // Linear address
    input  wire [`DATA_WIDTH-1:0]       wr_data,

    // Read interface (3x3 window)
    input  wire [7:0]                   rd_row,         // Top-left row of window
    input  wire [7:0]                   rd_col,         // Top-left col of window
    input  wire                         rd_en,

    // 3x3 Window output (row-major: 0,0 0,1 0,2 1,0 ...)
    output reg  [`DATA_WIDTH-1:0]       window_0, window_1, window_2,
    output reg  [`DATA_WIDTH-1:0]       window_3, window_4, window_5,
    output reg  [`DATA_WIDTH-1:0]       window_6, window_7, window_8,
    output reg                          window_valid
);

    //==========================================================================
    // Memory Banks (9 BRAMs)
    //==========================================================================
    reg [`DATA_WIDTH-1:0] bank [0:8][0:`IFMAP_DEPTH-1];

    //==========================================================================
    // Banking Function: Bank = (row % 3) * 3 + (col % 3)
    //==========================================================================
    wire [3:0] bank_addr [0:8];
    wire [7:0] row_addr  [0:8];
    wire [7:0] col_addr  [0:8];

    // Calculate addresses for 3x3 window
    // Row offsets: 0, 0, 0, 1, 1, 1, 2, 2, 2
    // Col offsets: 0, 1, 2, 0, 1, 2, 0, 1, 2
    assign row_addr[0] = rd_row;
    assign row_addr[1] = rd_row;
    assign row_addr[2] = rd_row;
    assign row_addr[3] = rd_row + 1;
    assign row_addr[4] = rd_row + 1;
    assign row_addr[5] = rd_row + 1;
    assign row_addr[6] = rd_row + 2;
    assign row_addr[7] = rd_row + 2;
    assign row_addr[8] = rd_row + 2;

    assign col_addr[0] = rd_col;
    assign col_addr[1] = rd_col + 1;
    assign col_addr[2] = rd_col + 2;
    assign col_addr[3] = rd_col;
    assign col_addr[4] = rd_col + 1;
    assign col_addr[5] = rd_col + 2;
    assign col_addr[6] = rd_col;
    assign col_addr[7] = rd_col + 1;
    assign col_addr[8] = rd_col + 2;

    // Bank selection for each position
    wire [3:0] target_bank [0:8];
    genvar i;
    generate
        for (i = 0; i < 9; i = i + 1) begin : bank_calc
            assign target_bank[i] = (row_addr[i] % 3) * 3 + (col_addr[i] % 3);
        end
    endgenerate

    //==========================================================================
    // On-the-fly Padding Logic
    //==========================================================================
    wire [8:0] out_of_bounds;
    wire [8:0] use_padding;

    generate
        for (i = 0; i < 9; i = i + 1) begin : bounds_check
            assign out_of_bounds[i] = (row_addr[i] >= height) || (col_addr[i] >= width);
        end
    endgenerate

    //==========================================================================
    // Write Logic (single port, multiplexed)
    //==========================================================================
    wire [3:0] wr_bank;
    wire [`ADDR_WIDTH-1:0] wr_bank_addr;

    assign wr_bank = (wr_addr % 9);
    assign wr_bank_addr = wr_addr / 9;

    integer b;
    always @(posedge clk) begin
        if (wr_en) begin
            bank[wr_bank][wr_bank_addr] <= wr_data;
        end
    end

    //==========================================================================
    // Read Logic with Padding
    //==========================================================================
    reg [`DATA_WIDTH-1:0] read_data [0:8];
    reg [8:0]             use_pad_reg;

    always @(posedge clk) begin
        if (rd_en) begin
            // Read from all banks
            read_data[0] <= bank[target_bank[0]][rd_row * (width/3) + rd_col/3];
            read_data[1] <= bank[target_bank[1]][rd_row * (width/3) + rd_col/3];
            read_data[2] <= bank[target_bank[2]][rd_row * (width/3) + rd_col/3];
            read_data[3] <= bank[target_bank[3]][(rd_row+1) * (width/3) + rd_col/3];
            read_data[4] <= bank[target_bank[4]][(rd_row+1) * (width/3) + rd_col/3];
            read_data[5] <= bank[target_bank[5]][(rd_row+1) * (width/3) + rd_col/3];
            read_data[6] <= bank[target_bank[6]][(rd_row+2) * (width/3) + rd_col/3];
            read_data[7] <= bank[target_bank[7]][(rd_row+2) * (width/3) + rd_col/3];
            read_data[8] <= bank[target_bank[8]][(rd_row+2) * (width/3) + rd_col/3];

            use_pad_reg <= out_of_bounds;
            window_valid <= 1'b1;
        end else begin
            window_valid <= 1'b0;
        end
    end

    //==========================================================================
    // Output Assignment with Padding
    //==========================================================================
    always @(*) begin
        window_0 = use_pad_reg[0] ? zero_point : read_data[0];
        window_1 = use_pad_reg[1] ? zero_point : read_data[1];
        window_2 = use_pad_reg[2] ? zero_point : read_data[2];
        window_3 = use_pad_reg[3] ? zero_point : read_data[3];
        window_4 = use_pad_reg[4] ? zero_point : read_data[4];
        window_5 = use_pad_reg[5] ? zero_point : read_data[5];
        window_6 = use_pad_reg[6] ? zero_point : read_data[6];
        window_7 = use_pad_reg[7] ? zero_point : read_data[7];
        window_8 = use_pad_reg[8] ? zero_point : read_data[8];
    end

endmodule
