// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsparse_buffer.h for the primary calling header

#include "verilated.h"

#include "Vsparse_buffer___024root.h"

VL_INLINE_OPT void Vsparse_buffer___024root___combo__TOP__1(Vsparse_buffer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root___combo__TOP__1\n"); );
    // Body
    vlSelf->read_allowIn_o = vlSelf->read_rtn_allowIn_i;
}

VL_INLINE_OPT void Vsparse_buffer___024root___sequent__TOP__3(Vsparse_buffer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root___sequent__TOP__3\n"); );
    // Init
    CData/*7:0*/ __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v0;
    CData/*7:0*/ __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v1;
    CData/*7:0*/ __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v2;
    CData/*7:0*/ __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v3;
    CData/*7:0*/ __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v4;
    CData/*7:0*/ __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v5;
    CData/*7:0*/ __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v6;
    CData/*7:0*/ __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v7;
    // Body
    if (vlSelf->rstn_i) {
        vlSelf->sparse_buffer__DOT__sparse_array_valid_Q 
            = vlSelf->sparse_buffer__DOT__sparse_array_valid_In;
        __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v0 
            = vlSelf->sparse_buffer__DOT__sparse_array_In
            [7U];
        __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v1 
            = vlSelf->sparse_buffer__DOT__sparse_array_In
            [6U];
        __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v2 
            = vlSelf->sparse_buffer__DOT__sparse_array_In
            [5U];
        __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v3 
            = vlSelf->sparse_buffer__DOT__sparse_array_In
            [4U];
        __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v4 
            = vlSelf->sparse_buffer__DOT__sparse_array_In
            [3U];
        __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v5 
            = vlSelf->sparse_buffer__DOT__sparse_array_In
            [2U];
        __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v6 
            = vlSelf->sparse_buffer__DOT__sparse_array_In
            [1U];
        __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v7 
            = vlSelf->sparse_buffer__DOT__sparse_array_In
            [0U];
        vlSelf->sparse_buffer__DOT__bottom_ptr_Q = vlSelf->sparse_buffer__DOT__bottom_ptr_In;
        if (vlSelf->sparse_buffer__DOT__write_kickoff) {
            vlSelf->sparse_buffer__DOT__write_ptr_Q 
                = vlSelf->sparse_buffer__DOT__write_ptr_In;
        }
    } else {
        vlSelf->sparse_buffer__DOT__sparse_array_valid_Q = 0U;
        __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v0 = 0U;
        __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v1 = 0U;
        __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v2 = 0U;
        __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v3 = 0U;
        __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v4 = 0U;
        __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v5 = 0U;
        __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v6 = 0U;
        __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v7 = 0U;
        vlSelf->sparse_buffer__DOT__bottom_ptr_Q = 7U;
        vlSelf->sparse_buffer__DOT__write_ptr_Q = 0U;
    }
    vlSelf->sparse_buffer__DOT__sparse_array_Q[7U] 
        = __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v0;
    vlSelf->sparse_buffer__DOT__sparse_array_Q[6U] 
        = __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v1;
    vlSelf->sparse_buffer__DOT__sparse_array_Q[5U] 
        = __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v2;
    vlSelf->sparse_buffer__DOT__sparse_array_Q[4U] 
        = __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v3;
    vlSelf->sparse_buffer__DOT__sparse_array_Q[3U] 
        = __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v4;
    vlSelf->sparse_buffer__DOT__sparse_array_Q[2U] 
        = __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v5;
    vlSelf->sparse_buffer__DOT__sparse_array_Q[1U] 
        = __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v6;
    vlSelf->sparse_buffer__DOT__sparse_array_Q[0U] 
        = __Vdlyvval__sparse_buffer__DOT__sparse_array_Q__v7;
    vlSelf->sparse_buffer_valid_o = vlSelf->sparse_buffer__DOT__sparse_array_valid_Q;
    vlSelf->sparse_buffer_bottom_ptr_o = vlSelf->sparse_buffer__DOT__bottom_ptr_Q;
    vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift 
        = (0xffU & (((IData)(vlSelf->sparse_buffer__DOT__sparse_array_valid_Q) 
                     >> (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q)) 
                    | ((7U >= ((IData)(8U) - (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q)))
                        ? ((IData)(vlSelf->sparse_buffer__DOT__sparse_array_valid_Q) 
                           << ((IData)(8U) - (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q)))
                        : 0U)));
    vlSelf->sparse_buffer__DOT__write_ptr_In = (7U 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->sparse_buffer__DOT__write_ptr_Q)));
    vlSelf->write_allowIn_o = ((IData)(vlSelf->sparse_buffer__DOT__write_ptr_Q) 
                               != (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q));
    vlSelf->sparse_buffer__DOT__bottom_ptr_In = (7U 
                                                 & ((1U 
                                                     & (IData)(vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift))
                                                     ? (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q)
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift))
                                                      ? 
                                                     ((IData)(1U) 
                                                      + (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q))
                                                      : 
                                                     ((4U 
                                                       & (IData)(vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift))
                                                       ? 
                                                      ((IData)(2U) 
                                                       + (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q))
                                                       : 
                                                      ((8U 
                                                        & (IData)(vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift))
                                                        ? 
                                                       ((IData)(3U) 
                                                        + (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q))
                                                        : 
                                                       ((0x10U 
                                                         & (IData)(vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift))
                                                         ? 
                                                        ((IData)(4U) 
                                                         + (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q))
                                                         : 
                                                        ((0x20U 
                                                          & (IData)(vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift))
                                                          ? 
                                                         ((IData)(5U) 
                                                          + (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q))
                                                          : 
                                                         ((0x40U 
                                                           & (IData)(vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift))
                                                           ? 
                                                          ((IData)(6U) 
                                                           + (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q))
                                                           : 
                                                          ((0x80U 
                                                            & (IData)(vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift))
                                                            ? 
                                                           ((IData)(7U) 
                                                            + (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q))
                                                            : 7U)))))))));
}

