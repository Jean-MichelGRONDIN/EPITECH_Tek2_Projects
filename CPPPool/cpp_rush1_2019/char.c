/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** char
*/

#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class   base;
    char c;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->c = va_arg(*args, int);
    va_end(*args);
}

static void Char_dtor(CharClass *this)
{
    this = this;
}

static char *get_str(Object *this)
{
    CharClass *obj = this;

    int size = 9 + 1 + 1;
    char *res = malloc(sizeof(char) * size);

    snprintf(res, size, "<Char (%c)>", obj->c);
    res[size - 1] = '\0';
    return (res);
}

static Object *Char_add(const Object *this, const Object *other)
{
    CharClass *new_obj = new(Char, ((CharClass *)this)->c);

    new_obj->c = ((CharClass *)this)->c + ((CharClass *)other)->c;
    return (new_obj);
}

static Object *Char_sub(const Object *this, const Object *other)
{
    CharClass *new_obj = new(Char, ((CharClass *)this)->c);

    new_obj->c = ((CharClass *)this)->c - ((CharClass *)other)->c;
    return (new_obj);
}

static Object *Char_mul(const Object *this, const Object *other)
{
    CharClass *new_obj = new(Char, ((CharClass *)this)->c);

    new_obj->c = ((CharClass *)this)->c * ((CharClass *)other)->c;
    return (new_obj);
}

static Object *Char_div(const Object *this, const Object *other)
{
    CharClass *new_obj = new(Char, ((CharClass *)this)->c);

    if (((CharClass *)other)->c == 0)
        new_obj->c = 0;
    else
        new_obj->c = ((CharClass *)this)->c / ((CharClass *)other)->c;
    return (new_obj);
}

static bool char_eq(const Object *this, const Object *other)
{
    if (((CharClass *)this)->c == ((CharClass *)other)->c)
        return (true);
    return (false);
}

static bool char_lt(const Object *this, const Object *other)
{
    if (((CharClass *)this)->c < ((CharClass *)other)->c)
        return (true);
    return (false);
}

static bool char_gt(const Object *this, const Object *other)
{
    if (((CharClass *)this)->c > ((CharClass *)other)->c)
        return (true);
    return (false);
}
static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = &get_str,
        .__add__ = &Char_add,
        .__sub__ = &Char_sub,
        .__mul__ = &Char_mul,
        .__div__ = &Char_div,
        .__eq__ = &char_eq,
        .__gt__ = &char_gt,
        .__lt__ = &char_lt
    },
    .c = 0
};

const Class   *Char = (const Class *)&_description;