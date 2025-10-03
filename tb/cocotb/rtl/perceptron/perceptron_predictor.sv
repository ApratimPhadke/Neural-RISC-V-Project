module perceptron_predictor #(parameter TRAINING_THRESHOLD=16) (
  input logic clk, rst, predict_en, train_en, actual_taken, history_update_en, branch_taken,
  input logic [31:0] pc, train_pc,
  output logic prediction
);
  localparam HISTORY_LENGTH = 32;
  localparam WEIGHT_WIDTH = 8;
  localparam NUM_PERCEPTRONS = 128;
  logic [HISTORY_LENGTH-1:0] history;
  logic signed [WEIGHT_WIDTH-1:0] weights [HISTORY_LENGTH:0];
  logic signed [WEIGHT_WIDTH-1:0] new_weights [HISTORY_LENGTH:0];
  logic signed [15:0] dot_product;
  logic dot_product_valid, should_train;
  
  global_history_register ghr_inst(.*);
  perceptron_table table_inst(.*);
  dot_product_unit dot_product_inst(.enable(predict_en), .*);

  assign prediction = dot_product >= 0;
  assign should_train = train_en && ((prediction != actual_taken) || ($abs(dot_product) < TRAINING_THRESHOLD));
  
  always_comb begin
    new_weights = weights;
    if (should_train) begin
      new_weights[HISTORY_LENGTH] = weights[HISTORY_LENGTH] + (actual_taken ? 1 : -1);
      for (int i=0; i < HISTORY_LENGTH; i++)
        new_weights[i] = weights[i] + ((actual_taken == history[i]) ? 1 : -1);
    end
  end
endmodule
