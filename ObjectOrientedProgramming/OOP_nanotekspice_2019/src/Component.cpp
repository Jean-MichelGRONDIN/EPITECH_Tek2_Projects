/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Component
*/

#include "../include/nanotekspice.hpp"

nts::Component::Component()
{
}

nts::Component::~Component()
{
}

void nts::Component::addLink(size_t put, nts::Cable &link)
{
    this->_links.emplace(put, link);
}

void nts::Component::compute()
{
}

void nts::Component::dump() const
{
}

nts::Tristate nts::Component::getThisPutStatu(size_t n)
{
    if (this->_puts.find(n) != _puts.end()) {
        return (this->_puts.find(n)->second);
    }
    throw MyError("Error try to acces invalid pin !");
}

void nts::Component::setThisPutStatu(size_t n, nts::Tristate statu)
{
    if (this->_puts.find(n) != _puts.end()) {
        this->_puts[n] = statu;
    }
}

std::string nts::Component::getName() const
{
    return (this->_name);
}

void nts::Component::setName(std::string new_name)
{
    this->_name = new_name;
}

nts::Componenttype nts::Component::getComponentType() const
{
    return (this->_type);
}

void nts::Component::print_compute()
{
}

nts::PutsType& nts::Component::getThisPutType(size_t n)
{
    if (this->_puts_types.find(n) != _puts_types.end()) {
        return (this->_puts_types.find(n)->second);
    }
    throw MyError("Error try to acces invalid pin !");
}