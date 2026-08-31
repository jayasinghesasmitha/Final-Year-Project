#ifndef MNV2_DEPTHWISE_H
#define MNV2_DEPTHWISE_H
#include <stdint.h>

#define MNV2_LOAD_IFMAP 0
#define MNV2_LOAD_EXP_W 1
#define MNV2_LOAD_DW_W 2
#define MNV2_LOAD_PROJ_W 3
#define MNV2_START 4
#define MNV2_STATUS 5
#define MNV2_READ_OUTPUT 6

#define MNV2_H 4
#define MNV2_W 4
#define MNV2_CIN 8
#define MNV2_CEXP 24
#define MNV2_COUT 16

#define MNV2_IFMAP_N (MNV2_H*MNV2_W*MNV2_CIN)
#define MNV2_EXP_W_N (MNV2_CEXP*MNV2_CIN)
#define MNV2_DW_W_N (MNV2_CEXP*9)
#define MNV2_PROJ_W_N (MNV2_COUT*MNV2_CEXP)
#define MNV2_OUT_N (MNV2_H*MNV2_W*MNV2_COUT)

uint32_t mnv2_cfu_call(uint32_t function_id, uint32_t input0, uint32_t input1);
void mnv2_load_ifmap(uint32_t address, int8_t value);
void mnv2_load_expansion_weight(uint32_t address, int8_t value);
void mnv2_load_depthwise_weight(uint32_t address, int8_t value);
void mnv2_load_projection_weight(uint32_t address, int8_t value);
void mnv2_start(void);
uint32_t mnv2_status(void);
int32_t mnv2_read_output(uint32_t address);

#endif
