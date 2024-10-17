// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsparse_buffer__Syms.h"


void Vsparse_buffer___024root__trace_chg_sub_0(Vsparse_buffer___024root* vlSelf, VerilatedVcd* tracep);

void Vsparse_buffer___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root__trace_chg_top_0\n"); );
    // Init
    Vsparse_buffer___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsparse_buffer___024root*>(voidSelf);
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vsparse_buffer___024root__trace_chg_sub_0((&vlSymsp->TOP), tracep);
}

void Vsparse_buffer___024root__trace_chg_sub_0(Vsparse_buffer___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root__trace_chg_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        tracep->chgCData(oldp+0,(vlSelf->sparse_buffer__DOT__sparse_array_In[0]),8);
        tracep->chgCData(oldp+1,(vlSelf->sparse_buffer__DOT__sparse_array_In[1]),8);
        tracep->chgCData(oldp+2,(vlSelf->sparse_buffer__DOT__sparse_array_In[2]),8);
        tracep->chgCData(oldp+3,(vlSelf->sparse_buffer__DOT__sparse_array_In[3]),8);
        tracep->chgCData(oldp+4,(vlSelf->sparse_buffer__DOT__sparse_array_In[4]),8);
        tracep->chgCData(oldp+5,(vlSelf->sparse_buffer__DOT__sparse_array_In[5]),8);
        tracep->chgCData(oldp+6,(vlSelf->sparse_buffer__DOT__sparse_array_In[6]),8);
        tracep->chgCData(oldp+7,(vlSelf->sparse_buffer__DOT__sparse_array_In[7]),8);
        tracep->chgCData(oldp+8,(vlSelf->sparse_buffer__DOT__sparse_array_valid_In),8);
        tracep->chgBit(oldp+9,(vlSelf->sparse_buffer__DOT__write_kickoff));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        tracep->chgCData(oldp+10,(vlSelf->sparse_buffer__DOT__sparse_array_Q[0]),8);
        tracep->chgCData(oldp+11,(vlSelf->sparse_buffer__DOT__sparse_array_Q[1]),8);
        tracep->chgCData(oldp+12,(vlSelf->sparse_buffer__DOT__sparse_array_Q[2]),8);
        tracep->chgCData(oldp+13,(vlSelf->sparse_buffer__DOT__sparse_array_Q[3]),8);
        tracep->chgCData(oldp+14,(vlSelf->sparse_buffer__DOT__sparse_array_Q[4]),8);
        tracep->chgCData(oldp+15,(vlSelf->sparse_buffer__DOT__sparse_array_Q[5]),8);
        tracep->chgCData(oldp+16,(vlSelf->sparse_buffer__DOT__sparse_array_Q[6]),8);
        tracep->chgCData(oldp+17,(vlSelf->sparse_buffer__DOT__sparse_array_Q[7]),8);
        tracep->chgCData(oldp+18,(vlSelf->sparse_buffer__DOT__sparse_array_valid_Q),8);
        tracep->chgCData(oldp+19,((7U & ((IData)(1U) 
                                         + (IData)(vlSelf->sparse_buffer__DOT__write_ptr_Q)))),3);
        tracep->chgCData(oldp+20,(vlSelf->sparse_buffer__DOT__write_ptr_Q),3);
        tracep->chgCData(oldp+21,((7U & ((1U & (IData)(vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift))
                                          ? (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q)
                                          : ((2U & (IData)(vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift))
                                              ? ((IData)(1U) 
                                                 + (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q))
                                              : ((4U 
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
                                                       : 7U)))))))))),3);
        tracep->chgCData(oldp+22,(vlSelf->sparse_buffer__DOT__bottom_ptr_Q),3);
        tracep->chgCData(oldp+23,(vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift),8);
    }
    tracep->chgBit(oldp+24,(vlSelf->clk_i));
    tracep->chgBit(oldp+25,(vlSelf->rstn_i));
    tracep->chgBit(oldp+26,(vlSelf->write_valid_i));
    tracep->chgBit(oldp+27,(vlSelf->write_allowIn_o));
    tracep->chgCData(oldp+28,(vlSelf->write_data_i),8);
    tracep->chgBit(oldp+29,(vlSelf->read_valid_i));
    tracep->chgBit(oldp+30,(vlSelf->read_allowIn_o));
    tracep->chgCData(oldp+31,(vlSelf->read_ptr_i),3);
    tracep->chgBit(oldp+32,(vlSelf->read_rtn_valid_o));
    tracep->chgBit(oldp+33,(vlSelf->read_rtn_allowIn_i));
    tracep->chgCData(oldp+34,(vlSelf->read_rtn_data_o),8);
    tracep->chgCData(oldp+35,(vlSelf->sparse_buffer_valid_o),8);
    tracep->chgCData(oldp+36,(vlSelf->sparse_buffer_bottom_ptr_o),3);
    tracep->chgBit(oldp+37,(((IData)(vlSelf->read_valid_i) 
                             & (IData)(vlSelf->read_allowIn_o))));
}

void Vsparse_buffer___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root__trace_cleanup\n"); );
    // Init
    Vsparse_buffer___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsparse_buffer___024root*>(voidSelf);
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
