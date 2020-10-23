/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** clock_comp
*/

#include "../include/Component.hpp"

nts::clock::clock(std::string name)
{
    this->_puts_types.emplace(0, nts::OUTPUT);
    this->_puts.emplace(0, nts::Tristate::UNDEFINED);
    this->_name = name;
    this->_type = nts::Componenttype::CLOCKC;
}

nts::clock::~clock()
{
}

void nts::clock::compute()
{
    if (_links.find(0) != _links.end() && _links.find(0)->second.getOut()->getName().compare(this->_name) != 0) {
        this->_links.find(0)->second.getOut()->setThisPutStatu(this->_links.find(0)->second.getOutNb(), _puts[0]);
        this->_links.find(0)->second.getOut()->compute();
    }
    if (_puts[0] == nts::Tristate::TRUE) {
        _puts[0] = nts::Tristate::FALSE;
    } else {
        _puts[0] = nts::Tristate::TRUE;
    }
}

std::unique_ptr<nts::Component> nts::clock::creatClock(const std::string &value)
{
    nts::Component *new_one = new nts::clock(value.c_str());

    return (std::unique_ptr<nts::Component>(new_one));
}

void nts::clock::dump() const
{
    std::cout << "clock named: " << _name << std::endl;
}