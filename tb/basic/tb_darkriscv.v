`timescale 1ns/1ps

module tb_darkriscv;
  // Testbench signals
  reg  tb_clk = 0;
  reg  tb_res = 1;
  wire [31:0] tb_debug; // Changed from tb_dbg

  // Clock generation (100MHz)
  always #5 tb_clk = ~tb_clk;

  // Reset sequence
  initial begin
    #100 tb_res = 0;
    #20000 $finish;
  end

  // Instantiate the simple, self-contained darkriscv core
  darkriscv dut (
    .CLK(tb_clk),
    .RES(tb_res),
    .DEBUG(tb_debug) // Changed from DBG
  );

  // Waveform generation
  initial begin
    $dumpfile("tb_darkriscv.vcd");
    $dumpvars(0, tb_darkriscv);
  end

endmodule
