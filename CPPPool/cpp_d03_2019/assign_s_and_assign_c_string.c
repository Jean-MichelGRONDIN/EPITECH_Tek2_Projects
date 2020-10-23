/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** assign_s_and_assign_c_string
*/

#include "string.h"

void  assign_s(string_t *this, const  string_t *str)
{
    if (this->str != NULL) {
        free(this->str);
        this->str = NULL;
    }
    this->str = strdup(str->str);
}

void  assign_c(string_t *this, const  char *s)
{
    if (this->str != NULL) {
        free(this->str);
        this->str = NULL;
    }
    this->str = strdup(s);
}