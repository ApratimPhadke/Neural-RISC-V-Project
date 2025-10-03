`include "config.vh"
module ronanchip_core (
  input  logic CLK, RES,
  output logic [31:0] final_ipc, final_mispred_rate
);
  // This is a simplified but functional model to demonstrate the predictor
  logic [31:0] pc_reg;
  logic is_branch, actual_taken, prediction;
  
  // Performance counters
  reg [31:0] cycle_count = 0;
  reg [31:0] instruction_count = 0;
  reg [31:0] branch_count = 0;
  reg [31:0] mispred_count = 0;

  perceptron_predictor bp_inst (
    .clk(CLK), .rst(RES), .pc(pc_reg), .predict_en(is_branch),
    .prediction(prediction), .train_en(is_branch), .actual_taken(actual_taken),
    .history_update_en(is_branch), .branch_taken(actual_taken)
  );

  assign is_branch = (pc_reg[4:2] == 3'b001); // Pseudo-random branch
  assign actual_taken = (pc_reg[5] ^ pc_reg[2]); // Pseudo-random outcome

  always_ff @(posedge CLK or posedge RES) begin
    if (RES) begin
      pc_reg <= `RESET_PC;
      cycle_count <= 0; instruction_count <= 0; branch_count <= 0; mispred_count <= 0;
    end else begin
      cycle_count <= cycle_count + 1;
      if (is_branch) begin
        branch_count <= branch_count + 1;
        if (prediction != actual_taken) begin
          mispred_count <= mispred_count + 1;
          pc_reg <= pc_reg + 12; // Penalty
        end else begin
          instruction_count <= instruction_count + 1;
          pc_reg <= pc_reg + 4;
        end
      end else begin
        instruction_count <= instruction_count + 1;
        pc_reg <= pc_reg + 4;
      end
    end
  end
  assign final_ipc = (cycle_count > 0) ? (instruction_count * 1000) / cycle_count : 0;
  assign final_mispred_rate = (branch_count > 0) ? (mispred_count * 1000) / branch_count : 0;
endmodule
