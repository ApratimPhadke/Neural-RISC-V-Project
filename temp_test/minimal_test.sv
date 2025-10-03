// Step 1: Define the macro directly
`define RESET_PC 32'h00000000

// Step 2: A minimal version of our module
module neural_darkriscv (
  input  logic CLK,
  input  logic RES
);
  logic [31:0] pc_reg;
  always_ff @(posedge CLK or posedge RES) begin
    if (RES) pc_reg <= `RESET_PC;
    else     pc_reg <= pc_reg + 4;
  end
endmodule

// Step 3: A minimal testbench
module tb_minimal;
  logic clk = 0;
  logic res = 1;

  // Instantiate the DUT
  neural_darkriscv dut (.CLK(clk), .RES(res));

  // Clock and Reset
  always #5 clk = ~clk;
  initial begin
    $display("Starting minimal test...");
    #100 res = 0;
    #1000 $display("Minimal test finished successfully.");
    $finish;
  end
endmodule
