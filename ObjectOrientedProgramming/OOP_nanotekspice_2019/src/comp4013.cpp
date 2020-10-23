/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** comp4013
*/

#include "../include/Component.hpp"

nts::comp4013::comp4013(std::string name)
{
    this->_puts_types.emplace(0, nts::PutsType::INPUT);
    this->_puts_types.emplace(1, nts::PutsType::INPUT);
    this->_puts_types.emplace(2, nts::PutsType::INPUT);
    this->_puts_types.emplace(3, nts::PutsType::INPUT);
    this->_puts_types.emplace(4, nts::PutsType::OUTPUT);
    this->_puts_types.emplace(5, nts::PutsType::OUTPUT);
    this->_puts_types.emplace(6, nts::PutsType::UNUSED);
    this->_puts_types.emplace(7, nts::PutsType::INPUT);
    this->_puts_types.emplace(8, nts::PutsType::INPUT);
    this->_puts_types.emplace(9, nts::PutsType::INPUT);
    this->_puts_types.emplace(10, nts::PutsType::INPUT);
    this->_puts_types.emplace(11, nts::PutsType::OUTPUT);
    this->_puts_types.emplace(12, nts::PutsType::OUTPUT);
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
    this->_parts.push_back(nts::and_Comp::creatAndComp(name + "and_numero0"));
    this->_parts.push_back(nts::and_Comp::creatAndComp(name + "and_numero1"));
    this->_parts.push_back(nts::nor_Comp::creatNorComp(name + "nor_numero0"));
    this->_parts.push_back(nts::nor_Comp::creatNorComp(name + "nor_numero1"));

    this->_parts.push_back(nts::not_Comp::creatNotComp(name + "not_numero1"));
    this->_parts.push_back(nts::and_Comp::creatAndComp(name + "and_numero2"));
    this->_parts.push_back(nts::and_Comp::creatAndComp(name + "and_numero3"));
    this->_parts.push_back(nts::nor_Comp::creatNorComp(name + "nor_numero2"));
    this->_parts.push_back(nts::nor_Comp::creatNorComp(name + "nor_numero3"));

    this->_name = name;
    this->_type = nts::Componenttype::C4013;
}

nts::comp4013::~comp4013()
{
}

void nts::comp4013::compute()
{
    size_t i = 0;
    size_t i_s = 0;

    for (i; i != 4; i++) {
        _parts[0]->setThisPutStatu(0, _puts[0]);
        _parts[0]->compute();

        _parts[1]->setThisPutStatu(0, _parts[0]->getThisPutStatu(1));
        _parts[1]->setThisPutStatu(1, _puts[1]);
        _parts[1]->compute();

        _parts[2]->setThisPutStatu(0, _puts[2]);
        _parts[2]->setThisPutStatu(1, _puts[3]);
        _parts[2]->compute();

        for (i_s; i_s != 2; i_s++) {
            _parts[3]->setThisPutStatu(0, _parts[1]->getThisPutStatu(2));
            _parts[3]->setThisPutStatu(1, _parts[4]->getThisPutStatu(2));
            _parts[3]->compute();

            _parts[4]->setThisPutStatu(0, _parts[3]->getThisPutStatu(2));
            _parts[4]->setThisPutStatu(1, _parts[2]->getThisPutStatu(2));
            _parts[4]->compute();
        }

        _puts[4] = _parts[4]->getThisPutStatu(2);
        if (_links.find(4) != _links.end())
            _links.find(4)->second.getOut()->setThisPutStatu(this->_links.find(4)->second.getOutNb(), _puts[4]);
        if (_links.find(4) != _links.end() && _links.find(4)->second.getOut()->getName().compare(this->_name) != 0)
            _links.find(4)->second.getOut()->compute();

        _puts[5] = _parts[3]->getThisPutStatu(2);
        if (_links.find(5) != _links.end())
            _links.find(5)->second.getOut()->setThisPutStatu(this->_links.find(5)->second.getOutNb(), _puts[5]);
        if (_links.find(5) != _links.end() && _links.find(5)->second.getOut()->getName().compare(this->_name) != 0)
            _links.find(5)->second.getOut()->compute();

        _parts[5]->setThisPutStatu(0, _puts[7]);
        _parts[5]->compute();

        _parts[6]->setThisPutStatu(0, _parts[5]->getThisPutStatu(1));
        _parts[6]->setThisPutStatu(1, _puts[8]);
        _parts[6]->compute();

        _parts[7]->setThisPutStatu(0, _puts[9]);
        _parts[7]->setThisPutStatu(1, _puts[10]);
        _parts[7]->compute();

        for (i_s; i_s != 2; i_s++) {
            _parts[8]->setThisPutStatu(0, _parts[6]->getThisPutStatu(2));
            _parts[8]->setThisPutStatu(1, _parts[9]->getThisPutStatu(2));
            _parts[8]->compute();

            _parts[9]->setThisPutStatu(0, _parts[8]->getThisPutStatu(2));
            _parts[9]->setThisPutStatu(1, _parts[7]->getThisPutStatu(2));
            _parts[9]->compute();
        }

        _puts[11] = _parts[9]->getThisPutStatu(2);
        if (_links.find(11) != _links.end())
            _links.find(11)->second.getOut()->setThisPutStatu(this->_links.find(11)->second.getOutNb(), _puts[11]);
        if (_links.find(11) != _links.end() && _links.find(11)->second.getOut()->getName().compare(this->_name) != 0)
            _links.find(11)->second.getOut()->compute();

        _puts[12] = _parts[8]->getThisPutStatu(2);
        if (_links.find(12) != _links.end())
            _links.find(12)->second.getOut()->setThisPutStatu(this->_links.find(12)->second.getOutNb(), _puts[12]);
        if (_links.find(12) != _links.end() && _links.find(12)->second.getOut()->getName().compare(this->_name) != 0)
            _links.find(12)->second.getOut()->compute();
    }
}

std::unique_ptr<nts::Component> nts::comp4013::creat4013Comp(const std::string &value)
{
    nts::Component *new_one = new nts::comp4013(value.c_str());

    return (std::unique_ptr<nts::Component>(new_one));
}

void nts::comp4013::dump() const
{
    std::cout << "dlatchComponent named: " << _name << std::endl;
}