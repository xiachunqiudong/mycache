#include "verilated_vcd_c.h" // for vcd wave
#include "verilated.h"
#include "Vplru_impl.h"
#include <stdio.h>

VerilatedContext *contextp;
VerilatedVcdC *tfp;
Vplru_impl *top;
vluint64_t main_time = 0; // Simulation time

double sc_time_stamp() {
	return main_time;
}

void init_verilator(int argc, char **argv) {
  contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  top = new Vplru_impl{contextp};
  Verilated::traceEverOn(true);
  tfp = new VerilatedVcdC;
  top->trace(tfp, 0);
  tfp->open("wave.vcd");
}

void free() {
  if (tfp != nullptr)
    delete tfp;
  if (top != nullptr)
    delete top;
  if (contextp != nullptr)
    delete contextp; 
}

void reset() {
  top->clk_i  = 0;
  top->rstn_i = 0;
  top->eval();
  tfp->dump(main_time++);
  top->clk_i  = 1;
  top->rstn_i = 0;
  top->eval();
  tfp->dump(main_time++);
}

void sim() {
  for (int i = 0; i < 10; i++) {
    top->clk_i  = 0;
    top->rstn_i = 1;
    top->cacheLine_access_map_i = 0;
    top->eval();
    tfp->dump(main_time++);
    top->clk_i  = 1;
    top->rstn_i = 1;
    top->cacheLine_access_map_i = 1 << i;
    top->eval();
    tfp->dump(main_time++);
  }
}

int main(int argc, char *argv[]) {
  init_verilator(argc, argv);  
  reset();
  sim();
  free();
  return 0;
}
