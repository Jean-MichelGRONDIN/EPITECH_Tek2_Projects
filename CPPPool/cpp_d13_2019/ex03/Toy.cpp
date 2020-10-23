/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy()
{
    this->_type = BASIC_TOY;
    this->_name = "toy";
    this->_picture = Picture();
}

Toy::Toy(int type, std::string name, const std::string file)
{
    this->_type = type;
    this->_name = name;
    this->_picture = Picture(file);
}

Toy::Toy(const Toy &obj)
{
    this->_type = obj._type;
    this->_name = obj._name;
    this->_picture = Picture(obj._picture);
}

Toy::~Toy()
{
}

int Toy::getType() const
{
    return (this->_type);
}

std::string Toy::getName() const
{
    return (this->_name);
}

void Toy::setName(std::string name)
{
    this->_name = name;
}


bool Toy::setAscii(const std::string file)
{
    return (this->_picture.getPictureFromFile(file));
}

std::string Toy::getAscii() const
{
    return (this->_picture.data);
}

void Toy::speak(std::string statement)
{
    std::cout << this->_name << " \"" << statement << "\"" << std::endl;
}