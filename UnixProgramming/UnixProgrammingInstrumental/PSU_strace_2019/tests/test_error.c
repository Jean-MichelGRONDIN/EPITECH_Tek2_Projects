/*
** EPITECH PROJECT, 2019
** test_error.c
** File description:
** test unitaire
*/

#include "../include/strace.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(check_args, return_0)
{
    char *av[3] = {
        "./strace\0",
        "-s",
        NULL
    };
    int nb = check_args(2, av);

    cr_assert_eq(nb, 0);
}

Test(check_args, return_neg_1)
{
    char *av[3] = {
        "./strace\0",
        "-oui",
        NULL
    };
    int nb = check_args(2, av);

    cr_assert_eq(nb, -1);
}

Test(check_args, return_zero_2)
{
    char *av[3] = {
        "./strace\0",
        "oui\0",
        NULL
    };
    int nb = check_args(2, av);

    cr_assert_eq(nb, 0);
}

Test(strace, return_84)
{
    char *av[3] = {
        "./strace\0",
        "-oui",
        NULL
    };
    int nb = strace(1, av, NULL);

    cr_assert_eq(nb, 84);
}

Test(strace, return_84_2)
{
    char *av[3] = {
        "./strace\0",
        "-oui",
        NULL
    };
    int nb = strace(2, av, NULL);

    cr_assert_eq(nb, 84);
}

Test(strace, return_0)
{
    char *av[3] = {
        "./strace\0",
        "-s\0",
        NULL
    };
    int nb = strace(2, av, NULL);

    cr_assert_eq(nb, 0);
}

Test(tab_length, return_tab_length)
{
    char *av[3] = {
        "./strace\0",
        "-s\0",
        NULL
    };
    int nb = tab_length(av);

    cr_assert_eq(nb, 3);
}