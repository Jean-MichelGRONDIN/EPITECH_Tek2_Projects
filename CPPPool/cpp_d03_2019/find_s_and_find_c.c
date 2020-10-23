/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** find_s_and_find_c
*/

#include "string.h"

int  find_s(const  string_t *this, const  string_t *str, size_t  pos)
{
    int i = pos;

    if (strlen(this->str) - 1 < pos || strlen(&(this->str[pos])) < strlen(str->str))
        return (-1);
    while (this->str[i] != '\0' && strncmp(&(this->str[i]),
        str->str, strlen(str->str)) != 0) {
        i++;
    }
    if (this->str[i] == '\0')
        return (-1);
    return (i);
}

int  find_c(const  string_t *this, const  char *str, size_t  pos)
{
    int i = pos;

    if (strlen(this->str) - 1 < pos || strlen(&(this->str[pos])) < strlen(str))
        return (-1);
    while (this->str[i] != '\0' && strncmp(&(this->str[i]),
        str, strlen(str)) != 0) {
        i++;
    }
    if (this->str[i] == '\0')
        return (-1);
    return (i);
}