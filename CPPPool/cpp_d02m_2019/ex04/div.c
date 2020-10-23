/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** div
*/

#include "castmania.h"
#include <stddef.h>

int  integer_div(int a, int b)
{
    if (b == 0)
        return (0);
    return (a / b);
}

float  decimale_div(int a, int b)
{
    if (b == 0)
        return (0);
    return (a / b);
}

void  exec_div(division_t *operation)
{
    integer_op_t *integer = NULL;
    decimale_op_t *decimal = NULL;

    if (operation->div_type == INTEGER) {
        integer = operation->div_op;
        integer->res = integer_div(integer->a, integer->b);
    } else {
        decimal = operation->div_op;
        decimal->res = decimale_div(decimal->a, decimal->b);
    }
}