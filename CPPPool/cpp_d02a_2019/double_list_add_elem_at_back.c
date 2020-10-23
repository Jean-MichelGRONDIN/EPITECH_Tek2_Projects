/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list_add_elem_at_back
*/

#include "double_list.h"
#include <stddef.h>
#include <stdlib.h>


bool  double_list_add_elem_at_back(double_list_t *front_ptr, double  elem)
{
    double_list_t save = *front_ptr;
    double_list_t tmp = *front_ptr;
    double_list_t new = malloc(sizeof(doublelist_node_t) * 1);

    new->value = elem;
    new->next = NULL;
    if (tmp == NULL) {
        *front_ptr = new;
        return (true);
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    *front_ptr = save;
    return (true);
}