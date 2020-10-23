/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** print_header
*/

#include "../include/objdump.h"

int print_header(char const *path, size_t bits, void *file)
{
    if (bits == 64) {
        if (print_header_sixty(path, file) != 0)
            return (1);
    } else if (bits == 32) {
        if (print_header_thirty(path, file) != 0)
            return (1);
    } else {
    }
    return (0);
}