/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list_add_elem_at_position
*/

#include <stddef.h>
#include <stdlib.h>
#include "double_list.h"

void double_list_add_elem_at_position_rec(double_list_t *front_ptr,
    double_list_t  elem, unsigned  int  max)
{
    double_list_t tmp = *front_ptr;
    double_list_t save;
    unsigned int i = 0;

    if (max == 0) {
        elem->next = tmp;
        *front_ptr = elem;
        return;
    }
    while (i != max - 1) {
        tmp = tmp->next;
        i++;
    }
    save = tmp->next;
    tmp->next = elem;
    elem->next = save;
}

bool  double_list_add_elem_at_position(double_list_t *front_ptr,
    double  elem, unsigned  int  position)
{
    double_list_t save = *front_ptr;
    double_list_t new = malloc(sizeof(doublelist_node_t) * 1);

    if (position > double_list_get_size(*front_ptr))
        return (false);
    new->value = elem;
    new->next = NULL;
    double_list_add_elem_at_position_rec(front_ptr, new, position);
    if (position != 0)
        *front_ptr = save;
    return (true);
}