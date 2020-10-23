/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list_get_first_node_with_value
*/

#include <stddef.h>
#include <stdlib.h>
#include "double_list.h"

doublelist_node_t *double_list_get_first_node_with_value(double_list_t  list,
    double  value)
{
    if (list == NULL)
        return (NULL);
    while (list->next != NULL && list->value != value) {
        list = list->next;
    }
    if (list->next == NULL)
        return (NULL);
    return (list);
}