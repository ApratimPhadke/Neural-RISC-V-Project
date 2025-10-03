// Perceptron Weight Table
// Stores weight vectors for different branch PCs using Block RAM
module perceptron_table #(
  parameter NUM_PERCEPTRONS = 128,
  parameter HISTORY_LENGTH  = 32,
  parameter WEIGHT_WIDTH    = 8,
  parameter ADDR_WIDTH      = $clog2(NUM_PERCEPTRONS)
) (
  input  logic clk,
  input  logic rst,

  // Read port (for making predictions)
  input  logic [ADDR_WIDTH-1:0] read_addr,
  output logic signed [WEIGHT_WIDTH-1:0] weights [HISTORY_LENGTH:0], // +1 for the bias weight

  // Write port (for training)
  input  logic write_en,
  input  logic [ADDR_WIDTH-1:0] write_addr,
  input  logic signed [WEIGHT_WIDTH-1:0] new_weights [HISTORY_LENGTH:0]
);

  // Weight memory implemented as BRAM on the FPGA
  // Synthesis tools will infer this as a RAM block
  logic signed [WEIGHT_WIDTH-1:0] weight_mem [NUM_PERCEPTRONS-1:0] [HISTORY_LENGTH:0];

  // Read operation (asynchronous read)
  always_comb begin
    for (int i = 0; i <= HISTORY_LENGTH; i++) begin
      weights[i] = weight_mem[read_addr][i];
    end
  end

  // Write operation (synchronous write)
  always_ff @(posedge clk) begin
    if (write_en) begin
      for (int i = 0; i <= HISTORY_LENGTH; i++) begin
        weight_mem[write_addr][i] <= new_weights[i];
      end
    end
  end

endmodule
