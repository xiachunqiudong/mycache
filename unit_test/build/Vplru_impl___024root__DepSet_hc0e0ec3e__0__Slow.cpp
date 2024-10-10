// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vplru_impl.h for the primary calling header

#include "verilated.h"

#include "Vplru_impl___024root.h"

VL_ATTR_COLD void Vplru_impl___024root___eval_initial(Vplru_impl___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vplru_impl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vplru_impl___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
    vlSelf->__Vclklast__TOP__rstn_i = vlSelf->rstn_i;
}

void Vplru_impl___024root___settle__TOP__2(Vplru_impl___024root* vlSelf);

VL_ATTR_COLD void Vplru_impl___024root___eval_settle(Vplru_impl___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vplru_impl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vplru_impl___024root___eval_settle\n"); );
    // Body
    Vplru_impl___024root___settle__TOP__2(vlSelf);
}

VL_ATTR_COLD void Vplru_impl___024root___final(Vplru_impl___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vplru_impl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vplru_impl___024root___final\n"); );
}

VL_ATTR_COLD void Vplru_impl___024root___ctor_var_reset(Vplru_impl___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vplru_impl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vplru_impl___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rstn_i = VL_RAND_RESET_I(1);
    vlSelf->cacheLine_access_map_i = VL_RAND_RESET_I(8);
    vlSelf->plru_impl__DOT__plru_node_state_In = VL_RAND_RESET_I(7);
    vlSelf->plru_impl__DOT__plru_node_state_Q = VL_RAND_RESET_I(7);
    vlSelf->plru_impl__DOT__plru_node7_old_cacheLine_access = VL_RAND_RESET_I(1);
}
