/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** tab_to_2dtab
*/

#include <stdlib.h>

int **malloc_2d_int_array(int lines, int colums)
{
    int **new = malloc(sizeof(int *) * lines);
    int i = 0;

    for (i = 0 ; i != lines ; i++) {
        new[i] = malloc(sizeof(int) * colums);
    }
    return (new);
}

void  tab_to_2dtab(const  int *tab, int  length, int width, int  ***res)
{
    int **new = malloc_2d_int_array(length, width);
    int max = width * length;
    int i = 0;
    int lines = 0;
    int colums = 0;

    for (i = 0 ; i != max; i++) {
        new[lines][colums] = tab[i];
        if (colums == width - 1) {
            colums = 0;
            lines++;
        } else
            colums++;
    }
    *res = new;
}