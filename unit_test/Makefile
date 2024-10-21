BUILD_DIR = ./build
VFLAGS = -cc -trace --exe --build -j 8

TOP ?= cross_bar_top
VTOP =  V$(TOP)

CSRC = ./$(TOP)_tb.cpp

$(VTOP):
	@verilator $(VFLAGS) \
	--top-module $(TOP) \
	--Mdir $(BUILD_DIR) \
	-sv \
	-f filelist.f \
	$(CSRC) \

sim: $(VTOP)
	$(BUILD_DIR)/$(VTOP)

clean:
	rm -rf ./build
