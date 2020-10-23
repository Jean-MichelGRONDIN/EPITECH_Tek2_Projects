/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** my_realloc
*/

#include "../include/my_malloc.h"
#include <string.h>

void *realloc(void *ptr , size_t  size)
{
    void *res = NULL;
    my_memory_t *ptr_pos = NULL;

    list = list;
    if (ptr == NULL)
        return (malloc(size));
    if (size == 0) {
        free(ptr);
        return (ptr);
    }
    ptr_pos = find_ptr_in_list(ptr);
    if (ptr_pos != NULL && size > ptr_pos->size) {
        res = malloc(size);
        if (res == NULL)
            return (res);
        memcpy(res, ptr, ptr_pos->size);
        free(ptr);
        return (res);
    }
    return (ptr);
}