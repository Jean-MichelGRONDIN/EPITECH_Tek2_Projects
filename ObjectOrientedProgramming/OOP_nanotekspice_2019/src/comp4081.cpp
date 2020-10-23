/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** comp4081
*/

#include "../include/Component.hpp"

nts::comp4081::comp4081(std::string name)
{
    this->_puts_types.emplace(0, nts::PutsType::INPUT);
    this->_puts_types.emplace(1, nts::PutsType::INPUT);
    this->_puts_types.emplace(2, nts::PutsType::OUTPUT);
    this->_puts_types.emplace(3, nts::PutsType::OUTPUT);
    this->_puts_types.emplace(4, nts::PutsType::INPUT);
    this->_puts_types.emplace(5, nts::PutsType::INPUT);
    this->_puts_types.emplace(6, nts::PutsType::UNUSED);
    this->_puts_types.emplace(7, nts::PutsType::INPUT);
    this->_puts_types.emplace(8, nts::PutsType::INPUT);
    this->_puts_types.emplace(9, nts::PutsType::OUTPUT);
    this->_puts_types.emplace(10, nts::PutsType::OUTPUT);
    this->_puts_types.emplace(11, nts::PutsType::INPUT);
    this->_puts_types.emplace(12, nts::PutsType::INPUT);
    this->_puts_types.emplace(13, nts::PutsType::UNUSED);

    this->_puts.emplace(0, nts::UNDEFINED);
    this->_puts.emplace(1, nts::UNDEFINED);
    this->_puts.emplace(2, nts::UNDEFINED);
    this->_puts.emplace(3, nts::UNDEFINED);
    this->_puts.emplace(4, nts::UNDEFINED);
    this->_puts.emplace(5, nts::UNDEFINED);
    this->_puts.emplace(7, nts::UNDEFINED);
    this->_puts.emplace(8, nts::UNDEFINED);
    this->_puts.emplace(9, nts::UNDEFINED);
    this->_puts.emplace(10, nts::UNDEFINED);
    this->_puts.emplace(11, nts::UNDEFINED);
    this->_puts.emplace(12, nts::UNDEFINED);

    this->_parts.push_back(nts::and_Comp::creatAndComp(name + "and_numero0"));
    this->_parts.push_back(nts::and_Comp::creatAndComp(name + "and_numero1"));
    this->_parts.push_back(nts::and_Comp::creatAndComp(name + "and_numero2"));
    this->_parts.push_back(nts::and_Comp::creatAndComp(name + "and_numero3"));

    this->_name = name;
    this->_type = nts::Componenttype::C4081;
}

nts::comp4081::~comp4081()
{
}

void nts::comp4081::compute()
{
    size_t i = 0;

    for (i; i != 4; i++) {
        _parts[0]->setThisPutStatu(0, _puts[0]);
        _parts[0]->setThisPutStatu(1, _puts[1]);
        _parts[0]->compute();
        _puts[2] = _parts[0]->getThisPutStatu(2);
        if (_links.find(2) != _links.end())
            _links.find(2)->second.getOut()->setThisPutStatu(this->_links.find(2)->second.getOutNb(), _puts[2]);
        if (_links.find(2) != _links.end() && _links.find(2)->second.getOut()->getName().compare(this->_name) != 0)
            _links.find(2)->second.getOut()->compute();

        _parts[1]->setThisPutStatu(0, _puts[4]);
        _parts[1]->setThisPutStatu(1, _puts[5]);
        _parts[1]->compute();
        _puts[3] = _parts[1]->getThisPutStatu(2);
        if (_links.find(3) != _links.end())
            _links.find(3)->second.getOut()->setThisPutStatu(this->_links.find(3)->second.getOutNb(), _puts[3]);
        if (_links.find(3) != _links.end() && _links.find(3)->second.getOut()->getName().compare(this->_name) != 0)
            _links.find(3)->second.getOut()->compute();

        _parts[2]->setThisPutStatu(0, _puts[7]);
        _parts[2]->setThisPutStatu(1, _puts[8]);
        _parts[2]->compute();
        _puts[9] = _parts[2]->getThisPutStatu(2);
        if (_links.find(9) != _links.end())
            _links.find(9)->second.getOut()->setThisPutStatu(this->_links.find(9)->second.getOutNb(), _puts[9]);
        if (_links.find(9) != _links.end() && _links.find(9)->second.getOut()->getName().compare(this->_name) != 0)
            _links.find(9)->second.getOut()->compute();

        _parts[3]->setThisPutStatu(0, _puts[11]);
        _parts[3]->setThisPutStatu(1, _puts[12]);
        _parts[3]->compute();
        _puts[10] = _parts[3]->getThisPutStatu(2);
        if (_links.find(10) != _links.end())
            _links.find(10)->second.getOut()->setThisPutStatu(this->_links.find(10)->second.getOutNb(), _puts[10]);
        if (_links.find(10) != _links.end() && _links.find(10)->second.getOut()->getName().compare(this->_name) != 0)
            _links.find(10)->second.getOut()->compute();
    }
}

std::unique_ptr<nts::Component> nts::comp4081::creat4081Comp(const std::string &value)
{
    nts::Component *new_one = new nts::comp4081(value.c_str());

    return (std::unique_ptr<nts::Component>(new_one));
}

void nts::comp4081::dump() const
{
    std::cout << "and_gate named: " << _name << std::endl;
}