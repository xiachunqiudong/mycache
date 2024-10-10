// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vplru_impl__Syms.h"


VL_ATTR_COLD void Vplru_impl___024root__trace_init_sub__TOP__0(Vplru_impl___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vplru_impl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vplru_impl___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"clk_i", false,-1);
    tracep->declBit(c+2,"rstn_i", false,-1);
    tracep->declBus(c+3,"cacheLine_access_map_i", false,-1, 7,0);
    tracep->pushNamePrefix("plru_impl ");
    tracep->declBit(c+1,"clk_i", false,-1);
    tracep->declBit(c+2,"rstn_i", false,-1);
    tracep->declBus(c+3,"cacheLine_access_map_i", false,-1, 7,0);
    tracep->declBus(c+4,"plru_node_state_In", false,-1, 6,0);
    tracep->declBus(c+5,"plru_node_state_Q", false,-1, 6,0);
    tracep->declBit(c+6,"plru_node0_old_cacheLine_access", false,-1);
    tracep->declBit(c+7,"plru_node1_old_cacheLine_access", false,-1);
    tracep->declBit(c+8,"plru_node2_old_cacheLine_access", false,-1);
    tracep->declBit(c+9,"plru_node3_old_cacheLine_access", false,-1);
    tracep->declBit(c+10,"plru_node4_old_cacheLine_access", false,-1);
    tracep->declBit(c+11,"plru_node5_old_cacheLine_access", false,-1);
    tracep->declBit(c+12,"plru_node6_old_cacheLine_access", false,-1);
    tracep->declBit(c+13,"plru_node7_old_cacheLine_access", false,-1);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vplru_impl___024root__trace_init_top(Vplru_impl___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vplru_impl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vplru_impl___024root__trace_init_top\n"); );
    // Body
    Vplru_impl___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vplru_impl___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vplru_impl___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vplru_impl___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vplru_impl___024root__trace_register(Vplru_impl___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vplru_impl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vplru_impl___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vplru_impl___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vplru_impl___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vplru_impl___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vplru_impl___024root__trace_full_sub_0(Vplru_impl___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vplru_impl___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vplru_impl___024root__trace_full_top_0\n"); );
    // Init
    Vplru_impl___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vplru_impl___024root*>(voidSelf);
    Vplru_impl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vplru_impl___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void Vplru_impl___024root__trace_full_sub_0(Vplru_impl___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vplru_impl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vplru_impl___024root__trace_full_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullBit(oldp+1,(vlSelf->clk_i));
    tracep->fullBit(oldp+2,(vlSelf->rstn_i));
    tracep->fullCData(oldp+3,(vlSelf->cacheLine_access_map_i),8);
    tracep->fullCData(oldp+4,(vlSelf->plru_impl__DOT__plru_node_state_In),7);
    tracep->fullCData(oldp+5,(vlSelf->plru_impl__DOT__plru_node_state_Q),7);
    tracep->fullBit(oldp+6,((1U & ((1U & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                                    ? ((IData)(vlSelf->cacheLine_access_map_i) 
                                       >> 1U) : (IData)(vlSelf->cacheLine_access_map_i)))));
    tracep->fullBit(oldp+7,((1U & ((2U & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                                    ? ((IData)(vlSelf->cacheLine_access_map_i) 
                                       >> 3U) : ((IData)(vlSelf->cacheLine_access_map_i) 
                                                 >> 2U)))));
    tracep->fullBit(oldp+8,((1U & ((4U & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                                    ? ((IData)(vlSelf->cacheLine_access_map_i) 
                                       >> 5U) : ((IData)(vlSelf->cacheLine_access_map_i) 
                                                 >> 4U)))));
    tracep->fullBit(oldp+9,((1U & ((8U & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                                    ? ((IData)(vlSelf->cacheLine_access_map_i) 
                                       >> 7U) : ((IData)(vlSelf->cacheLine_access_map_i) 
                                                 >> 6U)))));
    tracep->fullBit(oldp+10,(((0x10U & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                               ? (0U != (3U & ((IData)(vlSelf->cacheLine_access_map_i) 
                                               >> 2U)))
                               : (0U != (3U & (IData)(vlSelf->cacheLine_access_map_i))))));
    tracep->fullBit(oldp+11,(((0x20U & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                               ? (0U != (3U & ((IData)(vlSelf->cacheLine_access_map_i) 
                                               >> 6U)))
                               : (0U != (3U & ((IData)(vlSelf->cacheLine_access_map_i) 
                                               >> 4U))))));
    tracep->fullBit(oldp+12,(((0x40U & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                               ? (0U != (0xfU & ((IData)(vlSelf->cacheLine_access_map_i) 
                                                 >> 4U)))
                               : (0U != (0xfU & (IData)(vlSelf->cacheLine_access_map_i))))));
    tracep->fullBit(oldp+13,(vlSelf->plru_impl__DOT__plru_node7_old_cacheLine_access));
}
