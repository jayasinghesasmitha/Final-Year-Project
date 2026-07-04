// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcfu.h for the primary calling header

#include "Vcfu__pch.h"
#include "Vcfu___024root.h"

VL_ATTR_COLD void Vcfu___024root___eval_static__TOP(Vcfu___024root* vlSelf);

VL_ATTR_COLD void Vcfu___024root___eval_static(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_static\n"); );
    // Body
    Vcfu___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vcfu___024root___eval_static__TOP(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->Cfu__DOT__fsm_state = 0U;
    vlSelf->Cfu__DOT__stored_function_id = 0U;
    vlSelf->Cfu__DOT__stored_output = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__FIFO_r_rdy = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__consume = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_level = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__f7buf__DOT__captured = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_data = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_mem_addr = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_restart = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_data = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_mem_addr = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_restart = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_data = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_mem_addr = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_restart = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_data = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_mem_addr = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_restart = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__last_full = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_0 = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_1 = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins_r_ready = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_data = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_mem_addr = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_restart = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_data = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_mem_addr = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_restart = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_data = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_mem_addr = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_restart = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_data = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_mem_addr = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_restart = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT__waiting = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02419 = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02429 = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__0249 = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02412 = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02422 = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02432 = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__madd_result = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__mark_read_set = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__value = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT__waiting = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_shifted = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_1 = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_2 = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_3 = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__ab = 0ULL;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__areg = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__breg = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__overflow = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm_result = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__madd_delay__DOT__shift_register = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_value = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_value = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_set = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_value = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_value = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__value = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_output_depth__DOT__value = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_output_offset_value = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__start_run_set = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__value = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc__DOT__last_addr = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_count = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc__DOT__last_addr = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_count = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc__DOT__last_addr = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_count = 0U;
}

VL_ATTR_COLD void Vcfu___024root___eval_initial__TOP(Vcfu___024root* vlSelf);

VL_ATTR_COLD void Vcfu___024root___eval_initial(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_initial\n"); );
    // Body
    Vcfu___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vcfu___024root___eval_initial__TOP__0(Vcfu___024root* vlSelf);
VL_ATTR_COLD void Vcfu___024root___eval_initial__TOP__1(Vcfu___024root* vlSelf);

VL_ATTR_COLD void Vcfu___024root___eval_initial__TOP(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_initial__TOP\n"); );
    // Init
    IData/*31:0*/ __Vilp;
    // Body
    Vcfu___024root___eval_initial__TOP__0(vlSelf);
    Vcfu___024root___eval_initial__TOP__1(vlSelf);
    __Vilp = 0U;
    while ((__Vilp <= 0x1ffU)) {
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT__mem[__Vilp] = 0U;
        __Vilp = ((IData)(1U) + __Vilp);
    }
    __Vilp = 0U;
    while ((__Vilp <= 0x1ffU)) {
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT__mem[__Vilp] = 0U;
        __Vilp = ((IData)(1U) + __Vilp);
    }
    __Vilp = 0U;
    while ((__Vilp <= 0x1ffU)) {
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT__mem[__Vilp] = 0U;
        __Vilp = ((IData)(1U) + __Vilp);
    }
    __Vilp = 0U;
    while ((__Vilp <= 0x1ffU)) {
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT__mem[__Vilp] = 0U;
        __Vilp = ((IData)(1U) + __Vilp);
    }
    __Vilp = 0U;
    while ((__Vilp <= 0x1ffU)) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT__mem[__Vilp] = 0U;
        __Vilp = ((IData)(1U) + __Vilp);
    }
    __Vilp = 0U;
    while ((__Vilp <= 0x1ffU)) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT__mem[__Vilp] = 0U;
        __Vilp = ((IData)(1U) + __Vilp);
    }
    __Vilp = 0U;
    while ((__Vilp <= 0x1ffU)) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT__mem[__Vilp] = 0U;
        __Vilp = ((IData)(1U) + __Vilp);
    }
}

VL_ATTR_COLD void Vcfu___024root___eval_initial__TOP__0(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_initial__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vilp;
    // Body
    __Vilp = 0U;
    while ((__Vilp <= 0x1feU)) {
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__storage[__Vilp] = 0U;
        __Vilp = ((IData)(1U) + __Vilp);
    }
    __Vilp = 0U;
    while ((__Vilp <= 0x3ffU)) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem[__Vilp] = 0U;
        __Vilp = ((IData)(1U) + __Vilp);
    }
    __Vilp = 0U;
    while ((__Vilp <= 0x3ffU)) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT__mem[__Vilp] = 0U;
        __Vilp = ((IData)(1U) + __Vilp);
    }
    __Vilp = 0U;
    while ((__Vilp <= 0x3ffU)) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT__mem[__Vilp] = 0U;
        __Vilp = ((IData)(1U) + __Vilp);
    }
    __Vilp = 0U;
    while ((__Vilp <= 0x1a0U)) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem[__Vilp] = 0U;
        __Vilp = ((IData)(1U) + __Vilp);
    }
}

VL_ATTR_COLD void Vcfu___024root___eval_initial__TOP__1(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_initial__TOP__1\n"); );
    // Init
    IData/*31:0*/ __Vilp;
    // Body
    __Vilp = 0x1a1U;
    while ((__Vilp <= 0x3ffU)) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem[__Vilp] = 0U;
        __Vilp = ((IData)(1U) + __Vilp);
    }
}

