/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** trueC_comp
*/

#include "../include/Component.hpp"

nts::trueC::trueC(std::string name)
{
    this->_puts_types.emplace(0, nts::OUTPUT);
    this->_puts.emplace(0, nts::Tristate::TRUE);
    this->_name = name;
    this->_type = nts::Componenttype::TRUEC;
}

nts::trueC::~trueC()
{
}

void nts::trueC::compute()
{
    if (_links.find(0) != _links.end() && _links.find(0)->second.getOut()->getName().compare(this->_name) != 0) {
        this->_links.find(0)->second.getOut()->setThisPutStatu(this->_links.find(0)->second.getOutNb(), nts::Tristate::TRUE);
        this->_links.find(0)->second.getOut()->compute();
    }
}

std::unique_ptr<nts::Component> nts::trueC::creatTrue(const std::string &value)
{
    nts::Component *new_one = new nts::trueC(value.c_str());

    return (std::unique_ptr<nts::Component>(new_one));
}

void nts::trueC::dump() const
{
    std::cout << "trueComponent named: " << _name << std::endl;
}