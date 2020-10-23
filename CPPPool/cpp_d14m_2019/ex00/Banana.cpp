/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Banana
*/

#include "Banana.hpp"

Banana::Banana()
{
    this->_name = "banana";
    this->_vitamins = 5;
}

Banana::~Banana()
{
}

int Banana::getVitamins() const
{
    return (this->_vitamins);
}

std::string Banana::getName() const
{
    return (this->_name);
}