// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vplru_impl.h for the primary calling header

#include "verilated.h"

#include "Vplru_impl___024root.h"

VL_INLINE_OPT void Vplru_impl___024root___sequent__TOP__1(Vplru_impl___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vplru_impl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vplru_impl___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->plru_impl__DOT__plru_node_state_Q = ((IData)(vlSelf->rstn_i)
                                                  ? (IData)(vlSelf->plru_impl__DOT__plru_node_state_In)
                                                  : 0U);
}

VL_INLINE_OPT void Vplru_impl___024root___settle__TOP__2(Vplru_impl___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vplru_impl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vplru_impl___024root___settle__TOP__2\n"); );
    // Body
    vlSelf->plru_impl__DOT__plru_node_state_In = ((0x70U 
                                                   & (IData)(vlSelf->plru_impl__DOT__plru_node_state_In)) 
                                                  | ((8U 
                                                      & (((1U 
                                                           & ((8U 
                                                               & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                                                               ? 
                                                              ((IData)(vlSelf->cacheLine_access_map_i) 
                                                               >> 7U)
                                                               : 
                                                              ((IData)(vlSelf->cacheLine_access_map_i) 
                                                               >> 6U)))
                                                           ? 
                                                          (~ 
                                                           ((IData)(vlSelf->plru_impl__DOT__plru_node_state_Q) 
                                                            >> 3U))
                                                           : 
                                                          ((IData)(vlSelf->plru_impl__DOT__plru_node_state_Q) 
                                                           >> 3U)) 
                                                         << 3U)) 
                                                     | ((4U 
                                                         & (((1U 
                                                              & ((4U 
                                                                  & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                                                                  ? 
                                                                 ((IData)(vlSelf->cacheLine_access_map_i) 
                                                                  >> 5U)
                                                                  : 
                                                                 ((IData)(vlSelf->cacheLine_access_map_i) 
                                                                  >> 4U)))
                                                              ? 
                                                             (~ 
                                                              ((IData)(vlSelf->plru_impl__DOT__plru_node_state_Q) 
                                                               >> 2U))
                                                              : 
                                                             ((IData)(vlSelf->plru_impl__DOT__plru_node_state_Q) 
                                                              >> 2U)) 
                                                            << 2U)) 
                                                        | ((2U 
                                                            & (((1U 
                                                                 & ((2U 
                                                                     & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                                                                     ? 
                                                                    ((IData)(vlSelf->cacheLine_access_map_i) 
                                                                     >> 3U)
                                                                     : 
                                                                    ((IData)(vlSelf->cacheLine_access_map_i) 
                                                                     >> 2U)))
                                                                 ? 
                                                                (~ 
                                                                 ((IData)(vlSelf->plru_impl__DOT__plru_node_state_Q) 
                                                                  >> 1U))
                                                                 : 
                                                                ((IData)(vlSelf->plru_impl__DOT__plru_node_state_Q) 
                                                                 >> 1U)) 
                                                               << 1U)) 
                                                           | (1U 
                                                              & ((1U 
                                                                  & ((1U 
                                                                      & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                                                                      ? 
                                                                     ((IData)(vlSelf->cacheLine_access_map_i) 
                                                                      >> 1U)
                                                                      : (IData)(vlSelf->cacheLine_access_map_i)))
                                                                  ? 
                                                                 (~ (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                                                                  : (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q)))))));
    vlSelf->plru_impl__DOT__plru_node_state_In = ((0x4fU 
                                                   & (IData)(vlSelf->plru_impl__DOT__plru_node_state_In)) 
                                                  | ((0x20U 
                                                      & ((((0x20U 
                                                            & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                                                            ? 
                                                           (0U 
                                                            != 
                                                            (3U 
                                                             & ((IData)(vlSelf->cacheLine_access_map_i) 
                                                                >> 6U)))
                                                            : 
                                                           (0U 
                                                            != 
                                                            (3U 
                                                             & ((IData)(vlSelf->cacheLine_access_map_i) 
                                                                >> 4U))))
                                                           ? 
                                                          (~ 
                                                           ((IData)(vlSelf->plru_impl__DOT__plru_node_state_Q) 
                                                            >> 5U))
                                                           : 
                                                          ((IData)(vlSelf->plru_impl__DOT__plru_node_state_Q) 
                                                           >> 5U)) 
                                                         << 5U)) 
                                                     | (0x10U 
                                                        & ((((0x10U 
                                                              & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                                                              ? 
                                                             (0U 
                                                              != 
                                                              (3U 
                                                               & ((IData)(vlSelf->cacheLine_access_map_i) 
                                                                  >> 2U)))
                                                              : 
                                                             (0U 
                                                              != 
                                                              (3U 
                                                               & (IData)(vlSelf->cacheLine_access_map_i))))
                                                             ? 
                                                            (~ 
                                                             ((IData)(vlSelf->plru_impl__DOT__plru_node_state_Q) 
                                                              >> 4U))
                                                             : 
                                                            ((IData)(vlSelf->plru_impl__DOT__plru_node_state_Q) 
                                                             >> 4U)) 
                                                           << 4U))));
    vlSelf->plru_impl__DOT__plru_node_state_In = ((0x3fU 
                                                   & (IData)(vlSelf->plru_impl__DOT__plru_node_state_In)) 
                                                  | (0x40U 
                                                     & ((((0x40U 
                                                           & (IData)(vlSelf->plru_impl__DOT__plru_node_state_Q))
                                                           ? 
                                                          (0U 
                                                           != 
                                                           (0xfU 
                                                            & ((IData)(vlSelf->cacheLine_access_map_i) 
                                                               >> 4U)))
                                                           : 
                                                          (0U 
                                                           != 
                                                           (0xfU 
                                                            & (IData)(vlSelf->cacheLine_access_map_i))))
                                                          ? 
                                                         (~ 
                                                          ((IData)(vlSelf->plru_impl__DOT__plru_node_state_Q) 
                                                           >> 6U))
                                                          : 
                                                         ((IData)(vlSelf->plru_impl__DOT__plru_node_state_Q) 
                                                          >> 6U)) 
                                                        << 6U)));
    if (VL_UNLIKELY((0U != (IData)(vlSelf->cacheLine_access_map_i)))) {
        VL_WRITEF("==========================================\naccess_map: %b\n\nnode6: %1#\n\nnode5: %1# node4: %1#\n\nnode3: %1# node2: %1# node1: %1# node0: %1#\n\n",
                  8,vlSelf->cacheLine_access_map_i,
                  1,(1U & ((IData)(vlSelf->plru_impl__DOT__plru_node_state_In) 
                           >> 6U)),1,(1U & ((IData)(vlSelf->plru_impl__DOT__plru_node_state_In) 
                                            >> 5U)),
                  1,(1U & ((IData)(vlSelf->plru_impl__DOT__plru_node_state_In) 
                           >> 4U)),1,(1U & ((IData)(vlSelf->plru_impl__DOT__plru_node_state_In) 
                                            >> 3U)),
                  1,(1U & ((IData)(vlSelf->plru_impl__DOT__plru_node_state_In) 
                           >> 2U)),1,(1U & ((IData)(vlSelf->plru_impl__DOT__plru_node_state_In) 
                                            >> 1U)),
                  1,(1U & (IData)(vlSelf->plru_impl__DOT__plru_node_state_In)));
    }
}

void Vplru_impl___024root___eval(Vplru_impl___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vplru_impl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vplru_impl___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i))) 
         | ((~ (IData)(vlSelf->rstn_i)) & (IData)(vlSelf->__Vclklast__TOP__rstn_i)))) {
        Vplru_impl___024root___sequent__TOP__1(vlSelf);
    }
    Vplru_impl___024root___settle__TOP__2(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
    vlSelf->__Vclklast__TOP__rstn_i = vlSelf->rstn_i;
}

#ifdef VL_DEBUG
void Vplru_impl___024root___eval_debug_assertions(Vplru_impl___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vplru_impl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vplru_impl___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rstn_i & 0xfeU))) {
        Verilated::overWidthError("rstn_i");}
}
#endif  // VL_DEBUG
