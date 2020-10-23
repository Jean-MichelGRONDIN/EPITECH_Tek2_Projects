/*
** EPITECH PROJECT, 2020
** bootstrap_PSU_2019_malloc
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <string.h>
#include <unistd.h>

typedef struct my_memory_s {
    struct my_memory_s *next;
    size_t size;
    void *where;
    size_t is_freed;
} my_memory_t;

#define STRUC_SIZE (sizeof(my_memory_t))
#define PAGE_SIZE (getpagesize() * 2)

static my_memory_t *list = NULL;

void list_add(my_memory_t   *new);
void list_add_at_this_place(my_memory_t *after_this, my_memory_t *to_insert);
void    *new_block(size_t  size);
void    *is_already_one_free(size_t size);
my_memory_t *find_ptr_in_list(void *to_find);
void    cut_alocated_memory(size_t new_size, my_memory_t *ptr);
void unlink_this_block(my_memory_t *now);
void defrag_my_memory(my_memory_t *before, my_memory_t *actual);
void fusion_of_freed_ones(void);
void defrag_my_memory(my_memory_t *before, my_memory_t *actual);
void fusion_of_freed_ones(void);

void *malloc(size_t  size);
void  free(void *ptr);
void *calloc(size_t  nmemb , size_t  size);
void *realloc(void *ptr , size_t  size);
void *reallocarray(void *ptr , size_t  nmemb , size_t  size);

#endif