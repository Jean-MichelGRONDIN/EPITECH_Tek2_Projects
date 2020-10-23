/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** my_realloc_array
*/

#include <string.h>

void *realloc(void *ptr , size_t  size);

void *reallocarray(void *ptr , size_t  nmemb , size_t  size)
{
    return (realloc(ptr, nmemb*size));
}