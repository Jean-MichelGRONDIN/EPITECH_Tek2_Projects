/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list_get_elem_at_position
*/

#include <stddef.h>
#include <stdlib.h>
#include "double_list.h"

double  double_list_get_elem_at_position_two(double_list_t  list,
    unsigned  int  n)
{
    double_list_t tmp = list;
    unsigned int i = 0;

    if (n == 0) {
        return (tmp->value);
    }
    while (i != n) {
        tmp = tmp->next;
        i++;
    }
    return (tmp->value);
}

double  double_list_get_elem_at_position(double_list_t  list,
    unsigned  int  position)
{
    double_list_t tmp = list;

    if (tmp == NULL)
        return (0);
    if (position > double_list_get_size(list) - 1)
        return (0);
    return (double_list_get_elem_at_position_two(tmp, position));
}