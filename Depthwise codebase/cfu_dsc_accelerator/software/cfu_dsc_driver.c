/*******************************************************************************
 * CFU DSC Accelerator - Software Driver Implementation
 ******************************************************************************/

#include "cfu_dsc_driver.h"
#include <string.h>

//------------------------------------------------------------------------------
// Simulation Stub (for non-RISC-V builds)
//------------------------------------------------------------------------------
#ifndef __riscv
static int32_t cfu_sim(uint8_t funct3, uint8_t funct7, int32_t rs1, int32_t rs2) {
    // Simulation placeholder - would interface with Verilator model
    (void)funct3;
    (void)funct7;
    (void)rs1;
    (void)rs2;
    return 0;
}
#endif

//------------------------------------------------------------------------------
// Global State
//------------------------------------------------------------------------------
static cfu_dsc_config_t g_config;
static bool g_initialized = false;

//------------------------------------------------------------------------------
// Initialization
//------------------------------------------------------------------------------
void cfu_dsc_init(void) {
    memset(&g_config, 0, sizeof(g_config));
    g_initialized = true;
}

//------------------------------------------------------------------------------
// Configuration
//------------------------------------------------------------------------------
void cfu_dsc_configure(const cfu_dsc_config_t* config) {
    if (!g_initialized) {
        cfu_dsc_init();
    }

    memcpy(&g_config, config, sizeof(cfu_dsc_config_t));

    // Set dimensions (height, width)
    cfu_execute(0, config->height, config->width);

    // Set channel configuration
    cfu_execute(1, config->in_channels, config->exp_channels);

    // Set output channels
    cfu_execute(2, config->out_channels, 0);
}

//------------------------------------------------------------------------------
// Load Input Feature Map
//------------------------------------------------------------------------------
uint32_t cfu_dsc_load_ifmap(const int8_t* data, uint32_t size) {
    uint32_t loaded = 0;

    for (uint32_t i = 0; i < size; i++) {
        cfu_write(0, (int32_t)data[i]);
        loaded++;
    }

    return loaded;
}

//------------------------------------------------------------------------------
// Load Expansion Weights (1x1 conv)
//------------------------------------------------------------------------------
uint32_t cfu_dsc_load_expansion_weights(const int8_t* weights,
                                         uint16_t num_filters,
                                         uint16_t in_channels) {
    uint32_t loaded = 0;
    uint32_t total_weights = num_filters * in_channels;

    for (uint32_t i = 0; i < total_weights; i++) {
        cfu_write(1, (int32_t)weights[i]);
        loaded++;
    }

    return loaded;
}

//------------------------------------------------------------------------------
// Load Depthwise Weights (3x3 conv)
//------------------------------------------------------------------------------
uint32_t cfu_dsc_load_depthwise_weights(const int8_t* weights,
                                         uint16_t num_filters) {
    uint32_t loaded = 0;
    uint32_t total_weights = num_filters * 9;  // 3x3 kernel

    // Weights are stored bank-interleaved for parallel access
    // Bank 0: all filters' (0,0) position
    // Bank 1: all filters' (0,1) position
    // ...

    for (uint16_t bank = 0; bank < 9; bank++) {
        for (uint16_t f = 0; f < num_filters; f++) {
            uint32_t idx = f * 9 + bank;
            cfu_write(2, (int32_t)weights[idx]);
            loaded++;
        }
    }

    return loaded;
}

//------------------------------------------------------------------------------
// Load Projection Weights (1x1 conv)
//------------------------------------------------------------------------------
uint32_t cfu_dsc_load_projection_weights(const int8_t* weights,
                                          uint16_t num_filters,
                                          uint16_t exp_channels) {
    uint32_t loaded = 0;
    uint32_t total_weights = num_filters * exp_channels;

    for (uint32_t i = 0; i < total_weights; i++) {
        cfu_write(3, (int32_t)weights[i]);
        loaded++;
    }

    return loaded;
}

