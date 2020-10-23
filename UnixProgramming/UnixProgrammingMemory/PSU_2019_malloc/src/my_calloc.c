/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** my_calloc
*/

#include <string.h>
#include <unistd.h>

void    *malloc(size_t  size);

void *calloc(size_t  nmemb , size_t  size)
{
    void *res = malloc(nmemb * size);

    memset(res, 0, size*nmemb);
    return (res);
}