VL_ATTR_COLD void Vcfu___024root___eval_final(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcfu___024root___dump_triggers__stl(Vcfu___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vcfu___024root___eval_phase__stl(Vcfu___024root* vlSelf);

VL_ATTR_COLD void Vcfu___024root___eval_settle(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_settle\n"); );
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
            Vcfu___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/proj/mnv2_first/cfu.v", 6, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vcfu___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcfu___024root___dump_triggers__stl(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*0:0*/, 16> Vcfu__ConstPool__TABLE_hd5e7ca01_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vcfu__ConstPool__TABLE_h226c588b_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vcfu__ConstPool__TABLE_h3f5f8a41_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vcfu__ConstPool__TABLE_h855003bb_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vcfu__ConstPool__TABLE_hac88bb16_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vcfu__ConstPool__TABLE_hda23d5a5_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vcfu__ConstPool__TABLE_h70b41e53_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vcfu__ConstPool__TABLE_h7c969f7e_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vcfu__ConstPool__TABLE_h3f46fc78_0;

VL_ATTR_COLD void Vcfu___024root___stl_sequent__TOP__0(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ Cfu__DOT__fn0_done;
    Cfu__DOT__fn0_done = 0;
    CData/*6:0*/ Cfu__DOT__fn0__DOT__f7buf_output;
    Cfu__DOT__fn0__DOT__f7buf_output = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__ins_set_done;
    Cfu__DOT__fn0__DOT__ins_set_done = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__ins_set_start;
    Cfu__DOT__fn0__DOT__ins_set_start = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__ins_set_w_en;
    Cfu__DOT__fn0__DOT__ins_set_w_en = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__mark_read_done;
    Cfu__DOT__fn0__DOT__mark_read_done = 0;
    IData/*31:0*/ Cfu__DOT__fn0__DOT__mark_read_output;
    Cfu__DOT__fn0__DOT__mark_read_output = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__oq_get_done;
    Cfu__DOT__fn0__DOT__oq_get_done = 0;
    IData/*31:0*/ Cfu__DOT__fn0__DOT__oq_get_output;
    Cfu__DOT__fn0__DOT__oq_get_output = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__oq_get_start;
    Cfu__DOT__fn0__DOT__oq_get_start = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__set_activation_max_done;
    Cfu__DOT__fn0__DOT__set_activation_max_done = 0;
    IData/*31:0*/ Cfu__DOT__fn0__DOT__set_activation_max_output;
    Cfu__DOT__fn0__DOT__set_activation_max_output = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__set_activation_min_done;
    Cfu__DOT__fn0__DOT__set_activation_min_done = 0;
    IData/*31:0*/ Cfu__DOT__fn0__DOT__set_activation_min_output;
    Cfu__DOT__fn0__DOT__set_activation_min_output = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__set_input_depth_words_done;
    Cfu__DOT__fn0__DOT__set_input_depth_words_done = 0;
    IData/*31:0*/ Cfu__DOT__fn0__DOT__set_input_depth_words_output;
    Cfu__DOT__fn0__DOT__set_input_depth_words_output = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__set_input_offset_done;
    Cfu__DOT__fn0__DOT__set_input_offset_done = 0;
    IData/*31:0*/ Cfu__DOT__fn0__DOT__set_input_offset_output;
    Cfu__DOT__fn0__DOT__set_input_offset_output = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__set_output_batch_size_done;
    Cfu__DOT__fn0__DOT__set_output_batch_size_done = 0;
    IData/*31:0*/ Cfu__DOT__fn0__DOT__set_output_batch_size_output;
    Cfu__DOT__fn0__DOT__set_output_batch_size_output = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__set_output_depth_done;
    Cfu__DOT__fn0__DOT__set_output_depth_done = 0;
    IData/*31:0*/ Cfu__DOT__fn0__DOT__set_output_depth_output;
    Cfu__DOT__fn0__DOT__set_output_depth_output = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__set_output_offset_done;
    Cfu__DOT__fn0__DOT__set_output_offset_done = 0;
    IData/*31:0*/ Cfu__DOT__fn0__DOT__set_output_offset_output;
    Cfu__DOT__fn0__DOT__set_output_offset_output = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__start_run_done;
    Cfu__DOT__fn0__DOT__start_run_done = 0;
    IData/*31:0*/ Cfu__DOT__fn0__DOT__start_run_output;
    Cfu__DOT__fn0__DOT__start_run_output = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT____02411;
    Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT____02411 = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT____02411;
    Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT____02411 = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT____02411;
    Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT____02411 = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT____02411;
    Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT____02411 = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT____02411;
    Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT____02411 = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT____02411;
    Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT____02411 = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT____02411;
    Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT____02411 = 0;
    CData/*0:0*/ Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT____02411;
    Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT____02411 = 0;
    IData/*31:0*/ Cfu__DOT__fn0__DOT__pp__DOT__with_offset;
    Cfu__DOT__fn0__DOT__pp__DOT__with_offset = 0;
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*5:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*3:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*2:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    CData/*2:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    CData/*4:0*/ __Vtableidx7;
    __Vtableidx7 = 0;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    // Body
    vlSelf->cmd_ready = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem_w_addr 
        = (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf) 
            << 9U) | (0x1ffU & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr) 
                                >> 2U)));
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_0 = 0U;
    if (VL_GTES_III(32, 0U, vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT___0_)) {
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_0 
            = (0x1fU & (IData)((0x1ffffffffULL & (- 
                                                  VL_EXTENDS_QI(33,32, vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT___0_)))));
    }
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__left_shift = 0U;
    if (VL_LTS_III(32, 0U, vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT___0_)) {
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__left_shift 
            = (0x1fU & vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT___0_);
    }
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count_done = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__acc__DOT____VdfgExtracted_h784e4b37__0 
        = ((IData)((0x1ffffffffULL & VL_EXTENDS_QI(33,32, vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator))) 
           + (IData)((0x1ffffffffULL & VL_EXTENDS_QI(33,32, vlSelf->Cfu__DOT__fn0__DOT__madd_result))));
    Cfu__DOT__fn0__DOT__pp__DOT__with_offset = ((IData)(
                                                        (0x1ffffffffULL 
                                                         & VL_EXTENDS_QI(33,32, vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_shifted))) 
                                                + (IData)(
                                                          (0x1ffffffffULL 
                                                           & VL_EXTENDS_QI(33,32, vlSelf->Cfu__DOT__fn0__DOT__set_output_offset_value))));
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____02440 = 
        ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr) 
         == (0xfffU & ((0x7ffU & vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_value) 
                       - (IData)(1U))));
    Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT____02411 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_next) 
           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_restart));
    Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT____02411 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_next) 
           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_restart));
    Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT____02411 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_next) 
           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_restart));
    Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT____02411 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_next) 
           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_restart));
    Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT____02411 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_next) 
           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_restart));
    Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT____02411 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_next) 
           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_restart));
    Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT____02411 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_next) 
           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_restart));
    Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT____02411 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_next) 
           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_restart));
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT____02412 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count) 
           == (0xfffU & ((0x7ffU & vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_value) 
                         - (IData)(1U))));
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT____02412 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count) 
           == (0x1fffU & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count) 
                          - (IData)(1U))));
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__full = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf)
                                                   ? (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_1)
                                                   : (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_0));
    vlSelf->Cfu__DOT__fn0__DOT__fvf_next = (((IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running) 
                                             | (IData)(vlSelf->Cfu__DOT__fn0__DOT__start_run_set)) 
                                            & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_r_ready) 
                                               & (0x1f8U 
                                                  > 
                                                  (0x3ffU 
                                                   & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_level) 
                                                      + (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO_r_rdy))))));
    vlSelf->Cfu__DOT__fn0__DOT__ins_w_ready = (1U & 
                                               ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf)
                                                 ? 
                                                (~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_1))
                                                 : 
                                                (~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_0))));
    vlSelf->rst = vlSelf->reset;
    vlSelf->Cfu__DOT__current_function_id = 0U;
    if ((8U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register))) {
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count_done 
            = (3U == (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count));
    }
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT____0248 
        = ((0x1ffU != (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_level)) 
           & (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count_done));
    vlSelf->Cfu__DOT__fn0__DOT__acc_result = vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator;
    vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__calc = 0U;
    if ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated)))) {
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0_mem_addr = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1_mem_addr = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2_mem_addr = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3_mem_addr = 0U;
    } else {
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0_mem_addr 
            = (0x1ffU & ((2U == (2U & (((IData)(Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT____02411) 
                                        << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated))))
                          ? (((IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_mem_addr) 
                              == (0x7ffU & ((0x1ffU 
                                             & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count) 
                                                >> 2U)) 
                                            - (IData)(1U))))
                              ? 0U : ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_mem_addr)))
                          : (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_mem_addr)));
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1_mem_addr 
            = (0x1ffU & ((2U == (2U & (((IData)(Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT____02411) 
                                        << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated))))
                          ? (((IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_mem_addr) 
                              == (0x7ffU & ((0x1ffU 
                                             & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count) 
                                                >> 2U)) 
                                            - (IData)(1U))))
                              ? 0U : ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_mem_addr)))
                          : (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_mem_addr)));
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2_mem_addr 
            = (0x1ffU & ((2U == (2U & (((IData)(Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT____02411) 
                                        << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated))))
                          ? (((IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_mem_addr) 
                              == (0x7ffU & ((0x1ffU 
                                             & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count) 
                                                >> 2U)) 
                                            - (IData)(1U))))
                              ? 0U : ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_mem_addr)))
                          : (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_mem_addr)));
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3_mem_addr 
            = (0x1ffU & ((2U == (2U & (((IData)(Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT____02411) 
                                        << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated))))
                          ? (((IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_mem_addr) 
                              == (0x7ffU & ((0x1ffU 
                                             & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count) 
                                                >> 2U)) 
                                            - (IData)(1U))))
                              ? 0U : ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_mem_addr)))
                          : (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_mem_addr)));
    }
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0_data 
        = ((IData)(Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT____02411)
            ? vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT___0_
            : vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_data);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1_data 
        = ((IData)(Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT____02411)
            ? vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT___0_
            : vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_data);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2_data 
        = ((IData)(Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT____02411)
            ? vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT___0_
            : vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_data);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3_data 
        = ((IData)(Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT____02411)
            ? vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT___0_
            : vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_data);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_data 
        = ((IData)(Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT____02411)
            ? vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT___0_
            : vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_data);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_data 
        = ((IData)(Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT____02411)
            ? vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT___0_
            : vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_data);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_data 
        = ((IData)(Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT____02411)
            ? vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT___0_
            : vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_data);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_data 
        = ((IData)(Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT____02411)
            ? vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT___0_
            : vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_data);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count_done = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____02483 = 
        ((~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__last_full)) 
         & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__full));
    __Vtableidx4 = (((IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank) 
                     << 2U) | (((IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set) 
                                << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf_next)));
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_0 
        = Vcfu__ConstPool__TABLE_hd5e7ca01_0[__Vtableidx4];
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_1 
        = Vcfu__ConstPool__TABLE_h226c588b_0[__Vtableidx4];
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_2 
        = Vcfu__ConstPool__TABLE_h3f5f8a41_0[__Vtableidx4];
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_3 
        = Vcfu__ConstPool__TABLE_h855003bb_0[__Vtableidx4];
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____024101 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf_next) 
           & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_r_ready));
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count_done = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____02419 
        = ((~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_w_ready)) 
           & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT__waiting));
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_1__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_0;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_2__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_1;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_3__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_2;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__breg__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT___0_;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_shifted__024next 
        = ((IData)((0x1ffffffffULL & VL_EXTENDS_QI(33,32, 
                                                   VL_SHIFTRS_III(32,32,5, vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm_result, (IData)(vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_3))))) 
           + (IData)((0x1ffffffffULL & VL_EXTENDS_QI(33,32, 
                                                     VL_GTS_IQQ(35, 
                                                                (0x7ffffffffULL 
                                                                 & VL_EXTENDS_QQ(35,34, 
                                                                                (0x1ffffffffULL 
                                                                                & (VL_EXTENDS_QI(34,32, vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm_result) 
                                                                                & ((QData)((IData)(
                                                                                ((IData)(1U) 
                                                                                << (IData)(vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_3)))) 
                                                                                - 1ULL))))), 
                                                                (0x3ffffffffULL 
                                                                 & ((0x1ffffffffULL 
                                                                     & VL_SHIFTR_QQI(33,33,32, 
                                                                                (0x1ffffffffULL 
                                                                                & ((QData)((IData)(
                                                                                ((IData)(1U) 
                                                                                << (IData)(vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_3)))) 
                                                                                - 1ULL)), 1U)) 
                                                                    + (QData)((IData)(
                                                                                (vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm_result 
                                                                                >> 0x1fU))))))))));
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__overflow__024next 
        = ((0x80000000ULL == (0x1ffffffffULL & VL_EXTENDS_QI(33,32, vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__areg))) 
           & (0x80000000ULL == (0x1ffffffffULL & VL_EXTENDS_QI(33,32, vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__breg))));
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__ab__024next 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__areg), 
                      VL_EXTENDS_QI(64,32, vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__breg));
    __Vtemp_2[0U] = 0x40000000U;
    __Vtemp_2[1U] = 0U;
    __Vtemp_2[2U] = 0U;
    VL_EXTENDS_WQ(65,64, __Vtemp_3, vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__ab);
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__result__024next 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__overflow)
            ? 0x7fffffffU : ((__Vtemp_4[1U] << 1U) 
                             | (__Vtemp_4[0U] >> 0x1fU)));
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__madd_delay__DOT__shift_register__024next 
        = ((2U & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__madd_delay__DOT__shift_register) 
                  << 1U)) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf_next));
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count;
    if (vlSelf->Cfu__DOT__fn0__DOT__fvf_next) {
        if (vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT____02412) {
            vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count_done = 1U;
            vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count__024next = 0U;
        } else {
            vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count_done = 0U;
            vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count__024next 
                = (0xfffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count)));
        }
    }
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count;
    vlSelf->Cfu__DOT__stored_function_id__024next = vlSelf->Cfu__DOT__stored_function_id;
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__result__024next 
        = VL_EXTENDS_II(32,19, (0x7ffffU & (VL_EXTENDS_II(19,18, 
                                                          (0x3ffffU 
                                                           & (VL_EXTENDS_II(18,17, 
                                                                            (0x1ffffU 
                                                                             & VL_MULS_III(18, 
                                                                                (0x3ffffU 
                                                                                & VL_EXTENDS_II(18,9, (IData)(vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp))), 
                                                                                (0x3ffffU 
                                                                                & VL_EXTENDS_II(18,9, (IData)(vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp)))))) 
                                                              + 
                                                              VL_EXTENDS_II(18,17, 
                                                                            (0x1ffffU 
                                                                             & VL_MULS_III(18, 
                                                                                (0x3ffffU 
                                                                                & VL_EXTENDS_II(18,9, (IData)(vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02412))), 
                                                                                (0x3ffffU 
                                                                                & VL_EXTENDS_II(18,9, (IData)(vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__0249))))))))) 
                                            + VL_EXTENDS_II(19,18, 
                                                            (0x3ffffU 
                                                             & (VL_EXTENDS_II(18,17, 
                                                                              (0x1ffffU 
                                                                               & VL_MULS_III(18, 
                                                                                (0x3ffffU 
                                                                                & VL_EXTENDS_II(18,9, (IData)(vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02422))), 
                                                                                (0x3ffffU 
                                                                                & VL_EXTENDS_II(18,9, (IData)(vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02419)))))) 
                                                                + 
                                                                VL_EXTENDS_II(18,17, 
                                                                              (0x1ffffU 
                                                                               & VL_MULS_III(18, 
                                                                                (0x3ffffU 
                                                                                & VL_EXTENDS_II(18,9, (IData)(vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02432))), 
                                                                                (0x3ffffU 
                                                                                & VL_EXTENDS_II(18,9, (IData)(vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02429))))))))))));
    if ((0U == (IData)(vlSelf->Cfu__DOT__fsm_state))) {
        vlSelf->cmd_ready = 1U;
        vlSelf->Cfu__DOT__current_function_id = (7U 
                                                 & (IData)(vlSelf->cmd_payload_function_id));
    } else if ((2U == (IData)(vlSelf->Cfu__DOT__fsm_state))) {
        vlSelf->Cfu__DOT__current_function_id = vlSelf->Cfu__DOT__stored_function_id;
    }
    __Vtableidx1 = (((IData)(vlSelf->Cfu__DOT__current_function_id) 
                     << 3U) | (((IData)(vlSelf->cmd_valid) 
                                << 2U) | (IData)(vlSelf->Cfu__DOT__fsm_state)));
    vlSelf->Cfu__DOT____024signal__0242 = Vcfu__ConstPool__TABLE_hac88bb16_0
        [__Vtableidx1];
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce;
    if (vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT____0248) {
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce__024next 
            = ((0x1feU == (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce))
                ? 0U : (0x1ffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce))));
    }
    if ((2U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__madd_delay__DOT__shift_register))) {
        vlSelf->Cfu__DOT__fn0__DOT__acc_result = vlSelf->Cfu__DOT__fn0__DOT__acc__DOT____VdfgExtracted_h784e4b37__0;
    }
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__areg__024next 
        = ((IData)((0x7fffffffffffffffULL & VL_EXTENDS_QI(63,32, 
                                                          ((IData)(
                                                                   (0x1ffffffffULL 
                                                                    & VL_EXTENDS_QI(33,32, vlSelf->Cfu__DOT__fn0__DOT__acc_result))) 
                                                           + (IData)(
                                                                     (0x1ffffffffULL 
                                                                      & VL_EXTENDS_QI(33,32, vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT___0_))))))) 
           << (IData)(vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__left_shift));
    if ((8U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register))) {
        vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__calc 
            = (((VL_LTS_III(32, Cfu__DOT__fn0__DOT__pp__DOT__with_offset, vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_value)
                  ? vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_value
                  : (VL_GTS_III(32, Cfu__DOT__fn0__DOT__pp__DOT__with_offset, vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_value)
                      ? vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_value
                      : Cfu__DOT__fn0__DOT__pp__DOT__with_offset)) 
                << 0x18U) | (vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register 
                             >> 8U));
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count__024next 
            = ((3U == (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count))
                ? 0U : (7U & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count))));
        vlSelf->Cfu__DOT__fn0__DOT__btw_result = vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register;
        vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register;
        vlSelf->Cfu__DOT__fn0__DOT__btw_result = vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__calc;
        vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__calc;
    } else {
        vlSelf->Cfu__DOT__fn0__DOT__btw_result = vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register;
        vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register;
    }
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0_data;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1_data;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2_data;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3_data;
    vlSelf->Cfu__DOT__fn0__DOT__fvf_data = ((2U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank))
                                             ? ((1U 
                                                 & (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank))
                                                 ? vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3_data
                                                 : vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2_data)
                                             : ((1U 
                                                 & (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank))
                                                 ? vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1_data
                                                 : vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0_data));
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_data;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_data;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_data;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_data;
    vlSelf->Cfu__DOT__fn0__DOT__ins_r_data = ((2U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr))
                                               ? ((1U 
                                                   & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr))
                                                   ? vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_data
                                                   : vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_data)
                                               : ((1U 
                                                   & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr))
                                                   ? vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_data
                                                   : vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_data));
    if ((2U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__madd_delay__DOT__shift_register))) {
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count_done 
            = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT____02412;
    }
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register__024next 
        = ((0xeU & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register) 
                    << 1U)) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count_done));
    if ((2U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__madd_delay__DOT__shift_register))) {
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count__024next 
            = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT____02412)
                ? 0U : (0x7ffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count))));
        vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator;
        vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__acc__DOT____VdfgExtracted_h784e4b37__0;
    } else {
        vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count_done) {
        vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator__024next = 0U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc_r_addr 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc__DOT__last_addr;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc_r_addr 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc__DOT__last_addr;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc_r_addr 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc__DOT__last_addr;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_restart = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_restart = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_restart = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_restart = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_0;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_1;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_2;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_3;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running;
    if (vlSelf->Cfu__DOT__fn0__DOT__start_run_set) {
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running__024next = 1U;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count_done) {
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running__024next = 0U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins_r_finished = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__mark_read_set) 
                                                  | (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count_done));
    vlSelf->Cfu__DOT__fn0__DOT__f7buf__DOT__captured__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__f7buf__DOT__captured;
    if (vlSelf->Cfu__DOT____024signal__0242) {
        vlSelf->Cfu__DOT__fn0__DOT__f7buf__DOT__captured__024next 
            = (0x7fU & ((IData)(vlSelf->cmd_payload_function_id) 
                        >> 3U));
        Cfu__DOT__fn0__DOT__f7buf_output = (0x7fU & 
                                            ((IData)(vlSelf->cmd_payload_function_id) 
                                             >> 3U));
    } else {
        Cfu__DOT__fn0__DOT__f7buf_output = (0x7fU & (IData)(vlSelf->Cfu__DOT__fn0__DOT__f7buf__DOT__captured));
    }
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__024next 
        = (0x1ffU & VL_EXTENDS_II(9,8, (0xffU & vlSelf->Cfu__DOT__fn0__DOT__fvf_data)));
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__0249__024next 
        = (0x1ffU & VL_EXTENDS_II(9,8, (0xffU & (vlSelf->Cfu__DOT__fn0__DOT__fvf_data 
                                                 >> 8U))));
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02419__024next 
        = (0x1ffU & VL_EXTENDS_II(9,8, (0xffU & (vlSelf->Cfu__DOT__fn0__DOT__fvf_data 
                                                 >> 0x10U))));
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02429__024next 
        = (0x1ffU & VL_EXTENDS_II(9,8, (vlSelf->Cfu__DOT__fn0__DOT__fvf_data 
                                        >> 0x18U)));
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__024next 
        = (0x1ffU & ((0x3ffU & VL_EXTENDS_II(10,8, 
                                             (0xffU 
                                              & vlSelf->Cfu__DOT__fn0__DOT__ins_r_data))) 
                     + (0x3ffU & VL_EXTENDS_II(10,9, 
                                               (0x1ffU 
                                                & vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_value)))));
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02432__024next 
        = (0x1ffU & ((0x3ffU & VL_EXTENDS_II(10,8, 
                                             (vlSelf->Cfu__DOT__fn0__DOT__ins_r_data 
                                              >> 0x18U))) 
                     + (0x3ffU & VL_EXTENDS_II(10,9, 
                                               (0x1ffU 
                                                & vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_value)))));
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02412__024next 
        = (0x1ffU & ((0x3ffU & VL_EXTENDS_II(10,8, 
                                             (0xffU 
                                              & (vlSelf->Cfu__DOT__fn0__DOT__ins_r_data 
                                                 >> 8U)))) 
                     + (0x3ffU & VL_EXTENDS_II(10,9, 
                                               (0x1ffU 
                                                & vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_value)))));
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02422__024next 
        = (0x1ffU & ((0x3ffU & VL_EXTENDS_II(10,8, 
                                             (0xffU 
                                              & (vlSelf->Cfu__DOT__fn0__DOT__ins_r_data 
                                                 >> 0x10U)))) 
                     + (0x3ffU & VL_EXTENDS_II(10,9, 
                                               (0x1ffU 
                                                & vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_value)))));
    if ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set)))) {
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc_r_addr = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc__DOT__last_addr__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc_r_addr;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc_r_addr = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc__DOT__last_addr__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc_r_addr;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc_r_addr = 0U;
    } else {
        if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf_next) 
                           << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
            vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank__024next 
                = (3U & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank)));
        }
        if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count_done) 
                           << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
            vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc_r_addr 
                = (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc__DOT__last_addr) 
                    >= (0x3ffU & ((0x1ffU & (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_count)) 
                                  - (IData)(1U)))) ? 0U
                    : (0x1ffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc__DOT__last_addr))));
            vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc_r_addr 
                = (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc__DOT__last_addr) 
                    >= (0x3ffU & ((0x1ffU & (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_count)) 
                                  - (IData)(1U)))) ? 0U
                    : (0x1ffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc__DOT__last_addr))));
            vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc_r_addr 
                = (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc__DOT__last_addr) 
                    >= (0x3ffU & ((0x1ffU & (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_count)) 
                                  - (IData)(1U)))) ? 0U
                    : (0x1ffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc__DOT__last_addr))));
        }
        vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc__DOT__last_addr__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc_r_addr;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc__DOT__last_addr__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc_r_addr;
    }
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc__DOT__last_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc_r_addr;
    if (vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____02483) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_restart = 1U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_restart;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_mem_addr 
        = ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_restart)))
            ? 0U : (0x1ffU & ((2U == (2U & (((IData)(Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT____02411) 
                                             << 1U) 
                                            | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_restart))))
                               ? (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_mem_addr) 
                                   == (0x7ffU & ((0x3ffU 
                                                  & (((IData)(3U) 
                                                      + 
                                                      (0x7ffU 
                                                       & vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_value)) 
                                                     >> 2U)) 
                                                 - (IData)(1U))))
                                   ? 0U : ((IData)(1U) 
                                           + (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_mem_addr)))
                               : (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_mem_addr))));
    if (vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____02483) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_restart = 1U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_restart;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_mem_addr 
        = ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_restart)))
            ? 0U : (0x1ffU & ((2U == (2U & (((IData)(Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT____02411) 
                                             << 1U) 
                                            | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_restart))))
                               ? (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_mem_addr) 
                                   == (0x7ffU & ((0x3ffU 
                                                  & (((0xfffU 
                                                       & ((IData)(3U) 
                                                          + 
                                                          (0x7ffU 
                                                           & vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_value))) 
                                                      - (IData)(1U)) 
                                                     >> 2U)) 
                                                 - (IData)(1U))))
                                   ? 0U : ((IData)(1U) 
                                           + (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_mem_addr)))
                               : (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_mem_addr))));
    if (vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____02483) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_restart = 1U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_restart;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_mem_addr 
        = ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_restart)))
            ? 0U : (0x1ffU & ((2U == (2U & (((IData)(Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT____02411) 
                                             << 1U) 
                                            | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_restart))))
                               ? (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_mem_addr) 
                                   == (0x7ffU & ((0x3ffU 
                                                  & (((0xfffU 
                                                       & ((IData)(3U) 
                                                          + 
                                                          (0x7ffU 
                                                           & vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_value))) 
                                                      - (IData)(2U)) 
                                                     >> 2U)) 
                                                 - (IData)(1U))))
                                   ? 0U : ((IData)(1U) 
                                           + (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_mem_addr)))
                               : (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_mem_addr))));
    if (vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____02483) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_restart = 1U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_restart;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_mem_addr 
        = ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_restart)))
            ? 0U : (0x1ffU & ((2U == (2U & (((IData)(Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT____02411) 
                                             << 1U) 
                                            | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_restart))))
                               ? (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_mem_addr) 
                                   == (0x7ffU & ((0x3ffU 
                                                  & (((0xfffU 
                                                       & ((IData)(3U) 
                                                          + 
                                                          (0x7ffU 
                                                           & vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_value))) 
                                                      - (IData)(3U)) 
                                                     >> 2U)) 
                                                 - (IData)(1U))))
                                   ? 0U : ((IData)(1U) 
                                           + (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_mem_addr)))
                               : (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_mem_addr))));
    if (vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____024101) {
        if ((1U & (~ ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr)))) {
                vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_next = 1U;
            }
            if ((1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr))) {
                vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_next = 1U;
            }
        }
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_next__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_next;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_next__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_next;
        if ((2U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr))) {
            if ((1U & (~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr)))) {
                vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_next = 1U;
            }
            if ((1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr))) {
                vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_next = 1U;
            }
        }
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_next__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_next;
    } else {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_next__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_next;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_next__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_next;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_next__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_next;
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__last_full__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__full;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_ready__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins_r_ready;
    if (vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____02483) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_ready__024next = 1U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr;
    if (vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____024101) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr__024next 
            = (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr) 
                == (0xfffU & ((0x7ffU & vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_value) 
                              - (IData)(1U)))) ? 0U
                : (0x7ffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr))));
    }
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_start = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_start = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_start = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_start = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_start = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_output_depth_start = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_start = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_output_offset_start = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_start = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_start = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__mark_read_start = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__start_run_start = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_start = 0U;
    Cfu__DOT__fn0__DOT__ins_set_start = 0U;
    Cfu__DOT__fn0__DOT__oq_get_start = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set___024signal = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_w_data = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set__DOT__count__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_count;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set___024signal = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_w_data = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set__DOT__count__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_count;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set___024signal = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_w_data = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set__DOT__count__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_count;
    if ((0x15U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set)))) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set__DOT__count__024next = 0U;
    } else if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_start) 
                              << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set__DOT__count__024next 
            = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_count)));
    }
    if ((0x16U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set)))) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set__DOT__count__024next = 0U;
    } else if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_start) 
                              << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set__DOT__count__024next 
            = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_count)));
    }
    if ((0x17U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set)))) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set__DOT__count__024next = 0U;
    } else if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_start) 
                              << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set__DOT__count__024next 
            = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_count)));
    }
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_w_data = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set__DOT__count__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count;
    if ((0x18U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set)))) {
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set__DOT__count__024next = 0U;
    } else if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_start) 
                              << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set__DOT__count__024next 
            = (0xfffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count)));
    }
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0241 = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0242 = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0243 = 0U;
    if ((1U != (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set)))) {
        if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_start) 
                           << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
            vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set___024signal = 1U;
            vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_w_data 
                = vlSelf->cmd_payload_inputs_0;
        }
        if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_start) 
                           << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
            vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set___024signal = 1U;
            vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_w_data 
                = vlSelf->cmd_payload_inputs_0;
        }
        if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_start) 
                           << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
            vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set___024signal = 1U;
            vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_w_data 
                = vlSelf->cmd_payload_inputs_0;
        }
        if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_start) 
                           << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
            vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_w_data 
                = vlSelf->cmd_payload_inputs_0;
            if ((1U & (~ ((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count)))) {
                    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal = 1U;
                }
                if ((1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count))) {
                    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0241 = 1U;
                }
            }
            if ((2U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count))) {
                if ((1U & (~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count)))) {
                    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0242 = 1U;
                }
                if ((1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count))) {
                    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0243 = 1U;
                }
            }
        }
    }
    vlSelf->Cfu__DOT__fn0__DOT__set_activation_max__DOT__value__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_value;
    if ((0xfU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_start) {
        vlSelf->Cfu__DOT__fn0__DOT__set_activation_max__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
        Cfu__DOT__fn0__DOT__set_activation_max_output = 0U;
        Cfu__DOT__fn0__DOT__set_activation_max_done = 0U;
        Cfu__DOT__fn0__DOT__set_activation_max_output 
            = vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_value;
        Cfu__DOT__fn0__DOT__set_activation_max_done = 1U;
    } else {
        Cfu__DOT__fn0__DOT__set_activation_max_output = 0U;
        Cfu__DOT__fn0__DOT__set_activation_max_done = 0U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__set_output_depth__DOT__value__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__set_output_depth__DOT__value;
    if ((0xbU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__set_output_depth_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_output_depth_start) {
        vlSelf->Cfu__DOT__fn0__DOT__set_output_depth__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
        Cfu__DOT__fn0__DOT__set_output_depth_output = 0U;
        Cfu__DOT__fn0__DOT__set_output_depth_done = 0U;
        Cfu__DOT__fn0__DOT__set_output_depth_output 
            = vlSelf->Cfu__DOT__fn0__DOT__set_output_depth__DOT__value;
        Cfu__DOT__fn0__DOT__set_output_depth_done = 1U;
    } else {
        Cfu__DOT__fn0__DOT__set_output_depth_output = 0U;
        Cfu__DOT__fn0__DOT__set_output_depth_done = 0U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__set_input_offset__DOT__value__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_value;
    if ((0xcU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_start) {
        vlSelf->Cfu__DOT__fn0__DOT__set_input_offset__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
        Cfu__DOT__fn0__DOT__set_input_offset_output = 0U;
        Cfu__DOT__fn0__DOT__set_input_offset_done = 0U;
        Cfu__DOT__fn0__DOT__set_input_offset_output 
            = vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_value;
        Cfu__DOT__fn0__DOT__set_input_offset_done = 1U;
    } else {
        Cfu__DOT__fn0__DOT__set_input_offset_output = 0U;
        Cfu__DOT__fn0__DOT__set_input_offset_done = 0U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__set_output_offset__DOT__value__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__set_output_offset_value;
    if ((0xdU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__set_output_offset_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_output_offset_start) {
        vlSelf->Cfu__DOT__fn0__DOT__set_output_offset__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
        Cfu__DOT__fn0__DOT__set_output_offset_output = 0U;
        Cfu__DOT__fn0__DOT__set_output_offset_done = 0U;
        Cfu__DOT__fn0__DOT__set_output_offset_output 
            = vlSelf->Cfu__DOT__fn0__DOT__set_output_offset_value;
        Cfu__DOT__fn0__DOT__set_output_offset_done = 1U;
    } else {
        Cfu__DOT__fn0__DOT__set_output_offset_output = 0U;
        Cfu__DOT__fn0__DOT__set_output_offset_done = 0U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__set_activation_min__DOT__value__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_value;
    if ((0xeU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_start) {
        vlSelf->Cfu__DOT__fn0__DOT__set_activation_min__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
        Cfu__DOT__fn0__DOT__set_activation_min_output = 0U;
        Cfu__DOT__fn0__DOT__set_activation_min_done = 0U;
        Cfu__DOT__fn0__DOT__set_activation_min_output 
            = vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_value;
        Cfu__DOT__fn0__DOT__set_activation_min_done = 1U;
    } else {
        Cfu__DOT__fn0__DOT__set_activation_min_output = 0U;
        Cfu__DOT__fn0__DOT__set_activation_min_done = 0U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__set__024next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__value__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__value;
    if ((0x14U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_start) {
        vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__set__024next = 1U;
        vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
        Cfu__DOT__fn0__DOT__set_output_batch_size_output = 0U;
        Cfu__DOT__fn0__DOT__set_output_batch_size_done = 0U;
        Cfu__DOT__fn0__DOT__set_output_batch_size_output 
            = vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__value;
        Cfu__DOT__fn0__DOT__set_output_batch_size_done = 1U;
    } else {
        Cfu__DOT__fn0__DOT__set_output_batch_size_output = 0U;
        Cfu__DOT__fn0__DOT__set_output_batch_size_done = 0U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__set__024next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__value__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__value;
    if ((0x70U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__mark_read_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__mark_read_start) {
        vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__set__024next = 1U;
        vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
        Cfu__DOT__fn0__DOT__mark_read_output = 0U;
        Cfu__DOT__fn0__DOT__mark_read_done = 0U;
        Cfu__DOT__fn0__DOT__mark_read_output = vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__value;
        Cfu__DOT__fn0__DOT__mark_read_done = 1U;
    } else {
        Cfu__DOT__fn0__DOT__mark_read_output = 0U;
        Cfu__DOT__fn0__DOT__mark_read_done = 0U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__set__024next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__value__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__value;
    if ((0x21U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__start_run_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__start_run_start) {
        vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__set__024next = 1U;
        vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
        Cfu__DOT__fn0__DOT__start_run_output = 0U;
        Cfu__DOT__fn0__DOT__start_run_done = 0U;
        Cfu__DOT__fn0__DOT__start_run_output = vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__value;
        Cfu__DOT__fn0__DOT__start_run_done = 1U;
    } else {
        Cfu__DOT__fn0__DOT__start_run_output = 0U;
        Cfu__DOT__fn0__DOT__start_run_done = 0U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words__DOT__set__024next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words__DOT__value__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_value;
    if ((0xaU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_start) {
        vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words__DOT__set__024next = 1U;
        vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
        Cfu__DOT__fn0__DOT__set_input_depth_words_output = 0U;
        Cfu__DOT__fn0__DOT__set_input_depth_words_done = 0U;
        Cfu__DOT__fn0__DOT__set_input_depth_words_output 
            = vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_value;
        Cfu__DOT__fn0__DOT__set_input_depth_words_done = 1U;
    } else {
        Cfu__DOT__fn0__DOT__set_input_depth_words_output = 0U;
        Cfu__DOT__fn0__DOT__set_input_depth_words_done = 0U;
    }
    if ((0x19U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        Cfu__DOT__fn0__DOT__ins_set_start = vlSelf->Cfu__DOT____024signal__0242;
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____02415 
        = ((~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_w_ready)) 
           & (IData)(Cfu__DOT__fn0__DOT__ins_set_start));
    vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____0241 
        = ((IData)(Cfu__DOT__fn0__DOT__ins_set_start) 
           & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_w_ready));
    if ((0x22U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        Cfu__DOT__fn0__DOT__oq_get_start = vlSelf->Cfu__DOT____024signal__0242;
    }
    vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT____02415 
        = ((~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO_r_rdy)) 
           & (IData)(Cfu__DOT__fn0__DOT__oq_get_start));
    vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT____02411 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO_r_rdy) 
           & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT__waiting) 
              | (IData)(Cfu__DOT__fn0__DOT__oq_get_start)));
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated__024next 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0243) 
           | ((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0242) 
              | ((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal) 
                 | ((IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set) 
                    | (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0241)))));
    vlSelf->Cfu__DOT__fn0__DOT__ins_set_w_data = 0U;
    if ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____0241)))) {
        vlSelf->Cfu__DOT__fn0__DOT__ins_set_w_data 
            = vlSelf->cmd_payload_inputs_0;
    } else if ((2U != (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____02415) 
                              << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____0241))))) {
        if ((4U == (4U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____02419) 
                           << 2U) | (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____02415) 
                                      << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____0241)))))) {
            vlSelf->Cfu__DOT__fn0__DOT__ins_set_w_data 
                = vlSelf->cmd_payload_inputs_0;
        }
    }
    __Vtableidx7 = (((IData)(vlSelf->rst) << 4U) | 
                    (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____0241) 
                      << 3U) | (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____02415) 
                                 << 2U) | (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____02419) 
                                            << 1U) 
                                           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT__waiting)))));
    vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT__waiting__024next 
        = Vcfu__ConstPool__TABLE_hda23d5a5_0[__Vtableidx7];
    __Vtableidx6 = (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____0241) 
                     << 2U) | (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____02415) 
                                << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____02419)));
    Cfu__DOT__fn0__DOT__ins_set_w_en = Vcfu__ConstPool__TABLE_h70b41e53_0
        [__Vtableidx6];
    __Vtableidx5 = (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____0241) 
                     << 2U) | (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____02415) 
                                << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____02419)));
    Cfu__DOT__fn0__DOT__ins_set_done = Vcfu__ConstPool__TABLE_h70b41e53_0
        [__Vtableidx5];
    vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT__waiting__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT__waiting;
    if ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT____02411)))) {
        vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT__waiting__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__oq_get_next = 0U;
        Cfu__DOT__fn0__DOT__oq_get_output = 0U;
        Cfu__DOT__fn0__DOT__oq_get_done = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__oq_get_next = 1U;
        Cfu__DOT__fn0__DOT__oq_get_output = vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT___0_;
        Cfu__DOT__fn0__DOT__oq_get_done = 1U;
    } else {
        if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT____02415) 
                           << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT____02411))))) {
            vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT__waiting__024next = 1U;
        }
        vlSelf->Cfu__DOT__fn0__DOT__oq_get_next = 0U;
        Cfu__DOT__fn0__DOT__oq_get_output = 0U;
        Cfu__DOT__fn0__DOT__oq_get_done = 0U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____0241 = 
        ((IData)(Cfu__DOT__fn0__DOT__ins_set_w_en) 
         & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_w_ready));
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_r_en 
        = ((0U != (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_level)) 
           & ((~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO_r_rdy)) 
              | (IData)(vlSelf->Cfu__DOT__fn0__DOT__oq_get_next)));
    vlSelf->Cfu__DOT__fn0_output = 0U;
    if ((0xaU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0_output = Cfu__DOT__fn0__DOT__set_input_depth_words_output;
    }
    if ((0xbU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0_output = Cfu__DOT__fn0__DOT__set_output_depth_output;
    }
    if ((0xcU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0_output = Cfu__DOT__fn0__DOT__set_input_offset_output;
    }
    if ((0xdU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0_output = Cfu__DOT__fn0__DOT__set_output_offset_output;
    }
    if ((0xeU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0_output = Cfu__DOT__fn0__DOT__set_activation_min_output;
    }
    if ((0xfU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0_output = Cfu__DOT__fn0__DOT__set_activation_max_output;
    }
    if ((0x14U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0_output = Cfu__DOT__fn0__DOT__set_output_batch_size_output;
    }
    if ((0x15U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0_output = 0U;
    }
    if ((0x16U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0_output = 0U;
    }
    if ((0x17U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0_output = 0U;
    }
    if ((0x18U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0_output = 0U;
    }
    if ((0x19U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0_output = 0U;
    }
    if ((0x70U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0_output = Cfu__DOT__fn0__DOT__mark_read_output;
    }
    if ((0x22U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0_output = Cfu__DOT__fn0__DOT__oq_get_output;
    }
    Cfu__DOT__fn0_done = vlSelf->Cfu__DOT____024signal__0242;
    if ((0xaU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        Cfu__DOT__fn0_done = Cfu__DOT__fn0__DOT__set_input_depth_words_done;
    }
    if ((0xbU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        Cfu__DOT__fn0_done = Cfu__DOT__fn0__DOT__set_output_depth_done;
    }
    if ((0xcU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        Cfu__DOT__fn0_done = Cfu__DOT__fn0__DOT__set_input_offset_done;
    }
    if ((0xdU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        Cfu__DOT__fn0_done = Cfu__DOT__fn0__DOT__set_output_offset_done;
    }
    if ((0xeU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        Cfu__DOT__fn0_done = Cfu__DOT__fn0__DOT__set_activation_min_done;
    }
    if ((0xfU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        Cfu__DOT__fn0_done = Cfu__DOT__fn0__DOT__set_activation_max_done;
    }
    if ((0x14U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        Cfu__DOT__fn0_done = Cfu__DOT__fn0__DOT__set_output_batch_size_done;
    }
    if ((0x15U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        Cfu__DOT__fn0_done = 1U;
    }
    if ((0x16U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        Cfu__DOT__fn0_done = 1U;
    }
    if ((0x17U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        Cfu__DOT__fn0_done = 1U;
    }
    if ((0x18U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        Cfu__DOT__fn0_done = 1U;
    }
    if ((0x19U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        Cfu__DOT__fn0_done = Cfu__DOT__fn0__DOT__ins_set_done;
    }
    if ((0x70U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        Cfu__DOT__fn0_done = Cfu__DOT__fn0__DOT__mark_read_done;
    }
    if ((0x22U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        Cfu__DOT__fn0_done = Cfu__DOT__fn0__DOT__oq_get_done;
    }
    if ((0x21U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0_output = Cfu__DOT__fn0__DOT__start_run_output;
        Cfu__DOT__fn0_done = Cfu__DOT__fn0__DOT__start_run_done;
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_0__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_0;
    if (vlSelf->Cfu__DOT__fn0__DOT__ins_r_finished) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__last_full__024next = 0U;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_set) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__last_full__024next = 0U;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__ins_r_finished) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf__024next 
            = (1U & (~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf)));
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_set) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf__024next = 0U;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__ins_r_finished) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_ready__024next = 0U;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_set) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_ready__024next = 0U;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__ins_r_finished) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr__024next = 0U;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_set) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr__024next = 0U;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____0241) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr__024next 
            = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____02440)
                ? 0U : (0x7ffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr))));
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_set) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr__024next = 0U;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____0241) {
        if (vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____02440) {
            vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf__024next 
                = (1U & (~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf)));
        }
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_set) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_0__024next = 0U;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____0241) {
        if (vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____02440) {
            if ((1U & (~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf)))) {
                vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_0__024next = 1U;
            }
        }
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__ins_r_finished) {
        if ((1U & (~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf)))) {
            vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_0__024next = 0U;
        }
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_1__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_1;
    if (vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_set) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_1__024next = 0U;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____0241) {
        if (vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____02440) {
            if (vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf) {
                vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_1__024next = 1U;
            }
        }
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__ins_r_finished) {
        if (vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf) {
            vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_1__024next = 0U;
        }
    }
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__r_rdy__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__FIFO_r_rdy;
    if ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_r_en)))) {
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__r_rdy__024next = 1U;
    } else if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__oq_get_next) 
                              << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_r_en))))) {
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__r_rdy__024next = 0U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT____02417 
        = ((0U != (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_level)) 
           & (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_r_en));
    vlSelf->Cfu__DOT__current_function_done = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__consume__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__consume;
    if (vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT____02417) {
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__consume__024next 
            = ((0x1feU == (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__consume))
                ? 0U : (0x1ffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__consume))));
    }
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__level__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_level;
    if (((~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT____02417)) 
         & (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT____0248))) {
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__level__024next 
            = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_level)));
    }
    if (((~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT____0248)) 
         & (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT____02417))) {
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__level__024next 
            = (0x1ffU & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_level) 
                         - (IData)(1U)));
    }
    if ((0U == (IData)(vlSelf->Cfu__DOT__fsm_state))) {
        if (vlSelf->cmd_valid) {
            vlSelf->Cfu__DOT__stored_function_id__024next 
                = (7U & (IData)(vlSelf->cmd_payload_function_id));
        }
        vlSelf->Cfu__DOT__current_function_done = (
                                                   (1U 
                                                    & ((IData)(vlSelf->Cfu__DOT__current_function_id) 
                                                       >> 2U)) 
                                                   || ((1U 
                                                        & ((IData)(vlSelf->Cfu__DOT__current_function_id) 
                                                           >> 1U)) 
                                                       || ((1U 
                                                            & (IData)(vlSelf->Cfu__DOT__current_function_id)) 
                                                           || (IData)(Cfu__DOT__fn0_done))));
    } else if ((2U == (IData)(vlSelf->Cfu__DOT__fsm_state))) {
        vlSelf->Cfu__DOT__current_function_done = (
                                                   (1U 
                                                    & ((IData)(vlSelf->Cfu__DOT__current_function_id) 
                                                       >> 2U)) 
                                                   || ((1U 
                                                        & ((IData)(vlSelf->Cfu__DOT__current_function_id) 
                                                           >> 1U)) 
                                                       || ((1U 
                                                            & (IData)(vlSelf->Cfu__DOT__current_function_id)) 
                                                           || (IData)(Cfu__DOT__fn0_done))));
    }
    __Vtableidx2 = (((IData)(vlSelf->Cfu__DOT__current_function_done) 
                     << 3U) | (((IData)(vlSelf->cmd_valid) 
                                << 2U) | (IData)(vlSelf->Cfu__DOT__fsm_state)));
    vlSelf->rsp_valid = Vcfu__ConstPool__TABLE_h7c969f7e_0
        [__Vtableidx2];
    vlSelf->rsp_payload_outputs_0 = 0U;
    __Vtableidx3 = (((IData)(vlSelf->rst) << 5U) | 
                    (((IData)(vlSelf->rsp_ready) << 4U) 
                     | (((IData)(vlSelf->Cfu__DOT__current_function_done) 
                         << 3U) | (((IData)(vlSelf->cmd_valid) 
                                    << 2U) | (IData)(vlSelf->Cfu__DOT__fsm_state)))));
    vlSelf->Cfu__DOT__fsm_state__024next = Vcfu__ConstPool__TABLE_h3f46fc78_0
        [__Vtableidx3];
    vlSelf->Cfu__DOT__stored_output__024next = vlSelf->Cfu__DOT__stored_output;
    if ((0U == (IData)(vlSelf->Cfu__DOT__fsm_state))) {
        if (vlSelf->cmd_valid) {
            if (vlSelf->Cfu__DOT__current_function_done) {
                vlSelf->rsp_payload_outputs_0 = ((4U 
                                                  & (IData)(vlSelf->Cfu__DOT__current_function_id))
                                                  ? vlSelf->cmd_payload_inputs_0
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelf->Cfu__DOT__current_function_id))
                                                   ? vlSelf->cmd_payload_inputs_0
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->Cfu__DOT__current_function_id))
                                                    ? vlSelf->cmd_payload_inputs_0
                                                    : vlSelf->Cfu__DOT__fn0_output)));
                if ((1U & (~ (IData)(vlSelf->rsp_ready)))) {
                    vlSelf->Cfu__DOT__stored_output__024next 
                        = ((4U & (IData)(vlSelf->Cfu__DOT__current_function_id))
                            ? vlSelf->cmd_payload_inputs_0
                            : ((2U & (IData)(vlSelf->Cfu__DOT__current_function_id))
                                ? vlSelf->cmd_payload_inputs_0
                                : ((1U & (IData)(vlSelf->Cfu__DOT__current_function_id))
                                    ? vlSelf->cmd_payload_inputs_0
                                    : vlSelf->Cfu__DOT__fn0_output)));
                }
            }
        }
    } else if ((2U == (IData)(vlSelf->Cfu__DOT__fsm_state))) {
        if (vlSelf->Cfu__DOT__current_function_done) {
            vlSelf->rsp_payload_outputs_0 = ((4U & (IData)(vlSelf->Cfu__DOT__current_function_id))
                                              ? vlSelf->cmd_payload_inputs_0
                                              : ((2U 
                                                  & (IData)(vlSelf->Cfu__DOT__current_function_id))
                                                  ? vlSelf->cmd_payload_inputs_0
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->Cfu__DOT__current_function_id))
                                                   ? vlSelf->cmd_payload_inputs_0
                                                   : vlSelf->Cfu__DOT__fn0_output)));
            if ((1U & (~ (IData)(vlSelf->rsp_ready)))) {
                vlSelf->Cfu__DOT__stored_output__024next 
                    = ((4U & (IData)(vlSelf->Cfu__DOT__current_function_id))
                        ? vlSelf->cmd_payload_inputs_0
                        : ((2U & (IData)(vlSelf->Cfu__DOT__current_function_id))
                            ? vlSelf->cmd_payload_inputs_0
                            : ((1U & (IData)(vlSelf->Cfu__DOT__current_function_id))
                                ? vlSelf->cmd_payload_inputs_0
                                : vlSelf->Cfu__DOT__fn0_output)));
            }
        }
    } else if ((1U == (IData)(vlSelf->Cfu__DOT__fsm_state))) {
        vlSelf->rsp_payload_outputs_0 = vlSelf->Cfu__DOT__stored_output;
    }
    if (vlSelf->rst) {
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_1__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_2__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_3__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__breg__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_shifted__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__overflow__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__ab__024next = 0ULL;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__result__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__madd_delay__DOT__shift_register__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__stored_function_id__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__result__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__areg__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__f7buf__DOT__captured__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__0249__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02419__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02429__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02432__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02412__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02422__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc__DOT__last_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc__DOT__last_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc__DOT__last_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__last_full__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_ready__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_activation_max__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_output_depth__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_input_offset__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_output_offset__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_activation_min__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__set__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__set__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__set__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words__DOT__set__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT__waiting__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_0__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_1__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__r_rdy__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__consume__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__level__024next = 0U;
        vlSelf->Cfu__DOT__stored_output__024next = 0U;
    }
}

