// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmnv2_depthwise_cfu.h for the primary calling header

#ifndef VERILATED_VMNV2_DEPTHWISE_CFU___024ROOT_H_
#define VERILATED_VMNV2_DEPTHWISE_CFU___024ROOT_H_  // guard

#include "verilated.h"


class Vmnv2_depthwise_cfu__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmnv2_depthwise_cfu___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(cmd_valid,0,0);
        VL_OUT8(cmd_ready,0,0);
        VL_IN8(cmd_payload_function_id,2,0);
        VL_OUT8(rsp_valid,0,0);
        VL_IN8(rsp_ready,0,0);
        CData/*0:0*/ mnv2_depthwise_cfu__DOT__busy;
        CData/*0:0*/ mnv2_depthwise_cfu__DOT__done;
        CData/*0:0*/ mnv2_depthwise_cfu__DOT__start;
        CData/*0:0*/ mnv2_depthwise_cfu__DOT__ifmap_wr_en;
        CData/*6:0*/ mnv2_depthwise_cfu__DOT__ifmap_wr_addr;
        CData/*7:0*/ mnv2_depthwise_cfu__DOT__ifmap_wr_data;
        CData/*0:0*/ mnv2_depthwise_cfu__DOT__exp_wr_en;
        CData/*7:0*/ mnv2_depthwise_cfu__DOT__exp_wr_addr;
        CData/*7:0*/ mnv2_depthwise_cfu__DOT__exp_wr_data;
        CData/*0:0*/ mnv2_depthwise_cfu__DOT__dw_wr_en;
        CData/*7:0*/ mnv2_depthwise_cfu__DOT__dw_wr_addr;
        CData/*7:0*/ mnv2_depthwise_cfu__DOT__dw_wr_data;
        CData/*0:0*/ mnv2_depthwise_cfu__DOT__proj_wr_en;
        CData/*7:0*/ mnv2_depthwise_cfu__DOT__proj_wr_data;
        CData/*7:0*/ mnv2_depthwise_cfu__DOT__out_rd_addr;
        CData/*0:0*/ mnv2_depthwise_cfu__DOT__read_pending;
        CData/*2:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__state;
        CData/*7:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_hc52db093__0;
        CData/*7:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_hc4d36ef5__0;
        CData/*7:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_hf9dfa5c7__0;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __VactContinue;
        SData/*8:0*/ mnv2_depthwise_cfu__DOT__proj_wr_addr;
        VL_IN(cmd_payload_inputs_0,31,0);
        VL_IN(cmd_payload_inputs_1,31,0);
        VL_OUT(rsp_payload_outputs_0,31,0);
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__row_cnt;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__col_cnt;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__spatial_idx;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_ch;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__cin_cnt;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_ch;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_tap;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__out_ch;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_ch;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_acc_reg;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_acc_reg;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_acc_reg;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__rr;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__cc;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__if_idx;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_idx;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_idx;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_idx;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__out_idx;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__neigh_idx;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__product;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT__i;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_h50c84ad7__0;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_hfc1f09b4__0;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_h5c35e5fd__0;
        IData/*31:0*/ mnv2_depthwise_cfu__DOT__accelerator__DOT____Vlvbound_h9a256d64__0;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*7:0*/, 128> mnv2_depthwise_cfu__DOT__accelerator__DOT__ifmap_mem;
        VlUnpacked<CData/*7:0*/, 192> mnv2_depthwise_cfu__DOT__accelerator__DOT__exp_w_mem;
    };
    struct {
        VlUnpacked<CData/*7:0*/, 216> mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_w_mem;
        VlUnpacked<CData/*7:0*/, 384> mnv2_depthwise_cfu__DOT__accelerator__DOT__proj_w_mem;
        VlUnpacked<IData/*31:0*/, 384> mnv2_depthwise_cfu__DOT__accelerator__DOT__expanded_mem;
        VlUnpacked<IData/*31:0*/, 384> mnv2_depthwise_cfu__DOT__accelerator__DOT__dw_mem;
        VlUnpacked<IData/*31:0*/, 256> mnv2_depthwise_cfu__DOT__accelerator__DOT__output_mem;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vmnv2_depthwise_cfu__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmnv2_depthwise_cfu___024root(Vmnv2_depthwise_cfu__Syms* symsp, const char* v__name);
    ~Vmnv2_depthwise_cfu___024root();
    VL_UNCOPYABLE(Vmnv2_depthwise_cfu___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
