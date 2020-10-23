/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list_del_elem_at_position
*/

#include <stddef.h>
#include <stdlib.h>
#include "double_list.h"

void double_list_del_elem_at_position_rec(double_list_t *front_ptr, unsigned  int  max)
{
    double_list_t tmp = *front_ptr;
    double_list_t tmp2 = *front_ptr;
    double_list_t save = *front_ptr;
    unsigned int i = 0;

    if (max == 0) {
        *front_ptr = tmp->next;
        free(tmp);
        return;
    }
    while (i != max) {
        tmp2 = tmp;
        tmp = tmp->next;
        i++;
    }
    tmp2->next = tmp->next;
    free(tmp);
    *front_ptr = save;
}

bool  double_list_del_elem_at_position(double_list_t *front_ptr, unsigned  int  position)
{
    double_list_t tmp = *front_ptr;

    if (tmp == NULL)
        return (false);
    if (position > double_list_get_size(*front_ptr) - 1)
        return (false);
    double_list_del_elem_at_position_rec(front_ptr, position);
    return (true);
}