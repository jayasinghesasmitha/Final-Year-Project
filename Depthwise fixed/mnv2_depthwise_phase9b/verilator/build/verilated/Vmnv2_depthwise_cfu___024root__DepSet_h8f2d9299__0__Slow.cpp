// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmnv2_depthwise_cfu.h for the primary calling header

#include "Vmnv2_depthwise_cfu__pch.h"
#include "Vmnv2_depthwise_cfu___024root.h"

VL_ATTR_COLD void Vmnv2_depthwise_cfu___024root___eval_static(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vmnv2_depthwise_cfu___024root___eval_initial(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vmnv2_depthwise_cfu___024root___eval_final(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmnv2_depthwise_cfu___024root___dump_triggers__stl(Vmnv2_depthwise_cfu___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vmnv2_depthwise_cfu___024root___eval_phase__stl(Vmnv2_depthwise_cfu___024root* vlSelf);

VL_ATTR_COLD void Vmnv2_depthwise_cfu___024root___eval_settle(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vmnv2_depthwise_cfu___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/sasmitha-jayasinghe/Documents/github/depthwsie/mnv2_depthwise_phase9b/verilator/../rtl/mnv2_depthwise_cfu.v", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vmnv2_depthwise_cfu___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmnv2_depthwise_cfu___024root___dump_triggers__stl(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vmnv2_depthwise_cfu___024root___ico_sequent__TOP__0(Vmnv2_depthwise_cfu___024root* vlSelf);

VL_ATTR_COLD void Vmnv2_depthwise_cfu___024root___eval_stl(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vmnv2_depthwise_cfu___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vmnv2_depthwise_cfu___024root___eval_triggers__stl(Vmnv2_depthwise_cfu___024root* vlSelf);

VL_ATTR_COLD bool Vmnv2_depthwise_cfu___024root___eval_phase__stl(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vmnv2_depthwise_cfu___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vmnv2_depthwise_cfu___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmnv2_depthwise_cfu___024root___dump_triggers__ico(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmnv2_depthwise_cfu___024root___dump_triggers__act(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmnv2_depthwise_cfu___024root___dump_triggers__nba(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmnv2_depthwise_cfu___024root___ctor_var_reset(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->cmd_valid = VL_RAND_RESET_I(1);
    vlSelf->cmd_ready = VL_RAND_RESET_I(1);
    vlSelf->cmd_payload_function_id = VL_RAND_RESET_I(3);
    vlSelf->cmd_payload_inputs_0 = VL_RAND_RESET_I(32);
    vlSelf->cmd_payload_inputs_1 = VL_RAND_RESET_I(32);
    vlSelf->rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->rsp_payload_outputs_0 = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__busy = VL_RAND_RESET_I(1);
    vlSelf->mnv2_depthwise_cfu__DOT__done = VL_RAND_RESET_I(1);
    vlSelf->mnv2_depthwise_cfu__DOT__start = VL_RAND_RESET_I(1);
    vlSelf->mnv2_depthwise_cfu__DOT__ifmap_wr_en = VL_RAND_RESET_I(1);
    vlSelf->mnv2_depthwise_cfu__DOT__ifmap_wr_addr = VL_RAND_RESET_I(7);
    vlSelf->mnv2_depthwise_cfu__DOT__ifmap_wr_data = VL_RAND_RESET_I(8);
    vlSelf->mnv2_depthwise_cfu__DOT__exp_wr_en = VL_RAND_RESET_I(1);
    vlSelf->mnv2_depthwise_cfu__DOT__exp_wr_addr = VL_RAND_RESET_I(8);
    vlSelf->mnv2_depthwise_cfu__DOT__exp_wr_data = VL_RAND_RESET_I(8);
    vlSelf->mnv2_depthwise_cfu__DOT__dw_wr_en = VL_RAND_RESET_I(1);
    vlSelf->mnv2_depthwise_cfu__DOT__dw_wr_addr = VL_RAND_RESET_I(8);
    vlSelf->mnv2_depthwise_cfu__DOT__dw_wr_data = VL_RAND_RESET_I(8);
    vlSelf->mnv2_depthwise_cfu__DOT__proj_wr_en = VL_RAND_RESET_I(1);
    vlSelf->mnv2_depthwise_cfu__DOT__proj_wr_addr = VL_RAND_RESET_I(9);
    vlSelf->mnv2_depthwise_cfu__DOT__proj_wr_data = VL_RAND_RESET_I(8);
    vlSelf->mnv2_depthwise_cfu__DOT__out_rd_addr = VL_RAND_RESET_I(8);
    vlSelf->mnv2_depthwise_cfu__DOT__read_pending = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__ifmap_mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 192; ++__Vi0) {
        vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_w_mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 216; ++__Vi0) {
        vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_w_mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 384; ++__Vi0) {
        vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_w_mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 384; ++__Vi0) {
        vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 384; ++__Vi0) {
        vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__row_cnt = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__col_cnt = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__out_ch = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_ch = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_acc_reg = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_acc_reg = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_acc_reg = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__rr = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__cc = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__if_idx = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_idx = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_idx = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_idx = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__out_idx = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__neigh_idx = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__product = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_h50c84ad7__0 = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_hfc1f09b4__0 = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_hc52db093__0 = VL_RAND_RESET_I(8);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_hc4d36ef5__0 = VL_RAND_RESET_I(8);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_hf9dfa5c7__0 = VL_RAND_RESET_I(8);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_h5c35e5fd__0 = VL_RAND_RESET_I(32);
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_h9a256d64__0 = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
}
