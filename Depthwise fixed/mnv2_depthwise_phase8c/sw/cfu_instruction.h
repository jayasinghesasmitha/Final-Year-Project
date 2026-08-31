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
 * RISC-V custom-0 R-format:
 * opcode=0x0B, funct3=0, funct7=function ID.
 */
#define CFU_CALL(FN, OUT, A, B) \
    __asm__ volatile (".insn r 0x0B, 0, " #FN ", %0, %1, %2" \
                      : "=r"(OUT) : "r"(A), "r"(B))

static inline uint32_t cfu_call(uint32_t fn, uint32_t a, uint32_t b)
{
    uint32_t out = 0;
    switch(fn) {
    case 0: CFU_CALL(0,out,a,b); break;
    case 1: CFU_CALL(1,out,a,b); break;
    case 2: CFU_CALL(2,out,a,b); break;
    case 3: CFU_CALL(3,out,a,b); break;
    case 4: CFU_CALL(4,out,a,b); break;
    case 5: CFU_CALL(5,out,a,b); break;
    case 6: CFU_CALL(6,out,a,b); break;
    default: break;
    }
    return out;
}
#endif
