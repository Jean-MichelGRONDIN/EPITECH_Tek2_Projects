/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** size_string
*/

#include "string.h"

int  size(const  string_t *this)
{
    if (this->str == NULL)
        return (-1);
    if (this->str[0] == '\0')
        return (0);
    return (strlen(this->str));
}