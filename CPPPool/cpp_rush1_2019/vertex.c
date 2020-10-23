/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
    va_end(*args);
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

static void Vertex_dtor(VertexClass *this)
{
    this = this;
    // free(this);
}

static char *Vertex_str(Object *this)
{
    VertexClass *obj = this;

    int size = 15 + get_int_len(obj->x) + get_int_len(obj->y)
        + get_int_len(obj->z) + 1;
    char *res = malloc(sizeof(char) * size);

    snprintf(res, size, "<Vertex (%d, %d, %d)>", obj->x, obj->y, obj->z);
    res[size - 1] = '\0';
    return (res);
}

static Object *Vertex_add(const Object *this, const Object *other)
{
    VertexClass *new_obj = new(Vertex, ((VertexClass *)this)->x, ((VertexClass *)other)->y);

    new_obj->x = ((VertexClass *)this)->x + ((VertexClass *)other)->x;
    new_obj->y = ((VertexClass *)this)->y + ((VertexClass *)other)->y;
    new_obj->z = ((VertexClass *)this)->z + ((VertexClass *)other)->z;
    return (new_obj);
}

static Object *Vertex_sub(const Object *this, const Object *other)
{
    VertexClass *new_obj = new(Vertex, ((VertexClass *)this)->x, ((VertexClass *)other)->y);

    new_obj->x = ((VertexClass *)this)->x - ((VertexClass *)other)->x;
    new_obj->y = ((VertexClass *)this)->y - ((VertexClass *)other)->y;
    new_obj->z = ((VertexClass *)this)->z - ((VertexClass *)other)->z;
    return (new_obj);
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = &Vertex_str,
        .__add__ = &Vertex_add,
        .__sub__ = &Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;
