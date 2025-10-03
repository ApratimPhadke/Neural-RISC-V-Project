module ronanchip_top (
  input  logic        CLK,
  input  logic        RES,
  input  logic [31:0] if_inst_from_testbench, // Input from testbench
  output logic [31:0] DEBUG
);

  // Instantiate the DarkRISCV core
  darkriscv core_inst (
    .CLK               (CLK),
    .RES               (RES),
    .instruction_input (if_inst_from_testbench),
    .DEBUG             (DEBUG)
  );

endmodule

