/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** strace
*/

#include "../include/strace.h"

void print_all(struct user_regs_struct regs, pid_t pid, void *add, int rax_save)
{
    dprintf(2, "%s(",
            g_syscalls[regs.rax].fct_name);
    print_rdi(regs);
    print_rsi(regs);
    print_rdx(regs);
    print_rcx(regs);
    print_r_eight(regs);
    print_r_nine(regs);
    ptrace(PTRACE_SINGLESTEP, pid, add, NULL);
    ptrace(PTRACE_GETREGS, pid, NULL, &regs);
    if (g_syscalls[regs.rax].ret_type == "void *")
        dprintf(2, ") = ?\n");
    else
        dprintf(2, ") = %x\n", rax_save);
}

void loop(int status, pid_t pid, struct user_regs_struct regs, void *add)
{
    unsigned short instruction;
    int rax_save;

    while (WIFSTOPPED(status)) {
        ptrace(PTRACE_GETREGS, pid, NULL, &regs);
        instruction = ptrace(PTRACE_PEEKTEXT, pid, regs.rip, NULL);
        ptrace(PTRACE_SINGLESTEP, pid, add, NULL);
        if ((instruction == 0x80cd
        || instruction == 0x50f) && regs.rax <= 331) {
            rax_save = regs.rax;
            print_all(regs, pid, add, rax_save);
        }
        waitpid(pid, &status, 0);
    }
}

int my_strace(char *str, char **env)
{
    pid_t pid;
    int status;
    struct user_regs_struct regs;
    void *add = NULL;

    if (env == NULL)
        return 0;
    pid = fork();
    if (pid == 0) {
        ptrace(PTRACE_TRACEME);
        execve(str, NULL, env);
    } else {
        ptrace(PTRACE_SINGLESTEP, pid, add, NULL);
        waitpid(pid, &status, 0);
        loop(status, pid, regs, add);
    }
    return 0;
}

int check_args(int ac, char **av)
{
    int i = 1;
    int end = -1;

    while (i != ac && end != 1) {
        if (av[i][0] != '-' && strcmp(av[i], "-s") != 0 &&
        strcmp(av[i], "-p") != 0) {
            end = 1;
        } else if (av[i][0] == '-' && strcmp(av[i], "-s") != 0 &&
        strcmp(av[i], "-p") != 0) {
            dprintf(2, "Error wrong option detected: %s\n", av[i]);
            return (-1);
        }
        i++;
    }
    return (0);
}

int strace(int ac, char **av, char **env)
{
    int ret = -1;

    if (ac == 1) {
        dprintf(2, "Error wrong number of argument !\n");
        return (84);
    }
    if (ac == 2 && av[1][0] != '-')
        return (my_strace(av[1], env));
    if ((ret = check_args(ac, av)) != 0)
        return (84);
    my_strace(av[2], env);
    return (0);
}