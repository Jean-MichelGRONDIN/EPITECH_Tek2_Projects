/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** at_string
*/

#include "string.h"

char at(const  string_t *this, size_t  pos)
{
    if (this == NULL || this->str == NULL || strlen(this->str) - 1 < pos)
        return (-1);
    return (this->str[pos]);
}