// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->simple_riscv__DOT__clk = vlSelf->clk;
    vlSelf->simple_riscv__DOT__rst = vlSelf->rst;
    vlSelf->simple_riscv__DOT__instruction = vlSelf->instruction;
    vlSelf->pc_out = vlSelf->simple_riscv__DOT__pc;
    vlSelf->branch_count = vlSelf->simple_riscv__DOT__branches;
    vlSelf->mispred_count = vlSelf->simple_riscv__DOT__mispredictions;
    vlSelf->simple_riscv__DOT__pred_index = (0xffU 
                                             & (vlSelf->simple_riscv__DOT__pc 
                                                >> 2U));
    vlSelf->simple_riscv__DOT__is_branch = (0x63U == 
                                            (0x7fU 
                                             & vlSelf->instruction));
    vlSelf->simple_riscv__DOT__pc_out = vlSelf->pc_out;
    vlSelf->simple_riscv__DOT__branch_count = vlSelf->branch_count;
    vlSelf->simple_riscv__DOT__mispred_count = vlSelf->mispred_count;
    vlSelf->simple_riscv__DOT__prediction = (1U & (
                                                   vlSelf->simple_riscv__DOT__predictor_table
                                                   [vlSelf->simple_riscv__DOT__pred_index] 
                                                   >> 1U));
    vlSelf->simple_riscv__DOT__branch_taken = ((IData)(vlSelf->simple_riscv__DOT__is_branch) 
                                               & (3U 
                                                  == 
                                                  (3U 
                                                   & vlSelf->simple_riscv__DOT__cycle_count)));
    vlSelf->simple_riscv__DOT__mispredicted = ((IData)(vlSelf->simple_riscv__DOT__is_branch) 
                                               & ((IData)(vlSelf->simple_riscv__DOT__prediction) 
                                                  != (IData)(vlSelf->simple_riscv__DOT__branch_taken)));
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vdlyvdim0__simple_riscv__DOT__predictor_table__v0;
    __Vdlyvdim0__simple_riscv__DOT__predictor_table__v0 = 0;
    CData/*1:0*/ __Vdlyvval__simple_riscv__DOT__predictor_table__v0;
    __Vdlyvval__simple_riscv__DOT__predictor_table__v0 = 0;
    CData/*0:0*/ __Vdlyvset__simple_riscv__DOT__predictor_table__v0;
    __Vdlyvset__simple_riscv__DOT__predictor_table__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__simple_riscv__DOT__predictor_table__v1;
    __Vdlyvdim0__simple_riscv__DOT__predictor_table__v1 = 0;
    CData/*1:0*/ __Vdlyvval__simple_riscv__DOT__predictor_table__v1;
    __Vdlyvval__simple_riscv__DOT__predictor_table__v1 = 0;
    CData/*0:0*/ __Vdlyvset__simple_riscv__DOT__predictor_table__v1;
    __Vdlyvset__simple_riscv__DOT__predictor_table__v1 = 0;
    IData/*31:0*/ __Vdly__simple_riscv__DOT__instr_count;
    __Vdly__simple_riscv__DOT__instr_count = 0;
    SData/*15:0*/ __Vdly__simple_riscv__DOT__branches;
    __Vdly__simple_riscv__DOT__branches = 0;
    SData/*15:0*/ __Vdly__simple_riscv__DOT__mispredictions;
    __Vdly__simple_riscv__DOT__mispredictions = 0;
    // Body
    __Vdly__simple_riscv__DOT__instr_count = vlSelf->simple_riscv__DOT__instr_count;
    __Vdly__simple_riscv__DOT__branches = vlSelf->simple_riscv__DOT__branches;
    __Vdly__simple_riscv__DOT__mispredictions = vlSelf->simple_riscv__DOT__mispredictions;
    __Vdlyvset__simple_riscv__DOT__predictor_table__v0 = 0U;
    __Vdlyvset__simple_riscv__DOT__predictor_table__v1 = 0U;
    if (vlSelf->rst) {
        __Vdly__simple_riscv__DOT__instr_count = 0U;
        vlSelf->simple_riscv__DOT__cycle_count = 0U;
        __Vdly__simple_riscv__DOT__branches = 0U;
        __Vdly__simple_riscv__DOT__mispredictions = 0U;
        vlSelf->simple_riscv__DOT__pc = 0U;
    } else {
        if ((0x13U != vlSelf->instruction)) {
            __Vdly__simple_riscv__DOT__instr_count 
                = ((IData)(1U) + vlSelf->simple_riscv__DOT__instr_count);
        }
        vlSelf->simple_riscv__DOT__cycle_count = ((IData)(1U) 
                                                  + vlSelf->simple_riscv__DOT__cycle_count);
        if (vlSelf->simple_riscv__DOT__is_branch) {
            __Vdly__simple_riscv__DOT__branches = (0xffffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->simple_riscv__DOT__branches)));
            if (vlSelf->simple_riscv__DOT__mispredicted) {
                __Vdly__simple_riscv__DOT__mispredictions 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelf->simple_riscv__DOT__mispredictions)));
                vlSelf->simple_riscv__DOT__pc = ((IData)(4U) 
                                                 + vlSelf->simple_riscv__DOT__pc);
            } else {
                vlSelf->simple_riscv__DOT__pc = ((IData)(vlSelf->simple_riscv__DOT__branch_taken)
                                                  ? 
                                                 ((IData)(8U) 
                                                  + vlSelf->simple_riscv__DOT__pc)
                                                  : 
                                                 ((IData)(4U) 
                                                  + vlSelf->simple_riscv__DOT__pc));
            }
        } else {
            vlSelf->simple_riscv__DOT__pc = ((IData)(4U) 
                                             + vlSelf->simple_riscv__DOT__pc);
        }
    }
    if ((1U & (~ (IData)(vlSelf->rst)))) {
        if (vlSelf->simple_riscv__DOT__is_branch) {
            if (vlSelf->simple_riscv__DOT__branch_taken) {
                if ((3U != vlSelf->simple_riscv__DOT__predictor_table
                     [vlSelf->simple_riscv__DOT__pred_index])) {
                    __Vdlyvval__simple_riscv__DOT__predictor_table__v0 
                        = (3U & ((IData)(1U) + vlSelf->simple_riscv__DOT__predictor_table
                                 [vlSelf->simple_riscv__DOT__pred_index]));
                    __Vdlyvset__simple_riscv__DOT__predictor_table__v0 = 1U;
                    __Vdlyvdim0__simple_riscv__DOT__predictor_table__v0 
                        = vlSelf->simple_riscv__DOT__pred_index;
                }
            } else if ((0U != vlSelf->simple_riscv__DOT__predictor_table
                        [vlSelf->simple_riscv__DOT__pred_index])) {
                __Vdlyvval__simple_riscv__DOT__predictor_table__v1 
                    = (3U & (vlSelf->simple_riscv__DOT__predictor_table
                             [vlSelf->simple_riscv__DOT__pred_index] 
                             - (IData)(1U)));
                __Vdlyvset__simple_riscv__DOT__predictor_table__v1 = 1U;
                __Vdlyvdim0__simple_riscv__DOT__predictor_table__v1 
                    = vlSelf->simple_riscv__DOT__pred_index;
            }
        }
    }
    vlSelf->simple_riscv__DOT__instr_count = __Vdly__simple_riscv__DOT__instr_count;
    vlSelf->simple_riscv__DOT__branches = __Vdly__simple_riscv__DOT__branches;
    vlSelf->simple_riscv__DOT__mispredictions = __Vdly__simple_riscv__DOT__mispredictions;
    if (__Vdlyvset__simple_riscv__DOT__predictor_table__v0) {
        vlSelf->simple_riscv__DOT__predictor_table[__Vdlyvdim0__simple_riscv__DOT__predictor_table__v0] 
            = __Vdlyvval__simple_riscv__DOT__predictor_table__v0;
    }
    if (__Vdlyvset__simple_riscv__DOT__predictor_table__v1) {
        vlSelf->simple_riscv__DOT__predictor_table[__Vdlyvdim0__simple_riscv__DOT__predictor_table__v1] 
            = __Vdlyvval__simple_riscv__DOT__predictor_table__v1;
    }
    vlSelf->branch_count = vlSelf->simple_riscv__DOT__branches;
    vlSelf->mispred_count = vlSelf->simple_riscv__DOT__mispredictions;
    vlSelf->pc_out = vlSelf->simple_riscv__DOT__pc;
    vlSelf->simple_riscv__DOT__pred_index = (0xffU 
                                             & (vlSelf->simple_riscv__DOT__pc 
                                                >> 2U));
    vlSelf->simple_riscv__DOT__branch_count = vlSelf->branch_count;
    vlSelf->simple_riscv__DOT__mispred_count = vlSelf->mispred_count;
    vlSelf->simple_riscv__DOT__pc_out = vlSelf->pc_out;
    vlSelf->simple_riscv__DOT__prediction = (1U & (
                                                   vlSelf->simple_riscv__DOT__predictor_table
                                                   [vlSelf->simple_riscv__DOT__pred_index] 
                                                   >> 1U));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->simple_riscv__DOT__branch_taken = ((IData)(vlSelf->simple_riscv__DOT__is_branch) 
                                               & (3U 
                                                  == 
                                                  (3U 
                                                   & vlSelf->simple_riscv__DOT__cycle_count)));
    vlSelf->simple_riscv__DOT__mispredicted = ((IData)(vlSelf->simple_riscv__DOT__is_branch) 
                                               & ((IData)(vlSelf->simple_riscv__DOT__prediction) 
                                                  != (IData)(vlSelf->simple_riscv__DOT__branch_taken)));
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../rtl/simple_riscv.v", 2, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../rtl/simple_riscv.v", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../rtl/simple_riscv.v", 2, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
