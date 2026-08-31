// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmnv2_depthwise_cfu__pch.h"

//============================================================
// Constructors

Vmnv2_depthwise_cfu::Vmnv2_depthwise_cfu(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmnv2_depthwise_cfu__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , cmd_valid{vlSymsp->TOP.cmd_valid}
    , cmd_ready{vlSymsp->TOP.cmd_ready}
    , cmd_payload_function_id{vlSymsp->TOP.cmd_payload_function_id}
    , rsp_valid{vlSymsp->TOP.rsp_valid}
    , rsp_ready{vlSymsp->TOP.rsp_ready}
    , cmd_payload_inputs_0{vlSymsp->TOP.cmd_payload_inputs_0}
    , cmd_payload_inputs_1{vlSymsp->TOP.cmd_payload_inputs_1}
    , rsp_payload_outputs_0{vlSymsp->TOP.rsp_payload_outputs_0}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vmnv2_depthwise_cfu::Vmnv2_depthwise_cfu(const char* _vcname__)
    : Vmnv2_depthwise_cfu(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmnv2_depthwise_cfu::~Vmnv2_depthwise_cfu() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmnv2_depthwise_cfu___024root___eval_debug_assertions(Vmnv2_depthwise_cfu___024root* vlSelf);
#endif  // VL_DEBUG
void Vmnv2_depthwise_cfu___024root___eval_static(Vmnv2_depthwise_cfu___024root* vlSelf);
void Vmnv2_depthwise_cfu___024root___eval_initial(Vmnv2_depthwise_cfu___024root* vlSelf);
void Vmnv2_depthwise_cfu___024root___eval_settle(Vmnv2_depthwise_cfu___024root* vlSelf);
void Vmnv2_depthwise_cfu___024root___eval(Vmnv2_depthwise_cfu___024root* vlSelf);

void Vmnv2_depthwise_cfu::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmnv2_depthwise_cfu::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmnv2_depthwise_cfu___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmnv2_depthwise_cfu___024root___eval_static(&(vlSymsp->TOP));
        Vmnv2_depthwise_cfu___024root___eval_initial(&(vlSymsp->TOP));
        Vmnv2_depthwise_cfu___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmnv2_depthwise_cfu___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmnv2_depthwise_cfu::eventsPending() { return false; }

uint64_t Vmnv2_depthwise_cfu::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmnv2_depthwise_cfu::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmnv2_depthwise_cfu___024root___eval_final(Vmnv2_depthwise_cfu___024root* vlSelf);

VL_ATTR_COLD void Vmnv2_depthwise_cfu::final() {
    Vmnv2_depthwise_cfu___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmnv2_depthwise_cfu::hierName() const { return vlSymsp->name(); }
const char* Vmnv2_depthwise_cfu::modelName() const { return "Vmnv2_depthwise_cfu"; }
unsigned Vmnv2_depthwise_cfu::threads() const { return 1; }
void Vmnv2_depthwise_cfu::prepareClone() const { contextp()->prepareClone(); }
void Vmnv2_depthwise_cfu::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vmnv2_depthwise_cfu::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmnv2_depthwise_cfu::trace()' called on model that was Verilated without --trace option");
}
