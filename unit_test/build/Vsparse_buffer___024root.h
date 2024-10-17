// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsparse_buffer.h for the primary calling header

#ifndef VERILATED_VSPARSE_BUFFER___024ROOT_H_
#define VERILATED_VSPARSE_BUFFER___024ROOT_H_  // guard

#include "verilated.h"

class Vsparse_buffer__Syms;
VL_MODULE(Vsparse_buffer___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rstn_i,0,0);
    VL_IN8(write_valid_i,0,0);
    VL_OUT8(write_allowIn_o,0,0);
    VL_IN8(write_data_i,7,0);
    VL_IN8(read_valid_i,0,0);
    VL_OUT8(read_allowIn_o,0,0);
    VL_IN8(read_ptr_i,2,0);
    VL_OUT8(read_rtn_valid_o,0,0);
    VL_IN8(read_rtn_allowIn_i,0,0);
    VL_OUT8(read_rtn_data_o,7,0);
    VL_OUT8(sparse_buffer_valid_o,7,0);
    VL_OUT8(sparse_buffer_bottom_ptr_o,2,0);
    CData/*7:0*/ sparse_buffer__DOT__sparse_array_valid_In;
    CData/*7:0*/ sparse_buffer__DOT__sparse_array_valid_Q;
    CData/*0:0*/ sparse_buffer__DOT__write_kickoff;
    CData/*2:0*/ sparse_buffer__DOT__write_ptr_In;
    CData/*2:0*/ sparse_buffer__DOT__write_ptr_Q;
    CData/*2:0*/ sparse_buffer__DOT__bottom_ptr_In;
    CData/*2:0*/ sparse_buffer__DOT__bottom_ptr_Q;
    CData/*7:0*/ sparse_buffer__DOT__u_fid_bottom_ptr_impl__DOT__entry_valid_shift;
    CData/*0:0*/ __Vclklast__TOP__clk_i;
    CData/*0:0*/ __Vclklast__TOP__rstn_i;
    VlUnpacked<CData/*7:0*/, 8> sparse_buffer__DOT__sparse_array_In;
    VlUnpacked<CData/*7:0*/, 8> sparse_buffer__DOT__sparse_array_Q;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vsparse_buffer__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vsparse_buffer___024root(const char* name);
    ~Vsparse_buffer___024root();
    VL_UNCOPYABLE(Vsparse_buffer___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vsparse_buffer__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
