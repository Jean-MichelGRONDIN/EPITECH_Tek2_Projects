/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    va_end(*args);
}

static void Point_dtor(PointClass *this)
{
    this = this;
    // free(this);
}

static int get_int_len (int value)
{
    int l = value < 0 ? 1 : 0;

    if (value == 0)
        return (1);
    while (value) {
        l++;
        value /= 10;
    }
    return (l);
}

static char *get_str(Object *this)
{
    PointClass *obj = this;

    int size = 12 + get_int_len(obj->x) + get_int_len(obj->y) + 1;
    char *res = malloc(sizeof(char) * size);

    snprintf(res, size, "<Point (%i, %i)>", obj->x, obj->y);
    res[size - 1] = '\0';
    return (res);
}

static Object *Point_add(const Object *this, const Object *other)
{
    PointClass *new_obj = new(Point, ((PointClass *)this)->x, ((PointClass *)other)->y);

    new_obj->x = ((PointClass *)this)->x + ((PointClass *)other)->x;
    new_obj->y = ((PointClass *)this)->y + ((PointClass *)other)->y;
    return (new_obj);
}

static Object *Point_sub(const Object *this, const Object *other)
{
    PointClass *new_obj = new(Point, ((PointClass *)this)->x, ((PointClass *)other)->y);

    new_obj->x = ((PointClass *)this)->x - ((PointClass *)other)->x;
    new_obj->y = ((PointClass *)this)->y - ((PointClass *)other)->y;
    return (new_obj);
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = &get_str,
        .__add__ = &Point_add,
        .__sub__ = &Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;