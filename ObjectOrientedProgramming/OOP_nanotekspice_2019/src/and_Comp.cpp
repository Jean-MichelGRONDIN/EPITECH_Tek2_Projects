/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Gates_Components
*/

#include "../include/Component.hpp"

nts::and_Comp::and_Comp(std::string name)
{
    this->_puts_types.emplace(0, nts::INPUT);
    this->_puts_types.emplace(1, nts::INPUT);
    this->_puts_types.emplace(2, nts::OUTPUT);
    this->_puts.emplace(0, nts::UNDEFINED);
    this->_puts.emplace(1, nts::UNDEFINED);
    this->_puts.emplace(2, nts::UNDEFINED);
    this->_name = name;
    this->_type = nts::Componenttype::ANDC;
}

nts::and_Comp::~and_Comp()
{
}

void nts::and_Comp::compute()
{
    nts::Tristate state = nts::Tristate::UNDEFINED;

    if (_puts[0] == nts::Tristate::TRUE && _puts[1] == nts::Tristate::TRUE) {
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

std::unique_ptr<nts::Component> nts::and_Comp::creatAndComp(const std::string &value)
{
    nts::Component *new_one = new nts::and_Comp(value.c_str());

    return (std::unique_ptr<nts::Component>(new_one));
}

void nts::and_Comp::dump() const
{
    std::cout << "and_gate named: " << _name << std::endl;
}