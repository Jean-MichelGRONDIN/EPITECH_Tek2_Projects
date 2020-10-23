/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list_get_elem_at_back
*/

#include <stddef.h>
#include <stdlib.h>
#include "double_list.h"

double  double_list_get_elem_at_back(double_list_t  list)
{
    double_list_t tmp = list;

    if (tmp == NULL)
        return (0);
    if (tmp->next == NULL)
        return (tmp->value);
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    return (tmp->value);
}