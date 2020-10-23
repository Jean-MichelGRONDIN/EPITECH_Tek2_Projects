/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Cable
*/

#include "../include/Component.hpp"

nts::Cable::Cable()
{
    this->_in = nullptr;
    this->_in_nb = 0;
    this->_out = nullptr;
    this->_out_nb = 0;
}

nts::Cable::~Cable()
{
}

void nts::Cable::setIn(Component *in, size_t in_nb)
{
    this->_in = in;
    this->_in_nb = in_nb;
}

void nts::Cable::setOut(Component *out, size_t out_nb)
{
    this->_out = out;
    this->_out_nb = out_nb;
}

nts::Component *nts::Cable::getIn() const
{
    return (this->_in);
}

nts::Component *nts::Cable::getOut() const
{
    return (this->_out);
}

size_t nts::Cable::getInNb() const
{
    return (this->_in_nb);
}

size_t nts::Cable::getOutNb() const
{
    return (this->_out_nb);
}

void nts::Cable::dumb() const
{
    std::cout << "Cable from " << this->_in->getName() << " port: " <<
    this->getInNb() << ", to " << this->_out->getName() << " port: " <<
    this->getOutNb() << std::endl;
}