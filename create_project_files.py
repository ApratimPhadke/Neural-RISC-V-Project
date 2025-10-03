import os
from pathlib import Path

# --- Dictionary of all project files and their content ---
project_files = {
    "rtl/common/config.vh": """
// Configuration for the RISC-V Core
`define RESET_PC 32'h00000000
    """,

    "rtl/core/neural_darkriscv.sv": """
// Neural Network-Enhanced 5-Stage Pipelined RISC-V Core
`include "config.vh"

module neural_darkriscv #(
  parameter PREDICTOR_ENABLED = 1
) (
  input  logic CLK,
  input  logic RES,
  input  logic HLT,
  output logic branch_train_en,
  output logic branch_mispredicted,
  output logic [31:0] wb_inst,
  input  logic [31:0] if_inst_from_testbench
);
  logic [31:0] pc_reg, pc_next;
  logic [31:0] registers[0:31];
  logic [4:0]  id_rs1_addr, id_rs2_addr, wb_rd_addr;
  logic [31:0] id_rs1_data, id_rs2_data;
  logic [31:0] ex_alu_result;
  logic        ex_zero_flag;
  logic        wb_reg_write_en;
  logic [31:0] wb_write_data;
  logic stall, flush;
  logic [31:0] if_id_pc, id_ex_pc, ex_mem_pc, mem_wb_pc;
  logic [31:0] if_id_inst, id_ex_inst, ex_mem_inst, mem_wb_inst;
  logic is_branch_id, is_branch_ex;
  logic branch_prediction;
  logic branch_prediction_valid;
  logic branch_actual_taken;
  logic [31:0] branch_target;

  generate
    if (PREDICTOR_ENABLED) begin : gen_predictor
      perceptron_predictor bp_inst (
        .clk(CLK), .rst(RES), .pc(pc_reg), .predict_en(is_branch_id),
        .prediction(branch_prediction), .prediction_valid(branch_prediction_valid),
        .train_en(branch_train_en), .train_pc(ex_mem_pc), .actual_taken(branch_actual_taken),
        .history_update_en(branch_train_en), .branch_taken(branch_actual_taken)
      );
    end
  endgenerate

  always_ff @(posedge CLK or posedge RES) begin
    if (RES) pc_reg <= `RESET_PC;
    else pc_reg <= pc_next;
  end

  always_ff @(posedge CLK or posedge RES) begin
    if (RES || flush) begin
      if_id_inst <= 32'h13;
      if_id_pc   <= `RESET_PC;
    end else if (!stall) begin
      if_id_inst <= if_inst_from_testbench;
      if_id_pc   <= pc_reg;
    end
  end

  assign id_rs1_addr = if_id_inst[19:15];
  assign id_rs2_addr = if_id_inst[24:20];
  assign id_rs1_data = (id_rs1_addr == 5'b0) ? 32'b0 : registers[id_rs1_addr];
  assign id_rs2_data = (id_rs2_addr == 5'b0) ? 32'b0 : registers[id_rs2_addr];
  assign is_branch_id = (if_id_inst[6:0] == 7'b1100011);

  always_ff @(posedge CLK or posedge RES) begin
    if (RES || flush) begin
      id_ex_inst <= 32'h13;
      id_ex_pc   <= `RESET_PC;
    end else if (!stall) begin
      id_ex_inst <= if_id_inst;
      id_ex_pc   <= if_id_pc;
    end
  end
  
  assign is_branch_ex = (id_ex_inst[6:0] == 7'b1100011);
  assign ex_alu_result = id_rs1_data - id_rs2_data;
  assign ex_zero_flag = (ex_alu_result == 32'b0);
  assign branch_actual_taken = is_branch_ex && ex_zero_flag;
  assign branch_target = id_ex_pc; 

  always_ff @(posedge CLK or posedge RES) begin
    if (RES) begin
      ex_mem_inst <= 32'h13;
      ex_mem_pc   <= `RESET_PC;
    end else if (!stall) begin
      ex_mem_inst <= id_ex_inst;
      ex_mem_pc   <= id_ex_pc;
    end
  end

  always_ff @(posedge CLK or posedge RES) begin
    if (RES) mem_wb_inst <= 32'h13;
    else if (!stall) mem_wb_inst <= ex_mem_inst;
  end

  assign wb_inst = mem_wb_inst;
  assign wb_reg_write_en = (wb_inst[6:0] == 7'b0010011);
  assign wb_rd_addr = wb_inst[11:7];
  assign wb_write_data = ex_mem_pc + 4;
  
  always_ff @(posedge CLK) begin
      if(wb_reg_write_en && (wb_rd_addr != 5'b0))
          registers[wb_rd_addr] <= wb_write_data;
  end

  assign branch_train_en     = (ex_mem_inst[6:0] == 7'b1100011);
  assign branch_mispredicted = branch_train_en && branch_prediction_valid && (branch_prediction != branch_actual_taken);
  assign flush               = branch_mispredicted;
  assign stall               = 1'b0;

  assign pc_next = flush ? (branch_actual_taken ? branch_target : ex_mem_pc + 4) :
                   (is_branch_id && branch_prediction_valid && branch_prediction) ? branch_target :
                   pc_reg + 4;
endmodule
    """
}

def main():
    print("🚀 Starting to build project files...")
    for file_path_str, content in project_files.items():
        file_path = Path(file_path_str)
        file_path.parent.mkdir(parents=True, exist_ok=True)
        with open(file_path, "w") as f:
            f.write(content.strip())
        print(f"✅ Created file: {file_path}")
    print("🎉 All project files created successfully!")

if __name__ == "__main__":
    main()
