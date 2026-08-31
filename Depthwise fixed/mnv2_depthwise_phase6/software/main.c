#include <stdint.h>
#include "mnv2_depthwise.h"

/*
 * Phase 6 bare-metal smoke test.
 *
 * This uses the same deterministic data pattern as the verified Phase-4C
 * testbench:
 *   IFMAP = 1
 *   expansion weights = 1
 *   depthwise kernel = center tap = 1, all other taps = 0
 *   projection weights = 1
 *
 * Therefore every output is expected to be 192:
 *   expansion: 8
 *   depthwise: 8
 *   projection: 24 * 8 = 192
 *
 * The actual print/exit mechanism is platform-specific and intentionally
 * omitted here; the return value can be observed by a bare-metal harness.
 */

#define H 4
#define W 4
#define CIN 8
#define CEXP 24
#define COUT 16

#define IFMAP_N (H * W * CIN)
#define EXP_W_N (CEXP * CIN)
#define DW_W_N (CEXP * 9)
#define PROJ_W_N (COUT * CEXP)
#define OUT_N (H * W * COUT)

int main(void) {
    uint32_t i;

    for (i = 0; i < IFMAP_N; ++i)
        mnv2_load_ifmap(i, 1);

    for (i = 0; i < EXP_W_N; ++i)
        mnv2_load_exp_weight(i, 1);

    for (i = 0; i < DW_W_N; ++i)
        mnv2_load_dw_weight(i, (i % 9 == 4) ? 1 : 0);

    for (i = 0; i < PROJ_W_N; ++i)
        mnv2_load_proj_weight(i, 1);

    mnv2_start();

    while (mnv2_busy())
        ;

    for (i = 0; i < OUT_N; ++i) {
        if (mnv2_read_output(i) != 192)
            return 1;
    }

    return 0;
}
