#include "verilated_vcd_c.h" // for vcd wave
#include "verilated.h"
#include "Vcross_bar_top.h"
#include <stdio.h>
#include <ctime>
#include <cstdlib>

VerilatedContext *contextp;
VerilatedVcdC *tfp;
Vcross_bar_top *top;
vluint64_t main_time = 0; // Simulation time

double sc_time_stamp() {
	return main_time;
}

void init_verilator(int argc, char **argv) {
  contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  top = new Vcross_bar_top{contextp};
  Verilated::traceEverOn(true);
  tfp = new VerilatedVcdC;
  top->trace(tfp, 0);
  tfp->open("./wave/cross_bar_tb_wave.vcd");
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
  srand(time(0));
  for (int i = 0; i < 100; i++) {
    top->clk_i  = 0;
    top->rstn_i = 1;
    // send req to channel 0
    top->ch0_req_valid_i = rand() % 2;
    top->ch0_req_addr_i = rand() % 4;
    // send req to channel 1
    top->ch1_req_valid_i = rand() % 2;
    top->ch1_req_addr_i = rand() % 4;
    // send req to channel 2
    top->ch2_req_valid_i = rand() % 2;
    top->ch2_req_addr_i = rand() % 4;
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
