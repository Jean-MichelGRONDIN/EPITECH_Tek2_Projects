/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** double_list_is_empty
*/

#include "double_list.h"
#include <stddef.h>

bool  double_list_is_empty(double_list_t  list)
{
    if (list == NULL)
        return (true);
    return (false);
}