/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(const std::string &name, int level)
{
    this->_name = name;
    this->_level = level;
    this->_energy = 100;
    this->_pv = 100;
    this->_power = 5;
    std::cout << this->_name << " created" << std::endl;
}

Character::~Character()
{
}

const std::string &Character::getName() const
{
    return (this->_name);
}

int Character::getLvl() const
{
    return (this->_level);
}

int Character::getPv() const
{
    return (this->_pv);
}

int Character::getPower() const
{
    return (this->_power);
}

int Character::CloseAttack()
{
    if (this->_energy < 10) {
        std::cout << this->_name << " out of power" << std::endl;
    }
    std::cout << this->_name << " strikes with a wooden stick" << std::endl;
    return (10 + this->_power);
}

int Character::RangeAttack()
{
    if (this->_energy < 10) {
        std::cout << this->_name << " out of power" << std::endl;
    }
    std::cout << this->_name << " tosses a stone" << std::endl;
    return (5 + this->_power);
}

void Character::Heal()
{
    if (this->_pv < 100) {
        this->_pv += 50;
        if (this->_pv > 100)
            this->_pv = 100;
        std::cout << this->_name << " takes a potion" << std::endl;
    }
}

void Character::RestorePower()
{
    if (this->_energy < 100) {
        this->_energy += 100;
        if (this->_energy > 100)
            this->_energy = 100;
        std::cout << this->_name << " eats" << std::endl;
    }
}

void Character::TakeDamage(int damage)
{
    if (this->_pv > 1) {
        this->_pv -= damage;
    }
    if (this->_pv > 0) {
        std::cout << this->_name << " takes "
        << damage << " damage" << std::endl;
    } else {
        std::cout << this->_name << " out of combat" << std::endl;
    }
}