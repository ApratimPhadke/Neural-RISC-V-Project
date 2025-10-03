module global_history_register #(parameter HISTORY_LENGTH = 32) (
  input logic clk, rst, update_en, branch_taken,
  output logic [HISTORY_LENGTH-1:0] history
);
  always_ff @(posedge clk or posedge rst)
    if (rst) history <= '0;
    else if (update_en) history <= {history[HISTORY_LENGTH-2:0], branch_taken};
endmodule
