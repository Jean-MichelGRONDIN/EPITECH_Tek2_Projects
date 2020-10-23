/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Sorcerer
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
{
    this->_name = name;
    this->_title = title;
    std::cout << this->_name << ", " << this->_title
    << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->_name << ", " << this->_title
    << ", is dead. Consequences will never be the same!" << std::endl;
}

std::string Sorcerer::getname() const
{
    return (this->_name);
}

std::string Sorcerer::gettitle() const
{
    return (this->_title);
}

void Sorcerer::polymorph(const Victim &victim) const
{
    victim.getPolymorphed();
}

void Sorcerer::polymorph(const Peon &peon) const
{
    peon.getPolymorphed();
}

std::ostream &operator<<(std::ostream &s, const Sorcerer &obj)
{
    s << "I am " << obj.getname() << ", " << obj.gettitle()
    << ", and I like ponies!" << std::endl;
    return (s);
}