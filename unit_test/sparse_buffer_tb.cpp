#include "verilated_vcd_c.h" // for vcd wave
#include "verilated.h"
#include "Vsparse_buffer.h"
#include <stdio.h>

VerilatedContext *contextp;
VerilatedVcdC *tfp;
Vsparse_buffer *top;
vluint64_t main_time = 0; // Simulation time

double sc_time_stamp() {
	return main_time;
}

void init_verilator(int argc, char **argv) {
  contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  top = new Vsparse_buffer{contextp};
  Verilated::traceEverOn(true);
  tfp = new VerilatedVcdC;
  top->trace(tfp, 0);
  tfp->open("sparse_buffer_wave.vcd");
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
    top->write_valid_i = 0;
    // input data
    if (top->write_allowIn_o) {
      top->write_valid_i = 1;
      top->write_data_i = i;
    }
    top->eval();
    tfp->dump(main_time++);
    top->clk_i  = 1;
    top->rstn_i = 1;
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
