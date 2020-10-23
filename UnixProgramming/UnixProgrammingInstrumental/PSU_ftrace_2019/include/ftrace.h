/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** ftrace
*/

#ifndef FTRACE_H_
#define FTRACE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/user.h>
#include <libelf.h>
#include <gelf.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct functions_list {
    char *name;
    struct functions_list *next;
} functions_list_t;


typedef struct ftrace {
    int fd;
    Elf *elf_file;
    pid_t pid;
    int status;
    struct user_regs_struct regs;
    void *add;
    functions_list_t *func_list;
} ftrace_t;

functions_list_t *add_new_elem(char *name, functions_list_t *list);
functions_list_t *delet_head(functions_list_t *list);
functions_list_t *delete_all(functions_list_t *list);

int prog_loop(ftrace_t *vars);

void search_in_sec_tab_symbol(ftrace_t *vars, unsigned int addres);
void print_all_symbols(ftrace_t *vars);

int check_elf_file_struc(Elf *elf_file);
int is_sixty_bits(Elf *elf_file);

ftrace_t *init_vars_struc(void);
ftrace_t *destroy_vars_struc(ftrace_t *vars);

int ftrace(char *path, char **env);


void print_rdi(struct user_regs_struct regs);

void print_rsi(struct user_regs_struct regs);

void print_rdx(struct user_regs_struct regs);

void print_rcx(struct user_regs_struct regs);

void print_r_eight(struct user_regs_struct regs);

void print_r_nine(struct user_regs_struct regs);

int tab_length(char * const *tab);

#endif