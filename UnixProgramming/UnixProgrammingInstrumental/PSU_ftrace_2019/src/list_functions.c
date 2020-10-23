/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** list_functions
*/

#include "../include/ftrace.h"

functions_list_t *add_new_elem(char *name, functions_list_t *list)
{
    functions_list_t *new = malloc(sizeof(*new));

    new->name = name;
    new->next = list;
    return (new);
}

functions_list_t *delet_head(functions_list_t *list)
{
    functions_list_t *res = NULL;

    if (list != NULL) {
        res = list->next;
        free(list);
        list = NULL;
    }
    return (res);
}

functions_list_t *delete_all(functions_list_t *list)
{
    while (list != NULL) {
        list = delet_head(list);
    }
    return (list);
}