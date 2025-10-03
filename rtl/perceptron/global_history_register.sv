// Global History Register for Branch Prediction
// Maintains a sliding window of recent branch outcomes
module global_history_register #(
  parameter HISTORY_LENGTH = 32
) (
  input  logic clk,
  input  logic rst,
  input  logic update_en,      // Enable history update
  input  logic branch_taken,     // Actual branch outcome (1=taken, 0=not taken)
  output logic [HISTORY_LENGTH-1:0] history // Current history vector
);

  // Shift register to store branch history
  logic [HISTORY_LENGTH-1:0] history_reg;

  always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
      history_reg <= '0;
    end else if (update_en) begin
      // Shift left and insert the new branch outcome at the end
      history_reg <= {history_reg[HISTORY_LENGTH-2:0], branch_taken};
    end
  end

  assign history = history_reg;

endmodule
