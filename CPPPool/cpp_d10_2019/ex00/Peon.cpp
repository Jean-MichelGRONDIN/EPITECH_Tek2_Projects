/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Peon
*/

#include "Peon.hpp"

Peon::Peon(std::string name)
{
    this->_name = name;
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

std::string Peon::getname() const
{
    return (this->_name);
}

void Peon::getPolymorphed() const
{
    std::cout << this->_name
    <<" has been turned into a pink pony!" << std::endl;
}

std::ostream &operator<<(std::ostream &s, Peon obj)
{
    s << "I'm " << obj.getname() << " and I like otters!" << std::endl;
    return (s);
}
