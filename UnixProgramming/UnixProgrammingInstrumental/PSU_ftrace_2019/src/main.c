/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** main
*/

#include "../include/ftrace.h"

int main(int ac, char **av, char **env)
{
    if (ac != 2)
        return (84);
    if (strcmp(av[1], "-h") == 0 || strcmp(av[1], "--help") == 0) {
        fprintf(stderr, "USAGE: ftrace <command>\n");
        return (0);
    }
    return (ftrace(av[1], env));
}

//pas oublier de rajouter les trucs dans le makefile