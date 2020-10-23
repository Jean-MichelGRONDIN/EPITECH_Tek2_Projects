/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string name, const std::string file)
{
    this->_type = BUZZ;
    this->_name = name;
    this->_picture = Picture(file);
}

Buzz::~Buzz()
{
}

void Buzz::speak(std::string statement)
{
    std::cout << "BUZZ: " << this->_name << " \""
    << statement << "\"" << std::endl;
}