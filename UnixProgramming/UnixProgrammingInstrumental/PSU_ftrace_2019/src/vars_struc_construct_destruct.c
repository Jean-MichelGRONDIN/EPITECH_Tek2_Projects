/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** vars_struc_contruct_destruct
*/

#include "../include/ftrace.h"

ftrace_t *init_vars_struc(void)
{
    ftrace_t *new = malloc(sizeof(*new));

    new->fd = -1;
    new->elf_file = NULL;
    new->pid = -1;
    new->status = -1;
    new->add = NULL;
    new->func_list = NULL;
    return (new);
}

ftrace_t *destroy_vars_struc(ftrace_t *vars)
{
    if (vars->fd)
        close(vars->fd);
    if (vars->elf_file != NULL)
        elf_end(vars->elf_file);
    vars->func_list = delete_all(vars->func_list);
    if (vars != NULL) {
        free(vars);
        vars = NULL;
    }
    return (vars);
}