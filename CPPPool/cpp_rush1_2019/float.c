/*
** EPITECH PROJECT, 2020
** Piscine
** File description:
** float
*/

#include <stdio.h>
#include "float.h"
#include "new.h"

typedef struct
{
    Class   base;
    float     x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    va_end(*args);
}

static void Float_dtor(FloatClass *this)
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
    FloatClass *obj = this;

    int size = 10 + get_int_len(obj->x) + 1 + 6 + 1;
    char *res = malloc(sizeof(char) * size);

    snprintf(res, size, "<Float (%f)>", obj->x);
    res[size - 1] = '\0';
    return (res);
}

static Object *Float_add(const Object *this, const Object *other)
{
    FloatClass *new_obj = new(Float, ((FloatClass *)this)->x);

    new_obj->x = ((FloatClass *)this)->x + ((FloatClass *)other)->x;
    return (new_obj);
}

static Object *Float_sub(const Object *this, const Object *other)
{
    FloatClass *new_obj = new(Float, ((FloatClass *)this)->x);

    new_obj->x = ((FloatClass *)this)->x - ((FloatClass *)other)->x;
    return (new_obj);
}

static Object *Float_mul(const Object *this, const Object *other)
{
    FloatClass *new_obj = new(Float, ((FloatClass *)this)->x);

    new_obj->x = ((FloatClass *)this)->x * ((FloatClass *)other)->x;
    return (new_obj);
}

static Object *Float_div(const Object *this, const Object *other)
{
    FloatClass *new_obj = new(Float, ((FloatClass *)this)->x);

    new_obj->x = ((FloatClass *)this)->x / ((FloatClass *)other)->x;
    return (new_obj);
}

static bool Float_eq(const Object *this, const Object *other)
{
    if (((FloatClass *)this)->x == ((FloatClass *)other)->x)
        return true;
    return false;
}

static bool Float_lt(const Object *this, const Object *other)
{
    if (((FloatClass *)this)->x < ((FloatClass *)other)->x)
        return true;
    return false;
}

static bool Float_gt(const Object *this, const Object *other)
{
    if (((FloatClass *)this)->x > ((FloatClass *)other)->x)
        return true;
    return false;
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = &get_str,
        .__add__ = &Float_add,
        .__sub__ = &Float_sub,
        .__mul__ = &Float_mul,
        .__div__ = &Float_div,
        .__eq__ = &Float_eq,
        .__gt__ = &Float_gt,
        .__lt__ = &Float_lt
    },
    .x = 0
};

const Class   *Float = (const Class *)&_description;