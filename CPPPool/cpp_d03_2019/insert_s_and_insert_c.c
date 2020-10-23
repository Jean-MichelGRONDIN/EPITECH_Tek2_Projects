/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** insert_s_and_insert_c
*/

#include "string.h"

void  insert_s(string_t *this, size_t pos, const  string_t *str)
{
    char *tmp = NULL;

    if (pos > strlen(this->str) - 1) {
        this->str = strcat(this->str, str->str);
        return;
    }
    tmp = strndup(this->str, pos);
    tmp = strcat(tmp, str->str);
    tmp = strcat(tmp, &(this->str[pos]));
    free(this->str);
    this->str = tmp;
}

void  insert_c(string_t *this, size_t pos, const  char *str)
{
    char *tmp = NULL;

    if (pos > strlen(this->str) - 1) {
        this->str = strcat(this->str, str);
        return;
    }
    tmp = strndup(this->str, pos);
    tmp = strcat(tmp, str);
    tmp = strcat(tmp, &(this->str[pos]));
    free(this->str);
    this->str = tmp;
}