#ifndef CFU_INSTRUCTION_H
#define CFU_INSTRUCTION_H

#include <stdint.h>

/* RISC-V custom-0 opcode: 0001011 */
#define CFU_OPCODE 0x0B

#define CFU_LOAD_IFMAP  0
#define CFU_LOAD_EXP_W  1
#define CFU_LOAD_DW_W   2
#define CFU_LOAD_PROJ_W 3
#define CFU_START       4
#define CFU_STATUS      5
#define CFU_READ_OUTPUT 6

/*
 * funct7 is used as the CFU function ID.
 * funct3 = 000, opcode = custom-0.
 */
#define CFU_INSN(FUNCT7) \
    ".insn r 0x0B, 0, " #FUNCT7 ", %0, %1, %2"

static inline uint32_t cfu_call(uint32_t fn, uint32_t a, uint32_t b)
{
    uint32_t r = 0;
    switch (fn) {
    case CFU_LOAD_IFMAP:
        __asm__ volatile (CFU_INSN(0) : "=r"(r) : "r"(a), "r"(b));
        break;
    case CFU_LOAD_EXP_W:
        __asm__ volatile (CFU_INSN(1) : "=r"(r) : "r"(a), "r"(b));
        break;
    case CFU_LOAD_DW_W:
        __asm__ volatile (CFU_INSN(2) : "=r"(r) : "r"(a), "r"(b));
        break;
    case CFU_LOAD_PROJ_W:
        __asm__ volatile (CFU_INSN(3) : "=r"(r) : "r"(a), "r"(b));
        break;
    case CFU_START:
        __asm__ volatile (CFU_INSN(4) : "=r"(r) : "r"(a), "r"(b));
        break;
    case CFU_STATUS:
        __asm__ volatile (CFU_INSN(5) : "=r"(r) : "r"(a), "r"(b));
        break;
    case CFU_READ_OUTPUT:
        __asm__ volatile (CFU_INSN(6) : "=r"(r) : "r"(a), "r"(b));
        break;
    default:
        break;
    }
    return r;
}

#endif
