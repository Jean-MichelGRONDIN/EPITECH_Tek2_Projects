/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string id) : _attack(24), _toughness(15)
{
    this->_id = id;
    this->_energy = 50;
    this->_status = new std::string("Standing by");
    std::cout << "Droid '" << this->_id << "' Activated" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << this->_id << "' Destroyed" << std::endl;
    delete _status;
}

Droid::Droid(const Droid &other) : _attack(other._attack), _toughness(other._toughness)
{
    this->_id = other._id;
    this->_energy = other._energy;
    this->_status = new std::string(other._status->c_str());
    std::cout << "Droid '" << this->_id
    << "' Activated, Memory Dumped" << std::endl;
}

std::string Droid::getId() const
{
    return (this->_id);
}

size_t Droid::getEnergy() const
{
    return (this->_energy);
}

size_t Droid::getAttack() const
{
    return (this->_attack);
}

size_t Droid::getToughness() const
{
    return (this->_toughness);
}

std::string *Droid::getStatus() const
{
    return (this->_status);
}

void Droid::setId(std::string id)
{
    this->_id = id;
}

void Droid::setEnergy(size_t energy)
{
    this->_energy = energy;
}

void Droid::setStatus(std::string *status)
{
    this->_status = status;
}

bool Droid::operator==(const Droid &other)
{
    if (this->_status == other._status)
        return (true);
    return (false);
}

bool Droid::operator!=(const Droid &other)
{
    if (this->_status != other._status)
        return (true);
    return (false);
}

void Droid::operator<<(size_t &to_load)
{
    size_t missing = 100 - this->_energy;

    if (to_load < 1 || this->_energy == 100)
        return;
    if (missing > to_load) {
        this->_energy += to_load;
        to_load = 0;
    } else {
        this->_energy += missing;
        to_load -= missing;
    }
}

std::ostream &operator<<(std::ostream &s, const Droid &d)
{
    s << "Droid '" << d.getId() << "', "
    << *d.getStatus() << ", " << d.getEnergy();
    return (s);
}

void Droid::operator=(const Droid &other)
{
    this->_id = other._id;
    this->_energy = other._energy;
    delete this->_status;
    this->_status = new std::string(other._status->c_str());
}
