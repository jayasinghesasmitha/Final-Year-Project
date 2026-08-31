#ifndef CFU_INSTRUCTION_H
#define CFU_INSTRUCTION_H
#include <stdint.h>

#define CFU_LOAD_IFMAP  0
#define CFU_LOAD_EXP_W  1
#define CFU_LOAD_DW_W   2
#define CFU_LOAD_PROJ_W 3
#define CFU_START       4
#define CFU_STATUS      5
#define CFU_READ_OUTPUT 6

/*
 * Phase 8B software/custom-instruction boundary.
 * The exact CFU implementation is isolated here.
 */
static inline uint32_t cfu_call(uint32_t function_id,
                                uint32_t input0,
                                uint32_t input1)
{
    uint32_t result = 0;

    switch (function_id) {
    case CFU_LOAD_IFMAP:
        __asm__ volatile(".insn r 0x0B, 0, 0, %0, %1, %2"
                         : "=r"(result) : "r"(input0), "r"(input1));
        break;
    case CFU_LOAD_EXP_W:
        __asm__ volatile(".insn r 0x0B, 0, 1, %0, %1, %2"
                         : "=r"(result) : "r"(input0), "r"(input1));
        break;
    case CFU_LOAD_DW_W:
        __asm__ volatile(".insn r 0x0B, 0, 2, %0, %1, %2"
                         : "=r"(result) : "r"(input0), "r"(input1));
        break;
    case CFU_LOAD_PROJ_W:
        __asm__ volatile(".insn r 0x0B, 0, 3, %0, %1, %2"
                         : "=r"(result) : "r"(input0), "r"(input1));
        break;
    case CFU_START:
        __asm__ volatile(".insn r 0x0B, 0, 4, %0, %1, %2"
                         : "=r"(result) : "r"(input0), "r"(input1));
        break;
    case CFU_STATUS:
        __asm__ volatile(".insn r 0x0B, 0, 5, %0, %1, %2"
                         : "=r"(result) : "r"(input0), "r"(input1));
        break;
    case CFU_READ_OUTPUT:
        __asm__ volatile(".insn r 0x0B, 0, 6, %0, %1, %2"
                         : "=r"(result) : "r"(input0), "r"(input1));
        break;
    default:
        break;
    }
    return result;
}
#endif
