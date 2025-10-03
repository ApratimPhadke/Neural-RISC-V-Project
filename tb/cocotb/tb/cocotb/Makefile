SIM ?= icarus
TOPLEVEL = ronanchip_core
MODULE = test_core

VERILOG_SOURCES = ../../rtl/core/ronanchip_core.sv ../../rtl/perceptron/*.sv
COMPILE_ARGS += -g2012 -I../../rtl/common

include $(shell cocotb-config --makefiles)/Makefile.sim
