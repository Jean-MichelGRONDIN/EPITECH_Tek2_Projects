/*
** EPITECH PROJECT, 2020
** bootstrap_PSU_2019_malloc
** File description:
** my_free
*/

#include "my_malloc.h"

void    free(void *ptr)
{
    my_memory_t *tmp = list;

    while (tmp != NULL) {
        if (tmp == ptr) {
            tmp->is_freed = 1;
            tmp->where = memset(tmp->where, 0, tmp->size);
        }
        tmp = tmp->next;
    }
}