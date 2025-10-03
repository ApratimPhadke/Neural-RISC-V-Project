SIM ?= icarus
TOPLEVEL = ronanchip_top
MODULE = test_neural_riscv

VERILOG_SOURCES = \
    ../../rtl/core/ronanchip_top.sv \
    ../../rtl/core/darkriscv.v

# Add compile arguments for the simulator
COMPILE_ARGS += -sv -I../../rtl/common -Wno-CASEINCOMPLETE

include $(shell cocotb-config --makefiles)/Makefile.sim
