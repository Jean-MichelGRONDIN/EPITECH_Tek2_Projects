/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** objdump
*/

#include "../include/objdump.h"

int objdump(int ac, char **av)
{
    int ret = 0;
    int i = 1;

    if (ac == 1) {
        ret = process_this_file("a.out");
    } else {
        while (i != ac) {
            ret += process_this_file(av[i]);
            i++;
        }
    }
    if (ret != 0)
        return (1);
    return (0);
}