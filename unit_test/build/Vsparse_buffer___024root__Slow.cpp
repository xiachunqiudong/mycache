// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsparse_buffer.h for the primary calling header

#include "verilated.h"

#include "Vsparse_buffer__Syms.h"
#include "Vsparse_buffer___024root.h"

void Vsparse_buffer___024root___ctor_var_reset(Vsparse_buffer___024root* vlSelf);

Vsparse_buffer___024root::Vsparse_buffer___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vsparse_buffer___024root___ctor_var_reset(this);
}

void Vsparse_buffer___024root::__Vconfigure(Vsparse_buffer__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vsparse_buffer___024root::~Vsparse_buffer___024root() {
}
