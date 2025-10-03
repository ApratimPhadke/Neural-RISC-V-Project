import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles
import matplotlib.pyplot as plt

@cocotb.test()
async def test_ronanchip_performance(dut):
    """Run a long simulation and plot performance."""
    clock = Clock(dut.CLK, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    history_ipc = []
    history_mispred = []
    
    dut.RES.value = 1
    await ClockCycles(dut.CLK, 10)
    dut.RES.value = 0
    
    for i in range(100):
      await ClockCycles(dut.CLK, 500)
      ipc = dut.final_ipc.value.integer / 1000.0
      mispred_rate = dut.final_mispred_rate.value.integer / 1000.0
      history_ipc.append(ipc)
      history_mispred.append(mispred_rate)
      cocotb.log.info(f"IPC: {ipc:.3f}, Misprediction Rate: {mispred_rate:.3%}")

    # Plotting
    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 8))
    ax1.plot(history_ipc, 'b.-')
    ax1.set_title('RONANCHIP1 - IPC Over Time')
    ax1.set_ylabel('IPC')
    ax1.grid(True)
    ax2.plot(history_mispred, 'r.-')
    ax2.set_title('Branch Misprediction Rate Over Time (Learning Curve)')
    ax2.set_ylabel('Misprediction Rate')
    ax2.set_xlabel('Time (x500 cycles)')
    ax2.grid(True)
    plt.savefig("../../results/final_performance.png")
    cocotb.log.info("✅ Simulation complete. Performance graph saved to results/ directory.")
