#ifndef MNV2_DEPTHWISE_H
#define MNV2_DEPTHWISE_H

#include <stdint.h>

/*
 * Standalone software API for the Phase-6 CFU.
 *
 * In a real RISC-V build, these wrappers are implemented with the CUSTOM0
 * instruction. The function ID maps directly to the CFU function_id field.
 */

#define MNV2_F_LOAD_IFMAP       0
#define MNV2_F_LOAD_EXP_WEIGHT  1
#define MNV2_F_LOAD_DW_WEIGHT   2
#define MNV2_F_LOAD_PROJ_WEIGHT 3
#define MNV2_F_START            4
#define MNV2_F_STATUS           5
#define MNV2_F_READ_OUTPUT      6

uint32_t mnv2_cfu_op(uint32_t funct3, uint32_t rs1, uint32_t rs2);

static inline void mnv2_load_ifmap(uint32_t addr, int8_t value) {
    (void)mnv2_cfu_op(MNV2_F_LOAD_IFMAP, addr, (uint8_t)value);
}

static inline void mnv2_load_exp_weight(uint32_t addr, int8_t value) {
    (void)mnv2_cfu_op(MNV2_F_LOAD_EXP_WEIGHT, addr, (uint8_t)value);
}

static inline void mnv2_load_dw_weight(uint32_t addr, int8_t value) {
    (void)mnv2_cfu_op(MNV2_F_LOAD_DW_WEIGHT, addr, (uint8_t)value);
}

static inline void mnv2_load_proj_weight(uint32_t addr, int8_t value) {
    (void)mnv2_cfu_op(MNV2_F_LOAD_PROJ_WEIGHT, addr, (uint8_t)value);
}

static inline void mnv2_start(void) {
    (void)mnv2_cfu_op(MNV2_F_START, 0, 0);
}

static inline uint32_t mnv2_status(void) {
    return mnv2_cfu_op(MNV2_F_STATUS, 0, 0);
}

static inline int mnv2_busy(void) {
    return (mnv2_status() & 1u) != 0;
}

static inline int mnv2_done(void) {
    return (mnv2_status() & 2u) != 0;
}

static inline int32_t mnv2_read_output(uint32_t addr) {
    return (int32_t)mnv2_cfu_op(MNV2_F_READ_OUTPUT, addr, 0);
}

#endif
