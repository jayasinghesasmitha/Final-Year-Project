/*******************************************************************************
 * CFU DSC Accelerator - Software Driver
 *
 * Driver for the fused Depthwise Separable Convolution CFU.
 * Provides high-level API for configuring and executing DSC operations.
 *
 * Compatible with CFU-Playground and TensorFlow Lite Micro.
 ******************************************************************************/

#ifndef CFU_DSC_DRIVER_H
#define CFU_DSC_DRIVER_H

#include <stdint.h>
#include <stdbool.h>

//------------------------------------------------------------------------------
// CFU Operation Codes (matches hardware)
//------------------------------------------------------------------------------
#define CFU_OP_NOP          0
#define CFU_OP_LOAD_IFMAP   1
#define CFU_OP_LOAD_EXP_W   2
#define CFU_OP_LOAD_DW_W    3
#define CFU_OP_LOAD_PROJ_W  4
#define CFU_OP_LOAD_BIAS    5
#define CFU_OP_SET_PARAMS   6
#define CFU_OP_START        7

//------------------------------------------------------------------------------
// CFU Function IDs
//------------------------------------------------------------------------------
#define CFU_FUNC_READ       0
#define CFU_FUNC_WRITE      1
#define CFU_FUNC_EXECUTE    2
#define CFU_FUNC_STATUS     3

//------------------------------------------------------------------------------
// Status Codes
//------------------------------------------------------------------------------
#define STATUS_IDLE         0
#define STATUS_LOADING      1
#define STATUS_COMPUTING    2
#define STATUS_OUTPUT_RDY   3
#define STATUS_DONE         4
#define STATUS_ERROR        5

//------------------------------------------------------------------------------
// Hardware Limits
//------------------------------------------------------------------------------
#define MAX_INPUT_CHANNELS  320
#define MAX_EXP_CHANNELS    960
#define MAX_OUTPUT_CHANNELS 56
#define MAX_FILTER_SIZE     (3 * 3)

//------------------------------------------------------------------------------
// CFU Instruction Macro
//------------------------------------------------------------------------------
#ifdef __riscv
// RISC-V custom instruction encoding
#define CFU_INSTR(funct3, funct7, rs1, rs2) \
    ({ int32_t result; \
       asm volatile (".word 0b" #funct7 "00000" #rs1 "000" #rs2 "0000101011" \
                     : "=r"(result) : "r"(rs1), "r"(rs2)); \
       result; })
#else
// Simulation stub
#define CFU_INSTR(funct3, funct7, rs1, rs2) cfu_sim(funct3, funct7, rs1, rs2)
#endif

//------------------------------------------------------------------------------
// Data Structures
//------------------------------------------------------------------------------

typedef struct {
    uint16_t height;
    uint16_t width;
    uint16_t in_channels;
    uint16_t exp_channels;
    uint16_t out_channels;
    int32_t exp_bias;
    int32_t dw_bias;
    int32_t proj_bias[MAX_OUTPUT_CHANNELS];
    int32_t exp_scale;
    int32_t dw_scale;
    int32_t proj_scale;
    int32_t exp_zero_point;
    int32_t dw_zero_point;
    int32_t proj_zero_point;
    uint8_t exp_shift;
    uint8_t dw_shift;
    uint8_t proj_shift;
} cfu_dsc_config_t;

typedef struct {
    const int8_t* data;
    uint16_t height;
    uint16_t width;
    uint16_t channels;
} ifmap_buffer_t;

typedef struct {
    const int8_t* data;
    uint16_t num_filters;
    uint16_t filter_size;  // 1 for 1x1, 9 for 3x3
} weight_buffer_t;

//------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------

/**
 * Initialize the CFU DSC accelerator
 */
void cfu_dsc_init(void);

/**
 * Configure the accelerator dimensions and quantization parameters
 */
void cfu_dsc_configure(const cfu_dsc_config_t* config);

/**
 * Load input feature map into accelerator
 * Returns: number of bytes loaded
 */
uint32_t cfu_dsc_load_ifmap(const int8_t* data, uint32_t size);

/**
 * Load expansion (1x1) weights
 * Returns: number of weights loaded
 */
uint32_t cfu_dsc_load_expansion_weights(const int8_t* weights,
                                         uint16_t num_filters,
                                         uint16_t in_channels);

/**
 * Load depthwise (3x3) weights
 * Returns: number of weights loaded
 */
uint32_t cfu_dsc_load_depthwise_weights(const int8_t* weights,
                                         uint16_t num_filters);

/**
 * Load projection (1x1) weights
 * Returns: number of weights loaded
 */
uint32_t cfu_dsc_load_projection_weights(const int8_t* weights,
                                          uint16_t num_filters,
                                          uint16_t exp_channels);

/**
 * Load bias values for all stages
 */
void cfu_dsc_load_bias(const int32_t* exp_bias,
                       const int32_t* dw_bias,
                       const int32_t* proj_bias);

/**
 * Start the fused computation
 */
void cfu_dsc_start(void);

/**
 * Wait for computation to complete (blocking)
 */
void cfu_dsc_wait_done(void);

/**
 * Check if computation is done (non-blocking)
 */
bool cfu_dsc_is_done(void);

/**
 * Read output channel data
 * Returns: int8_t value for specified channel
 */
int8_t cfu_dsc_read_output(uint8_t channel);

/**
 * Read all output channels
 * buffer must be large enough for out_channels elements
 */
void cfu_dsc_read_all_outputs(int8_t* buffer, uint16_t out_channels);

/**
 * Get current status of the accelerator
 */
uint8_t cfu_dsc_get_status(void);

/**
 * Execute complete DSC block (convenience function)
 */
int cfu_dsc_execute_dsc_block(const ifmap_buffer_t* ifmap,
                               const weight_buffer_t* exp_weights,
                               const weight_buffer_t* dw_weights,
                               const weight_buffer_t* proj_weights,
                               const cfu_dsc_config_t* config,
                               int8_t* output_buffer);

//------------------------------------------------------------------------------
// Low-level CFU Access Functions
//------------------------------------------------------------------------------

static inline int32_t cfu_read(uint8_t channel) {
    return CFU_INSTR(CFU_FUNC_READ, 0, channel, 0);
}

static inline void cfu_write(uint8_t type, int32_t data) {
    CFU_INSTR(CFU_FUNC_WRITE, type, data, 0);
}

static inline void cfu_execute(uint8_t cmd, int32_t arg1, int32_t arg2) {
    CFU_INSTR(CFU_FUNC_EXECUTE, cmd, arg1, arg2);
}

static inline int32_t cfu_status(void) {
    return CFU_INSTR(CFU_FUNC_STATUS, 0, 0, 0);
}

#endif // CFU_DSC_DRIVER_H
