// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsparse_buffer.h"
#include "Vsparse_buffer__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vsparse_buffer::Vsparse_buffer(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vsparse_buffer__Syms(_vcontextp__, _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , rstn_i{vlSymsp->TOP.rstn_i}
    , write_valid_i{vlSymsp->TOP.write_valid_i}
    , write_allowIn_o{vlSymsp->TOP.write_allowIn_o}
    , write_data_i{vlSymsp->TOP.write_data_i}
    , read_valid_i{vlSymsp->TOP.read_valid_i}
    , read_allowIn_o{vlSymsp->TOP.read_allowIn_o}
    , read_ptr_i{vlSymsp->TOP.read_ptr_i}
    , read_rtn_valid_o{vlSymsp->TOP.read_rtn_valid_o}
    , read_rtn_allowIn_i{vlSymsp->TOP.read_rtn_allowIn_i}
    , read_rtn_data_o{vlSymsp->TOP.read_rtn_data_o}
    , sparse_buffer_valid_o{vlSymsp->TOP.sparse_buffer_valid_o}
    , sparse_buffer_bottom_ptr_o{vlSymsp->TOP.sparse_buffer_bottom_ptr_o}
    , rootp{&(vlSymsp->TOP)}
{
}

Vsparse_buffer::Vsparse_buffer(const char* _vcname__)
    : Vsparse_buffer(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vsparse_buffer::~Vsparse_buffer() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vsparse_buffer___024root___eval_initial(Vsparse_buffer___024root* vlSelf);
void Vsparse_buffer___024root___eval_settle(Vsparse_buffer___024root* vlSelf);
void Vsparse_buffer___024root___eval(Vsparse_buffer___024root* vlSelf);
#ifdef VL_DEBUG
void Vsparse_buffer___024root___eval_debug_assertions(Vsparse_buffer___024root* vlSelf);
#endif  // VL_DEBUG
void Vsparse_buffer___024root___final(Vsparse_buffer___024root* vlSelf);

static void _eval_initial_loop(Vsparse_buffer__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vsparse_buffer___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vsparse_buffer___024root___eval_settle(&(vlSymsp->TOP));
        Vsparse_buffer___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vsparse_buffer::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsparse_buffer::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsparse_buffer___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vsparse_buffer___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vsparse_buffer::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vsparse_buffer::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vsparse_buffer::final() {
    Vsparse_buffer___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Trace configuration

void Vsparse_buffer___024root__trace_init_top(Vsparse_buffer___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsparse_buffer___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsparse_buffer___024root*>(voidSelf);
    Vsparse_buffer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vsparse_buffer___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vsparse_buffer___024root__trace_register(Vsparse_buffer___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsparse_buffer::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vsparse_buffer___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
