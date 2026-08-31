#include <stdint.h>
#include "mnv2_depthwise.h"

/*
 * Renode LiteX UART
 *
 * Register map:
 *   +0x00 : TX data
 *   +0x04 : status/control
 *
 * Bit 0 of the status register indicates that the TX FIFO is full.
 */
#define UART_BASE       0x40008000u
#define UART_DATA       0x00u
#define UART_STATUS     0x04u
#define UART_TX_FULL    0x01u


static void putc(char c)
{
    volatile uint32_t *data =
        (volatile uint32_t *)(UART_BASE + UART_DATA);

    volatile uint32_t *status =
        (volatile uint32_t *)(UART_BASE + UART_STATUS);

    /*
     * Wait until the UART TX FIFO has space.
     */
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


int main(void)
{
    uint32_t i;
    uint32_t status;

    puts_("\nMNv2 Depthwise Phase 8D\n");

    puts_("Loading IFMAP...\n");

    for (i = 0; i < IFMAP_N; ++i)
        mnv2_load_ifmap(i, 1);


    puts_("Loading expansion weights...\n");

    for (i = 0; i < EXP_W_N; ++i)
        mnv2_load_expansion_weight(i, 1);


    puts_("Loading depthwise weights...\n");

    for (i = 0; i < DW_W_N; ++i) {

        mnv2_load_depthwise_weight(
            i,
            ((i % 9) == 4) ? 1 : 0
        );
    }


    puts_("Loading projection weights...\n");

    for (i = 0; i < PROJ_W_N; ++i)
        mnv2_load_projection_weight(i, 1);


    puts_("Starting accelerator...\n");

    mnv2_start();


    /*
     * Wait until accelerator is no longer busy.
     *
     * STATUS:
     *   bit 0 = busy
     *   bit 1 = done
     */
    do {
        status = mnv2_status();
    } while (status & 1u);


    puts_("Checking outputs...\n");


    for (i = 0; i < OUT_N; ++i) {

        int32_t v = mnv2_read_output(i);

        if (v != 192) {

            puts_("FAIL output ");
            print_u32(i);

            puts_(" expected 192 got ");
            print_u32((uint32_t)v);

            puts_("\n");

            return 1;
        }
    }


    puts_("PHASE8D PASS\n");
    puts_("RISC-V custom-0 CFU path verified.\n");

    return 0;
}