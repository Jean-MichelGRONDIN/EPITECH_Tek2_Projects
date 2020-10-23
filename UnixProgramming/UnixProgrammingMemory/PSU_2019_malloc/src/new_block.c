/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** new_block
*/

#include "../include/my_malloc.h"
#include <unistd.h>

void cut_this_memory(my_memory_t *elem, size_t size);

// void    *new_block(size_t  size)
// {
//     my_memory_t *new = NULL;
//     void *request = NULL;

//     list = list;
//     new = sbrk(0);
//     request = sbrk(STRUC_SIZE + (size * size));
//     if (request == (void *)-1) {
//         return (NULL);
//     }
//     new->where = request + STRUC_SIZE;
//     new->is_freed = 0;
//     new->size = size;
//     new->next = NULL;
//     list_add(new);
//     return (new->where);
// }

size_t find_how_many_pages_needed(size_t size)
{
    size_t n = 1;

    while (PAGE_SIZE * n < size || (PAGE_SIZE * n) - size <= size + STRUC_SIZE) {
        n++;
    }
    return (n);
}

my_memory_t *give_block_this_size(size_t size)
{
    my_memory_t *new = NULL;
    void *requested = NULL;
    size_t n = find_how_many_pages_needed(size);

    new = sbrk(0);
    requested = sbrk(PAGE_SIZE * n);
    new->where = requested + STRUC_SIZE;
    new->is_freed = 0;
    new->size = (PAGE_SIZE * n) - STRUC_SIZE;
    new->next = NULL;
    cut_this_memory(new, size);
    return (new);
}

static void print_int(int v)
{
  char c[10];
  int cpt = 0, nb, i;

  if(v < 0)
  {
    write(1, "-", 1);
    v = -v;
  }

  nb = v;
  do
  {
    cpt++;
    nb=nb/10;
  }
  while(nb != 0);
 
  for(i = 1 ; i <= cpt ; i++)
  {
    c[cpt - i] = '0' + (v % 10);
    v = v / 10;
  }
 
  write(1, c, cpt);
}

void expand_last_to_fit(my_memory_t *last, size_t size)
{
    size_t n = find_how_many_pages_needed(size - last->size);

    sbrk(PAGE_SIZE * n);
    last->size = last->size + (PAGE_SIZE * n);
    last->is_freed = 0;
    cut_this_memory(last, size);
}

void *add_more_memory(size_t size)
{
    my_memory_t *tmp = list;
    my_memory_t *new = NULL;

    for (; tmp->next != NULL; tmp = tmp->next);
    if (tmp->is_freed > 0) {
        expand_last_to_fit(tmp, size);
        return (tmp->where);
    } else {
        new = give_block_this_size(size);
        tmp->next = new;
    }
    return (new->where);
}

void    *new_block(size_t size)
{
    if (list == NULL) {
        list = give_block_this_size(size);
        if (list != NULL) {
            return (list->where);
        } else {
            return (NULL);
        }
    } else {
        write(1, "vasi chiant la!\n", 16);
        return (add_more_memory(size));
    }
}