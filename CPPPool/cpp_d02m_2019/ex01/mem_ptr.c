/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** mem_ptr
*/

#include <stdlib.h>
#include <string.h>
#include "mem_ptr.h"

void  add_str(const  char *str1, const  char *str2, char **res)
{
    char *tmp_res = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    int i = 0;
    int i_t = 0;

    while (str1[i] != '\0' || str2[i_t] != '\0') {
        if (str1[i] == '\0') {
            tmp_res[i + i_t] = str2[i_t];
        } else {
            tmp_res[i + i_t] = str1[i];
        }
        if (str1[i] == '\0') {
            i_t++;
        } else {
            i++;
        }
    }
    tmp_res[i + i_t] = '\0';
    *res = tmp_res;
}

void  add_str_struct(str_op_t *str_op)
{
    add_str(str_op->str1, str_op->str2, &str_op->res);
}