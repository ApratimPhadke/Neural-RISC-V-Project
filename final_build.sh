#!/bin/bash
echo "🚀 Starting the final, automated build and test process..."

# --- STEP 1: CLEANUP ---
echo "🧹 Cleaning up old files..."
rm -f rtl/core/ronanchip_top.sv
rm -f rtl/core/darkriscv.v
rm -f rtl/common/config.vh
rm -f tb/cocotb/test_neural_riscv.py
rm -f tb/cocotb/Makefile
rm -rf baseline-core

# --- STEP 2: GET & FIX FRESH BASELINE ---
echo "🚚 Getting a fresh copy of the baseline core..."
git clone https://github.com/darklife/darkriscv.git baseline-core
cp baseline-core/rtl/darkriscv.v rtl/core/
cp baseline-core/rtl/config.vh rtl/common/

echo "🔧 Fixing hardcoded path in the baseline core..."
sed -i 's|`include "../rtl/config.vh"|`include "config.vh"|g' rtl/core/darkriscv.v

# --- STEP 3: CREATE FINAL, CORRECT FILES ---
echo "🛠️ Creating final, correct project files..."

cat > rtl/core/ronanchip_top.sv << 'EOT'
module ronanchip_top (
  input  logic CLK,
  input  logic RES,
  output logic [31:0] DEBUG
);
  darkriscv core_inst (
    .CLK(CLK),
    .RES(RES),
    .DEBUG(DEBUG)
  );
endmodule
EOT

cat > tb/cocotb/test_neural_riscv.py << 'EOT'
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles

@cocotb.test()
async def test_core_activity(dut):
    """Checks that the core is active and running."""
    clock = Clock(dut.CLK, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    dut.RES.value = 1
    await ClockCycles(dut.CLK, 10)
    dut.RES.value = 0
    
    await ClockCycles(dut.CLK, 500)
    
    dbg = dut.DEBUG.value
    if not dbg.is_resolvable:
        assert False, f"DEBUG has unknowns: {dbg.binstr}"

    assert dut.DEBUG.value.integer != 0, "Core is not active, DEBUG port is zero."
    cocotb.log.info(f"✅ Test passed: Core is active and running. DEBUG=0b{dut.DEBUG.value.binstr}")
EOT

cat > tb/cocotb/Makefile << 'EOT'
SIM ?= icarus
TOPLEVEL = ronanchip_top
MODULE = test_neural_riscv

VERILOG_SOURCES = \
    ../../rtl/core/ronanchip_top.sv \
    ../../rtl/core/darkriscv.v

COMPILE_ARGS += -g2012 -I../../rtl/common

include $(shell cocotb-config --makefiles)/Makefile.sim
EOT

echo "✅ All project files have been created successfully."

# --- STEP 4: RUN THE SIMULATION ---
echo "🏁 Running the final simulation..."
source /home/abc/neural-riscv-env/bin/activate
cd /home/abc/neural-riscv-project/tb/cocotb
make

# --- FINAL CHECK ---
if [ $? -eq 0 ]; then
    echo "🎉 CONGRATULATIONS! The simulation passed successfully!"
else
    echo "❌ Simulation failed. Please check the log for errors."
fi
