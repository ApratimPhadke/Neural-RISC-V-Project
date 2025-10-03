`timescale 1ns/1ps

module tb_darkriscv_basic;
  // Clock and reset
  logic clk = 0;
  logic rst = 1;

  // Memory interface signals
  logic [31:0] iaddr, daddr;
  logic [31:0] idata, datai, datao;
  logic [3:0] be;
  logic wr, rd;

  // Debug interface
  logic [31:0] debug;

  // Clock generation (100MHz)
  always #5 clk = ~clk;

  // Reset sequence
  initial begin
    #100 rst = 0;
    #50000 $finish;
  end

  // Simple instruction memory (ROM)
  reg [31:0] imem [0:1023];
  initial begin
    // Load a simple test program
    imem[0] = 32'h00000013; // nop (addi x0, x0, 0)
    imem[1] = 32'h00100093; // addi x1, x0, 1
    imem[2] = 32'h00200113; // addi x2, x0, 2
    imem[3] = 32'h002081b3; // add x3, x1, x2
    imem[4] = 32'h00000063; // beq x0, x0, +0 (infinite loop)
    // Fill rest with NOPs
    for (int i = 5; i < 1024; i++) begin
      imem[i] = 32'h00000013; // nop
    end
  end

  // Instruction memory read logic
  assign idata = imem[iaddr[11:2]];

  // Simple data memory (RAM)
  reg [31:0] dmem [0:1023];
  always_ff @(posedge clk) begin
    if (wr) begin
      if (be[0]) dmem[daddr[11:2]][7:0]   <= datao[7:0];
      if (be[1]) dmem[daddr[11:2]][15:8]  <= datao[15:8];
      if (be[2]) dmem[daddr[11:2]][23:16] <= datao[23:16];
      if (be[3]) dmem[daddr[11:2]][31:24] <= datao[31:24];
    end
  end
  assign datai = rd ? dmem[daddr[11:2]] : 32'h0;

  // DUT instantiation (the CPU core itself)
  // Parameter overrides removed
  darkriscv dut (
    .CLK(clk),
    .RES(rst),
    .HLT(1'b0),
    .IADDR(iaddr),
    .IDATA(idata),
    .DADDR(daddr),
    .DATAI(datai),
    .DATAO(datao),
    .BE(be),
    .WR(wr),
    .RD(rd),
    .DEBUG(debug)
  );

  // Waveform dump
  initial begin
    $dumpfile("tb_darkriscv_basic.vcd");
    $dumpvars(0, tb_darkriscv_basic);
  end

  // Monitor
  always @(posedge clk) begin
    if (!rst && iaddr < 32'h20) begin
      $display("Time: %0t, PC: 0x%08x, Instr: 0x%08x", $time, iaddr, idata);
    end
  end

endmodule
