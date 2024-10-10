// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vplru_impl__Syms.h"


void Vplru_impl___024root__trace_chg_sub_0(Vplru_impl___024root* vlSelf, VerilatedVcd* tracep);

void Vplru_impl___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vplru_impl___024root__trace_chg_top_0\n"); );
    // Init
    Vplru_impl___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vplru_impl___024root*>(voidSelf);
    Vplru_impl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vplru_impl___024root__trace_chg_sub_0((&vlSymsp->TOP), tracep);
}

void Vplru_impl___024root__trace_chg_sub_0(Vplru_impl___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vplru_impl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vplru_impl___024root__trace_chg_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    tracep->chgBit(oldp+0,(vlSelf->clk_i));
    tracep->chgBit(oldp+1,(vlSelf->rstn_i));
    tracep->chgCData(oldp+2,(vlSelf->cacheLine_access_map_i),8);
    tracep->chgCData(oldp+3,(vlSelf->plru_impl__DOT__plru_node_state_In),7);
    tracep->chgCData(oldp+4,(vlSelf->plru_impl__DOT__plru_node_state_Q),7);
    tracep->chgBit(oldp+5,((1U & ((1U & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                                   ? ((IData)(vlSelf->cacheLine_access_map_i) 
                                      >> 1U) : (IData)(vlSelf->cacheLine_access_map_i)))));
    tracep->chgBit(oldp+6,((1U & ((2U & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                                   ? ((IData)(vlSelf->cacheLine_access_map_i) 
                                      >> 3U) : ((IData)(vlSelf->cacheLine_access_map_i) 
                                                >> 2U)))));
    tracep->chgBit(oldp+7,((1U & ((4U & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                                   ? ((IData)(vlSelf->cacheLine_access_map_i) 
                                      >> 5U) : ((IData)(vlSelf->cacheLine_access_map_i) 
                                                >> 4U)))));
    tracep->chgBit(oldp+8,((1U & ((8U & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                                   ? ((IData)(vlSelf->cacheLine_access_map_i) 
                                      >> 7U) : ((IData)(vlSelf->cacheLine_access_map_i) 
                                                >> 6U)))));
    tracep->chgBit(oldp+9,(((0x10U & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                             ? (0U != (3U & ((IData)(vlSelf->cacheLine_access_map_i) 
                                             >> 2U)))
                             : (0U != (3U & (IData)(vlSelf->cacheLine_access_map_i))))));
    tracep->chgBit(oldp+10,(((0x20U & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                              ? (0U != (3U & ((IData)(vlSelf->cacheLine_access_map_i) 
                                              >> 6U)))
                              : (0U != (3U & ((IData)(vlSelf->cacheLine_access_map_i) 
                                              >> 4U))))));
    tracep->chgBit(oldp+11,(((0x40U & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                              ? (0U != (0xfU & ((IData)(vlSelf->cacheLine_access_map_i) 
                                                >> 4U)))
                              : (0U != (0xfU & (IData)(vlSelf->cacheLine_access_map_i))))));
}

void Vplru_impl___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vplru_impl___024root__trace_cleanup\n"); );
    // Init
    Vplru_impl___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vplru_impl___024root*>(voidSelf);
    Vplru_impl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
