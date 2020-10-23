/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** compare_s_and_compare_c
*/

#include "string.h"

int  compare_s(const  string_t *this, const  string_t *str)
{
    return (strcmp(this->str, str->str));
}

int  compare_c(const  string_t *this, const  char *str)
{
    return (strcmp(this->str, str));
}