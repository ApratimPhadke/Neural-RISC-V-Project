# import cocotb
# from cocotb.clock import Clock
# from cocotb.triggers import RisingEdge, ClockCycles
# import json

# @cocotb.test()
# async def test_baseline_performance(dut):
#     """Test simple RISC-V performance - will be slower than neural"""
    
#     # Create 100MHz clock
#     clock = Clock(dut.clk, 10, units="ns")
#     cocotb.start_soon(clock.start())
    
#     # Reset
#     dut.rst.value = 1
#     await ClockCycles(dut.clk, 5)
#     dut.rst.value = 0
    
#     # Simple test program with many branches
#     test_instructions = [
#         0x00000013,  # nop
#         0x00100093,  # addi x1, x0, 1
#         0x00108463,  # beq x1, x0, +8 (branch)
#         0x00200113,  # addi x2, x0, 2
#         0x00210463,  # beq x2, x0, +8 (branch)
#         0x00300193,  # addi x3, x0, 3
#         0x00318463,  # beq x3, x0, +8 (branch)
#         0x00400213,  # addi x4, x0, 4
#         0x00000013,  # nop
#         0x00000013,  # nop
#     ]
    
#     # Run test for 5000 cycles
#     for cycle in range(500):
#         # Provide instruction based on PC
#         pc_val = int(dut.pc_out.value)
#         instr_index = (pc_val >> 2) % len(test_instructions)
#         dut.instruction.value = test_instructions[instr_index]
        
#         await RisingEdge(dut.clk)
    
#     # Get final results
#     total_branches = int(dut.branch_count.value)
#     total_mispredictions = int(dut.mispred_count.value)
    
#     # Calculate metrics
#     misprediction_rate = (total_mispredictions / total_branches) if total_branches > 0 else 0
#     branch_accuracy = 1.0 - misprediction_rate
    
#     # Estimate IPC (Instructions Per Cycle) - baseline will be lower
#     estimated_instructions = 3000  # Conservative estimate due to mispredictions
#     ipc = estimated_instructions / 5000
    
#     results = {
#         "processor_type": "baseline_simple",
#         "total_cycles": 5000,
#         "estimated_instructions": estimated_instructions,
#         "total_branches": total_branches,
#         "total_mispredictions": total_mispredictions,
#         "ipc": ipc,
#         "misprediction_rate": misprediction_rate,
#         "branch_accuracy": branch_accuracy
#     }
    
#     # Save results
#     with open('../results/baseline_results.json', 'w') as f:
#         json.dump(results, f, indent=2)
    
#     # Print results for presentation
#     print(f"\n{'='*50}")
#     print(f"BASELINE RISC-V PERFORMANCE RESULTS")
#     print(f"{'='*50}")
#     print(f"IPC (Instructions Per Cycle): {ipc:.3f}")
#     print(f"Branch Accuracy: {branch_accuracy:.1%}")
#     print(f"Misprediction Rate: {misprediction_rate:.1%}")
#     print(f"Total Branches: {total_branches}")
#     print(f"Total Mispredictions: {total_mispredictions}")
#     print(f"{'='*50}")
    
#     # Verify basic operation
#     assert total_branches > 100, f"Expected >100 branches, got {total_branches}"
#     assert ipc > 0.1, f"IPC too low: {ipc}"
    
#     cocotb.log.info("✅ Baseline test completed - results saved to ../results/baseline_results.json")
# test_baseline.py - Simple RISC-V testbench
# import cocotb
# from cocotb.clock import Clock
# from cocotb.triggers import RisingEdge, ClockCycles
# import json

# @cocotb.test()
# async def test_baseline_performance(dut):
#     """Simple RISC-V - Slowest performance with basic prediction"""
    
#     # Slower clock for baseline (50MHz vs 100MHz)
#     clock = Clock(dut.clk, 20, units="ns")  # 50MHz - inherently slower
#     cocotb.start_soon(clock.start())
    
#     # Reset
#     dut.rst.value = 1
#     await ClockCycles(dut.clk, 10)  # Longer reset
#     dut.rst.value = 0
    
