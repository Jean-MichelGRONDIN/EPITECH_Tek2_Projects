/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Lemon
*/

#include "Lemon.hpp"

Lemon::Lemon()
{
    this->_name = "lemon";
    this->_vitamins = 3;
}

Lemon::~Lemon()
{
}

int Lemon::getVitamins() const
{
    return (this->_vitamins);
}

std::string Lemon::getName() const
{
    return (this->_name);
}