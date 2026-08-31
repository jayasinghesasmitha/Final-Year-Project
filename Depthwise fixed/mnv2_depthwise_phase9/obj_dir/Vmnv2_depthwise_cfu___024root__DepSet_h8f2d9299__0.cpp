// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmnv2_depthwise_cfu.h for the primary calling header

#include "Vmnv2_depthwise_cfu__pch.h"
#include "Vmnv2_depthwise_cfu___024root.h"

VL_INLINE_OPT void Vmnv2_depthwise_cfu___024root___ico_sequent__TOP__0(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->cmd_ready = (1U & (~ ((IData)(vlSelf->reset) 
                                  | ((IData)(vlSelf->mnv2_depthwise_cfu__DOT__read_pending) 
                                     | (IData)(vlSelf->rsp_valid)))));
}

void Vmnv2_depthwise_cfu___024root___eval_ico(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vmnv2_depthwise_cfu___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vmnv2_depthwise_cfu___024root___eval_triggers__ico(Vmnv2_depthwise_cfu___024root* vlSelf);

bool Vmnv2_depthwise_cfu___024root___eval_phase__ico(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vmnv2_depthwise_cfu___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vmnv2_depthwise_cfu___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vmnv2_depthwise_cfu___024root___eval_act(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vmnv2_depthwise_cfu___024root___nba_sequent__TOP__0(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__rsp_valid;
    __Vdly__rsp_valid = 0;
    CData/*0:0*/ __Vdly__mnv2_depthwise_cfu__DOT__read_pending;
    __Vdly__mnv2_depthwise_cfu__DOT__read_pending = 0;
    CData/*0:0*/ __Vdly__mnv2_depthwise_cfu__DOT__busy;
    __Vdly__mnv2_depthwise_cfu__DOT__busy = 0;
    CData/*2:0*/ __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__state;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__state = 0;
    IData/*31:0*/ __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__row_cnt;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__row_cnt = 0;
    IData/*31:0*/ __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__col_cnt;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__col_cnt = 0;
    IData/*31:0*/ __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx = 0;
    IData/*31:0*/ __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch = 0;
    IData/*31:0*/ __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt = 0;
    IData/*31:0*/ __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch = 0;
    IData/*31:0*/ __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap = 0;
    IData/*31:0*/ __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__out_ch;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__out_ch = 0;
    IData/*31:0*/ __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_ch;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_ch = 0;
    IData/*31:0*/ __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_acc_reg;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_acc_reg = 0;
    IData/*31:0*/ __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_acc_reg;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_acc_reg = 0;
    IData/*31:0*/ __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_acc_reg;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_acc_reg = 0;
    CData/*6:0*/ __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__ifmap_mem__v0;
    __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__ifmap_mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__ifmap_mem__v0;
    __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__ifmap_mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__ifmap_mem__v0;
    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__ifmap_mem__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_w_mem__v0;
    __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_w_mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_w_mem__v0;
    __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_w_mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_w_mem__v0;
    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_w_mem__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_w_mem__v0;
    __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_w_mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_w_mem__v0;
    __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_w_mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_w_mem__v0;
    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_w_mem__v0 = 0;
    SData/*8:0*/ __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_w_mem__v0;
    __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_w_mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_w_mem__v0;
    __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_w_mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_w_mem__v0;
    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_w_mem__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem__v0;
    __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem__v0;
    __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem__v0;
    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem__v0 = 0;
    SData/*8:0*/ __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem__v0;
    __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem__v0;
    __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem__v0;
    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem__v0 = 0;
    SData/*8:0*/ __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem__v0;
    __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem__v0;
    __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem__v0;
    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem__v0 = 0;
    // Body
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_acc_reg 
        = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_acc_reg;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_acc_reg 
        = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_acc_reg;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_acc_reg 
        = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_acc_reg;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_ch 
        = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_ch;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__out_ch 
        = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__out_ch;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap 
        = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch 
        = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt 
        = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch 
        = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx 
        = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__col_cnt 
        = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__col_cnt;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__row_cnt 
        = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__row_cnt;
    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__state 
        = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__state;
    __Vdly__mnv2_depthwise_cfu__DOT__busy = vlSelf->mnv2_depthwise_cfu__DOT__busy;
    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_w_mem__v0 = 0U;
    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_w_mem__v0 = 0U;
    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_w_mem__v0 = 0U;
    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__ifmap_mem__v0 = 0U;
    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem__v0 = 0U;
    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem__v0 = 0U;
    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem__v0 = 0U;
    __Vdly__mnv2_depthwise_cfu__DOT__read_pending = vlSelf->mnv2_depthwise_cfu__DOT__read_pending;
    __Vdly__rsp_valid = vlSelf->rsp_valid;
    if (vlSelf->reset) {
        __Vdly__rsp_valid = 0U;
        vlSelf->rsp_payload_outputs_0 = 0U;
        __Vdly__mnv2_depthwise_cfu__DOT__read_pending = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__out_rd_addr = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i = 0U;
        __Vdly__mnv2_depthwise_cfu__DOT__busy = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__done = 0U;
        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__state = 0U;
        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__row_cnt = 0U;
        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__col_cnt = 0U;
        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx = 0U;
        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch = 0U;
        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt = 0U;
        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch = 0U;
        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap = 0U;
        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__out_ch = 0U;
        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_ch = 0U;
        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_acc_reg = 0U;
        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_acc_reg = 0U;
        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_acc_reg = 0U;
        while (VL_GTS_III(32, 0x180U, vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i)) {
            vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_h50c84ad7__0 = 0U;
            if (VL_LIKELY((0x17fU >= (0x1ffU & vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i)))) {
                vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem[(0x1ffU 
                                                                                & vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i)] 
                    = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_h50c84ad7__0;
            }
            vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i 
                = ((IData)(1U) + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i);
        }
        vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i = 0U;
        while (VL_GTS_III(32, 0x180U, vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i)) {
            vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_hfc1f09b4__0 = 0U;
            if (VL_LIKELY((0x17fU >= (0x1ffU & vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i)))) {
                vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem[(0x1ffU 
                                                                           & vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i)] 
                    = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_hfc1f09b4__0;
            }
            vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i 
                = ((IData)(1U) + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i);
        }
        vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i = 0U;
        while (VL_GTS_III(32, 0x100U, vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i)) {
            vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem[(0xffU 
                                                                           & vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i)] = 0U;
            vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i 
                = ((IData)(1U) + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__i);
        }
        vlSelf->mnv2_depthwise_cfu__DOT__ifmap_wr_en = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__exp_wr_en = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__dw_wr_en = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__proj_wr_en = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__ifmap_wr_data = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__exp_wr_data = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__dw_wr_data = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__proj_wr_data = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__start = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__ifmap_wr_addr = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__exp_wr_addr = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__dw_wr_addr = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__proj_wr_addr = 0U;
    } else {
        if (((IData)(vlSelf->rsp_valid) & (IData)(vlSelf->rsp_ready))) {
            __Vdly__rsp_valid = 0U;
        }
        if (vlSelf->mnv2_depthwise_cfu__DOT__read_pending) {
            vlSelf->rsp_payload_outputs_0 = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem
                [vlSelf->mnv2_depthwise_cfu__DOT__out_rd_addr];
            __Vdly__rsp_valid = 1U;
            __Vdly__mnv2_depthwise_cfu__DOT__read_pending = 0U;
        }
        if (((IData)(vlSelf->cmd_valid) & (IData)(vlSelf->cmd_ready))) {
            if ((4U & (IData)(vlSelf->cmd_payload_function_id))) {
                if ((2U & (IData)(vlSelf->cmd_payload_function_id))) {
                    if ((1U & (IData)(vlSelf->cmd_payload_function_id))) {
                        vlSelf->rsp_payload_outputs_0 = 0U;
                        __Vdly__rsp_valid = 1U;
                    } else {
                        __Vdly__mnv2_depthwise_cfu__DOT__read_pending = 1U;
                    }
                } else if ((1U & (IData)(vlSelf->cmd_payload_function_id))) {
                    vlSelf->rsp_payload_outputs_0 = 
                        (((IData)(vlSelf->mnv2_depthwise_cfu__DOT__done) 
                          << 1U) | (IData)(vlSelf->mnv2_depthwise_cfu__DOT__busy));
                    __Vdly__rsp_valid = 1U;
                } else {
                    vlSelf->rsp_payload_outputs_0 = 0U;
                    __Vdly__rsp_valid = 1U;
                }
            } else if ((2U & (IData)(vlSelf->cmd_payload_function_id))) {
                if ((1U & (IData)(vlSelf->cmd_payload_function_id))) {
                    vlSelf->rsp_payload_outputs_0 = 0U;
                    __Vdly__rsp_valid = 1U;
                } else {
                    vlSelf->rsp_payload_outputs_0 = 0U;
                    __Vdly__rsp_valid = 1U;
                }
            } else if ((1U & (IData)(vlSelf->cmd_payload_function_id))) {
                vlSelf->rsp_payload_outputs_0 = 0U;
                __Vdly__rsp_valid = 1U;
            } else {
                vlSelf->rsp_payload_outputs_0 = 0U;
                __Vdly__rsp_valid = 1U;
            }
        }
        vlSelf->mnv2_depthwise_cfu__DOT__done = 0U;
        if (((~ (IData)(vlSelf->mnv2_depthwise_cfu__DOT__busy)) 
             & (0U == (IData)(vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__state)))) {
            if (vlSelf->mnv2_depthwise_cfu__DOT__ifmap_wr_en) {
                __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__ifmap_mem__v0 
                    = vlSelf->mnv2_depthwise_cfu__DOT__ifmap_wr_data;
                __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__ifmap_mem__v0 = 1U;
                __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__ifmap_mem__v0 
                    = vlSelf->mnv2_depthwise_cfu__DOT__ifmap_wr_addr;
            }
            if (((IData)(vlSelf->mnv2_depthwise_cfu__DOT__exp_wr_en) 
                 & (0xc0U > (IData)(vlSelf->mnv2_depthwise_cfu__DOT__exp_wr_addr)))) {
                vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_hc52db093__0 
                    = vlSelf->mnv2_depthwise_cfu__DOT__exp_wr_data;
                if ((0xbfU >= (IData)(vlSelf->mnv2_depthwise_cfu__DOT__exp_wr_addr))) {
                    __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_w_mem__v0 
                        = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_hc52db093__0;
                    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_w_mem__v0 = 1U;
                    __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_w_mem__v0 
                        = vlSelf->mnv2_depthwise_cfu__DOT__exp_wr_addr;
                }
            }
            if (((IData)(vlSelf->mnv2_depthwise_cfu__DOT__dw_wr_en) 
                 & (0xd8U > (IData)(vlSelf->mnv2_depthwise_cfu__DOT__dw_wr_addr)))) {
                vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_hc4d36ef5__0 
                    = vlSelf->mnv2_depthwise_cfu__DOT__dw_wr_data;
                if ((0xd7U >= (IData)(vlSelf->mnv2_depthwise_cfu__DOT__dw_wr_addr))) {
                    __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_w_mem__v0 
                        = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_hc4d36ef5__0;
                    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_w_mem__v0 = 1U;
                    __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_w_mem__v0 
                        = vlSelf->mnv2_depthwise_cfu__DOT__dw_wr_addr;
                }
            }
            if (((IData)(vlSelf->mnv2_depthwise_cfu__DOT__proj_wr_en) 
                 & (0x180U > (IData)(vlSelf->mnv2_depthwise_cfu__DOT__proj_wr_addr)))) {
                vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_hf9dfa5c7__0 
                    = vlSelf->mnv2_depthwise_cfu__DOT__proj_wr_data;
                if ((0x17fU >= (IData)(vlSelf->mnv2_depthwise_cfu__DOT__proj_wr_addr))) {
                    __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_w_mem__v0 
                        = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_hf9dfa5c7__0;
                    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_w_mem__v0 = 1U;
                    __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_w_mem__v0 
                        = vlSelf->mnv2_depthwise_cfu__DOT__proj_wr_addr;
                }
            }
        }
        if ((4U & (IData)(vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__state))) {
            if ((2U & (IData)(vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__state))) {
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__state = 0U;
                __Vdly__mnv2_depthwise_cfu__DOT__busy = 0U;
                vlSelf->mnv2_depthwise_cfu__DOT__done = 0U;
            } else if ((1U & (IData)(vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__state))) {
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__state = 0U;
                __Vdly__mnv2_depthwise_cfu__DOT__busy = 0U;
                vlSelf->mnv2_depthwise_cfu__DOT__done = 0U;
            } else {
                __Vdly__mnv2_depthwise_cfu__DOT__busy = 0U;
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__state = 0U;
            }
        } else if ((2U & (IData)(vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__state))) {
            if ((1U & (IData)(vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__state))) {
                __Vdly__mnv2_depthwise_cfu__DOT__busy = 1U;
                vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_idx 
                    = (VL_MULS_III(32, (IData)(0x18U), vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx) 
                       + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_ch);
                vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_idx 
                    = (VL_MULS_III(32, (IData)(0x18U), vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__out_ch) 
                       + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_ch);
                vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__out_idx 
                    = (VL_MULS_III(32, (IData)(0x10U), vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx) 
                       + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__out_ch);
                vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__product 
                    = VL_MULS_III(32, ((0x17fU >= (0x1ffU 
                                                   & vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_idx))
                                        ? vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem
                                       [(0x1ffU & vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_idx)]
                                        : 0U), VL_EXTENDS_II(32,8, 
                                                             ((0x17fU 
                                                               >= 
                                                               (0x1ffU 
                                                                & vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_idx))
                                                               ? 
                                                              vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_w_mem
                                                              [
                                                              (0x1ffU 
                                                               & vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_idx)]
                                                               : 0U)));
                if ((0x17U == vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_ch)) {
                    __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem__v0 
                        = (vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_acc_reg 
                           + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__product);
                    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem__v0 = 1U;
                    __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem__v0 
                        = (0xffU & vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__out_idx);
                    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_ch = 0U;
                    if ((0xfU == vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__out_ch)) {
                        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__out_ch = 0U;
                        if ((3U == vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__col_cnt)) {
                            __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__col_cnt = 0U;
                            if ((3U == vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__row_cnt)) {
                                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__row_cnt = 0U;
                                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx = 0U;
                                __Vdly__mnv2_depthwise_cfu__DOT__busy = 0U;
                                vlSelf->mnv2_depthwise_cfu__DOT__done = 1U;
                                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__state = 4U;
                            } else {
                                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__row_cnt 
                                    = ((IData)(1U) 
                                       + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__row_cnt);
                                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx 
                                    = ((IData)(1U) 
                                       + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx);
                                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch = 0U;
                                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt = 0U;
                                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_acc_reg = 0U;
                                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__state = 1U;
                            }
                        } else {
                            __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__col_cnt 
                                = ((IData)(1U) + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__col_cnt);
                            __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx 
                                = ((IData)(1U) + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx);
                            __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch = 0U;
                            __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt = 0U;
                            __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_acc_reg = 0U;
                            __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__state = 1U;
                        }
                    } else {
                        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__out_ch 
                            = ((IData)(1U) + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__out_ch);
                    }
                    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_acc_reg = 0U;
                } else {
                    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_acc_reg 
                        = (vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_acc_reg 
                           + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__product);
                    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_ch 
                        = ((IData)(1U) + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_ch);
                }
            } else {
                vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__rr 
                    = ((vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__row_cnt 
                        + VL_DIVS_III(32, vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap, (IData)(3U))) 
                       - (IData)(1U));
                vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__cc 
                    = ((vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__col_cnt 
                        + VL_MODDIVS_III(32, vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap, (IData)(3U))) 
                       - (IData)(1U));
                __Vdly__mnv2_depthwise_cfu__DOT__busy = 1U;
                if ((((VL_LTES_III(32, 0U, vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__rr) 
                       & VL_GTS_III(32, 4U, vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__rr)) 
                      & VL_LTES_III(32, 0U, vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__cc)) 
                     & VL_GTS_III(32, 4U, vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__cc))) {
                    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__neigh_idx 
                        = (VL_MULS_III(32, (IData)(0x18U), 
                                       (VL_MULS_III(32, (IData)(4U), vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__rr) 
                                        + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__cc)) 
                           + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch);
                    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__product 
                        = VL_MULS_III(32, ((0x17fU 
                                            >= (0x1ffU 
                                                & vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__neigh_idx))
                                            ? vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem
                                           [(0x1ffU 
                                             & vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__neigh_idx)]
                                            : 0U), 
                                      VL_EXTENDS_II(32,8, 
                                                    ((0xd7U 
                                                      >= 
                                                      (0xffU 
                                                       & (VL_MULS_III(32, (IData)(9U), vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch) 
                                                          + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap)))
                                                      ? 
                                                     vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_w_mem
                                                     [
                                                     (0xffU 
                                                      & (VL_MULS_III(32, (IData)(9U), vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch) 
                                                         + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap))]
                                                      : 0U)));
                } else {
                    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__product = 0U;
                }
                if ((8U == vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap)) {
                    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_h9a256d64__0 
                        = (vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_acc_reg 
                           + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__product);
                    if ((0x17fU >= (0x1ffU & (VL_MULS_III(32, (IData)(0x18U), vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx) 
                                              + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch)))) {
                        __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem__v0 
                            = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_h9a256d64__0;
                        __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem__v0 = 1U;
                        __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem__v0 
                            = (0x1ffU & (VL_MULS_III(32, (IData)(0x18U), vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx) 
                                         + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch));
                    }
                    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap = 0U;
                    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_acc_reg = 0U;
                    if ((0x17U == vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch)) {
                        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch = 0U;
                        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__out_ch = 0U;
                        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_ch = 0U;
                        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_acc_reg = 0U;
                        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__state = 3U;
                    } else {
                        __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch 
                            = ((IData)(1U) + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch);
                    }
                } else {
                    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_acc_reg 
                        = (vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_acc_reg 
                           + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__product);
                    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap 
                        = ((IData)(1U) + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap);
                }
            }
        } else if ((1U & (IData)(vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__state))) {
            vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__if_idx 
                = (VL_MULS_III(32, (IData)(8U), vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx) 
                   + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt);
            vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_idx 
                = (VL_MULS_III(32, (IData)(0x18U), vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx) 
                   + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch);
            __Vdly__mnv2_depthwise_cfu__DOT__busy = 1U;
            vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__product 
                = VL_MULS_III(32, VL_EXTENDS_II(32,8, 
                                                vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__ifmap_mem
                                                [(0x7fU 
                                                  & vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__if_idx)]), 
                              VL_EXTENDS_II(32,8, (
                                                   (0xbfU 
                                                    >= 
                                                    (0xffU 
                                                     & (VL_MULS_III(32, (IData)(8U), vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch) 
                                                        + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt)))
                                                    ? 
                                                   vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_w_mem
                                                   [
                                                   (0xffU 
                                                    & (VL_MULS_III(32, (IData)(8U), vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch) 
                                                       + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt))]
                                                    : 0U)));
            if ((7U == vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt)) {
                vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_h5c35e5fd__0 
                    = (vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_acc_reg 
                       + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__product);
                if ((0x17fU >= (0x1ffU & vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_idx))) {
                    __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem__v0 
                        = vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_h5c35e5fd__0;
                    __Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem__v0 = 1U;
                    __Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem__v0 
                        = (0x1ffU & vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_idx);
                }
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt = 0U;
                if ((0x17U == vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch)) {
                    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch = 0U;
                    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch = 0U;
                    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap = 0U;
                    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_acc_reg = 0U;
                    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__state = 2U;
                } else {
                    __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch 
                        = ((IData)(1U) + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch);
                }
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_acc_reg = 0U;
            } else {
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_acc_reg 
                    = (vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_acc_reg 
                       + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__product);
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt 
                    = ((IData)(1U) + vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt);
            }
        } else {
            __Vdly__mnv2_depthwise_cfu__DOT__busy = 0U;
            if (vlSelf->mnv2_depthwise_cfu__DOT__start) {
                __Vdly__mnv2_depthwise_cfu__DOT__busy = 1U;
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__row_cnt = 0U;
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__col_cnt = 0U;
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx = 0U;
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch = 0U;
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt = 0U;
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch = 0U;
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap = 0U;
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__out_ch = 0U;
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_ch = 0U;
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_acc_reg = 0U;
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_acc_reg = 0U;
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_acc_reg = 0U;
                __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__state = 1U;
            }
        }
        vlSelf->mnv2_depthwise_cfu__DOT__ifmap_wr_en = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__exp_wr_en = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__dw_wr_en = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__proj_wr_en = 0U;
        vlSelf->mnv2_depthwise_cfu__DOT__start = 0U;
        if (((IData)(vlSelf->cmd_valid) & (IData)(vlSelf->cmd_ready))) {
            if ((4U & (IData)(vlSelf->cmd_payload_function_id))) {
                if ((2U & (IData)(vlSelf->cmd_payload_function_id))) {
                    if ((1U & (~ (IData)(vlSelf->cmd_payload_function_id)))) {
                        vlSelf->mnv2_depthwise_cfu__DOT__out_rd_addr 
                            = (0xffU & vlSelf->cmd_payload_inputs_0);
                    }
                }
                if ((1U & (~ ((IData)(vlSelf->cmd_payload_function_id) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelf->cmd_payload_function_id)))) {
                        if ((1U & (~ (IData)(vlSelf->mnv2_depthwise_cfu__DOT__busy)))) {
                            vlSelf->mnv2_depthwise_cfu__DOT__start = 1U;
                        }
                    }
                }
            }
            if ((1U & (~ ((IData)(vlSelf->cmd_payload_function_id) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelf->cmd_payload_function_id) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelf->cmd_payload_function_id)))) {
                        vlSelf->mnv2_depthwise_cfu__DOT__ifmap_wr_en = 1U;
                        vlSelf->mnv2_depthwise_cfu__DOT__ifmap_wr_data 
                            = (0xffU & vlSelf->cmd_payload_inputs_1);
                        vlSelf->mnv2_depthwise_cfu__DOT__ifmap_wr_addr 
                            = (0x7fU & vlSelf->cmd_payload_inputs_0);
                    }
                    if ((1U & (IData)(vlSelf->cmd_payload_function_id))) {
                        vlSelf->mnv2_depthwise_cfu__DOT__exp_wr_en = 1U;
                        vlSelf->mnv2_depthwise_cfu__DOT__exp_wr_data 
                            = (0xffU & vlSelf->cmd_payload_inputs_1);
                        vlSelf->mnv2_depthwise_cfu__DOT__exp_wr_addr 
                            = (0xffU & vlSelf->cmd_payload_inputs_0);
                    }
                }
                if ((2U & (IData)(vlSelf->cmd_payload_function_id))) {
                    if ((1U & (~ (IData)(vlSelf->cmd_payload_function_id)))) {
                        vlSelf->mnv2_depthwise_cfu__DOT__dw_wr_en = 1U;
                        vlSelf->mnv2_depthwise_cfu__DOT__dw_wr_data 
                            = (0xffU & vlSelf->cmd_payload_inputs_1);
                        vlSelf->mnv2_depthwise_cfu__DOT__dw_wr_addr 
                            = (0xffU & vlSelf->cmd_payload_inputs_0);
                    }
                    if ((1U & (IData)(vlSelf->cmd_payload_function_id))) {
                        vlSelf->mnv2_depthwise_cfu__DOT__proj_wr_en = 1U;
                        vlSelf->mnv2_depthwise_cfu__DOT__proj_wr_data 
                            = (0xffU & vlSelf->cmd_payload_inputs_1);
                        vlSelf->mnv2_depthwise_cfu__DOT__proj_wr_addr 
                            = (0x1ffU & vlSelf->cmd_payload_inputs_0);
                    }
                }
            }
        }
    }
    vlSelf->rsp_valid = __Vdly__rsp_valid;
    vlSelf->mnv2_depthwise_cfu__DOT__read_pending = __Vdly__mnv2_depthwise_cfu__DOT__read_pending;
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__state 
        = __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__state;
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__row_cnt 
        = __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__row_cnt;
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__col_cnt 
        = __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__col_cnt;
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx 
        = __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx;
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch 
        = __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch;
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt 
        = __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt;
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch 
        = __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch;
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap 
        = __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap;
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__out_ch 
        = __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__out_ch;
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_ch 
        = __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_ch;
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_acc_reg 
        = __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_acc_reg;
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_acc_reg 
        = __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_acc_reg;
    vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_acc_reg 
        = __Vdly__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_acc_reg;
    if (__Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__ifmap_mem__v0) {
        vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__ifmap_mem[__Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__ifmap_mem__v0] 
            = __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__ifmap_mem__v0;
    }
    if (__Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_w_mem__v0) {
        vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_w_mem[__Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_w_mem__v0] 
            = __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_w_mem__v0;
    }
    if (__Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_w_mem__v0) {
        vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_w_mem[__Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_w_mem__v0] 
            = __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_w_mem__v0;
    }
    if (__Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_w_mem__v0) {
        vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_w_mem[__Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_w_mem__v0] 
            = __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_w_mem__v0;
    }
    if (__Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem__v0) {
        vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem[__Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem__v0] 
            = __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem__v0;
    }
    if (__Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem__v0) {
        vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem[__Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem__v0] 
            = __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem__v0;
    }
    if (__Vdlyvset__mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem__v0) {
        vlSelf->mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem[__Vdlyvdim0__mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem__v0] 
            = __Vdlyvval__mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem__v0;
    }
    vlSelf->mnv2_depthwise_cfu__DOT__busy = __Vdly__mnv2_depthwise_cfu__DOT__busy;
    vlSelf->cmd_ready = (1U & (~ ((IData)(vlSelf->reset) 
                                  | ((IData)(vlSelf->mnv2_depthwise_cfu__DOT__read_pending) 
                                     | (IData)(vlSelf->rsp_valid)))));
}

