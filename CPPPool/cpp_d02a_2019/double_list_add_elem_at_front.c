/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list_add_elem_at_front
*/

#include "double_list.h"
#include <stddef.h>
#include <stdlib.h>

bool  double_list_add_elem_at_front(double_list_t *front_ptr, double  elem)
{
    double_list_t new = malloc(sizeof(doublelist_node_t) * 1);

    new->value = elem;
    new->next = *front_ptr;
    *front_ptr = new;
    return (true);
}