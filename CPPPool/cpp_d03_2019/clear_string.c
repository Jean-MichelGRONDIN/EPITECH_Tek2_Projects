/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** clear_string
*/

#include "string.h"

void  clear(string_t *this)
{
    free(this->str);
    this->str = malloc(sizeof(char) * 1);
    this->str[0] = '\0';
}