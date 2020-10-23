/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** input_comp
*/

#include "../include/Component.hpp"

nts::input::input(std::string name)
{
    this->_puts_types.emplace(0, nts::OUTPUT);
    this->_puts.emplace(0, nts::UNDEFINED);
    this->_name = name;
    this->_type = nts::Componenttype::INPUTC;
}

nts::input::~input()
{
}

void nts::input::compute()
{
    if (_links.find(0) != _links.end() && _links.find(0)->second.getOut()->getName().compare(this->_name) != 0) {
        this->_links.find(0)->second.getOut()->setThisPutStatu(this->_links.find(0)->second.getOutNb(), _puts[0]);
        this->_links.find(0)->second.getOut()->compute();
    }
}

std::unique_ptr<nts::Component> nts::input::creatInput(const std::string &value)
{
    nts::Component *new_one = new nts::input(value.c_str());

    return (std::unique_ptr<nts::Component>(new_one));
}

void nts::input::dump() const
{
    std::cout << "input named: " << _name << std::endl;
}