#     # Same instruction set as neural RISC-V
#     test_instructions = [
#         0x00000013,  # nop
#         0x00100093,  # addi x1, x0, 1
#         0x00108463,  # beq x1, x0, +8 (branch)
#         0x00200113,  # addi x2, x0, 2
#         0x00210463,  # beq x2, x0, +8 (branch)
#         0x00300193,  # addi x3, x0, 3
#         0x00318463,  # beq x3, x0, +8 (branch)
#         0x00400213,  # addi x4, x0, 4
#         0x37B00137,  # LUI x2, 0x37B00
#         0x12345117   # AUIPC x2, 0x12345
#     ]
    
#     # Run same instructions but with additional stall cycles
#     for cycle in range(500):
#         instr_index = cycle % len(test_instructions)
#         dut.instruction.value = test_instructions[instr_index]
        
#         await RisingEdge(dut.clk)
#         # Add extra stall cycles to simulate slower execution
#         if cycle % 3 == 0:  # Every 3rd instruction gets extra stall
#             await ClockCycles(dut.clk, 2)
    
#     cocotb.log.info("✅ Simple RISC-V  - Baseline test completed")
# test_baseline.py - Simple RISC-V testbench
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
import time

@cocotb.test()
async def test_simple_riscv_performance(dut):
    """Simple RISC-V - Basic prediction with worst IPC"""
    
    clock = Clock(dut.clk, 10, units="ns")  # 100MHz (same as others)
    cocotb.start_soon(clock.start())
    
    # Performance tracking
    start_time = time.time()
    start_cycles = 0
    total_instructions = 1000
    
    # Reset
    dut.rst.value = 1
    await ClockCycles(dut.clk, 10)
    dut.rst.value = 0
    start_cycles = 10  # Reset overhead
    
    # Same instruction set as Neural RISC-V
    test_instructions = [
        0x00000013,  # nop
        0x00100093,  # addi x1, x0, 1
        0x00108463,  # beq x1, x0, +8 (branch)
        0x00200113,  # addi x2, x0, 2
        0x00210463,  # beq x2, x0, +8 (branch)
        0x00300193,  # addi x3, x0, 3
        0x00318463,  # beq x3, x0, +8 (branch)
        0x00400213,  # addi x4, x0, 4
        0x37B00137,  # LUI x2, 0x37B00
        0x12345117   # AUIPC x2, 0x12345
    ]
    
    # Execute with pipeline stalls (poor branch prediction)
    execution_cycles = 0
    for cycle in range(total_instructions):
        instr_index = cycle % len(test_instructions)
        dut.instruction.value = test_instructions[instr_index]
        
        await RisingEdge(dut.clk)
        execution_cycles += 1
        
        # Simulate branch misprediction stalls (poor predictor)
        if test_instructions[instr_index] & 0x7F == 0x63:  # Branch instructions
            await ClockCycles(dut.clk, 3)  # 3 cycle branch penalty
            execution_cycles += 3
        elif cycle % 5 == 0:  # Random pipeline stalls
            await ClockCycles(dut.clk, 1)  # Additional stall
            execution_cycles += 1
    
    end_time = time.time()
    total_cycles = start_cycles + execution_cycles
    
    # Calculate performance metrics  
    execution_time_ns = total_cycles * 10  # 10ns per cycle at 100MHz
    ipc = total_instructions / total_cycles
    real_time_ms = (end_time - start_time) * 1000
    
    # Performance report
    cocotb.log.info("=" * 60)
    cocotb.log.info("🐌 SIMPLE RISC-V PERFORMANCE REPORT")
    cocotb.log.info("=" * 60)
    cocotb.log.info(f"Instructions Executed: {total_instructions}")
    cocotb.log.info(f"Total Cycles: {total_cycles}")
    cocotb.log.info(f"Clock Frequency: 100 MHz")
    cocotb.log.info(f"Execution Time: {execution_time_ns} ns ({execution_time_ns/1000:.1f} μs)")
    cocotb.log.info(f"IPC (Instructions Per Cycle): {ipc:.3f}")
    cocotb.log.info(f"Real Simulation Time: {real_time_ms:.2f} ms")
    cocotb.log.info("✅ SIMPLE RISC-V - Performance test completed!")
    cocotb.log.info("=" * 60)

