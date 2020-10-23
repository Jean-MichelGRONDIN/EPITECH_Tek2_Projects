/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** output_comp
*/

#include "../include/Component.hpp"

nts::output::output(std::string name)
{
    this->_puts_types.emplace(0, nts::INPUT);
    this->_puts.emplace(0, nts::UNDEFINED);
    this->_name = name;
    this->_type = nts::Componenttype::OUTPUTC;
}

nts::output::~output()
{
}

void nts::output::print_compute()
{
    std::cout << this->getName() << "="
    << (this->getThisPutStatu(0) == nts::TRUE ? 1 : 0)
    << std::endl;
}

std::unique_ptr<nts::Component> nts::output::creatOutput(const std::string &value)
{
    nts::Component *new_one = new nts::output(value.c_str());

    return (std::unique_ptr<nts::Component>(new_one));
}

void nts::output::dump() const
{
    std::cout << "output named: " << _name << std::endl;
}