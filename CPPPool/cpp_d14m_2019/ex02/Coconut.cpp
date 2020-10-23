/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Coconut
*/

#include "Coconut.hpp"

Coconut::Coconut()
{
    this->_name = "coconut";
    this->_vitamins = 15;
}

Coconut::~Coconut()
{
}

int Coconut::getVitamins() const
{
    return (this->_vitamins);
}

std::string Coconut::getName() const
{
    return (this->_name);
}