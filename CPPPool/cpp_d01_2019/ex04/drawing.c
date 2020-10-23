/*
** EPITECH PROJECT, 2020
** ex04
** File description:
** drawing
*/

#include "drawing.h"

void  draw_square(uint32_t  **img, const  point_t *origin,
    size_t  size, uint32_t  color)
{
    for (size_t x = origin->x / size; x != size; x++)
        for (size_t y = origin->y / size; y != size; y++)
            img[x][y] = color;
}
