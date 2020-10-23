/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** to_int_string
*/

#include "string.h"

int  to_int(const  string_t *this)
{
    return (atoi(this->str));
}