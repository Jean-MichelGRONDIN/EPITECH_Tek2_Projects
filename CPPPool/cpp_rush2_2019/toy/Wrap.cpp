/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Wrap
*/

#include "Wrap.hpp"

Wrap::Wrap()
{
    is_open = true;
    is_wrap = false;
    is_close = false;
    object = nullptr;
}

Wrap::~Wrap()
{
}

bool Wrap::isOpen()
{
    return (this->is_open);
}

bool Wrap::isClose()
{
    return (this->is_close);
}

bool Wrap::isWraped()
{
    return ();
}

bool Wrap::WrapMeThat(Object *obj)
{
    if (obj->isWraped()) {
        std::cout << "Is wrapped" << std::endl;
    return (false);
    }

    if (!is_open) {
        std::cout << "The box is closed" << std::endl;
    }

    if (obj) {
        std::cout << "cannot wrap because isn't empty" << std::endl;
        return (false);
    }
    obj->setWrap(true);
    is_open = false;
    object = obj;
    std::cout << "tuuuut tuuut tuut" << std::endl;
    return (true);
}

void Wrap::CloseMe()
{
    if (!is_open)
        std::cout << "The box is close"  << std::endl;
    else 
        is_open = false;
}

void Wrap::OpenMe()
{
    if (is_open)
        std::cout << "The box is open" << std::endl;
    else
        is_open = true;
}