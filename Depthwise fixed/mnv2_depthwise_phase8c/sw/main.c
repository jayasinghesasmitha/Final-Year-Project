#include "mnv2_depthwise.h"

volatile uint32_t mnv2_result = 0;

int main(void)
{
    uint32_t i;

    for (i = 0; i < MNV2_IFMAP_N; ++i)
        mnv2_load_ifmap(i, 1);

    for (i = 0; i < MNV2_EXP_W_N; ++i)
        mnv2_load_expansion_weight(i, 1);

    for (i = 0; i < MNV2_DW_W_N; ++i)
        mnv2_load_depthwise_weight(i, ((i % 9) == 4) ? 1 : 0);

    for (i = 0; i < MNV2_PROJ_W_N; ++i)
        mnv2_load_projection_weight(i, 1);

    mnv2_start();

    while (mnv2_status() & 1u)
        ;

    for (i = 0; i < MNV2_OUT_N; ++i) {
        if (mnv2_read_output(i) != 192) {
            mnv2_result = 0xBAD00000u | i;
            return 1;
        }
    }

    mnv2_result = 0x60000000u;
    return 0;
}
