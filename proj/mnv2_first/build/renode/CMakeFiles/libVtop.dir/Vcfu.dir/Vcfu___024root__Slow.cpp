// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcfu.h for the primary calling header

#include "Vcfu__pch.h"
#include "Vcfu__Syms.h"
#include "Vcfu___024root.h"

void Vcfu___024root___ctor_var_reset(Vcfu___024root* vlSelf);

Vcfu___024root::Vcfu___024root(Vcfu__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vcfu___024root___ctor_var_reset(this);
}

void Vcfu___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vcfu___024root::~Vcfu___024root() {
}
