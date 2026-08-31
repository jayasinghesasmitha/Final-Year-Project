#include <stdint.h>
#include "mnv2_depthwise.h"

#define UART_BASE       0xf0003000u
#define UART_DATA       0x00u
#define UART_STATUS     0x04u
#define UART_TX_FULL    0x01u

#define H       4
#define W       4
#define CIN     8
#define CEXP    24
#define COUT    16

#define SPATIAL_COUNT   (H * W)
#define OUTPUT_COUNT    (SPATIAL_COUNT * COUT)


static void putc(char c)
{
    volatile uint32_t *data =
        (volatile uint32_t *)(UART_BASE + UART_DATA);

    volatile uint32_t *status =
        (volatile uint32_t *)(UART_BASE + UART_STATUS);

    while ((*status) & UART_TX_FULL)
        ;

    *data = (uint32_t)(uint8_t)c;
}


static void puts_(const char *s)
{
    while (*s)
        putc(*s++);
}


static void print_u32(uint32_t x)
{
    char b[11];
    int n = 0;

    if (x == 0) {
        putc('0');
        return;
    }

    while (x && n < 10) {
        b[n++] = (char)('0' + (x % 10));
        x /= 10;
    }

    while (n)
        putc(b[--n]);
}


/*
 * Return the expected output for one spatial position.
 *
 * All IFMAP and weights are 1.
 *
 * Expansion:
 *
 *     8 input channels
 *
 * Depthwise:
 *
 *     valid 3x3 neighbours
 *
 * Projection:
 *
 *     24 expansion channels
 *
 * Therefore:
 *
 *     output = 8 * valid_neighbors * 24
 *            = 192 * valid_neighbors
 */
static uint32_t expected_output(uint32_t spatial)
{
    uint32_t row = spatial / W;
    uint32_t col = spatial % W;

    uint32_t valid_neighbors = 0;

    for (int kr = -1; kr <= 1; ++kr) {

        for (int kc = -1; kc <= 1; ++kc) {

            int rr = (int)row + kr;
            int cc = (int)col + kc;

            if (rr >= 0 && rr < H &&
                cc >= 0 && cc < W) {

                valid_neighbors++;
            }
        }
    }

    return 192u * valid_neighbors;
}


int main(void)
{
    uint32_t i;
    uint32_t status;

    puts_("\n");
    puts_("MNv2 Depthwise Phase 10\n");


    /*
     * ============================================================
     * LOAD IFMAP
     * ============================================================
     */

    puts_("Loading IFMAP...\n");

    for (i = 0; i < IFMAP_N; ++i)
        mnv2_load_ifmap(i, 1);


    /*
     * ============================================================
     * LOAD EXPANSION WEIGHTS
     * ============================================================
     */

    puts_("Loading expansion weights...\n");

    for (i = 0; i < EXP_W_N; ++i)
        mnv2_load_expansion_weight(i, 1);


    /*
     * ============================================================
     * LOAD DEPTHWISE WEIGHTS
     * ============================================================
     *
     * Every depthwise weight = 1.
     */

    puts_("Loading depthwise weights...\n");

    for (i = 0; i < DW_W_N; ++i)
        mnv2_load_depthwise_weight(i, 1);


    /*
     * ============================================================
     * LOAD PROJECTION WEIGHTS
     * ============================================================
     */

    puts_("Loading projection weights...\n");

    for (i = 0; i < PROJ_W_N; ++i)
        mnv2_load_projection_weight(i, 1);


    /*
     * ============================================================
     * START
     * ============================================================
     */

    puts_("Starting accelerator...\n");

    mnv2_start();


    /*
     * ============================================================
     * WAIT FOR COMPLETION
     * ============================================================
     */

    puts_("Waiting for accelerator...\n");

    do {
        status = mnv2_status();
    } while (status & 1u);


    /*
     * ============================================================
     * CHECK DONE
     * ============================================================
     */

    status = mnv2_status();

    if (!(status & 2u)) {

        puts_("FAIL: accelerator finished without DONE\n");

        return 1;
    }


    puts_("Accelerator DONE.\n");
    puts_("Checking outputs...\n");


    /*
     * ============================================================
     * VERIFY OUTPUTS
     * ============================================================
     */

    for (i = 0; i < OUTPUT_COUNT; ++i) {

        uint32_t spatial = i / COUT;

        int32_t actual =
            mnv2_read_output(i);

        uint32_t expected =
            expected_output(spatial);


        if (actual != (int32_t)expected) {

            puts_("FAIL output ");

            print_u32(i);

            puts_(" spatial ");

            print_u32(spatial);

            puts_(" expected ");

            print_u32(expected);

            puts_(" got ");

            print_u32((uint32_t)actual);

            puts_("\n");

            return 1;
        }
    }


    /*
     * ============================================================
     * PASS
     * ============================================================
     */

    puts_("PHASE10 PASS\n");
    puts_("RISC-V -> Renode -> CFU -> RTL verified.\n");

    return 0;
}