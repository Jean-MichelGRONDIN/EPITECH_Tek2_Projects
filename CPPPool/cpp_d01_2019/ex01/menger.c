/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** menger functions
*/

#include "./ex01.h"

void fractal_rec(int level, int size, int abscis, int ordin)
{
    int div = size / 3;

    printf("%03d %03d %03d\n", size / 3, size / 3 + abscis, size / 3 + ordin);
    if (level > 0) {
        fractal_rec(level - 1, div, abscis, ordin);
        fractal_rec(level - 1, div, abscis, ordin + div);
        fractal_rec(level - 1, div, abscis, ordin + 2 * div);
        fractal_rec(level - 1, div, abscis + div, ordin);
        fractal_rec(level - 1, div, abscis + div, ordin + 2 * div);
        fractal_rec(level - 1, div, abscis + 2 * div, ordin);
        fractal_rec(level - 1, div, abscis + 2 * div, ordin + div);
        fractal_rec(level - 1, div, abscis + 2 * div, ordin + 2 * div);
    }
}

void menger(int level, int size)
{
    if (level > 0 && size > 1) {
        fractal_rec(level - 1, size, 0, 0);
    }
}
