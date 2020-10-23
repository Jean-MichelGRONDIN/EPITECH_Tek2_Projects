/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** list_add
*/

#include "../include/my_malloc.h"

void list_add(my_memory_t   *new)
{
    my_memory_t *tmp = list;

    if (list == NULL) {
        list = new;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
}