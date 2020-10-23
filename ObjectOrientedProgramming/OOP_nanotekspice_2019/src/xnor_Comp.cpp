/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** xnor_Comp
*/

#include "../include/Component.hpp"

nts::xnor_Comp::xnor_Comp(std::string name)
{
    this->_puts_types.emplace(0, nts::INPUT);
    this->_puts_types.emplace(1, nts::INPUT);
    this->_puts_types.emplace(2, nts::OUTPUT);
    this->_puts.emplace(0, nts::UNDEFINED);
    this->_puts.emplace(1, nts::UNDEFINED);
    this->_puts.emplace(2, nts::UNDEFINED);
    this->_name = name;
    this->_type = nts::Componenttype::XNORC;
}

nts::xnor_Comp::~xnor_Comp()
{
}

void nts::xnor_Comp::compute()
{
    nts::Tristate state = nts::Tristate::UNDEFINED;

    if ((_puts[0] == _puts[1] && _puts[0] != nts::Tristate::UNDEFINED)) {
        state = nts::Tristate::TRUE;
    } else {
        state = nts::FALSE;
    }
    this->setThisPutStatu(2, state);
    if (this->_links.find(2) != _links.end()) {
        this->_links.find(2)->second.getOut()->setThisPutStatu(this->_links.find(2)->second.getOutNb(), state);
        this->_links.find(2)->second.getOut()->compute();
    }
}

std::unique_ptr<nts::Component> nts::xnor_Comp::creatXnorComp(const std::string &value)
{
    nts::Component *new_one = new nts::xnor_Comp(value.c_str());

    return (std::unique_ptr<nts::Component>(new_one));
}

void nts::xnor_Comp::dump() const
{
    std::cout << "xnor_gate named: " << _name << std::endl;
}