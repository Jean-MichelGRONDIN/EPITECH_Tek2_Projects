/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** strace
*/

#ifndef STRACE_H_
#define STRACE_H_

#include "../include/strace_function.h"

int strace(int ac, char **av, char **env);

void print_rdi(struct user_regs_struct regs);

void print_rsi(struct user_regs_struct regs);

void print_rdx(struct user_regs_struct regs);

void print_rcx(struct user_regs_struct regs);

void print_r_eight(struct user_regs_struct regs);

void print_r_nine(struct user_regs_struct regs);

int tab_length(char * const *tab);

#endif