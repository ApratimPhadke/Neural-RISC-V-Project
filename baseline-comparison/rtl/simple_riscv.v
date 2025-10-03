// Simple RISC-V with Basic 2-bit Branch Predictor - Verilator Compatible
module simple_riscv (
    input  wire         clk,
    input  wire         rst,
    output wire [31:0]  pc_out,
    input  wire [31:0]  instruction,
    output wire [15:0]  branch_count,
    output wire [15:0]  mispred_count
);

// Basic processor state
reg [31:0] pc;
reg [31:0] cycle_count;
reg [31:0] instr_count;

// Simple 2-bit branch predictor (256 entries) - Fixed for Verilator
reg [1:0] predictor_table [0:255];
reg [15:0] branches;
reg [15:0] mispredictions;

// Instruction decode
wire is_branch = (instruction[6:0] == 7'b1100011);
wire [7:0] pred_index = pc[9:2];

// Fixed: Extract single bit from predictor table
reg prediction;
always @(*) begin
    prediction = predictor_table[pred_index][1]; // CORRECT - extract MSB
end


// Simulate branch condition (simple pattern)
wire branch_taken = is_branch && (cycle_count[1:0] == 2'b11);
wire mispredicted = is_branch && (prediction != branch_taken);

// Initialize arrays outside of clocked block (Verilator friendly)
integer i;
initial begin
    for (i = 0; i < 256; i = i + 1) begin
        predictor_table[i] = 2'b01; // Weakly not-taken
    end
end

// Main processor logic
always @(posedge clk) begin
    if (rst) begin
        pc <= 32'h00000000;
        cycle_count <= 0;
        instr_count <= 0;
        branches <= 0;
        mispredictions <= 0;
    end else begin
        cycle_count <= cycle_count + 1;
        
        // Count instructions (exclude NOPs)
        if (instruction != 32'h00000013) begin
            instr_count <= instr_count + 1;
        end
        
        // Handle branches
        if (is_branch) begin
            branches <= branches + 1;
            
            if (mispredicted) begin
                mispredictions <= mispredictions + 1;
                pc <= pc + 4; // Misprediction penalty
            end else begin
                pc <= branch_taken ? (pc + 8) : (pc + 4);
            end
            
            // Update 2-bit saturating counter
            if (branch_taken) begin
                if (predictor_table[pred_index] != 2'b11) begin
                    predictor_table[pred_index] <= predictor_table[pred_index] + 1;
                end
            end else begin
                if (predictor_table[pred_index] != 2'b00) begin
                    predictor_table[pred_index] <= predictor_table[pred_index] - 1;
                end
            end
        end else begin
            pc <= pc + 4; // Normal instruction
        end
    end
end

assign pc_out = pc;
assign branch_count = branches;
assign mispred_count = mispredictions;

endmodule

