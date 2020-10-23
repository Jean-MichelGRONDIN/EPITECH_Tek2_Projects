/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** comp4069
*/

#include "../include/Component.hpp"

nts::comp4069::comp4069(std::string name)
{
    this->_puts_types.emplace(0, nts::PutsType::INPUT);
    this->_puts_types.emplace(1, nts::PutsType::OUTPUT);
    this->_puts_types.emplace(2, nts::PutsType::INPUT);
    this->_puts_types.emplace(3, nts::PutsType::OUTPUT);
    this->_puts_types.emplace(4, nts::PutsType::INPUT);
    this->_puts_types.emplace(5, nts::PutsType::OUTPUT);
    this->_puts_types.emplace(6, nts::PutsType::UNUSED);
    this->_puts_types.emplace(7, nts::PutsType::OUTPUT);
    this->_puts_types.emplace(8, nts::PutsType::INPUT);
    this->_puts_types.emplace(9, nts::PutsType::OUTPUT);
    this->_puts_types.emplace(10, nts::PutsType::INPUT);
    this->_puts_types.emplace(11, nts::PutsType::OUTPUT);
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

    this->_parts.push_back(nts::not_Comp::creatNotComp(name + "not_numero0"));
    this->_parts.push_back(nts::not_Comp::creatNotComp(name + "not_numero1"));
    this->_parts.push_back(nts::not_Comp::creatNotComp(name + "not_numero2"));
    this->_parts.push_back(nts::not_Comp::creatNotComp(name + "not_numero3"));
    this->_parts.push_back(nts::not_Comp::creatNotComp(name + "not_numero4"));
    this->_parts.push_back(nts::not_Comp::creatNotComp(name + "not_numero5"));

    this->_name = name;
    this->_type = nts::Componenttype::C4069;
}

nts::comp4069::~comp4069()
{
}

void nts::comp4069::compute()
{
    size_t i = 0;

    for (i; i != 6; i++) {
        _parts[0]->setThisPutStatu(0, _puts[0]);
        _parts[0]->compute();
        _puts[1] = _parts[0]->getThisPutStatu(1);
        if (_links.find(1) != _links.end())
            _links.find(1)->second.getOut()->setThisPutStatu(this->_links.find(1)->second.getOutNb(), _puts[1]);
        if (_links.find(1) != _links.end() && _links.find(1)->second.getOut()->getName().compare(this->_name) != 0)
            _links.find(1)->second.getOut()->compute();

        _parts[1]->setThisPutStatu(0, _puts[2]);
        _parts[1]->compute();
        _puts[3] = _parts[1]->getThisPutStatu(1);
        if (_links.find(3) != _links.end())
            _links.find(3)->second.getOut()->setThisPutStatu(this->_links.find(3)->second.getOutNb(), _puts[3]);
        if (_links.find(3) != _links.end() && _links.find(3)->second.getOut()->getName().compare(this->_name) != 0)
            _links.find(3)->second.getOut()->compute();

        _parts[2]->setThisPutStatu(0, _puts[4]);
        _parts[2]->compute();
        _puts[5] = _parts[2]->getThisPutStatu(1);
        if (_links.find(5) != _links.end())
            _links.find(5)->second.getOut()->setThisPutStatu(this->_links.find(5)->second.getOutNb(), _puts[5]);
        if (_links.find(5) != _links.end() && _links.find(5)->second.getOut()->getName().compare(this->_name) != 0)
            _links.find(5)->second.getOut()->compute();

        _parts[3]->setThisPutStatu(0, _puts[8]);
        _parts[3]->compute();
        _puts[7] = _parts[3]->getThisPutStatu(1);
        if (_links.find(7) != _links.end())
            _links.find(7)->second.getOut()->setThisPutStatu(this->_links.find(7)->second.getOutNb(), _puts[7]);
        if (_links.find(7) != _links.end() && _links.find(7)->second.getOut()->getName().compare(this->_name) != 0)
            _links.find(7)->second.getOut()->compute();
            
        _parts[4]->setThisPutStatu(0, _puts[10]);
        _parts[4]->compute();
        _puts[9] = _parts[4]->getThisPutStatu(1);
        if (_links.find(9) != _links.end())
            _links.find(9)->second.getOut()->setThisPutStatu(this->_links.find(9)->second.getOutNb(), _puts[9]);
        if (_links.find(9) != _links.end() && _links.find(9)->second.getOut()->getName().compare(this->_name) != 0)
            _links.find(9)->second.getOut()->compute();

        _parts[5]->setThisPutStatu(0, _puts[12]);
        _parts[5]->compute();
        _puts[11] = _parts[5]->getThisPutStatu(1);
        if (_links.find(11) != _links.end())
            _links.find(11)->second.getOut()->setThisPutStatu(this->_links.find(11)->second.getOutNb(), _puts[11]);
        if (_links.find(11) != _links.end() && _links.find(11)->second.getOut()->getName().compare(this->_name) != 0)
            _links.find(11)->second.getOut()->compute();
    }
}

std::unique_ptr<nts::Component> nts::comp4069::creat4069Comp(const std::string &value)
{
    nts::Component *new_one = new nts::comp4069(value.c_str());

    return (std::unique_ptr<nts::Component>(new_one));
}

void nts::comp4069::dump() const
{
    std::cout << "not_gate named: " << _name << std::endl;
}