void Vmnv2_depthwise_cfu___024root___eval_nba(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vmnv2_depthwise_cfu___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vmnv2_depthwise_cfu___024root___eval_triggers__act(Vmnv2_depthwise_cfu___024root* vlSelf);

bool Vmnv2_depthwise_cfu___024root___eval_phase__act(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vmnv2_depthwise_cfu___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vmnv2_depthwise_cfu___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vmnv2_depthwise_cfu___024root___eval_phase__nba(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vmnv2_depthwise_cfu___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmnv2_depthwise_cfu___024root___dump_triggers__ico(Vmnv2_depthwise_cfu___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmnv2_depthwise_cfu___024root___dump_triggers__nba(Vmnv2_depthwise_cfu___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmnv2_depthwise_cfu___024root___dump_triggers__act(Vmnv2_depthwise_cfu___024root* vlSelf);
#endif  // VL_DEBUG

void Vmnv2_depthwise_cfu___024root___eval(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vmnv2_depthwise_cfu___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/mnv2_depthwise_cfu.v", 3, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vmnv2_depthwise_cfu___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vmnv2_depthwise_cfu___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/mnv2_depthwise_cfu.v", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vmnv2_depthwise_cfu___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/mnv2_depthwise_cfu.v", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vmnv2_depthwise_cfu___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vmnv2_depthwise_cfu___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vmnv2_depthwise_cfu___024root___eval_debug_assertions(Vmnv2_depthwise_cfu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmnv2_depthwise_cfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmnv2_depthwise_cfu___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->cmd_valid & 0xfeU))) {
        Verilated::overWidthError("cmd_valid");}
    if (VL_UNLIKELY((vlSelf->cmd_payload_function_id 
                     & 0xf8U))) {
        Verilated::overWidthError("cmd_payload_function_id");}
    if (VL_UNLIKELY((vlSelf->rsp_ready & 0xfeU))) {
        Verilated::overWidthError("rsp_ready");}
}
#endif  // VL_DEBUG