VL_INLINE_OPT void Vsparse_buffer___024root___combo__TOP__4(Vsparse_buffer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root___combo__TOP__4\n"); );
    // Body
    if (vlSelf->read_valid_i) {
        vlSelf->read_rtn_valid_o = (1U & ((IData)(vlSelf->sparse_buffer__DOT__sparse_array_valid_Q) 
                                          >> (IData)(vlSelf->read_ptr_i)));
        vlSelf->read_rtn_data_o = (0xffU & vlSelf->sparse_buffer__DOT__sparse_array_Q
                                   [vlSelf->read_ptr_i]);
    } else {
        vlSelf->read_rtn_valid_o = 0U;
        vlSelf->read_rtn_data_o = 0U;
    }
    vlSelf->sparse_buffer__DOT__write_kickoff = ((IData)(vlSelf->write_valid_i) 
                                                 & (IData)(vlSelf->write_allowIn_o));
    vlSelf->sparse_buffer__DOT__sparse_array_In[7U] 
        = vlSelf->sparse_buffer__DOT__sparse_array_Q
        [7U];
    vlSelf->sparse_buffer__DOT__sparse_array_In[6U] 
        = vlSelf->sparse_buffer__DOT__sparse_array_Q
        [6U];
    vlSelf->sparse_buffer__DOT__sparse_array_In[5U] 
        = vlSelf->sparse_buffer__DOT__sparse_array_Q
        [5U];
    vlSelf->sparse_buffer__DOT__sparse_array_In[4U] 
        = vlSelf->sparse_buffer__DOT__sparse_array_Q
        [4U];
    vlSelf->sparse_buffer__DOT__sparse_array_In[3U] 
        = vlSelf->sparse_buffer__DOT__sparse_array_Q
        [3U];
    vlSelf->sparse_buffer__DOT__sparse_array_In[2U] 
        = vlSelf->sparse_buffer__DOT__sparse_array_Q
        [2U];
    vlSelf->sparse_buffer__DOT__sparse_array_In[1U] 
        = vlSelf->sparse_buffer__DOT__sparse_array_Q
        [1U];
    vlSelf->sparse_buffer__DOT__sparse_array_In[0U] 
        = vlSelf->sparse_buffer__DOT__sparse_array_Q
        [0U];
    if (vlSelf->sparse_buffer__DOT__write_kickoff) {
        vlSelf->sparse_buffer__DOT__sparse_array_In[vlSelf->sparse_buffer__DOT__write_ptr_Q] 
            = vlSelf->write_data_i;
        vlSelf->sparse_buffer__DOT__sparse_array_valid_In 
            = vlSelf->sparse_buffer__DOT__sparse_array_valid_Q;
        vlSelf->sparse_buffer__DOT__sparse_array_valid_In 
            = ((IData)(vlSelf->sparse_buffer__DOT__sparse_array_valid_In) 
               | (0xffU & ((IData)(1U) << (IData)(vlSelf->sparse_buffer__DOT__write_ptr_Q))));
    } else {
        vlSelf->sparse_buffer__DOT__sparse_array_valid_In 
            = vlSelf->sparse_buffer__DOT__sparse_array_valid_Q;
    }
    if (((IData)(vlSelf->read_valid_i) & (IData)(vlSelf->read_allowIn_o))) {
        vlSelf->sparse_buffer__DOT__sparse_array_valid_In 
            = ((~ ((IData)(1U) << (IData)(vlSelf->read_ptr_i))) 
               & (IData)(vlSelf->sparse_buffer__DOT__sparse_array_valid_In));
    }
}

void Vsparse_buffer___024root___eval(Vsparse_buffer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root___eval\n"); );
    // Body
    Vsparse_buffer___024root___combo__TOP__1(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    if ((((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i))) 
         | ((~ (IData)(vlSelf->rstn_i)) & (IData)(vlSelf->__Vclklast__TOP__rstn_i)))) {
        Vsparse_buffer___024root___sequent__TOP__3(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    Vsparse_buffer___024root___combo__TOP__4(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
    vlSelf->__Vclklast__TOP__rstn_i = vlSelf->rstn_i;
}

#ifdef VL_DEBUG
void Vsparse_buffer___024root___eval_debug_assertions(Vsparse_buffer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rstn_i & 0xfeU))) {
        Verilated::overWidthError("rstn_i");}
    if (VL_UNLIKELY((vlSelf->write_valid_i & 0xfeU))) {
        Verilated::overWidthError("write_valid_i");}
    if (VL_UNLIKELY((vlSelf->read_valid_i & 0xfeU))) {
        Verilated::overWidthError("read_valid_i");}
    if (VL_UNLIKELY((vlSelf->read_ptr_i & 0xf8U))) {
        Verilated::overWidthError("read_ptr_i");}
    if (VL_UNLIKELY((vlSelf->read_rtn_allowIn_i & 0xfeU))) {
        Verilated::overWidthError("read_rtn_allowIn_i");}
}
#endif  // VL_DEBUG
