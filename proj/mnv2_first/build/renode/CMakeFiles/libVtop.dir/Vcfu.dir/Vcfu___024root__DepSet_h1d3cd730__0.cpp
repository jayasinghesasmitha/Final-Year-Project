// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcfu.h for the primary calling header

#include "Vcfu__pch.h"
#include "Vcfu___024root.h"

extern const VlUnpacked<CData/*0:0*/, 64> Vcfu__ConstPool__TABLE_hac88bb16_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vcfu__ConstPool__TABLE_hda23d5a5_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vcfu__ConstPool__TABLE_h70b41e53_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vcfu__ConstPool__TABLE_h7c969f7e_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vcfu__ConstPool__TABLE_h3f46fc78_0;

VL_INLINE_OPT void Vcfu___024root___ico_sequent__TOP__0(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___ico_sequent__TOP__0\n"); );
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
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*5:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
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
    vlSelf->rst = vlSelf->reset;
    vlSelf->Cfu__DOT__current_function_id = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_0;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0_data;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_1;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1_data;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_2;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2_data;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_3;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3_data;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_restart;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_data;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_restart;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_data;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_restart;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_data;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_restart;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_data;
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
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_1__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_0;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_2__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_1;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_3__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_2;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__breg__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT___0_;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc__DOT__last_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc_r_addr;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc__DOT__last_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc_r_addr;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc__DOT__last_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc_r_addr;
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce;
    if (vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT____0248) {
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce__024next 
            = ((0x1feU == (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce))
                ? 0U : (0x1ffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce))));
    }
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
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register__024next 
        = ((0xeU & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register) 
                    << 1U)) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count_done));
    if ((8U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register))) {
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count__024next 
            = ((3U == (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count))
                ? 0U : (7U & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count))));
        vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register;
        vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__calc;
    } else {
        vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register;
    }
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__last_full__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__full;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__areg__024next 
        = ((IData)((0x7fffffffffffffffULL & VL_EXTENDS_QI(63,32, 
                                                          ((IData)(
                                                                   (0x1ffffffffULL 
                                                                    & VL_EXTENDS_QI(33,32, vlSelf->Cfu__DOT__fn0__DOT__acc_result))) 
                                                           + (IData)(
                                                                     (0x1ffffffffULL 
                                                                      & VL_EXTENDS_QI(33,32, vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT___0_))))))) 
           << (IData)(vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__left_shift));
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count;
    if (vlSelf->Cfu__DOT__fn0__DOT__fvf_next) {
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count__024next 
            = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT____02412)
                ? 0U : (0xfffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count))));
    }
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running;
    if (vlSelf->Cfu__DOT__fn0__DOT__start_run_set) {
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running__024next = 1U;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count_done) {
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running__024next = 0U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count;
    vlSelf->Cfu__DOT__stored_function_id__024next = vlSelf->Cfu__DOT__stored_function_id;
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
    if ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set)))) {
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank__024next = 0U;
    } else if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf_next) 
                              << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank__024next 
            = (3U & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank)));
    }
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
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__0249__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02419__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02429__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_1__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_2__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_3__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__breg__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc__DOT__last_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc__DOT__last_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc__DOT__last_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02432__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02412__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02422__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_shifted__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__overflow__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__ab__024next = 0ULL;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__result__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__madd_delay__DOT__shift_register__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__last_full__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__areg__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__stored_function_id__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_ready__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__result__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__f7buf__DOT__captured__024next = 0U;
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

