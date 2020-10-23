/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** new
*/

#include "new.h"

Object  *new(const Class *class, ...)
{
    Object  *new = malloc(class->__size__);
    va_list ap;

    memcpy(new, class, class->__size__);
    if (class->__ctor__ != NULL) {
        va_start(ap, class);
        class->__ctor__(new, &ap);
    }
    return (new);
}

Object  *va_new(const Class *class, va_list* ap)
{
    Object  *new = malloc(class->__size__);

    memcpy(new, class, class->__size__);
    if (class->__ctor__ != NULL)
        class->__ctor__(new, ap);
    return (new);
}

void delete(Object *ptr)
{
    Class *ptr_class = ptr;

    if (ptr_class->__dtor__ != NULL) {
        ptr_class->__dtor__(ptr);
        free (ptr);
    }
}