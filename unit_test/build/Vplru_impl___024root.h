// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vplru_impl.h for the primary calling header

#ifndef VERILATED_VPLRU_IMPL___024ROOT_H_
#define VERILATED_VPLRU_IMPL___024ROOT_H_  // guard

#include "verilated.h"

class Vplru_impl__Syms;
VL_MODULE(Vplru_impl___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rstn_i,0,0);
    VL_IN8(cacheLine_access_map_i,7,0);
    CData/*6:0*/ plru_impl__DOT__plru_node_state_In;
    CData/*6:0*/ plru_impl__DOT__plru_node_state_Q;
    CData/*0:0*/ plru_impl__DOT__plru_node7_old_cacheLine_access;
    CData/*0:0*/ __Vclklast__TOP__clk_i;
    CData/*0:0*/ __Vclklast__TOP__rstn_i;

    // INTERNAL VARIABLES
    Vplru_impl__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vplru_impl___024root(const char* name);
    ~Vplru_impl___024root();
    VL_UNCOPYABLE(Vplru_impl___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vplru_impl__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
