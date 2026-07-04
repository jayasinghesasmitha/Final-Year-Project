// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcfu__pch.h"

//============================================================
// Constructors

Vcfu::Vcfu(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcfu__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , cmd_ready{vlSymsp->TOP.cmd_ready}
    , rsp_valid{vlSymsp->TOP.rsp_valid}
    , rsp_ready{vlSymsp->TOP.rsp_ready}
    , reset{vlSymsp->TOP.reset}
    , rst{vlSymsp->TOP.rst}
    , cmd_valid{vlSymsp->TOP.cmd_valid}
    , cmd_payload_function_id{vlSymsp->TOP.cmd_payload_function_id}
    , cmd_payload_inputs_0{vlSymsp->TOP.cmd_payload_inputs_0}
    , cmd_payload_inputs_1{vlSymsp->TOP.cmd_payload_inputs_1}
    , rsp_payload_outputs_0{vlSymsp->TOP.rsp_payload_outputs_0}
    , port0_addr{vlSymsp->TOP.port0_addr}
    , port1_addr{vlSymsp->TOP.port1_addr}
    , port2_addr{vlSymsp->TOP.port2_addr}
    , port3_addr{vlSymsp->TOP.port3_addr}
    , port0_din{vlSymsp->TOP.port0_din}
    , port1_din{vlSymsp->TOP.port1_din}
    , port2_din{vlSymsp->TOP.port2_din}
    , port3_din{vlSymsp->TOP.port3_din}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vcfu::Vcfu(const char* _vcname__)
    : Vcfu(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcfu::~Vcfu() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vcfu___024root___eval_debug_assertions(Vcfu___024root* vlSelf);
#endif  // VL_DEBUG
void Vcfu___024root___eval_static(Vcfu___024root* vlSelf);
void Vcfu___024root___eval_initial(Vcfu___024root* vlSelf);
void Vcfu___024root___eval_settle(Vcfu___024root* vlSelf);
void Vcfu___024root___eval(Vcfu___024root* vlSelf);

void Vcfu::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcfu::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcfu___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vcfu___024root___eval_static(&(vlSymsp->TOP));
        Vcfu___024root___eval_initial(&(vlSymsp->TOP));
        Vcfu___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vcfu___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vcfu::eventsPending() { return false; }

uint64_t Vcfu::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vcfu::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vcfu___024root___eval_final(Vcfu___024root* vlSelf);

VL_ATTR_COLD void Vcfu::final() {
    Vcfu___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcfu::hierName() const { return vlSymsp->name(); }
const char* Vcfu::modelName() const { return "Vcfu"; }
unsigned Vcfu::threads() const { return 1; }
void Vcfu::prepareClone() const { contextp()->prepareClone(); }
void Vcfu::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vcfu::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vcfu::trace()' called on model that was Verilated without --trace option");
}
