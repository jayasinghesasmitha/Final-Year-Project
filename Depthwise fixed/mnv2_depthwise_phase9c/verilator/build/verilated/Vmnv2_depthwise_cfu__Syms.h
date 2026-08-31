// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMNV2_DEPTHWISE_CFU__SYMS_H_
#define VERILATED_VMNV2_DEPTHWISE_CFU__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vmnv2_depthwise_cfu.h"

// INCLUDE MODULE CLASSES
#include "Vmnv2_depthwise_cfu___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vmnv2_depthwise_cfu__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vmnv2_depthwise_cfu* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vmnv2_depthwise_cfu___024root  TOP;

    // CONSTRUCTORS
    Vmnv2_depthwise_cfu__Syms(VerilatedContext* contextp, const char* namep, Vmnv2_depthwise_cfu* modelp);
    ~Vmnv2_depthwise_cfu__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
