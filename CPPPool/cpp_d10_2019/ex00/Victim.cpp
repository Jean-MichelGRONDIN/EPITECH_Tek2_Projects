/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Victim
*/

#include "Victim.hpp"

Victim::Victim(std::string name)
{
    this->_name = name;
    std::cout << "Some random victim called "
    << this->_name << " just popped!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << this->_name
    << " just died for no apparent reason!" << std::endl;
}

std::string Victim::getname() const
{
    return (this->_name);
}

void Victim::getPolymorphed() const
{
    std::cout << this->_name
    <<" has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator<<(std::ostream &s, Victim obj)
{
    s << "I'm " << obj.getname() << " and I like otters!" << std::endl;
    return (s);
}