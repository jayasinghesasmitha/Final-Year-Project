// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCFU__SYMS_H_
#define VERILATED_VCFU__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vcfu.h"

// INCLUDE MODULE CLASSES
#include "Vcfu___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vcfu__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vcfu* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vcfu___024root                 TOP;

    // CONSTRUCTORS
    Vcfu__Syms(VerilatedContext* contextp, const char* namep, Vcfu* modelp);
    ~Vcfu__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
