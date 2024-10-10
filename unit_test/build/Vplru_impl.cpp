// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vplru_impl.h"
#include "Vplru_impl__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vplru_impl::Vplru_impl(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vplru_impl__Syms(_vcontextp__, _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , rstn_i{vlSymsp->TOP.rstn_i}
    , cacheLine_access_map_i{vlSymsp->TOP.cacheLine_access_map_i}
    , rootp{&(vlSymsp->TOP)}
{
}

Vplru_impl::Vplru_impl(const char* _vcname__)
    : Vplru_impl(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vplru_impl::~Vplru_impl() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vplru_impl___024root___eval_initial(Vplru_impl___024root* vlSelf);
void Vplru_impl___024root___eval_settle(Vplru_impl___024root* vlSelf);
void Vplru_impl___024root___eval(Vplru_impl___024root* vlSelf);
#ifdef VL_DEBUG
void Vplru_impl___024root___eval_debug_assertions(Vplru_impl___024root* vlSelf);
#endif  // VL_DEBUG
void Vplru_impl___024root___final(Vplru_impl___024root* vlSelf);

static void _eval_initial_loop(Vplru_impl__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vplru_impl___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vplru_impl___024root___eval_settle(&(vlSymsp->TOP));
        Vplru_impl___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vplru_impl::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vplru_impl::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vplru_impl___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vplru_impl___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vplru_impl::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vplru_impl::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vplru_impl::final() {
    Vplru_impl___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Trace configuration

void Vplru_impl___024root__trace_init_top(Vplru_impl___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vplru_impl___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vplru_impl___024root*>(voidSelf);
    Vplru_impl__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vplru_impl___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vplru_impl___024root__trace_register(Vplru_impl___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vplru_impl::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vplru_impl___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
