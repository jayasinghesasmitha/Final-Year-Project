// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcfu.h for the primary calling header

#include "Vcfu__pch.h"
#include "Vcfu__Syms.h"
#include "Vcfu___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcfu___024root___dump_triggers__ico(Vcfu___024root* vlSelf);
#endif  // VL_DEBUG

void Vcfu___024root___eval_triggers__ico(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vcfu___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcfu___024root___dump_triggers__act(Vcfu___024root* vlSelf);
#endif  // VL_DEBUG

void Vcfu___024root___eval_triggers__act(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vcfu___024root___dump_triggers__act(vlSelf);
    }
#endif
}
