#include "mnv2_depthwise.h"

void mnv2_load_ifmap(uint32_t a,int8_t v)
{ cfu_call(CFU_LOAD_IFMAP,a,(uint32_t)(int32_t)v); }

void mnv2_load_expansion_weight(uint32_t a,int8_t v)
{ cfu_call(CFU_LOAD_EXP_W,a,(uint32_t)(int32_t)v); }

void mnv2_load_depthwise_weight(uint32_t a,int8_t v)
{ cfu_call(CFU_LOAD_DW_W,a,(uint32_t)(int32_t)v); }

void mnv2_load_projection_weight(uint32_t a,int8_t v)
{ cfu_call(CFU_LOAD_PROJ_W,a,(uint32_t)(int32_t)v); }

void mnv2_start(void)
{ cfu_call(CFU_START,0,0); }

uint32_t mnv2_status(void)
{ return cfu_call(CFU_STATUS,0,0); }

int32_t mnv2_read_output(uint32_t a)
{ return (int32_t)cfu_call(CFU_READ_OUTPUT,a,0); }