VL_ATTR_COLD void Vcfu___024root___eval_stl(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vcfu___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vcfu___024root___eval_triggers__stl(Vcfu___024root* vlSelf);

VL_ATTR_COLD bool Vcfu___024root___eval_phase__stl(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vcfu___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vcfu___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcfu___024root___dump_triggers__ico(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vcfu___024root___dump_triggers__act(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___dump_triggers__act\n"); );
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
VL_ATTR_COLD void Vcfu___024root___dump_triggers__nba(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vcfu___024root___ctor_var_reset(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->cmd_ready = VL_RAND_RESET_I(1);
    vlSelf->cmd_payload_function_id = VL_RAND_RESET_I(10);
    vlSelf->cmd_payload_inputs_0 = VL_RAND_RESET_I(32);
    vlSelf->cmd_payload_inputs_1 = VL_RAND_RESET_I(32);
    vlSelf->rsp_valid = VL_RAND_RESET_I(1);
    vlSelf->rsp_ready = VL_RAND_RESET_I(1);
    vlSelf->rsp_payload_outputs_0 = VL_RAND_RESET_I(32);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->port0_addr = VL_RAND_RESET_I(32);
    vlSelf->port1_addr = VL_RAND_RESET_I(32);
    vlSelf->port2_addr = VL_RAND_RESET_I(32);
    vlSelf->port3_addr = VL_RAND_RESET_I(32);
    vlSelf->port0_din = VL_RAND_RESET_I(32);
    vlSelf->port1_din = VL_RAND_RESET_I(32);
    vlSelf->port2_din = VL_RAND_RESET_I(32);
    vlSelf->port3_din = VL_RAND_RESET_I(32);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->cmd_valid = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT____024signal__0242 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__current_function_done = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__current_function_id = VL_RAND_RESET_I(3);
    vlSelf->Cfu__DOT__fn0_output = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fsm_state = VL_RAND_RESET_I(2);
    vlSelf->Cfu__DOT__fsm_state__024next = VL_RAND_RESET_I(2);
    vlSelf->Cfu__DOT__stored_function_id = VL_RAND_RESET_I(3);
    vlSelf->Cfu__DOT__stored_function_id__024next = VL_RAND_RESET_I(3);
    vlSelf->Cfu__DOT__stored_output = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__stored_output__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__FIFO_r_rdy = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__acc_result = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__btw_result = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__fvf_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__fvf_next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins_r_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__ins_r_finished = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins_r_ready = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins_set_w_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__ins_w_ready = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__madd_result = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__mark_read_set = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__mark_read_start = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__oq_get_next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_start = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_value = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_start = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_value = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_set = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_start = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_value = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_start = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_value = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_start = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__set_output_depth_start = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__set_output_offset_start = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__set_output_offset_value = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__start_run_set = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__start_run_start = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0241 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0242 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0243 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count = VL_RAND_RESET_I(12);
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_start = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_w_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc_r_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set___024signal = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_count = VL_RAND_RESET_I(10);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_start = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_w_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc_r_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set___024signal = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_count = VL_RAND_RESET_I(10);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_start = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_w_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc_r_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set___024signal = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_count = VL_RAND_RESET_I(10);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_start = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_w_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__r_rdy__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_level = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_r_en = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT____02417 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT____0248 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__consume = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__consume__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__level__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce__024next = VL_RAND_RESET_I(9);
    for (int __Vi0 = 0; __Vi0 < 511; ++__Vi0) {
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__storage[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT___0_ = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT____Vlvbound_h12409c5f__0 = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__acc__DOT____VdfgExtracted_h784e4b37__0 = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__calc = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__f7buf__DOT__captured = VL_RAND_RESET_I(7);
    vlSelf->Cfu__DOT__fn0__DOT__f7buf__DOT__captured__024next = VL_RAND_RESET_I(7);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank = VL_RAND_RESET_I(2);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank__024next = VL_RAND_RESET_I(2);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0_mem_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1_mem_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2_mem_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3_mem_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_0 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_1 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_2 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_3 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_data__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_mem_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_mem_addr__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_next__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_restart = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_restart__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_data__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_mem_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_mem_addr__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_next__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_restart = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_restart__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_data__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_mem_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_mem_addr__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_next__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_restart = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_restart__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_data__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_mem_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_mem_addr__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_next__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_restart = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_restart__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____0241 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____024101 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____02440 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____02483 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__last_full = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__last_full__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr = VL_RAND_RESET_I(11);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr__024next = VL_RAND_RESET_I(11);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_0 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_0__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_1 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_1__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_ready__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_mem_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_restart = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_mem_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_restart = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_mem_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_restart = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_mem_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_restart = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr = VL_RAND_RESET_I(11);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr__024next = VL_RAND_RESET_I(11);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem_w_addr = VL_RAND_RESET_I(10);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT___0_ = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT___0_ = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT___0_ = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT___0_ = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_data__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_mem_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_mem_addr__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_next__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_restart = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_restart__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_data__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_mem_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_mem_addr__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_next__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_restart = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_restart__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_data__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_mem_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_mem_addr__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_next__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_restart = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_restart__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_data = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_data__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_mem_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_mem_addr__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_next__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_restart = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_restart__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____0241 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____02415 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____02419 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT__waiting = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT__waiting__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02419 = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02419__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02429 = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02429__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__0249 = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__0249__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02412 = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02412__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02422 = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02422__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02432 = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02432__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__result__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__set__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__value = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__value__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT____02411 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT____02415 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT__waiting = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT__waiting__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__left_shift = VL_RAND_RESET_I(5);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_shifted = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_shifted__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_0 = VL_RAND_RESET_I(5);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_1 = VL_RAND_RESET_I(5);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_1__024next = VL_RAND_RESET_I(5);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_2 = VL_RAND_RESET_I(5);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_2__024next = VL_RAND_RESET_I(5);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_3 = VL_RAND_RESET_I(5);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_3__024next = VL_RAND_RESET_I(5);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm_result = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__ab = VL_RAND_RESET_Q(64);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__ab__024next = VL_RAND_RESET_Q(64);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__areg = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__areg__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__breg = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__breg__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__overflow = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__overflow__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__result__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count_done = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count_done = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count_done = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT____02412 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count = VL_RAND_RESET_I(12);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count__024next = VL_RAND_RESET_I(12);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count = VL_RAND_RESET_I(3);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count__024next = VL_RAND_RESET_I(3);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT____02412 = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count = VL_RAND_RESET_I(11);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count__024next = VL_RAND_RESET_I(11);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__madd_delay__DOT__shift_register = VL_RAND_RESET_I(2);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__madd_delay__DOT__shift_register__024next = VL_RAND_RESET_I(2);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register = VL_RAND_RESET_I(4);
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register__024next = VL_RAND_RESET_I(4);
    vlSelf->Cfu__DOT__fn0__DOT__set_activation_max__DOT__value__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__set_activation_min__DOT__value__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words__DOT__set__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words__DOT__value__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__set_input_offset__DOT__value__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__set__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__value = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__value__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__set_output_depth__DOT__value = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__set_output_depth__DOT__value__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__set_output_offset__DOT__value__024next = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__set__024next = VL_RAND_RESET_I(1);
    vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__value = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__value__024next = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT___0_ = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT___0_ = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT___0_ = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT___0_ = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set__DOT__count__024next = VL_RAND_RESET_I(12);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT___0_ = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc__DOT__last_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc__DOT__last_addr__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set__DOT__count__024next = VL_RAND_RESET_I(10);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT___0_ = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc__DOT__last_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc__DOT__last_addr__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set__DOT__count__024next = VL_RAND_RESET_I(10);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT___0_ = VL_RAND_RESET_I(32);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc__DOT__last_addr = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc__DOT__last_addr__024next = VL_RAND_RESET_I(9);
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set__DOT__count__024next = VL_RAND_RESET_I(10);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
}
