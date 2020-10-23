/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** func_ptr
*/

#ifndef FUNC_PTR_H_
#define FUNC_PTR_H_

#include "func_ptr_enum.h"

typedef struct action_list {
    action_t action_num;
    void (*do_it)(const char *str);
} action_list_t;

void  print_normal(const  char *str);
void  print_reverse(const  char *str);
void  print_upper(const  char *str);
void  print_42(const  char *str);
void  do_action(action_t  action, const  char *str);

#endif /* !FUNC_PTR_H_ */