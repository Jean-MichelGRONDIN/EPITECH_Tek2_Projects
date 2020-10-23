/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** find_ptr_in_list
*/

#include "../include/my_malloc.h"

my_memory_t *find_ptr_in_list(void *to_find)
{
    my_memory_t *tmp = list;

    while (tmp != NULL) {
        if (tmp->where == to_find) {
            return (tmp);
        }
        tmp = tmp->next;
    }
    return (NULL);
}