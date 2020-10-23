/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list_del_elem_at_back
*/

#include <stddef.h>
#include <stdlib.h>
#include "double_list.h"

bool  double_list_del_elem_at_back(double_list_t *front_ptr)
{
    double_list_t tmp = *front_ptr;
    double_list_t tmp2 = *front_ptr;
    double_list_t save = *front_ptr;

    if (tmp == NULL)
        return (false);
    if (tmp->next == NULL) {
        free(tmp);
        *front_ptr = NULL;
        return (true);
    }
    while (tmp->next != NULL) {
        tmp2 = tmp;
        tmp = tmp->next;
    }
    tmp2->next = NULL;
    free(tmp);
    *front_ptr = save;
    return (true);
}