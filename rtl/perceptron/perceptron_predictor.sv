// Main Perceptron Branch Predictor Module
// Integrates all components and provides the prediction/training interface.
module perceptron_predictor #(
  parameter NUM_PERCEPTRONS    = 128,
  parameter HISTORY_LENGTH     = 32,
  parameter WEIGHT_WIDTH       = 8,
  parameter TRAINING_THRESHOLD = 16
) (
  input  logic clk,
  input  logic rst,

  // Prediction interface
  input  logic [31:0] pc,
  input  logic predict_en,
  output logic prediction,
  output logic prediction_valid,
  output logic signed [15:0] confidence,

  // Training interface
  input  logic train_en,
  input  logic [31:0] train_pc,
  input  logic actual_taken,

  // History update interface
  input  logic history_update_en,
  input  logic branch_taken,

  // Debug/monitoring outputs
  output logic [15:0] prediction_count,
  output logic [15:0] misprediction_count
);

  localparam ADDR_WIDTH = $clog2(NUM_PERCEPTRONS);

  // Internal signals
  logic [HISTORY_LENGTH-1:0]        history;
  logic [ADDR_WIDTH-1:0]            pred_index, train_index;
  logic signed [WEIGHT_WIDTH-1:0]   weights[HISTORY_LENGTH:0];
  logic signed [WEIGHT_WIDTH-1:0]   new_weights[HISTORY_LENGTH:0];
  logic signed [15:0]               dot_product;
  logic                             dot_product_valid;
  logic                             weight_write_en;

  // Performance counters
  logic [15:0] pred_count_reg, mispred_count_reg;

  // Simple hash function to map PC to a perceptron table index
  function [ADDR_WIDTH-1:0] hash_pc(input [31:0] pc_in);
    // Simple hash: XOR multiple bit ranges of the PC
    return pc_in[ADDR_WIDTH+1:2] ^ pc_in[ADDR_WIDTH+9:10] ^ pc_in[ADDR_WIDTH+17:18];
  endfunction

  assign pred_index  = hash_pc(pc);
  assign train_index = hash_pc(train_pc);

  // 1. Instantiate the Global History Register
  global_history_register #(
    .HISTORY_LENGTH(HISTORY_LENGTH)
  ) ghr_inst (
    .clk(clk),
    .rst(rst),
    .update_en(history_update_en),
    .branch_taken(branch_taken),
    .history(history)
  );

  // 2. Instantiate the Perceptron Weight Table
  perceptron_table #(
    .NUM_PERCEPTRONS(NUM_PERCEPTRONS),
    .HISTORY_LENGTH(HISTORY_LENGTH),
    .WEIGHT_WIDTH(WEIGHT_WIDTH)
  ) weight_table_inst (
    .clk(clk),
    .rst(rst),
    .read_addr(pred_index),
    .weights(weights),
    .write_en(weight_write_en),
    .write_addr(train_index),
    .new_weights(new_weights)
  );

  // 3. Instantiate the Dot Product Unit
  dot_product_unit #(
    .HISTORY_LENGTH(HISTORY_LENGTH),
    .WEIGHT_WIDTH(WEIGHT_WIDTH)
  ) dot_product_inst (
    .clk(clk),
    .rst(rst),
    .enable(predict_en),
    .history(history),
    .weights(weights),
    .dot_product(dot_product),
    .result_valid(dot_product_valid)
  );

  // --- Prediction Generation Logic ---
  assign prediction       = (dot_product >= 0);
  assign prediction_valid = dot_product_valid;
  assign confidence       = dot_product;

  // --- Training Logic ---
  logic mispredicted;
  logic signed [15:0] abs_confidence;
  logic should_train;

  assign abs_confidence = (dot_product >= 0) ? dot_product : -dot_product;
  assign mispredicted   = (prediction != actual_taken);
  assign should_train   = train_en && (mispredicted || (abs_confidence < TRAINING_THRESHOLD));
  assign weight_write_en = should_train;

  // Perceptron learning rule for updating weights
  always_comb begin
    // Default assignment: keep weights the same if not training
    for (int i = 0; i <= HISTORY_LENGTH; i++) begin
      new_weights[i] = weights[i];
    end

    if (should_train) begin
      // Bias weight update
      if (actual_taken) begin // Reinforce "taken"
        new_weights[HISTORY_LENGTH] = (weights[HISTORY_LENGTH] == 127) ? 127 : weights[HISTORY_LENGTH] + 1;
      end else begin // Reinforce "not taken"
        new_weights[HISTORY_LENGTH] = (weights[HISTORY_LENGTH] == -128) ? -128 : weights[HISTORY_LENGTH] - 1;
      end

      // History weights update
      for (int i = 0; i < HISTORY_LENGTH; i++) begin
        if (actual_taken == history[i]) begin // History bit agrees with outcome, strengthen weight
          new_weights[i] = (weights[i] == 127) ? 127 : weights[i] + 1;
        end else begin // History bit disagrees, weaken weight
          new_weights[i] = (weights[i] == -128) ? -128 : weights[i] - 1;
        end
      end
    end
  end

  // --- Performance Counters ---
  always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
      pred_count_reg    <= 16'h0;
      mispred_count_reg <= 16'h0;
    end else begin
      if (train_en) begin
        pred_count_reg <= pred_count_reg + 1;
        if (mispredicted) begin
          mispred_count_reg <= mispred_count_reg + 1;
        end
      end
    end
  end

  assign prediction_count    = pred_count_reg;
  assign misprediction_count = mispred_count_reg;

endmodule
