/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 04
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    va_end(*args);
}

static void Int_dtor(IntClass *this)
{
    this = this;
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
    IntClass *obj = this;

    int size = 9 + get_int_len(obj->x) + 1;
    char *res = malloc(sizeof(char) * size);

    snprintf(res, size, "<Int (%i)>", obj->x);
    res[size - 1] = '\0';
    return (res);
}

static Object *Int_add(const Object *this, const Object *other)
{
    IntClass *new_obj = new(Int, ((IntClass *)this)->x);

    new_obj->x = ((IntClass *)this)->x + ((IntClass *)other)->x;
    return (new_obj);
}

static Object *Int_sub(const Object *this, const Object *other)
{
    IntClass *new_obj = new(Int, ((IntClass *)this)->x);

    new_obj->x = ((IntClass *)this)->x - ((IntClass *)other)->x;
    return (new_obj);
}

static Object *Int_mul(const Object *this, const Object *other)
{
    IntClass *new_obj = new(Int, ((IntClass *)this)->x);

    new_obj->x = ((IntClass *)this)->x * ((IntClass *)other)->x;
    return (new_obj);
}

static Object *Int_div(const Object *this, const Object *other)
{
    IntClass *new_obj = new(Int, ((IntClass *)this)->x);

    if (((IntClass *)other)->x != 0)
        new_obj->x = ((IntClass *)this)->x / ((IntClass *)other)->x;
    else
        new_obj->x = 0;
    return (new_obj);
}

static bool Int_eq(const Object *this, const Object *other)
{
    if (((IntClass *)this)->x == ((IntClass *)other)->x)
        return (true);
    return (false);
}

static bool Int_lt(const Object *this, const Object *other)
{
    if (((IntClass *)this)->x < ((IntClass *)other)->x)
        return (true);
    return (false);
}

static bool Int_gt(const Object *this, const Object *other)
{
    if (((IntClass *)this)->x > ((IntClass *)other)->x)
        return (true);
    return (false);
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = &get_str,
        .__add__ = &Int_add,
        .__sub__ = &Int_sub,
        .__mul__ = &Int_mul,
        .__div__ = &Int_div,
        .__eq__ = &Int_eq,
        .__gt__ = &Int_gt,
        .__lt__ = &Int_lt
    },
    .x = 0
};

const Class   *Int = (const Class *)&_description;