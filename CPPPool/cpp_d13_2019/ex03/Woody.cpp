/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(std::string name, const std::string file)
{
    this->_type = WOODY;
    this->_name = name;
    this->_picture = Picture(file);
}

Woody::~Woody()
{
}

void Woody::speak(std::string statement)
{
    std::cout << "WOODY: " << this->_name << " \""
    << statement << "\"" << std::endl;
}