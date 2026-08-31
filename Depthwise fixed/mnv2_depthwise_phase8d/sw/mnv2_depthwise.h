#ifndef MNV2_DEPTHWISE_H
#define MNV2_DEPTHWISE_H

#include <stdint.h>
#include "cfu_instruction.h"

#define H 4
#define W 4
#define CIN 8
#define CEXP 24
#define COUT 16

#define IFMAP_N  (H*W*CIN)
#define EXP_W_N  (CEXP*CIN)
#define DW_W_N   (CEXP*9)
#define PROJ_W_N (COUT*CEXP)
#define OUT_N    (H*W*COUT)

void mnv2_load_ifmap(uint32_t a, int8_t v);
void mnv2_load_expansion_weight(uint32_t a, int8_t v);
void mnv2_load_depthwise_weight(uint32_t a, int8_t v);
void mnv2_load_projection_weight(uint32_t a, int8_t v);
void mnv2_start(void);
uint32_t mnv2_status(void);
int32_t mnv2_read_output(uint32_t a);

#endif
