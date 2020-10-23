/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list_dump
*/

#include "double_list.h"
#include <stddef.h>
#include <stdio.h>

void  double_list_dump(double_list_t  list)
{
    if (double_list_is_empty(list) == false) {
        printf("%f\n", list->value);
        double_list_dump(list->next);
    }
}