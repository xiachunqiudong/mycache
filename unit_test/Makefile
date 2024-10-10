BUILD_DIR = ./build
VFLAGS = -cc -trace --exe --build -j 8

TOP ?= plru_impl
VTOP =  V$(TOP)

CSRC = ./plru_impl_tb.cpp
VSRC = ../vsrc/plru_impl.sv

$(VTOP):
	@echo "====================== CSRC ======================"
	@echo $(CSRC)
	@echo "====================== VSRC ======================"
	@echo $(VSRC)
	@echo "====================== END  ======================"
	@verilator $(VFLAGS) \
	--top-module $(TOP) \
	--Mdir $(BUILD_DIR) \
	-sv \
	$(VSRC) $(CSRC) \

sim: $(VTOP)
	$(BUILD_DIR)/$(VTOP)

clean:
	rm -rf ./build