// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsparse_buffer__Syms.h"


VL_ATTR_COLD void Vsparse_buffer___024root__trace_init_sub__TOP__0(Vsparse_buffer___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+25,"clk_i", false,-1);
    tracep->declBit(c+26,"rstn_i", false,-1);
    tracep->declBit(c+27,"write_valid_i", false,-1);
    tracep->declBit(c+28,"write_allowIn_o", false,-1);
    tracep->declBus(c+29,"write_data_i", false,-1, 7,0);
    tracep->declBit(c+30,"read_valid_i", false,-1);
    tracep->declBit(c+31,"read_allowIn_o", false,-1);
    tracep->declBus(c+32,"read_ptr_i", false,-1, 2,0);
    tracep->declBit(c+33,"read_rtn_valid_o", false,-1);
    tracep->declBit(c+34,"read_rtn_allowIn_i", false,-1);
    tracep->declBus(c+35,"read_rtn_data_o", false,-1, 7,0);
    tracep->declBus(c+36,"sparse_buffer_valid_o", false,-1, 7,0);
    tracep->declBus(c+37,"sparse_buffer_bottom_ptr_o", false,-1, 2,0);
    tracep->pushNamePrefix("sparse_buffer ");
    tracep->declBus(c+39,"DW", false,-1, 31,0);
    tracep->declBus(c+40,"AW", false,-1, 31,0);
    tracep->declBus(c+39,"SIZE", false,-1, 31,0);
    tracep->declBit(c+25,"clk_i", false,-1);
    tracep->declBit(c+26,"rstn_i", false,-1);
    tracep->declBit(c+27,"write_valid_i", false,-1);
    tracep->declBit(c+28,"write_allowIn_o", false,-1);
    tracep->declBus(c+29,"write_data_i", false,-1, 7,0);
    tracep->declBit(c+30,"read_valid_i", false,-1);
    tracep->declBit(c+31,"read_allowIn_o", false,-1);
    tracep->declBus(c+32,"read_ptr_i", false,-1, 2,0);
    tracep->declBit(c+33,"read_rtn_valid_o", false,-1);
    tracep->declBit(c+34,"read_rtn_allowIn_i", false,-1);
    tracep->declBus(c+35,"read_rtn_data_o", false,-1, 7,0);
    tracep->declBus(c+36,"sparse_buffer_valid_o", false,-1, 7,0);
    tracep->declBus(c+37,"sparse_buffer_bottom_ptr_o", false,-1, 2,0);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+1+i*1,"sparse_array_In", true,(i+0), 7,0);
    }
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+11+i*1,"sparse_array_Q", true,(i+0), 7,0);
    }
    tracep->declBus(c+9,"sparse_array_valid_In", false,-1, 7,0);
    tracep->declBus(c+19,"sparse_array_valid_Q", false,-1, 7,0);
    tracep->declBit(c+10,"write_kickoff", false,-1);
    tracep->declBus(c+20,"write_ptr_In", false,-1, 2,0);
    tracep->declBus(c+21,"write_ptr_Q", false,-1, 2,0);
    tracep->declBit(c+38,"read_kickoff", false,-1);
    tracep->declBus(c+22,"bottom_ptr_In", false,-1, 2,0);
    tracep->declBus(c+23,"bottom_ptr_Q", false,-1, 2,0);
    tracep->pushNamePrefix("u_fid_bottom_ptr_impl ");
    tracep->declBus(c+19,"entry_valid_i", false,-1, 7,0);
    tracep->declBus(c+23,"bottom_ptr_current", false,-1, 2,0);
    tracep->declBus(c+22,"bottom_ptr_next", false,-1, 2,0);
    tracep->declBus(c+24,"entry_valid_shift", false,-1, 7,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vsparse_buffer___024root__trace_init_top(Vsparse_buffer___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root__trace_init_top\n"); );
    // Body
    Vsparse_buffer___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vsparse_buffer___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vsparse_buffer___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vsparse_buffer___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vsparse_buffer___024root__trace_register(Vsparse_buffer___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vsparse_buffer___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vsparse_buffer___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vsparse_buffer___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vsparse_buffer___024root__trace_full_sub_0(Vsparse_buffer___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsparse_buffer___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root__trace_full_top_0\n"); );
    // Init
    Vsparse_buffer___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsparse_buffer___024root*>(voidSelf);
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsparse_buffer___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void Vsparse_buffer___024root__trace_full_sub_0(Vsparse_buffer___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsparse_buffer___024root__trace_full_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullCData(oldp+1,(vlSelf->sparse_buffer__DOT__sparse_array_In[0]),8);
    tracep->fullCData(oldp+2,(vlSelf->sparse_buffer__DOT__sparse_array_In[1]),8);
    tracep->fullCData(oldp+3,(vlSelf->sparse_buffer__DOT__sparse_array_In[2]),8);
    tracep->fullCData(oldp+4,(vlSelf->sparse_buffer__DOT__sparse_array_In[3]),8);
    tracep->fullCData(oldp+5,(vlSelf->sparse_buffer__DOT__sparse_array_In[4]),8);
    tracep->fullCData(oldp+6,(vlSelf->sparse_buffer__DOT__sparse_array_In[5]),8);
    tracep->fullCData(oldp+7,(vlSelf->sparse_buffer__DOT__sparse_array_In[6]),8);
    tracep->fullCData(oldp+8,(vlSelf->sparse_buffer__DOT__sparse_array_In[7]),8);
    tracep->fullCData(oldp+9,(vlSelf->sparse_buffer__DOT__sparse_array_valid_In),8);
    tracep->fullBit(oldp+10,(vlSelf->sparse_buffer__DOT__write_kickoff));
    tracep->fullCData(oldp+11,(vlSelf->sparse_buffer__DOT__sparse_array_Q[0]),8);
    tracep->fullCData(oldp+12,(vlSelf->sparse_buffer__DOT__sparse_array_Q[1]),8);
    tracep->fullCData(oldp+13,(vlSelf->sparse_buffer__DOT__sparse_array_Q[2]),8);
    tracep->fullCData(oldp+14,(vlSelf->sparse_buffer__DOT__sparse_array_Q[3]),8);
    tracep->fullCData(oldp+15,(vlSelf->sparse_buffer__DOT__sparse_array_Q[4]),8);
    tracep->fullCData(oldp+16,(vlSelf->sparse_buffer__DOT__sparse_array_Q[5]),8);
    tracep->fullCData(oldp+17,(vlSelf->sparse_buffer__DOT__sparse_array_Q[6]),8);
    tracep->fullCData(oldp+18,(vlSelf->sparse_buffer__DOT__sparse_array_Q[7]),8);
    tracep->fullCData(oldp+19,(vlSelf->sparse_buffer__DOT__sparse_array_valid_Q),8);
    tracep->fullCData(oldp+20,((7U & ((IData)(1U) + (IData)(vlSelf->sparse_buffer__DOT__write_ptr_Q)))),3);
    tracep->fullCData(oldp+21,(vlSelf->sparse_buffer__DOT__write_ptr_Q),3);
    tracep->fullCData(oldp+22,((7U & ((1U & (IData)(vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift))
                                       ? (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q)
                                       : ((2U & (IData)(vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift))
                                           ? ((IData)(1U) 
                                              + (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q))
                                           : ((4U & (IData)(vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift))
                                               ? ((IData)(2U) 
                                                  + (IData)(vlSelf->sparse_buffer__DOT__bottom_ptr_Q))
                                               : ((8U 
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
    tracep->fullCData(oldp+23,(vlSelf->sparse_buffer__DOT__bottom_ptr_Q),3);
    tracep->fullCData(oldp+24,(vlSelf->sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift),8);
    tracep->fullBit(oldp+25,(vlSelf->clk_i));
    tracep->fullBit(oldp+26,(vlSelf->rstn_i));
    tracep->fullBit(oldp+27,(vlSelf->write_valid_i));
    tracep->fullBit(oldp+28,(vlSelf->write_allowIn_o));
    tracep->fullCData(oldp+29,(vlSelf->write_data_i),8);
    tracep->fullBit(oldp+30,(vlSelf->read_valid_i));
    tracep->fullBit(oldp+31,(vlSelf->read_allowIn_o));
    tracep->fullCData(oldp+32,(vlSelf->read_ptr_i),3);
    tracep->fullBit(oldp+33,(vlSelf->read_rtn_valid_o));
    tracep->fullBit(oldp+34,(vlSelf->read_rtn_allowIn_i));
    tracep->fullCData(oldp+35,(vlSelf->read_rtn_data_o),8);
    tracep->fullCData(oldp+36,(vlSelf->sparse_buffer_valid_o),8);
    tracep->fullCData(oldp+37,(vlSelf->sparse_buffer_bottom_ptr_o),3);
    tracep->fullBit(oldp+38,(((IData)(vlSelf->read_valid_i) 
                              & (IData)(vlSelf->read_allowIn_o))));
    tracep->fullIData(oldp+39,(8U),32);
    tracep->fullIData(oldp+40,(3U),32);
}
