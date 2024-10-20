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
  tfp->open("./wave/sparse_buffer_wave.vcd");
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
  for (int i = 0; i < 100; i++) {
    top->clk_i  = 0;
    top->rstn_i = 1;
    top->write_valid_i = 0;
    // write data
    if (top->write_allowIn_o) {
      top->write_valid_i = 1;
      top->write_data_i = i;
    }
    // read data
    int bottom_ptr = top->sparse_buffer_bottom_ptr_o;
    top->read_rtn_allowIn_i = 1;
    if ((top->sparse_buffer_valid_o >> bottom_ptr) & 1) {
      printf("bottom ptr [%d] is point a valid entry, read this entry from buffer.\n", bottom_ptr);
      if (top->read_allowIn_o) {
        top->read_valid_i = 1;
        top->read_ptr_i = bottom_ptr;
      }
    }
    top->eval();
    tfp->dump(main_time++);
    if (top->read_rtn_valid_o) {
      printf("read data from buffer success, data: %d\n", top->read_rtn_data_o);
    }
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