//------------------------------------------------------------------------------
// Load Bias Values
//------------------------------------------------------------------------------
void cfu_dsc_load_bias(const int32_t* exp_bias,
                       const int32_t* dw_bias,
                       const int32_t* proj_bias) {
    // Load expansion bias
    cfu_write(4, exp_bias[0]);

    // Load depthwise bias
    cfu_write(4, dw_bias[0]);

    // Load projection biases (up to 56 channels)
    for (int i = 0; i < MAX_OUTPUT_CHANNELS && i < g_config.out_channels; i++) {
        cfu_write(4, proj_bias[i]);
    }
}

//------------------------------------------------------------------------------
// Start Computation
//------------------------------------------------------------------------------
void cfu_dsc_start(void) {
    cfu_execute(7, 0, 0);  // Start command
}

//------------------------------------------------------------------------------
// Wait for Completion (blocking)
//------------------------------------------------------------------------------
void cfu_dsc_wait_done(void) {
    while (!cfu_dsc_is_done()) {
        // Busy wait - could be replaced with interrupt-based waiting
        __asm__ volatile("nop");
    }
}

//------------------------------------------------------------------------------
// Check if Done (non-blocking)
//------------------------------------------------------------------------------
bool cfu_dsc_is_done(void) {
    uint8_t status = cfu_dsc_get_status();
    return (status == STATUS_DONE) || (status == STATUS_OUTPUT_RDY);
}

//------------------------------------------------------------------------------
// Read Output Channel
//------------------------------------------------------------------------------
int8_t cfu_dsc_read_output(uint8_t channel) {
    int32_t value = cfu_read(channel);
    return (int8_t)(value & 0xFF);
}

//------------------------------------------------------------------------------
// Read All Output Channels
//------------------------------------------------------------------------------
void cfu_dsc_read_all_outputs(int8_t* buffer, uint16_t out_channels) {
    for (uint16_t i = 0; i < out_channels && i < MAX_OUTPUT_CHANNELS; i++) {
        buffer[i] = cfu_dsc_read_output((uint8_t)i);
    }
}

//------------------------------------------------------------------------------
// Get Status
//------------------------------------------------------------------------------
uint8_t cfu_dsc_get_status(void) {
    return (uint8_t)(cfu_status() & 0xF);
}

//------------------------------------------------------------------------------
// Execute Complete DSC Block (High-level API)
//------------------------------------------------------------------------------
int cfu_dsc_execute_dsc_block(const ifmap_buffer_t* ifmap,
                               const weight_buffer_t* exp_weights,
                               const weight_buffer_t* dw_weights,
                               const weight_buffer_t* proj_weights,
                               const cfu_dsc_config_t* config,
                               int8_t* output_buffer) {
    // Validate inputs
    if (!ifmap || !exp_weights || !dw_weights || !proj_weights || !config || !output_buffer) {
        return -1;  // Invalid parameters
    }

    if (!g_initialized) {
        cfu_dsc_init();
    }

    // Configure accelerator
    cfu_dsc_configure(config);

    // Load input feature map
    uint32_t ifmap_size = ifmap->height * ifmap->width * ifmap->channels;
    cfu_dsc_load_ifmap(ifmap->data, ifmap_size);

    // Load expansion weights (1x1 conv: N -> M)
    cfu_dsc_load_expansion_weights(exp_weights->data,
                                    config->exp_channels,
                                    config->in_channels);

    // Load depthwise weights (3x3 conv, depthwise)
    cfu_dsc_load_depthwise_weights(dw_weights->data,
                                    config->exp_channels);

    // Load projection weights (1x1 conv: M -> N)
    cfu_dsc_load_projection_weights(proj_weights->data,
                                     config->out_channels,
                                     config->exp_channels);

    // Load biases
    cfu_dsc_load_bias(&config->exp_bias,
                      &config->dw_bias,
                      config->proj_bias);

    // Start computation
    cfu_dsc_start();

    // Wait for completion
    cfu_dsc_wait_done();

    // Read outputs
    cfu_dsc_read_all_outputs(output_buffer, config->out_channels);

    return 0;  // Success
}
