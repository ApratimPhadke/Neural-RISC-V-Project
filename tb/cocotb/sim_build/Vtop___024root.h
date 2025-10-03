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
    VL_IN8(CLK,0,0);
    VL_IN8(RES,0,0);
    CData/*0:0*/ ronanchip_top__DOT__CLK;
    CData/*0:0*/ ronanchip_top__DOT__RES;
    CData/*0:0*/ ronanchip_top__DOT__core_inst__DOT__CLK;
    CData/*0:0*/ ronanchip_top__DOT__core_inst__DOT__RES;
    CData/*6:0*/ ronanchip_top__DOT__core_inst__DOT__opcode;
    CData/*4:0*/ ronanchip_top__DOT__core_inst__DOT__rd;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__CLK__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(if_inst_from_testbench,31,0);
    VL_OUT(DEBUG,31,0);
    IData/*31:0*/ ronanchip_top__DOT__if_inst_from_testbench;
    IData/*31:0*/ ronanchip_top__DOT__DEBUG;
    IData/*31:0*/ ronanchip_top__DOT__core_inst__DOT__instruction_input;
    IData/*31:0*/ ronanchip_top__DOT__core_inst__DOT__DEBUG;
    IData/*31:0*/ ronanchip_top__DOT__core_inst__DOT__pc_reg;
    IData/*19:0*/ ronanchip_top__DOT__core_inst__DOT__imm_u;
    IData/*31:0*/ ronanchip_top__DOT__core_inst__DOT__imm_extended;
    IData/*31:0*/ ronanchip_top__DOT__core_inst__DOT__next_pc;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> ronanchip_top__DOT__core_inst__DOT__registers;
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
