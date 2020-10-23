/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list_get_elem_at_front
*/

#include <stddef.h>
#include <stdlib.h>
#include "double_list.h"

double  double_list_get_elem_at_front(double_list_t  list)
{
    if (list == NULL)
        return (0);
    return (list->value);
}