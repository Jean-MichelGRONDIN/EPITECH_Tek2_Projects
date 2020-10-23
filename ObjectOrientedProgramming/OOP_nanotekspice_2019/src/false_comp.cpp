/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** falseC_comp
*/

#include "../include/Component.hpp"

nts::falseC::falseC(std::string name)
{
    this->_puts_types.emplace(0, nts::OUTPUT);
    this->_puts.emplace(0, nts::Tristate::FALSE);
    this->_name = name;
    this->_type = nts::Componenttype::FALSEC;
}

nts::falseC::~falseC()
{
}

void nts::falseC::compute()
{
    if (_links.find(0) != _links.end() && _links.find(0)->second.getOut()->getName().compare(this->_name) != 0) {
        this->_links.find(0)->second.getOut()->setThisPutStatu(this->_links.find(0)->second.getOutNb(), nts::Tristate::FALSE);
        this->_links.find(0)->second.getOut()->compute();
    }
}

std::unique_ptr<nts::Component> nts::falseC::creatFalse(const std::string &value)
{
    nts::Component *new_one = new nts::falseC(value.c_str());

    return (std::unique_ptr<nts::Component>(new_one));
}

void nts::falseC::dump() const
{
    std::cout << "falseComponent named: " << _name << std::endl;
}