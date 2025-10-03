// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_simple_riscv);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_simple_riscv.configure(this, name(), "simple_riscv", "simple_riscv", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_simple_riscv);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"branch_count", &(TOP.branch_count), false, VLVT_UINT16,VLVD_OUT|VLVF_PUB_RW,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"instruction", &(TOP.instruction), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"mispred_count", &(TOP.mispred_count), false, VLVT_UINT16,VLVD_OUT|VLVF_PUB_RW,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"pc_out", &(TOP.pc_out), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst", &(TOP.rst), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_simple_riscv.varInsert(__Vfinal,"branch_count", &(TOP.simple_riscv__DOT__branch_count), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,15,0);
        __Vscope_simple_riscv.varInsert(__Vfinal,"branch_taken", &(TOP.simple_riscv__DOT__branch_taken), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_simple_riscv.varInsert(__Vfinal,"branches", &(TOP.simple_riscv__DOT__branches), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,15,0);
        __Vscope_simple_riscv.varInsert(__Vfinal,"clk", &(TOP.simple_riscv__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_simple_riscv.varInsert(__Vfinal,"cycle_count", &(TOP.simple_riscv__DOT__cycle_count), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_simple_riscv.varInsert(__Vfinal,"i", &(TOP.simple_riscv__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_simple_riscv.varInsert(__Vfinal,"instr_count", &(TOP.simple_riscv__DOT__instr_count), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_simple_riscv.varInsert(__Vfinal,"instruction", &(TOP.simple_riscv__DOT__instruction), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_simple_riscv.varInsert(__Vfinal,"is_branch", &(TOP.simple_riscv__DOT__is_branch), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_simple_riscv.varInsert(__Vfinal,"mispred_count", &(TOP.simple_riscv__DOT__mispred_count), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,15,0);
        __Vscope_simple_riscv.varInsert(__Vfinal,"mispredicted", &(TOP.simple_riscv__DOT__mispredicted), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_simple_riscv.varInsert(__Vfinal,"mispredictions", &(TOP.simple_riscv__DOT__mispredictions), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,15,0);
        __Vscope_simple_riscv.varInsert(__Vfinal,"pc", &(TOP.simple_riscv__DOT__pc), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_simple_riscv.varInsert(__Vfinal,"pc_out", &(TOP.simple_riscv__DOT__pc_out), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_simple_riscv.varInsert(__Vfinal,"pred_index", &(TOP.simple_riscv__DOT__pred_index), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_simple_riscv.varInsert(__Vfinal,"prediction", &(TOP.simple_riscv__DOT__prediction), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_simple_riscv.varInsert(__Vfinal,"predictor_table", &(TOP.simple_riscv__DOT__predictor_table), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,2 ,1,0 ,0,255);
        __Vscope_simple_riscv.varInsert(__Vfinal,"rst", &(TOP.simple_riscv__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
    }
}
