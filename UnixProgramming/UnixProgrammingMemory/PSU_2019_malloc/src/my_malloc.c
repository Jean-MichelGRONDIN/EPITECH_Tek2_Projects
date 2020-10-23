/*
** EPITECH PROJECT, 2020
** bootstrap_PSU_2019_malloc
** File description:
** my_malloc
*/

#include "../include/my_malloc.h"
#include <unistd.h>

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

void    *malloc(size_t  size)
{
    write(1, "my_malloc\n", 10);
    void *new = NULL;

    list = list;
    if (size == 0)
        return (NULL);
    if ((new = is_already_one_free(size)) != NULL) {
        return (new);
    }
    new = new_block(size);
    return (new);
}