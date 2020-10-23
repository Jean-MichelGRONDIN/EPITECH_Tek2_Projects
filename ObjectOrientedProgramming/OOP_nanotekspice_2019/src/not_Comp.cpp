/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** not_Comp
*/

#include "../include/Component.hpp"

nts::not_Comp::not_Comp(std::string name)
{
    this->_puts_types.emplace(0, nts::INPUT);
    this->_puts_types.emplace(1, nts::OUTPUT);
    this->_puts.emplace(0, nts::UNDEFINED);
    this->_puts.emplace(1, nts::UNDEFINED);
    this->_name = name;
    this->_type = nts::Componenttype::NOTC;
}

nts::not_Comp::~not_Comp()
{
}

void nts::not_Comp::compute()
{
    nts::Tristate state = nts::Tristate::UNDEFINED;

    if (_puts[0] == nts::Tristate::FALSE) {
        state = nts::Tristate::TRUE;
    } else {
        state = nts::FALSE;
    }
    this->setThisPutStatu(1, state);
    if (this->_links.find(1) != _links.end()) {
        this->_links.find(1)->second.getOut()->setThisPutStatu(this->_links.find(1)->second.getOutNb(), state);
        this->_links.find(1)->second.getOut()->compute();
    }
}

std::unique_ptr<nts::Component> nts::not_Comp::creatNotComp(const std::string &value)
{
    nts::Component *new_one = new nts::not_Comp(value.c_str());

    return (std::unique_ptr<nts::Component>(new_one));
}

void nts::not_Comp::dump() const
{
    std::cout << "not_gate named: " << _name << std::endl;
}