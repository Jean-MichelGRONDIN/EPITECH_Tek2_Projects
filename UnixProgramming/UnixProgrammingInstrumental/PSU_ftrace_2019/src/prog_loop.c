/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** prog_loop
*/

#include "../include/ftrace.h"
#include "../include/strace_function.h"

void print_all(ftrace_t *vars)
{
    int rax_save = vars->regs.rax;

    dprintf(2, "Syscall %s(",
            g_syscalls[rax_save].fct_name);
    print_rdi(vars->regs);
    print_rsi(vars->regs);
    print_rdx(vars->regs);
    print_rcx(vars->regs);
    print_r_eight(vars->regs);
    print_r_nine(vars->regs);
    ptrace(PTRACE_GETREGS, vars->pid, NULL, &vars->regs);
    waitpid(vars->pid, &vars->status, WUNTRACED);
    ptrace(PTRACE_SINGLESTEP, vars->pid, NULL, NULL);
    if (strncmp(g_syscalls[rax_save].ret_type, "void", 4) == 0)
        dprintf(2, ") = ?\n");
    else
        dprintf(2, ")\t= 0x%llx\n",  vars->regs.rax);
}

static void identify_op_code(long int instruction, ftrace_t *vars)
{
    unsigned int tmp_addrs = 0;
    unsigned short tmp_opcode = instruction;

    if ((tmp_opcode == 0x80cd
    || tmp_opcode == 0x50f)) {
        print_all(vars);
        return;
    }
    if ((instruction & 0xff) == 0xe8) {
        tmp_addrs = (vars->regs.rip & 0xffffffff) + 5
            + ((instruction >> 8) & 0xffffffff);
        search_in_sec_tab_symbol(vars, tmp_addrs);
    }
    if ( (instruction & 0xff) == 0xc3 || (instruction & 0xff) == 0xc2 ||
        (instruction & 0xff) == 0xCB || (instruction & 0xff) == 0xcA) {
        if (vars->func_list != NULL) {
            printf("Leaving function %s\n", vars->func_list->name);
            vars->func_list = delet_head(vars->func_list);
        }
    }
}

int prog_loop(ftrace_t *vars)
{
    long int instruction;

    while (WIFSTOPPED(vars->status)) {
        ptrace(PTRACE_GETREGS, vars->pid, NULL, &vars->regs);
        instruction = ptrace(PTRACE_PEEKTEXT, vars->pid, vars->regs.rip, NULL);
        ptrace(PTRACE_SINGLESTEP, vars->pid, NULL, NULL);
        identify_op_code(instruction, vars);
        waitpid(vars->pid, &vars->status, 0);
    }
    return (0);
}