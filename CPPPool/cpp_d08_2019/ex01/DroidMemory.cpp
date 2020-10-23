/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
{
}

DroidMemory::~DroidMemory()
{
}

size_t DroidMemory::getFingerprint()
{
    return (this->_Fingerprint);
}

size_t DroidMemory::getExp()
{
    return (this->_Exp);
}

void DroidMemory::setFingerprint(size_t Fingerprint)
{
    this->_Fingerprint = Fingerprint;
}

void DroidMemory::setExp(size_t Exp)
{
    this->_Exp = Exp;
}

void DroidMemory::operator<<(size_t added_xp)
{
    this->_Exp += added_xp;
}

void DroidMemory::operator+=(DroidMemory &other)
{
    this->_Exp += other.getExp();
}

void DroidMemory::operator+=(size_t added_xp)
{
    this->_Exp += added_xp;
}

void operator>>(size_t added_xp, DroidMemory &dm)
{
    dm.setExp(dm.getExp() + added_xp);
}