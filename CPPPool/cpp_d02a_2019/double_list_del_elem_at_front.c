/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list_del_elem_at_front
*/

#include <stddef.h>
#include <stdlib.h>
#include "double_list.h"

bool  double_list_del_elem_at_front(double_list_t *front_ptr)
{
    double_list_t tmp = *front_ptr;

    if (tmp == NULL)
        return (false);
    *front_ptr = tmp->next;
    free(tmp);
    return (true);
}