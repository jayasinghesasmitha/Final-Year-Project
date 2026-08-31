#include "mnv2_depthwise.h"

/*
 * Phase 8 software abstraction.
 * The body is intentionally isolated so the actual RISC-V custom
 * instruction implementation can replace it without changing main.c.
 */
uint32_t mnv2_cfu_call(uint32_t function_id, uint32_t input0, uint32_t input1)
{
    (void)function_id;
    (void)input0;
    (void)input1;
    return 0;
}

void mnv2_load_ifmap(uint32_t a, int8_t v) {
    mnv2_cfu_call(MNV2_LOAD_IFMAP, a, (uint32_t)(int32_t)v);
}
void mnv2_load_expansion_weight(uint32_t a, int8_t v) {
    mnv2_cfu_call(MNV2_LOAD_EXP_W, a, (uint32_t)(int32_t)v);
}
void mnv2_load_depthwise_weight(uint32_t a, int8_t v) {
    mnv2_cfu_call(MNV2_LOAD_DW_W, a, (uint32_t)(int32_t)v);
}
void mnv2_load_projection_weight(uint32_t a, int8_t v) {
    mnv2_cfu_call(MNV2_LOAD_PROJ_W, a, (uint32_t)(int32_t)v);
}
void mnv2_start(void) { mnv2_cfu_call(MNV2_START, 0, 0); }
uint32_t mnv2_status(void) { return mnv2_cfu_call(MNV2_STATUS, 0, 0); }
int32_t mnv2_read_output(uint32_t a) {
    return (int32_t)mnv2_cfu_call(MNV2_READ_OUTPUT, a, 0);
}
