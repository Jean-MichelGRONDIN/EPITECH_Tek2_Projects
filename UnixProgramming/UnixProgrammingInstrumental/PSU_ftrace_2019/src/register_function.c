/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** regFunction
*/

#include "../include/strace_function.h"

void print_rsi(struct user_regs_struct regs)
{
    if (tab_length(g_syscalls[regs.rax].fct_params) > 2) {
        dprintf(2, "0x%llx", regs.rsi);
        if (g_syscalls[regs.rax].fct_params[1] != NULL
        && tab_length(g_syscalls[regs.rax].fct_params) > 3)
            dprintf(2, ", ");
    }
}

void print_rdx(struct user_regs_struct regs)
{
    if (tab_length(g_syscalls[regs.rax].fct_params) > 3) {
        dprintf(2, "0x%llx", regs.rdx);
        if (g_syscalls[regs.rax].fct_params[2] != NULL
        && tab_length(g_syscalls[regs.rax].fct_params) > 4)
            dprintf(2, ", ");
    }
}

void print_rcx(struct user_regs_struct regs)
{
    if (tab_length(g_syscalls[regs.rax].fct_params) > 4) {
        dprintf(2, "0x%llx", regs.rcx);
        if (g_syscalls[regs.rax].fct_params[3] != NULL
        && tab_length(g_syscalls[regs.rax].fct_params) > 5)
            dprintf(2, ", ");
    }
}

void print_r_eight(struct user_regs_struct regs)
{
    if (tab_length(g_syscalls[regs.rax].fct_params) > 5) {
        dprintf(2, "0x%llx", regs.r8);
        if (g_syscalls[regs.rax].fct_params[4] != NULL
        && tab_length(g_syscalls[regs.rax].fct_params) > 6)
            dprintf(2, ", ");
    }
}

void print_r_nine(struct user_regs_struct regs)
{
    if (tab_length(g_syscalls[regs.rax].fct_params) > 6) {
        dprintf(2, "0x%llx", regs.r9);
    }
}