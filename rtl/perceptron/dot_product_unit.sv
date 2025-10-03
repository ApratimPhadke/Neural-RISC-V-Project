// Pipelined Dot Product Computation Unit
// Computes the weighted sum of history bits and the bias weight.
module dot_product_unit #(
  parameter HISTORY_LENGTH = 32,
  parameter WEIGHT_WIDTH   = 8
) (
  input  logic clk,
  input  logic rst,
  input  logic enable,

  // Inputs
  input  logic [HISTORY_LENGTH-1:0] history,
  input  logic signed [WEIGHT_WIDTH-1:0] weights [HISTORY_LENGTH:0],

  // Outputs
  output logic signed [15:0] dot_product,
  output logic result_valid
);

  // Pipeline Stage 1: Partial Products
  // If history bit is 1, use the positive weight; otherwise, use the negative weight.
  logic signed [WEIGHT_WIDTH:0] partial_products [HISTORY_LENGTH-1:0];
  logic signed [WEIGHT_WIDTH-1:0] bias_reg;
  logic enable_stage1;

  always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
      enable_stage1 <= 1'b0;
      bias_reg      <= '0;
      for (int i = 0; i < HISTORY_LENGTH; i++) begin
        partial_products[i] <= '0;
      end
    end else begin
      enable_stage1 <= enable;
      bias_reg      <= weights[HISTORY_LENGTH]; // Latch the bias weight
      if (enable) begin
        for (int i = 0; i < HISTORY_LENGTH; i++) begin
          partial_products[i] <= history[i] ? $signed(weights[i]) : -$signed(weights[i]);
        end
      end
    end
  end

  // Pipeline Stage 2: Sum partial products in parallel groups for better timing
  logic signed [15:0] sum_stage1, sum_stage2, sum_stage3, sum_stage4;
  logic enable_stage2;

  always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
      enable_stage2 <= 1'b0;
      sum_stage1    <= '0;
      sum_stage2    <= '0;
      sum_stage3    <= '0;
      sum_stage4    <= '0;
    end else begin
      enable_stage2 <= enable_stage1;
      if (enable_stage1) begin
        // Sum in groups of 8
        sum_stage1 <= partial_products[0] + partial_products[1] + partial_products[2] + partial_products[3] + partial_products[4] + partial_products[5] + partial_products[6] + partial_products[7];
        sum_stage2 <= partial_products[8] + partial_products[9] + partial_products[10] + partial_products[11] + partial_products[12] + partial_products[13] + partial_products[14] + partial_products[15];
        sum_stage3 <= partial_products[16] + partial_products[17] + partial_products[18] + partial_products[19] + partial_products[20] + partial_products[21] + partial_products[22] + partial_products[23];
        sum_stage4 <= partial_products[24] + partial_products[25] + partial_products[26] + partial_products[27] + partial_products[28] + partial_products[29] + partial_products[30] + partial_products[31];
      end
    end
  end

  // Pipeline Stage 3: Final accumulation with the bias
  always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
      dot_product  <= '0;
      result_valid <= 1'b0;
    end else begin
      result_valid <= enable_stage2;
      if (enable_stage2) begin
        dot_product <= sum_stage1 + sum_stage2 + sum_stage3 + sum_stage4 + bias_reg;
      end
    end
  end

endmodule
