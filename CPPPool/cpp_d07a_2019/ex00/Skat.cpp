/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** Skat
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks)
{
    this->_name = name;
    this->_stimpak = stimPaks;
}

Skat::~Skat()
{
}

int &Skat::stimPaks()
{
    return (this->_stimpak);
}

const std::string &Skat::name()
{
    return (this->_name);
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (number > this->_stimpak) {
        std::cout << "Don't be greedy" << std::endl;
    } else {
        stock += number;
        this->_stimpak -= number;
        std::cout << "Keep the change." << std::endl;
    }
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
        return;
    }
    this->_stimpak += number;
}

void Skat::useStimPaks()
{
    if (this->_stimpak == 0) {
        std::cout << "Mediiiiiic" << std::endl;
        return;
    }
    this->_stimpak -= 1;
    std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
}

void Skat::status()
{
    std::cout << "Soldier " << this->_name << " reporting "
    << this->_stimpak << " stimpaks remaining sir!" << std::endl;
}