void Vcfu___024root___eval_ico(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vcfu___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vcfu___024root___eval_triggers__ico(Vcfu___024root* vlSelf);

bool Vcfu___024root___eval_phase__ico(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vcfu___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vcfu___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vcfu___024root___eval_act(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_act\n"); );
}

extern const VlUnpacked<CData/*0:0*/, 16> Vcfu__ConstPool__TABLE_hd5e7ca01_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vcfu__ConstPool__TABLE_h226c588b_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vcfu__ConstPool__TABLE_h3f5f8a41_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vcfu__ConstPool__TABLE_h855003bb_0;

VL_INLINE_OPT void Vcfu___024root___nba_sequent__TOP__0(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___nba_sequent__TOP__0\n"); );
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
    CData/*3:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*2:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    CData/*2:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    SData/*8:0*/ __Vdlyvdim0__Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__storage__v0;
    __Vdlyvdim0__Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__storage__v0 = 0;
    IData/*31:0*/ __Vdlyvval__Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__storage__v0;
    __Vdlyvval__Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__storage__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__storage__v0;
    __Vdlyvset__Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__storage__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem__v0;
    __Vdlyvdim0__Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem__v0;
    __Vdlyvval__Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem__v0;
    __Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT__mem__v0;
    __Vdlyvdim0__Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT__mem__v0;
    __Vdlyvval__Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT__mem__v0;
    __Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT__mem__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT__mem__v0;
    __Vdlyvdim0__Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT__mem__v0;
    __Vdlyvval__Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT__mem__v0;
    __Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT__mem__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem__v0;
    __Vdlyvdim0__Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem__v0;
    __Vdlyvval__Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem__v0;
    __Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem__v0 = 0;
    SData/*8:0*/ __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT__mem__v0;
    __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT__mem__v0;
    __Vdlyvval__Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT__mem__v0;
    __Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT__mem__v0 = 0;
    SData/*8:0*/ __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT__mem__v0;
    __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT__mem__v0;
    __Vdlyvval__Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT__mem__v0;
    __Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT__mem__v0 = 0;
    SData/*8:0*/ __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT__mem__v0;
    __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT__mem__v0;
    __Vdlyvval__Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT__mem__v0;
    __Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT__mem__v0 = 0;
    SData/*8:0*/ __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT__mem__v0;
    __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT__mem__v0;
    __Vdlyvval__Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT__mem__v0;
    __Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT__mem__v0 = 0;
    SData/*8:0*/ __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT__mem__v0;
    __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT__mem__v0;
    __Vdlyvval__Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT__mem__v0;
    __Vdlyvset__Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT__mem__v0 = 0;
    SData/*8:0*/ __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT__mem__v0;
    __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT__mem__v0;
    __Vdlyvval__Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT__mem__v0;
    __Vdlyvset__Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT__mem__v0 = 0;
    SData/*8:0*/ __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT__mem__v0;
    __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT__mem__v0;
    __Vdlyvval__Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT__mem__v0;
    __Vdlyvset__Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT__mem__v0 = 0;
    // Body
    __Vdlyvset__Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT__mem__v0 = 0U;
    __Vdlyvset__Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT__mem__v0 = 0U;
    __Vdlyvset__Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT__mem__v0 = 0U;
    __Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem__v0 = 0U;
    __Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT__mem__v0 = 0U;
    __Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT__mem__v0 = 0U;
    __Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem__v0 = 0U;
    __Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT__mem__v0 = 0U;
    __Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT__mem__v0 = 0U;
    __Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT__mem__v0 = 0U;
    __Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT__mem__v0 = 0U;
    __Vdlyvset__Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__storage__v0 = 0U;
    if (vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set___024signal) {
        __Vdlyvval__Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT__mem__v0 
            = vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_w_data;
        __Vdlyvset__Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT__mem__v0 = 1U;
        __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT__mem__v0 
            = (0x1ffU & (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_count));
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set___024signal) {
        __Vdlyvval__Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT__mem__v0 
            = vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_w_data;
        __Vdlyvset__Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT__mem__v0 = 1U;
        __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT__mem__v0 
            = (0x1ffU & (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_count));
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set___024signal) {
        __Vdlyvval__Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT__mem__v0 
            = vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_w_data;
        __Vdlyvset__Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT__mem__v0 = 1U;
        __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT__mem__v0 
            = (0x1ffU & (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_count));
    }
    if (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____0241) 
         & (3U == (3U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr))))) {
        __Vdlyvval__Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem__v0 
            = vlSelf->Cfu__DOT__fn0__DOT__ins_set_w_data;
        __Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem__v0 = 1U;
        __Vdlyvdim0__Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem__v0 
            = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem_w_addr;
    }
    if (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____0241) 
         & (2U == (3U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr))))) {
        __Vdlyvval__Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT__mem__v0 
            = vlSelf->Cfu__DOT__fn0__DOT__ins_set_w_data;
        __Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT__mem__v0 = 1U;
        __Vdlyvdim0__Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT__mem__v0 
            = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem_w_addr;
    }
    if (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____0241) 
         & (1U == (3U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr))))) {
        __Vdlyvval__Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT__mem__v0 
            = vlSelf->Cfu__DOT__fn0__DOT__ins_set_w_data;
        __Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT__mem__v0 = 1U;
        __Vdlyvdim0__Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT__mem__v0 
            = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem_w_addr;
    }
    if (((~ (IData)((0U != (3U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr))))) 
         & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____0241))) {
        __Vdlyvval__Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem__v0 
            = vlSelf->Cfu__DOT__fn0__DOT__ins_set_w_data;
        __Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem__v0 = 1U;
        __Vdlyvdim0__Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem__v0 
            = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem_w_addr;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0243) {
        __Vdlyvval__Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT__mem__v0 
            = vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_w_data;
        __Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT__mem__v0 = 1U;
        __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT__mem__v0 
            = (0x1ffU & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count) 
                         >> 2U));
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0242) {
        __Vdlyvval__Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT__mem__v0 
            = vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_w_data;
        __Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT__mem__v0 = 1U;
        __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT__mem__v0 
            = (0x1ffU & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count) 
                         >> 2U));
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0241) {
        __Vdlyvval__Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT__mem__v0 
            = vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_w_data;
        __Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT__mem__v0 = 1U;
        __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT__mem__v0 
            = (0x1ffU & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count) 
                         >> 2U));
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal) {
        __Vdlyvval__Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT__mem__v0 
            = vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_w_data;
        __Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT__mem__v0 = 1U;
        __Vdlyvdim0__Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT__mem__v0 
            = (0x1ffU & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count) 
                         >> 2U));
    }
    if (((IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count_done) 
         & (0x1ffU != (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_level)))) {
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT____Vlvbound_h12409c5f__0 
            = vlSelf->Cfu__DOT__fn0__DOT__btw_result;
        if ((0x1feU >= (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce))) {
            __Vdlyvval__Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__storage__v0 
                = vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT____Vlvbound_h12409c5f__0;
            __Vdlyvset__Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__storage__v0 = 1U;
            __Vdlyvdim0__Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__storage__v0 
                = vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce;
        }
    }
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_2 
        = vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_2__024next;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_1 
        = vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_1__024next;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_3 
        = vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_3__024next;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm_result 
        = vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__result__024next;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__ab 
        = vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__ab__024next;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__overflow 
        = vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__overflow__024next;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc__DOT__last_addr 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc__DOT__last_addr__024next;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc__DOT__last_addr 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc__DOT__last_addr__024next;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc__DOT__last_addr 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc__DOT__last_addr__024next;
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__breg 
        = vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__breg__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_mem_addr 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_mem_addr__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_mem_addr 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_mem_addr__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_mem_addr 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_mem_addr__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_mem_addr 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_mem_addr__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_mem_addr 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_mem_addr__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_mem_addr 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_mem_addr__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_mem_addr 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_mem_addr__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_mem_addr 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_mem_addr__024next;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT___0_ 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT__mem
        [vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc_r_addr];
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__areg 
        = vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__areg__024next;
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02429 
        = vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02429__024next;
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02419 
        = vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02419__024next;
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__0249 
        = vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__0249__024next;
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp = vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__024next;
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02432 
        = vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02432__024next;
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02422 
        = vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02422__024next;
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02412 
        = vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02412__024next;
    vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp = vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__024next;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT___0_ 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT__mem
        [vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc_r_addr];
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT___0_ 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT__mem
        [vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc_r_addr];
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_shifted 
        = vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_shifted__024next;
    vlSelf->Cfu__DOT__stored_output = vlSelf->Cfu__DOT__stored_output__024next;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count 
        = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count__024next;
    vlSelf->Cfu__DOT__fn0__DOT__madd_result = vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__result__024next;
    vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register 
        = vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_data 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_data__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_data 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_data__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_data 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_data__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_data 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_data__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_data 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_data__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_data 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_data__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_data 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_data__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_data 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_data__024next;
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT___0_ 
        = vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT__mem
        [vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3_mem_addr];
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT___0_ 
        = vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT__mem
        [vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2_mem_addr];
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT___0_ 
        = vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT__mem
        [vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1_mem_addr];
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT___0_ 
        = vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT__mem
        [vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0_mem_addr];
    vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator 
        = vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator__024next;
    vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__value 
        = vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__value__024next;
    vlSelf->Cfu__DOT__fn0__DOT__set_output_depth__DOT__value 
        = vlSelf->Cfu__DOT__fn0__DOT__set_output_depth__DOT__value__024next;
    vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__value 
        = vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__value__024next;
    vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__value 
        = vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__value__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_next__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_restart 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_restart__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_next__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_restart 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_restart__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_next__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_restart 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_restart__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_next__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_restart 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_restart__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_next__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_restart 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_restart__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_next__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_restart 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_restart__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_next__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_restart 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_restart__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_next__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_restart 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_restart__024next;
    vlSelf->Cfu__DOT__fn0__DOT__mark_read_set = vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__set__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated__024next;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register 
        = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register__024next;
    vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_set 
        = vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words__DOT__set__024next;
    vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_value 
        = vlSelf->Cfu__DOT__fn0__DOT__set_activation_min__DOT__value__024next;
    vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_value 
        = vlSelf->Cfu__DOT__fn0__DOT__set_activation_max__DOT__value__024next;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count 
        = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count__024next;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank__024next;
    vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_value 
        = vlSelf->Cfu__DOT__fn0__DOT__set_input_offset__DOT__value__024next;
    vlSelf->Cfu__DOT__fn0__DOT__set_output_offset_value 
        = vlSelf->Cfu__DOT__fn0__DOT__set_output_offset__DOT__value__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr__024next;
    if (vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_r_en) {
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT___0_ 
            = ((0x1feU >= (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__consume))
                ? vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__storage
               [vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__consume]
                : 0U);
    }
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__madd_delay__DOT__shift_register 
        = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__madd_delay__DOT__shift_register__024next;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count 
        = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__last_full 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__last_full__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT__waiting 
        = vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT__waiting__024next;
    vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT__waiting 
        = vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT__waiting__024next;
    vlSelf->Cfu__DOT__fn0__DOT__start_run_set = vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__set__024next;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running 
        = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running__024next;
    vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set 
        = vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__set__024next;
    vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_value 
        = vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words__DOT__value__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins_r_ready = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_ready__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT___0_ 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem
        [(((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf) 
           << 9U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_mem_addr))];
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT___0_ 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT__mem
        [(((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf) 
           << 9U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_mem_addr))];
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT___0_ 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT__mem
        [(((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf) 
           << 9U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_mem_addr))];
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT___0_ 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem
        [(((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf) 
           << 9U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_mem_addr))];
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf__024next;
    vlSelf->Cfu__DOT__fn0__DOT__FIFO_r_rdy = vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__r_rdy__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_1 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_1__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_0 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_0__024next;
    vlSelf->Cfu__DOT__fn0__DOT__f7buf__DOT__captured 
        = vlSelf->Cfu__DOT__fn0__DOT__f7buf__DOT__captured__024next;
    vlSelf->Cfu__DOT__stored_function_id = vlSelf->Cfu__DOT__stored_function_id__024next;
    vlSelf->Cfu__DOT__fsm_state = vlSelf->Cfu__DOT__fsm_state__024next;
    if (__Vdlyvset__Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT__mem__v0) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT__mem[__Vdlyvdim0__Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT__mem__v0] 
            = __Vdlyvval__Cfu__DOT__fn0__DOT__store_output_multiplier_dp__DOT__mem__v0;
    }
    if (__Vdlyvset__Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT__mem__v0) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT__mem[__Vdlyvdim0__Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT__mem__v0] 
            = __Vdlyvval__Cfu__DOT__fn0__DOT__store_output_bias_dp__DOT__mem__v0;
    }
    if (__Vdlyvset__Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT__mem__v0) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT__mem[__Vdlyvdim0__Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT__mem__v0] 
            = __Vdlyvval__Cfu__DOT__fn0__DOT__store_output_shift_dp__DOT__mem__v0;
    }
    if (__Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT__mem__v0) {
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT__mem[__Vdlyvdim0__Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT__mem__v0] 
            = __Vdlyvval__Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT__mem__v0;
    }
    if (__Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT__mem__v0) {
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT__mem[__Vdlyvdim0__Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT__mem__v0] 
            = __Vdlyvval__Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT__mem__v0;
    }
    if (__Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT__mem__v0) {
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT__mem[__Vdlyvdim0__Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT__mem__v0] 
            = __Vdlyvval__Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT__mem__v0;
    }
    if (__Vdlyvset__Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT__mem__v0) {
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT__mem[__Vdlyvdim0__Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT__mem__v0] 
            = __Vdlyvval__Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT__mem__v0;
    }
    if (__Vdlyvset__Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__storage__v0) {
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__storage[__Vdlyvdim0__Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__storage__v0] 
            = __Vdlyvval__Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__storage__v0;
    }
    if (__Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem__v0) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem[__Vdlyvdim0__Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem__v0] 
            = __Vdlyvval__Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT__mem__v0;
    }
    if (__Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT__mem__v0) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT__mem[__Vdlyvdim0__Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT__mem__v0] 
            = __Vdlyvval__Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT__mem__v0;
    }
    if (__Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT__mem__v0) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT__mem[__Vdlyvdim0__Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT__mem__v0] 
            = __Vdlyvval__Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT__mem__v0;
    }
    if (__Vdlyvset__Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem__v0) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem[__Vdlyvdim0__Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem__v0] 
            = __Vdlyvval__Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem__v0;
    }
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_count 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set__DOT__count__024next;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_count 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set__DOT__count__024next;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_count 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set__DOT__count__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr__024next;
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count 
        = vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set__DOT__count__024next;
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce 
        = vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce__024next;
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_level 
        = vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__level__024next;
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
    vlSelf->Cfu__DOT__fn0__DOT__acc__DOT____VdfgExtracted_h784e4b37__0 
        = ((IData)((0x1ffffffffULL & VL_EXTENDS_QI(33,32, vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator))) 
           + (IData)((0x1ffffffffULL & VL_EXTENDS_QI(33,32, vlSelf->Cfu__DOT__fn0__DOT__madd_result))));
    Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT____02411 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_next) 
           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_restart));
    Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT____02411 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_next) 
           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_restart));
    Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT____02411 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_next) 
           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_restart));
    Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT____02411 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_next) 
           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_restart));
    Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT____02411 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_next) 
           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_restart));
    Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT____02411 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_next) 
           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_restart));
    Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT____02411 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_next) 
           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_restart));
    Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT____02411 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_next) 
           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_restart));
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count_done = 0U;
    Cfu__DOT__fn0__DOT__pp__DOT__with_offset = ((IData)(
                                                        (0x1ffffffffULL 
                                                         & VL_EXTENDS_QI(33,32, vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_shifted))) 
                                                + (IData)(
                                                          (0x1ffffffffULL 
                                                           & VL_EXTENDS_QI(33,32, vlSelf->Cfu__DOT__fn0__DOT__set_output_offset_value))));
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__consume 
        = vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__consume__024next;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT____02412 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count) 
           == (0xfffU & ((0x7ffU & vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_value) 
                         - (IData)(1U))));
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf__024next;
    vlSelf->Cfu__DOT__fn0__DOT__ins_w_ready = (1U & 
                                               ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf)
                                                 ? 
                                                (~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_1))
                                                 : 
                                                (~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_0))));
    vlSelf->cmd_ready = 0U;
    vlSelf->Cfu__DOT__current_function_id = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__acc_result = vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3_data 
        = ((IData)(Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT____02411)
            ? vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_3__DOT___0_
            : vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_data);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2_data 
        = ((IData)(Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT____02411)
            ? vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_2__DOT___0_
            : vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_data);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1_data 
        = ((IData)(Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT____02411)
            ? vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_1__DOT___0_
            : vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_data);
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0_data 
        = ((IData)(Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT____02411)
            ? vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_dp_0__DOT___0_
            : vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_data);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_data 
        = ((IData)(Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT____02411)
            ? vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_3__DOT___0_
            : vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_data);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_data 
        = ((IData)(Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT____02411)
            ? vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_2__DOT___0_
            : vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_data);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_data 
        = ((IData)(Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT____02411)
            ? vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_1__DOT___0_
            : vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_data);
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_data 
        = ((IData)(Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT____02411)
            ? vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT___0_
            : vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_data);
    vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__calc = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count_done = 0U;
    if ((2U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__madd_delay__DOT__shift_register))) {
        vlSelf->Cfu__DOT__fn0__DOT__acc_result = vlSelf->Cfu__DOT__fn0__DOT__acc__DOT____VdfgExtracted_h784e4b37__0;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count_done 
            = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT____02412;
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____02419 
        = ((~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_w_ready)) 
           & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT__waiting));
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
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__dp_0__DOT__mem_w_addr 
        = (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf) 
            << 9U) | (0x1ffU & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr) 
                                >> 2U)));
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____02440 = 
        ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr) 
         == (0xfffU & ((0x7ffU & vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_value) 
                       - (IData)(1U))));
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
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT____02412 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count) 
           == (0x1fffU & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count) 
                          - (IData)(1U))));
    if ((8U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register))) {
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count_done 
            = (3U == (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count));
    }
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT____0248 
        = ((0x1ffU != (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_level)) 
           & (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count_done));
    vlSelf->Cfu__DOT__fn0__DOT__fvf_next = (((IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running) 
                                             | (IData)(vlSelf->Cfu__DOT__fn0__DOT__start_run_set)) 
                                            & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_r_ready) 
                                               & (0x1f8U 
                                                  > 
                                                  (0x3ffU 
                                                   & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_level) 
                                                      + (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO_r_rdy))))));
    vlSelf->Cfu__DOT__fn0__DOT__fvf_data = ((2U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank))
                                             ? ((1U 
                                                 & (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank))
                                                 ? vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3_data
                                                 : vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2_data)
                                             : ((1U 
                                                 & (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank))
                                                 ? vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1_data
                                                 : vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0_data));
    vlSelf->Cfu__DOT__fn0__DOT__ins_r_data = ((2U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr))
                                               ? ((1U 
                                                   & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr))
                                                   ? vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_data
                                                   : vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_data)
                                               : ((1U 
                                                   & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr))
                                                   ? vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_data
                                                   : vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_data));
    vlSelf->Cfu__DOT__fn0__DOT__btw_result = vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register;
    if ((8U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register))) {
        vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__calc 
            = (((VL_LTS_III(32, Cfu__DOT__fn0__DOT__pp__DOT__with_offset, vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_value)
                  ? vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_value
                  : (VL_GTS_III(32, Cfu__DOT__fn0__DOT__pp__DOT__with_offset, vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_value)
                      ? vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_value
                      : Cfu__DOT__fn0__DOT__pp__DOT__with_offset)) 
                << 0x18U) | (vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register 
                             >> 8U));
        vlSelf->Cfu__DOT__fn0__DOT__btw_result = vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__calc;
    }
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc_r_addr 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc__DOT__last_addr;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc_r_addr 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc__DOT__last_addr;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc_r_addr 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc__DOT__last_addr;
    if ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set)))) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc_r_addr = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc_r_addr = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc_r_addr = 0U;
    } else if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count_done) 
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
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__full = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf)
                                                   ? (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_1)
                                                   : (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_0));
    Cfu__DOT__fn0__DOT__f7buf_output = (0x7fU & ((IData)(vlSelf->Cfu__DOT____024signal__0242)
                                                  ? 
                                                 ((IData)(vlSelf->cmd_payload_function_id) 
                                                  >> 3U)
                                                  : (IData)(vlSelf->Cfu__DOT__fn0__DOT__f7buf__DOT__captured)));
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
    if (vlSelf->Cfu__DOT__fn0__DOT__fvf_next) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____024101 
            = vlSelf->Cfu__DOT__fn0__DOT__ins_r_ready;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count_done = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count_done 
            = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT____02412;
    } else {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____024101 = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count_done = 0U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____02483 = 
        ((~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__last_full)) 
         & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__full));
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
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_next = 0U;
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
        if ((2U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr))) {
            if ((1U & (~ (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr)))) {
                vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_next = 1U;
            }
            if ((1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr))) {
                vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_next = 1U;
            }
        }
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins_r_finished = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__mark_read_set) 
                                                  | (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count_done));
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_restart = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_restart = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_restart = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_restart = 0U;
    if (vlSelf->Cfu__DOT__fn0__DOT__ins__DOT____02483) {
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_restart = 1U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_restart = 1U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_restart = 1U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_restart = 1U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set___024signal = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_w_data = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set___024signal = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_w_data = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set___024signal = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_w_data = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_w_data = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0241 = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0242 = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0243 = 0U;
    if ((0x15U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if ((1U != (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set)))) {
        if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_start) 
                           << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
            vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set___024signal = 1U;
            vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_w_data 
                = vlSelf->cmd_payload_inputs_0;
        }
    }
    if ((0x16U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if ((1U != (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set)))) {
        if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_start) 
                           << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
            vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set___024signal = 1U;
            vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_w_data 
                = vlSelf->cmd_payload_inputs_0;
        }
    }
    if ((0x17U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if ((1U != (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set)))) {
        if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_start) 
                           << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
            vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set___024signal = 1U;
            vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_w_data 
                = vlSelf->cmd_payload_inputs_0;
        }
    }
    if ((0x18U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if ((1U != (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set)))) {
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
    Cfu__DOT__fn0__DOT__set_activation_max_output = 0U;
    Cfu__DOT__fn0__DOT__set_activation_max_done = 0U;
    if ((0xfU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_start) {
        Cfu__DOT__fn0__DOT__set_activation_max_output 
            = vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_value;
        Cfu__DOT__fn0__DOT__set_activation_max_done = 1U;
    }
    Cfu__DOT__fn0__DOT__set_output_depth_output = 0U;
    Cfu__DOT__fn0__DOT__set_output_depth_done = 0U;
    if ((0xbU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__set_output_depth_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_output_depth_start) {
        Cfu__DOT__fn0__DOT__set_output_depth_output 
            = vlSelf->Cfu__DOT__fn0__DOT__set_output_depth__DOT__value;
        Cfu__DOT__fn0__DOT__set_output_depth_done = 1U;
    }
    Cfu__DOT__fn0__DOT__set_input_offset_output = 0U;
    Cfu__DOT__fn0__DOT__set_input_offset_done = 0U;
    if ((0xcU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_start) {
        Cfu__DOT__fn0__DOT__set_input_offset_output 
            = vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_value;
        Cfu__DOT__fn0__DOT__set_input_offset_done = 1U;
    }
    Cfu__DOT__fn0__DOT__set_output_offset_output = 0U;
    Cfu__DOT__fn0__DOT__set_output_offset_done = 0U;
    if ((0xdU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__set_output_offset_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_output_offset_start) {
        Cfu__DOT__fn0__DOT__set_output_offset_output 
            = vlSelf->Cfu__DOT__fn0__DOT__set_output_offset_value;
        Cfu__DOT__fn0__DOT__set_output_offset_done = 1U;
    }
    Cfu__DOT__fn0__DOT__set_activation_min_output = 0U;
    Cfu__DOT__fn0__DOT__set_activation_min_done = 0U;
    if ((0xeU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_start) {
        Cfu__DOT__fn0__DOT__set_activation_min_output 
            = vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_value;
        Cfu__DOT__fn0__DOT__set_activation_min_done = 1U;
    }
    Cfu__DOT__fn0__DOT__set_output_batch_size_output = 0U;
    Cfu__DOT__fn0__DOT__set_output_batch_size_done = 0U;
    if ((0x14U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_start) {
        Cfu__DOT__fn0__DOT__set_output_batch_size_output 
            = vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__value;
        Cfu__DOT__fn0__DOT__set_output_batch_size_done = 1U;
    }
    Cfu__DOT__fn0__DOT__mark_read_output = 0U;
    Cfu__DOT__fn0__DOT__mark_read_done = 0U;
    if ((0x70U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__mark_read_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__mark_read_start) {
        Cfu__DOT__fn0__DOT__mark_read_output = vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__value;
        Cfu__DOT__fn0__DOT__mark_read_done = 1U;
    }
    Cfu__DOT__fn0__DOT__start_run_output = 0U;
    Cfu__DOT__fn0__DOT__start_run_done = 0U;
    if ((0x21U == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__start_run_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__start_run_start) {
        Cfu__DOT__fn0__DOT__start_run_output = vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__value;
        Cfu__DOT__fn0__DOT__start_run_done = 1U;
    }
    Cfu__DOT__fn0__DOT__set_input_depth_words_output = 0U;
    Cfu__DOT__fn0__DOT__set_input_depth_words_done = 0U;
    if ((0xaU == (IData)(Cfu__DOT__fn0__DOT__f7buf_output))) {
        vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_start 
            = vlSelf->Cfu__DOT____024signal__0242;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_start) {
        Cfu__DOT__fn0__DOT__set_input_depth_words_output 
            = vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_value;
        Cfu__DOT__fn0__DOT__set_input_depth_words_done = 1U;
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
    vlSelf->Cfu__DOT__fn0__DOT__oq_get_next = 0U;
    Cfu__DOT__fn0__DOT__oq_get_output = 0U;
    Cfu__DOT__fn0__DOT__oq_get_done = 0U;
    if ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT____02411)))) {
        vlSelf->Cfu__DOT__fn0__DOT__oq_get_next = 1U;
        Cfu__DOT__fn0__DOT__oq_get_output = vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT___0_;
        Cfu__DOT__fn0__DOT__oq_get_done = 1U;
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
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT____02417 
        = ((0U != (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_level)) 
           & (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_r_en));
    vlSelf->Cfu__DOT__current_function_done = 0U;
    if ((0U == (IData)(vlSelf->Cfu__DOT__fsm_state))) {
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
        }
    } else if ((1U == (IData)(vlSelf->Cfu__DOT__fsm_state))) {
        vlSelf->rsp_payload_outputs_0 = vlSelf->Cfu__DOT__stored_output;
    }
}

VL_INLINE_OPT void Vcfu___024root___nba_sequent__TOP__1(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*5:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*4:0*/ __Vtableidx7;
    __Vtableidx7 = 0;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    // Body
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated;
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
    vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_1__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_0;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0_data;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1_data;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2_data;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3_data;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_data;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_data;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_data;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_data__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_data;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register__024next 
        = ((0xeU & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register) 
                    << 1U)) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count_done));
    if ((8U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register))) {
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count__024next 
            = ((3U == (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count))
                ? 0U : (7U & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count))));
        vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register;
        vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__calc;
    } else {
        vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register;
    }
    vlSelf->Cfu__DOT__fn0__DOT__f7buf__DOT__captured__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__f7buf__DOT__captured;
    if (vlSelf->Cfu__DOT____024signal__0242) {
        vlSelf->Cfu__DOT__fn0__DOT__f7buf__DOT__captured__024next 
            = (0x7fU & ((IData)(vlSelf->cmd_payload_function_id) 
                        >> 3U));
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
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce;
    if (vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT____0248) {
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce__024next 
            = ((0x1feU == (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce))
                ? 0U : (0x1ffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce))));
    }
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__madd_delay__DOT__shift_register__024next 
        = ((2U & ((IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__madd_delay__DOT__shift_register) 
                  << 1U)) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf_next));
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count;
    if (vlSelf->Cfu__DOT__fn0__DOT__fvf_next) {
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count__024next 
            = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT____02412)
                ? 0U : (0xfffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count))));
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
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc__DOT__last_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc_r_addr;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc__DOT__last_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc_r_addr;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc__DOT__last_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc_r_addr;
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
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_0;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_1;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_2;
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_next_3;
    vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running;
    if (vlSelf->Cfu__DOT__fn0__DOT__start_run_set) {
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running__024next = 1U;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count_done) {
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running__024next = 0U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__set__024next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words__DOT__set__024next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__set__024next = 0U;
    vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__set__024next = 0U;
    if (vlSelf->Cfu__DOT__fn0__DOT__mark_read_start) {
        vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__set__024next = 1U;
        vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__value__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__value;
        vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
    } else {
        vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__value__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__value;
    }
    vlSelf->Cfu__DOT__fn0__DOT__set_activation_max__DOT__value__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_value;
    if (vlSelf->Cfu__DOT__fn0__DOT__set_activation_max_start) {
        vlSelf->Cfu__DOT__fn0__DOT__set_activation_max__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
    }
    vlSelf->Cfu__DOT__fn0__DOT__set_activation_min__DOT__value__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_value;
    if (vlSelf->Cfu__DOT__fn0__DOT__set_activation_min_start) {
        vlSelf->Cfu__DOT__fn0__DOT__set_activation_min__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_start) {
        vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words__DOT__set__024next = 1U;
        vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words__DOT__value__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_value;
        vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
    } else {
        vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words__DOT__value__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words_value;
    }
    vlSelf->Cfu__DOT__fn0__DOT__set_input_offset__DOT__value__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_value;
    if (vlSelf->Cfu__DOT__fn0__DOT__set_input_offset_start) {
        vlSelf->Cfu__DOT__fn0__DOT__set_input_offset__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_start) {
        vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__set__024next = 1U;
        vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__value__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__value;
        vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
    } else {
        vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__value__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__value;
    }
    vlSelf->Cfu__DOT__fn0__DOT__set_output_depth__DOT__value__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__set_output_depth__DOT__value;
    if (vlSelf->Cfu__DOT__fn0__DOT__set_output_depth_start) {
        vlSelf->Cfu__DOT__fn0__DOT__set_output_depth__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
    }
    vlSelf->Cfu__DOT__fn0__DOT__set_output_offset__DOT__value__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__set_output_offset_value;
    if (vlSelf->Cfu__DOT__fn0__DOT__set_output_offset_start) {
        vlSelf->Cfu__DOT__fn0__DOT__set_output_offset__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
    }
    if (vlSelf->Cfu__DOT__fn0__DOT__start_run_start) {
        vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__set__024next = 1U;
        vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__value__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__value;
        vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__value__024next 
            = vlSelf->cmd_payload_inputs_0;
    } else {
        vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__value__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__value;
    }
    vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set__DOT__count__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set__DOT__count__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_count;
    vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set__DOT__count__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_count;
    if ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set)))) {
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set__DOT__count__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_count;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set__DOT__count__024next = 0U;
    } else {
        if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf_next) 
                           << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
            vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank__024next 
                = (3U & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank)));
        }
        if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_start) 
                           << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
            vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set__DOT__count__024next 
                = (0xfffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set_count)));
        }
        if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_start) 
                           << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
            vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set__DOT__count__024next 
                = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set_count)));
        }
        if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_start) 
                           << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
            vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set__DOT__count__024next 
                = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set_count)));
        }
        vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set__DOT__count__024next 
            = vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_count;
        if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_start) 
                           << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set))))) {
            vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set__DOT__count__024next 
                = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set_count)));
        }
    }
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_next;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_next__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_next;
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
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_restart;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_restart;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_restart;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_restart__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_restart;
    vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT__waiting__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT__waiting;
    if ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT____02411)))) {
        vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT__waiting__024next = 0U;
    } else if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT____02415) 
                              << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT____02411))))) {
        vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT__waiting__024next = 1U;
    }
    vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated__024next 
        = ((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0243) 
           | ((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0242) 
              | ((IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal) 
                 | ((IData)(vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size_set) 
                    | (IData)(vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set___024signal__0241)))));
    __Vtableidx7 = (((IData)(vlSelf->rst) << 4U) | 
                    (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____0241) 
                      << 3U) | (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____02415) 
                                 << 2U) | (((IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT____02419) 
                                            << 1U) 
                                           | (IData)(vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT__waiting)))));
    vlSelf->Cfu__DOT__fn0__DOT__ins_set__DOT__waiting__024next 
        = Vcfu__ConstPool__TABLE_hda23d5a5_0[__Vtableidx7];
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_mem_addr__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3_mem_addr;
    vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__r_rdy__024next 
        = vlSelf->Cfu__DOT__fn0__DOT__FIFO_r_rdy;
    if ((1U == (1U & (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_r_en)))) {
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__r_rdy__024next = 1U;
    } else if ((2U == (2U & (((IData)(vlSelf->Cfu__DOT__fn0__DOT__oq_get_next) 
                              << 1U) | (IData)(vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered_r_en))))) {
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__r_rdy__024next = 0U;
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
    }
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
    if (vlSelf->rst) {
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_2__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_3__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__breg__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_shifted__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__overflow__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__ab__024next = 0ULL;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__result__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__four_count__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__stored_function_id__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__result__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__right_sr_1__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__i_count__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_data__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__pp_delay__DOT__shift_register__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__btw__DOT__register__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__f7buf__DOT__captured__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__pp__DOT__srdhm__DOT__areg__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__acc__DOT__accumulator__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__produce__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__madd_delay__DOT__shift_register__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__curr_bank__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__f_count__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__0249__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02419__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__f_tmp__02429__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_inc__DOT__last_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_inc__DOT__last_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_inc__DOT__last_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02432__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02412__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__madd__DOT__i_tmp__02422__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_0__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_1__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_2__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__smr_3__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__seq__DOT__gate_calc__DOT__running__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__set__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words__DOT__set__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__set__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__set__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__mark_read__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_activation_max__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_activation_min__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_input_depth_words__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_input_offset__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_output_batch_size__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_output_depth__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__set_output_offset__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__start_run__DOT__value__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_filter_values_set__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_bias_set__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_multiplier_set__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__store_output_shift_set__DOT__count__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_next__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__last_full__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_curr_buf__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_ready__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__was_restart__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__oq_get__DOT__waiting__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__fvf__DOT__was_updated__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_0__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_1__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_2__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__smr_3__DOT__last_mem_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__r_rdy__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_addr__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__w_curr_buf__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_0__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__ins__DOT__r_full_1__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__consume__024next = 0U;
        vlSelf->Cfu__DOT__fn0__DOT__FIFO__DOT__unbuffered__DOT__level__024next = 0U;
        vlSelf->Cfu__DOT__stored_output__024next = 0U;
    }
}

