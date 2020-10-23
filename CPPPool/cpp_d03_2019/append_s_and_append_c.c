/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** append_s_and_append_c
*/

#include "string.h"

void  append_s(string_t *this, const  string_t *ap)
{
    this->str = strcat(this->str, ap->str);
}

void  append_c(string_t *this, const  char *ap)
{
    this->str = strcat(this->str, ap);
}