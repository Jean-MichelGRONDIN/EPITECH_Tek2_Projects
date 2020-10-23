/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list_get_siz
*/

#include "double_list.h"
#include <stddef.h>

unsigned int double_list_get_size(double_list_t  list)
{
    double_list_t tmp = list;
    int i = 0;

    while (tmp != NULL) {
        tmp = tmp->next;
        i++;
    }
    return (i);
}