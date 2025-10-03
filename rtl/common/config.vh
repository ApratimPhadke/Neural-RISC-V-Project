// Configuration file for the DarkRISCV core

// --- Opcodes ---
`define OPC_LUI     7'b0110111
`define OPC_AUIPC   7'b0010111
`define OPC_JAL     7'b1101111
`define OPC_JALR    7'b1100111
`define OPC_BRANCH  7'b1100011
`define OPC_LOAD    7'b0000011
`define OPC_STORE   7'b0100011
`define OPC_ARI_I   7'b0010011
`define OPC_ARI     7'b0110011
`define OPC_FENCE   7'b0001111
`define OPC_SYS     7'b1110011

// --- Reset Vector ---
`define RESET_PC    32'h00000000
