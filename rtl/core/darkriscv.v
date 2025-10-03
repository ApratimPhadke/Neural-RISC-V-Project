// Optimized baseline RISC-V core with improved efficiency
`include "config.vh"

module darkriscv
(
    input  wire        CLK,
    input  wire        RES,
    // ADD THIS INPUT PORT for the testbench
    input  wire [31:0] instruction_input, 
    output wire [31:0] DEBUG
);
    // Internal registers
    reg [31:0] registers [0:31];
    reg [31:0] pc_reg;
    
    // Pre-decoded instruction fields
    wire [6:0]  opcode;
    wire [4:0]  rd;
    wire [19:0] imm_u;
    wire [31:0] imm_extended;
    wire [31:0] next_pc;
    
    // CHANGE THIS LINE: Fetch from the new input port
    assign opcode = instruction_input[6:0];
    assign rd = instruction_input[11:7];
    assign imm_u = instruction_input[31:12];
    assign imm_extended = {imm_u, 12'b0};
    
    // Next PC calculation
    assign next_pc = pc_reg + 32'd4;
    
    // --- Optimized Core Logic ---
    always @(posedge CLK) begin
        if (RES) begin
            pc_reg <= `RESET_PC;
            registers[0] <= 32'h0;
        end else begin
            pc_reg <= next_pc;
            
            case (opcode)
                `OPC_LUI: begin
                    if (rd != 5'b0)
                        registers[rd] <= imm_extended;
                end
                
                `OPC_AUIPC: begin
                    if (rd != 5'b0)
                        registers[rd] <= pc_reg + imm_extended;
                end
            endcase
            
            registers[0] <= 32'h0;
        end
    end
    
    // Debug output
    assign DEBUG = pc_reg;
    
endmodule
