/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** regFunctionTwo
*/

#include "../include/strace_function.h"

int tab_length(char * const *tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return (i + 1);
}

void print_rdi(struct user_regs_struct regs)
{
    if (tab_length(g_syscalls[regs.rax].fct_params) >= 1) {
        dprintf(2, "0x%x", regs.rdi);
        if (g_syscalls[regs.rax].fct_params[0] != NULL
        && tab_length(g_syscalls[regs.rax].fct_params) != 1)
            dprintf(2, ", ");
    }
}