/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Object
*/

#include "Object.hpp"

Object::Object()
{
}

Object::~Object()
{
}

bool Object::isWraped()
{
    return (is_wrap);
}

void Object::setWrap(bool wrap)
{
    is_wrap = wrap;
}