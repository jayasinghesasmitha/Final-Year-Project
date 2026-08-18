/*******************************************************************************
 * CFU DSC Accelerator - Common Definitions
 *
 * Based on: "RISC-V Based TinyML Accelerator for Depthwise Separable
 *            Convolutions in Edge AI"
 *
 * This file contains common parameters and definitions for the fused
 * Expansion -> Depthwise -> Projection accelerator.
 ******************************************************************************/

`ifndef CFU_DSC_DEFINES_V
`define CFU_DSC_DEFINES_V

//------------------------------------------------------------------------------
// Data Width Parameters
//------------------------------------------------------------------------------
`define DATA_WIDTH      8       // INT8 quantized data
`define ACC_WIDTH       32      // Accumulator width (32-bit)
`define ADDR_WIDTH      16      // Address width for memory

//------------------------------------------------------------------------------
// Architecture Parameters (from paper)
//------------------------------------------------------------------------------
// Expansion Unit: 9 parallel engines (3x3 spatial tile)
`define EXP_ENGINES     9
`define EXP_MAC_WIDTH   8       // 8-way MAC per engine

// Depthwise Unit: Single engine, 9-way MAC (3x3 filter)
`define DW_MAC_WIDTH    9

// Projection Unit: 56 parallel engines
`define PROJ_ENGINES    56

// Maximum channel dimensions (MobileNetV2 compatible)
`define MAX_CHANNELS    320     // Max channel depth

//------------------------------------------------------------------------------
// Pipeline Stage Definitions (5-stage intra-stage pipeline)
//------------------------------------------------------------------------------
`define STAGE_EXP_MAC       3'd0
`define STAGE_EXP_QUANT     3'd1
`define STAGE_DW_MAC        3'd2
`define STAGE_DW_QUANT      3'd3
`define STAGE_PROJ_MAC      3'd4

//------------------------------------------------------------------------------
// Memory Parameters
//------------------------------------------------------------------------------
// IFMAP Buffer: 9 banks for parallel 3x3 access
`define IFMAP_BANKS     9
`define IFMAP_DEPTH     4096    // Configurable based on feature map size

// Filter Buffer depths
`define EXP_FILTER_DEPTH    8192    // Expansion filter storage
`define DW_FILTER_DEPTH     4096    // Depthwise filter storage
`define PROJ_FILTER_DEPTH   4096    // Projection filter per engine

//------------------------------------------------------------------------------
// Instruction Opcodes (CFU Interface)
//------------------------------------------------------------------------------
`define CFU_OP_NOP          3'd0
`define CFU_OP_LOAD_IFMAP   3'd1
`define CFU_OP_LOAD_EXP_W   3'd2
`define CFU_OP_LOAD_DW_W    3'd3
`define CFU_OP_LOAD_PROJ_W  3'd4
`define CFU_OP_LOAD_BIAS    3'd5
`define CFU_OP_SET_PARAMS   3'd6
`define CFU_OP_START        3'd7

//------------------------------------------------------------------------------
// CFU Function IDs
//------------------------------------------------------------------------------
`define CFU_FUNC_READ       3'd0
`define CFU_FUNC_WRITE      3'd1
`define CFU_FUNC_EXECUTE    3'd2
`define CFU_FUNC_STATUS     3'd3

//------------------------------------------------------------------------------
// Status Codes
//------------------------------------------------------------------------------
`define STATUS_IDLE         4'd0
`define STATUS_LOADING      4'd1
`define STATUS_COMPUTING    4'd2
`define STATUS_OUTPUT_RDY   4'd3
`define STATUS_DONE         4'd4
`define STATUS_ERROR        4'd5

`endif // CFU_DSC_DEFINES_V
