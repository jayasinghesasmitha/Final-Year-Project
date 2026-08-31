// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmnv2_depthwise_cfu.h for the primary calling header

#include "Vmnv2_depthwise_cfu__pch.h"
#include "Vmnv2_depthwise_cfu__Syms.h"
#include "Vmnv2_depthwise_cfu___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmnv2_depthwise_cfu___024root___dump_triggers__stl(Vmnv2_depthwise_cfu___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmnv2_depthwise_cfu___024root___eval_triggers__stl(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmnv2_depthwise_cfu___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
