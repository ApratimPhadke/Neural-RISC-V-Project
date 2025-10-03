import cocotb
from cocotb.clock import Clock
from cocotb.triggers import Timer

@cocotb.test()
async def test_boot(dut):
    """Test that the core boots and runs."""
    clock = Clock(dut.CLK, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    dut.RES.value = 1
    dut.HLT.value = 0
    await Timer(100, units="ns")
    dut.RES.value = 0
    
    await Timer(1000, units="ns")
    assert dut.DEBUG.value.integer != 0
