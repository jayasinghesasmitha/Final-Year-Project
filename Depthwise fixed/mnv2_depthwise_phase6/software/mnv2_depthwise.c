#include "mnv2_depthwise.h"

/*
 * RV32 CUSTOM0 encoding.
 *
 * CFU-Playground uses CUSTOM0 and the 3-bit funct3 field as the function ID.
 * This standalone implementation uses inline assembly so the software side
 * can later be connected to the same RISC-V toolchain/SoC used for Renode.
 *
 * funct7 is kept at zero for Phase 6; it remains available for future
 * sub-operations without changing the top-level API.
 */
uint32_t mnv2_cfu_op(uint32_t funct3, uint32_t rs1, uint32_t rs2) {
    uint32_t result;

    switch (funct3) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            __asm__ volatile (
                ".insn r 0x0b, %1, 0, %2, %3, 0"
                : "=r"(result)
                : "i"(funct3), "r"(rs1), "r"(rs2)
                : "memory"
            );
            return result;

        default:
            return 0;
    }
}
