/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** copy_string
*/

#include "string.h"

size_t  copy(const  string_t *this, char *s, size_t n, size_t  pos)
{
    s = strncpy(&(s[pos]), this->str, n);
    return (strlen(&(s[pos])));
}