// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_ronanchip_top);
    __Vhier.remove(&__Vscope_ronanchip_top, &__Vscope_ronanchip_top__core_inst);

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
    __Vscope_ronanchip_top.configure(this, name(), "ronanchip_top", "ronanchip_top", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_ronanchip_top__core_inst.configure(this, name(), "ronanchip_top.core_inst", "core_inst", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_ronanchip_top);
    __Vhier.add(&__Vscope_ronanchip_top, &__Vscope_ronanchip_top__core_inst);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"CLK", &(TOP.CLK), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"DEBUG", &(TOP.DEBUG), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"RES", &(TOP.RES), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"if_inst_from_testbench", &(TOP.if_inst_from_testbench), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ronanchip_top.varInsert(__Vfinal,"CLK", &(TOP.ronanchip_top__DOT__CLK), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_ronanchip_top.varInsert(__Vfinal,"DEBUG", &(TOP.ronanchip_top__DOT__DEBUG), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ronanchip_top.varInsert(__Vfinal,"RES", &(TOP.ronanchip_top__DOT__RES), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_ronanchip_top.varInsert(__Vfinal,"if_inst_from_testbench", &(TOP.ronanchip_top__DOT__if_inst_from_testbench), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ronanchip_top__core_inst.varInsert(__Vfinal,"CLK", &(TOP.ronanchip_top__DOT__core_inst__DOT__CLK), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_ronanchip_top__core_inst.varInsert(__Vfinal,"DEBUG", &(TOP.ronanchip_top__DOT__core_inst__DOT__DEBUG), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ronanchip_top__core_inst.varInsert(__Vfinal,"RES", &(TOP.ronanchip_top__DOT__core_inst__DOT__RES), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_ronanchip_top__core_inst.varInsert(__Vfinal,"imm_extended", &(TOP.ronanchip_top__DOT__core_inst__DOT__imm_extended), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ronanchip_top__core_inst.varInsert(__Vfinal,"imm_u", &(TOP.ronanchip_top__DOT__core_inst__DOT__imm_u), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,19,0);
        __Vscope_ronanchip_top__core_inst.varInsert(__Vfinal,"instruction_input", &(TOP.ronanchip_top__DOT__core_inst__DOT__instruction_input), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ronanchip_top__core_inst.varInsert(__Vfinal,"next_pc", &(TOP.ronanchip_top__DOT__core_inst__DOT__next_pc), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ronanchip_top__core_inst.varInsert(__Vfinal,"opcode", &(TOP.ronanchip_top__DOT__core_inst__DOT__opcode), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,6,0);
        __Vscope_ronanchip_top__core_inst.varInsert(__Vfinal,"pc_reg", &(TOP.ronanchip_top__DOT__core_inst__DOT__pc_reg), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ronanchip_top__core_inst.varInsert(__Vfinal,"rd", &(TOP.ronanchip_top__DOT__core_inst__DOT__rd), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,4,0);
        __Vscope_ronanchip_top__core_inst.varInsert(__Vfinal,"registers", &(TOP.ronanchip_top__DOT__core_inst__DOT__registers), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,2 ,31,0 ,0,31);
    }
}
