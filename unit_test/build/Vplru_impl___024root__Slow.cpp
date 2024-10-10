// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vplru_impl.h for the primary calling header

#include "verilated.h"

#include "Vplru_impl__Syms.h"
#include "Vplru_impl___024root.h"

void Vplru_impl___024root___ctor_var_reset(Vplru_impl___024root* vlSelf);

Vplru_impl___024root::Vplru_impl___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vplru_impl___024root___ctor_var_reset(this);
}

void Vplru_impl___024root::__Vconfigure(Vplru_impl__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vplru_impl___024root::~Vplru_impl___024root() {
}
