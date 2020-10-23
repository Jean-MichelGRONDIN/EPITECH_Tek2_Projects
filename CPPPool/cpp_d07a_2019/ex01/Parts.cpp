/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** Parts
*/

#include "Parts.hpp"

Arms::Arms(std::string serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
}

Arms::~Arms()
{
}

bool Arms::isFunctional() const
{
    return (this->_functional);
}

std::string Arms::serial() const
{
    return (this->_serial);
}

void Arms::informations() const
{
    std::cout << "\t[Parts] Arms " << this->_serial << " status : "
    << (this->_functional == true ? "OK" : "KO") << std::endl;
}



Legs::Legs(std::string serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
}

Legs::~Legs()
{
}

bool Legs::isFunctional() const
{
    return (this->_functional);
}

std::string Legs::serial() const
{
    return (this->_serial);
}

void Legs::informations() const
{
    std::cout << "\t[Parts] Legs " << this->_serial << " status : "
    << (this->_functional == true ? "OK" : "KO") << std::endl;
}



Head::Head(std::string serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
}

Head::~Head()
{
}

bool Head::isFunctional() const
{
    return (this->_functional);
}

std::string Head::serial() const
{
    return (this->_serial);
}

void Head::informations() const
{
    std::cout << "\t[Parts] Head " << this->_serial << " status : "
    << (this->_functional == true ? "OK" : "KO") << std::endl;
}