/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** is_already_one_freed
*/

#include "../include/my_malloc.h"

void cut_this_memory(my_memory_t *elem, size_t size)
{
    my_memory_t *new = elem->where + size;

    new->next = elem->next;
    elem->next = new;
    new->size = elem->size - size;
    elem->size = size;
    new->is_freed = 1;
    new->where = elem->where + size + STRUC_SIZE;
}

static void *searsh_greater_but_can_cut(size_t size)
{
    my_memory_t *tmp = list;

    while (tmp != NULL) {
        if (tmp->is_freed > 0 && tmp->size > size + STRUC_SIZE) {
            cut_this_memory(tmp, size);
            tmp->is_freed = 0;
            return (tmp->where);
        }
        tmp = tmp->next;
    }
    return (NULL);
}

static void *searsh_greater(size_t size)
{
    my_memory_t *tmp = list;

    while (tmp != NULL) {
        if (tmp->is_freed > 0 && tmp->size > size) {
            tmp->is_freed = 0;
            return (tmp->where);
        }
        tmp = tmp->next;
    }
    return (NULL);
}

void    *is_already_one_free(size_t size)
{
    my_memory_t *tmp = list;
    void *res = NULL;

    if (list == NULL) {
        write(1, "c est nul as fuck\n", 18);
        return (NULL);
    }
    while (tmp != NULL) {
        if (tmp->is_freed != 0)
        if (tmp->is_freed > 0 && tmp->size == size) {
            tmp->is_freed = 0;
            return (tmp->where);
        }
        tmp = tmp->next;
    }
    res = searsh_greater_but_can_cut(size);
    if (res != NULL)
        return (res);
    res = searsh_greater(size);
    return (res);
}