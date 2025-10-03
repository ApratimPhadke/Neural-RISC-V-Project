// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ simple_riscv__DOT__clk;
    CData/*0:0*/ simple_riscv__DOT__rst;
    CData/*0:0*/ simple_riscv__DOT__is_branch;
    CData/*7:0*/ simple_riscv__DOT__pred_index;
    CData/*0:0*/ simple_riscv__DOT__prediction;
    CData/*0:0*/ simple_riscv__DOT__branch_taken;
    CData/*0:0*/ simple_riscv__DOT__mispredicted;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT16(branch_count,15,0);
    VL_OUT16(mispred_count,15,0);
    SData/*15:0*/ simple_riscv__DOT__branch_count;
    SData/*15:0*/ simple_riscv__DOT__mispred_count;
    SData/*15:0*/ simple_riscv__DOT__branches;
    SData/*15:0*/ simple_riscv__DOT__mispredictions;
    VL_OUT(pc_out,31,0);
    VL_IN(instruction,31,0);
    IData/*31:0*/ simple_riscv__DOT__pc_out;
    IData/*31:0*/ simple_riscv__DOT__instruction;
    IData/*31:0*/ simple_riscv__DOT__pc;
    IData/*31:0*/ simple_riscv__DOT__cycle_count;
    IData/*31:0*/ simple_riscv__DOT__instr_count;
    IData/*31:0*/ simple_riscv__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*1:0*/, 256> simple_riscv__DOT__predictor_table;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
