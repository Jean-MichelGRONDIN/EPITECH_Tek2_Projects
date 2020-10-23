/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** split_s_and_split_c
*/

#include "string.h"

string_t  **split_s(const  string_t *this, char  separator)
{
    char *sep = malloc(sizeof(char) * 2);
    string_t **tmp;

    sep[0] = separator;
    sep[1] = '\0';
    tmp = my_str_to_word_array_string(this->str, sep);
    free(sep);
    sep = NULL;
    return (tmp);
}

char **split_c(const  string_t *this, char  separator)
{
    char *sep = malloc(sizeof(char) * 2);
    char **tmp;

    sep[0] = separator;
    sep[1] = '\0';
    tmp = my_str_to_word_array(this->str, sep);
    free(sep);
    sep = NULL;
    return (tmp);
}