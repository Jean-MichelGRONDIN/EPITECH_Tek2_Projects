/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** func_ptr
*/

#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "func_ptr.h"

void  print_normal(const  char *str)
{
    char c = '\n';

    write(1, str, strlen(str));
    write(1, &c, 1);
}

void  print_reverse(const  char *str)
{
    char c = '\n';
    int i = 0;

    for (i = strlen(str) -1 ; i != -1 ; i--)
        write(1, &(str[i]), 1);
    write(1, &c, 1);
}

void  print_upper(const  char *str)
{
    char c = '\n';
    int i = 0;

    for (i = 0 ; str[i] != '\0' ; i++) {
        c = toupper(str[i]);
        write(1, &(c), 1);
    }
    c = '\n';
    write(1, &c, 1);
}

void  print_42(const  char *str)
{
    str = str;
    write(1, "42\n", 3);
}

void  do_action(action_t  action, const  char *str)
{
    int i = 0;
    action_list_t   list[4] = {
        {PRINT_NORMAL, print_normal},
        {PRINT_REVERSE, print_reverse},
        {PRINT_UPPER, print_upper},
        {PRINT_42, print_42},
    };

    for (i = 0; i != 4 && i != -1;)
        if (action == list[i].action_num) {
            list[i].do_it(str);
            i = -1;
        } else
            i++;
}