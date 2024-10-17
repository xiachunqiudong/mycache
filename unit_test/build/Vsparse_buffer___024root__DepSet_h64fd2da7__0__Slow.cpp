// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsparse_buffer.h for the primary calling header

#include "verilated.h"

#include "Vsparse_buffer___024root.h"

VL_ATTR_COLD void Vsparse_buffer___024root___settle__TOP__2(Vsparse_buffer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root___settle__TOP__2\n"); );
    // Body
    vlSelf->read_allowIn_o = vlSelf->read_rtn_allowIn_i;
    vlSelf->sparse_buffer__DOT__write_ptr_In = (7U 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->sparse_buffer__DOT__write_ptr_Q)));
    vlSelf->sparse_buffer_valid_o = vlSelf->sparse_buffer__DOT__sparse_array_valid_Q;
    vlSelf->sparse_buffer_bottom_ptr_o = vlSelf->sparse_buffer__DOT__bottom_ptr_Q;
    if (vlSelf->read_valid_i) {
        vlSelf->read_rtn_valid_o = (1U & ((IData)(vlSelf->sparse_buffer__DOT__sparse_array_valid_Q) 
                                          >> (IData)(vlSelf->read_ptr_i)));
        vlSelf->read_rtn_data_o = (0xffU & vlSelf->sparse_buffer__DOT__sparse_array_Q
                                   [vlSelf->read_ptr_i]);
    } else {
        vlSelf->read_rtn_valid_o = 0U;
        vlSelf->read_rtn_data_o = 0U;
    }
    vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift 
        = (0xffU & (((IData)(vlSelf->sparse_buffer__DOT__sparse_array_valid_Q) 
                     >> (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q)) 
                    | ((7U >= ((IData)(8U) - (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q)))
                        ? ((IData)(vlSelf->sparse_buffer__DOT__sparse_array_valid_Q) 
                           << ((IData)(8U) - (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q)))
                        : 0U)));
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

VL_ATTR_COLD void Vsparse_buffer___024root___eval_initial(Vsparse_buffer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
    vlSelf->__Vclklast__TOP__rstn_i = vlSelf->rstn_i;
}

VL_ATTR_COLD void Vsparse_buffer___024root___eval_settle(Vsparse_buffer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root___eval_settle\n"); );
    // Body
    Vsparse_buffer___024root___settle__TOP__2(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vsparse_buffer___024root___final(Vsparse_buffer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root___final\n"); );
}

VL_ATTR_COLD void Vsparse_buffer___024root___ctor_var_reset(Vsparse_buffer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rstn_i = VL_RAND_RESET_I(1);
    vlSelf->write_valid_i = VL_RAND_RESET_I(1);
    vlSelf->write_allowIn_o = VL_RAND_RESET_I(1);
    vlSelf->write_data_i = VL_RAND_RESET_I(8);
    vlSelf->read_valid_i = VL_RAND_RESET_I(1);
    vlSelf->read_allowIn_o = VL_RAND_RESET_I(1);
    vlSelf->read_ptr_i = VL_RAND_RESET_I(3);
    vlSelf->read_rtn_valid_o = VL_RAND_RESET_I(1);
    vlSelf->read_rtn_allowIn_i = VL_RAND_RESET_I(1);
    vlSelf->read_rtn_data_o = VL_RAND_RESET_I(8);
    vlSelf->sparse_buffer_valid_o = VL_RAND_RESET_I(8);
    vlSelf->sparse_buffer_bottom_ptr_o = VL_RAND_RESET_I(3);
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        vlSelf->sparse_buffer__DOT__sparse_array_In[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        vlSelf->sparse_buffer__DOT__sparse_array_Q[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->sparse_buffer__DOT__sparse_array_valid_In = VL_RAND_RESET_I(8);
    vlSelf->sparse_buffer__DOT__sparse_array_valid_Q = VL_RAND_RESET_I(8);
    vlSelf->sparse_buffer__DOT__write_kickoff = VL_RAND_RESET_I(1);
    vlSelf->sparse_buffer__DOT__write_ptr_In = VL_RAND_RESET_I(3);
    vlSelf->sparse_buffer__DOT__write_ptr_Q = VL_RAND_RESET_I(3);
    vlSelf->sparse_buffer__DOT__bottom_ptr_In = VL_RAND_RESET_I(3);
    vlSelf->sparse_buffer__DOT__bottom_ptr_Q = VL_RAND_RESET_I(3);
    vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift = VL_RAND_RESET_I(8);
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
