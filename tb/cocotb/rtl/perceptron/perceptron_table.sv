module perceptron_table #(parameter NUM_PERCEPTRONS=128, HISTORY_LENGTH=32, WEIGHT_WIDTH=8, ADDR_WIDTH=$clog2(NUM_PERCEPTRONS)) (
  input logic clk, rst, write_en,
  input logic [ADDR_WIDTH-1:0] read_addr, write_addr,
  output logic signed [WEIGHT_WIDTH-1:0] weights [HISTORY_LENGTH:0],
  input logic signed [WEIGHT_WIDTH-1:0] new_weights [HISTORY_LENGTH:0]
);
  logic signed [WEIGHT_WIDTH-1:0] weight_mem [NUM_PERCEPTRONS-1:0] [HISTORY_LENGTH:0];
  assign weights = weight_mem[read_addr];
  always_ff @(posedge clk)
    if (write_en) weight_mem[write_addr] <= new_weights;
endmodule
