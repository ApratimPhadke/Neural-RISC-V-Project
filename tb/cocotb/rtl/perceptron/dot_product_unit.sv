module dot_product_unit #(parameter HISTORY_LENGTH=32, WEIGHT_WIDTH=8) (
  input logic clk, rst, enable,
  input logic [HISTORY_LENGTH-1:0] history,
  input logic signed [WEIGHT_WIDTH-1:0] weights [HISTORY_LENGTH:0],
  output logic signed [15:0] dot_product,
  output logic result_valid
);
  logic signed [15:0] temp_sum;
  always_comb begin
    temp_sum = weights[HISTORY_LENGTH]; // Start with bias
    for (int i = 0; i < HISTORY_LENGTH; i++)
      temp_sum += history[i] ? weights[i] : -weights[i];
  end
  always_ff @(posedge clk or posedge rst) begin
    if (rst) begin dot_product <= 0; result_valid <= 0; end
    else begin dot_product <= temp_sum; result_valid <= enable; end
  end
endmodule
