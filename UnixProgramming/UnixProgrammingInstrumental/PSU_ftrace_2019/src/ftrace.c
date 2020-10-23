/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** ftrace
*/

#include "../include/ftrace.h"

static int init_ptrace(ftrace_t *vars, char **env, char *path)
{
    int ret = 0;
    char *tab[2] = {path, NULL};

    if (env == NULL)
        return 0;
    vars->pid = fork();
    if (vars->pid == 0) {
        ptrace(PTRACE_TRACEME, vars->pid, 0, 0);
        execve(path, tab, env);
    } else {
        waitpid(vars->pid, &vars->status, 0);
        ret = prog_loop(vars);
    }
    return (ret);
}

static int check_elf_format(ftrace_t *vars, char **env, char *path)
{
    int ret = 0;

    if (is_sixty_bits(vars->elf_file) != 0) {
        fprintf(stderr, "Error This number of bites is not supported\n");
        return (84);
    }
    if (check_elf_file_struc(vars->elf_file) != 0) {
        fprintf(stderr, "Error This elf file in not well formed\n\n");
        return (84);
    }
    ret = init_ptrace(vars, env, path);
    return (ret);
}

static int get_elf_file(ftrace_t *vars, char **env, char *path)
{
    int ret = 0;

    elf_version(EV_NONE);
    if (elf_version(EV_CURRENT) == EV_NONE) {
        dprintf(2, "Error unsupported file\'s elf version\n\n");
        return (84);
    }
    vars->elf_file = elf_begin(vars->fd, ELF_C_READ, NULL);
    if (vars->elf_file == NULL) {
        fprintf(stderr, "Error can\'t read file\n");
        return (84);
    }
    ret = check_elf_format(vars, env, path);
    return (ret);
}

int ftrace(char *path, char **env)
{
    ftrace_t *vars = init_vars_struc();
    int ret = 0;

    vars->fd = open(path, O_RDONLY);
    if (!vars->fd) {
        fprintf(stderr, "Error can\'t open file\n");
        return (84);
    }
    ret = get_elf_file(vars, env, path);
    vars = destroy_vars_struc(vars);
    return (ret);
}