/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** Materials
*/

#include "Materials.hpp"

Materials::Materials(const std::string &type)
{
    this->_type = type;
}

Materials::~Materials()
{
}

/* GETTERS */

std::string Materials::getType() const
{
    return this->_type;
}

/* SETTERS */


/* OTHERS */