void Vcfu___024root___eval_nba(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vcfu___024root___nba_sequent__TOP__0(vlSelf);
        Vcfu___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vcfu___024root___eval_triggers__act(Vcfu___024root* vlSelf);

bool Vcfu___024root___eval_phase__act(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vcfu___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vcfu___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vcfu___024root___eval_phase__nba(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vcfu___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcfu___024root___dump_triggers__ico(Vcfu___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcfu___024root___dump_triggers__nba(Vcfu___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcfu___024root___dump_triggers__act(Vcfu___024root* vlSelf);
#endif  // VL_DEBUG

void Vcfu___024root___eval(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval\n"); );
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
            Vcfu___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/proj/mnv2_first/cfu.v", 6, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vcfu___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vcfu___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/proj/mnv2_first/cfu.v", 6, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vcfu___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/proj/mnv2_first/cfu.v", 6, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vcfu___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vcfu___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vcfu___024root___eval_debug_assertions(Vcfu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcfu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcfu___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->cmd_payload_function_id 
                     & 0xfc00U))) {
        Verilated::overWidthError("cmd_payload_function_id");}
    if (VL_UNLIKELY((vlSelf->rsp_ready & 0xfeU))) {
        Verilated::overWidthError("rsp_ready");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->cmd_valid & 0xfeU))) {
        Verilated::overWidthError("cmd_valid");}
}
#endif  // VL_DEBUG
