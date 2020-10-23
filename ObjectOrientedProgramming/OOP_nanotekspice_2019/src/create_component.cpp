/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** create_component
*/

#include "../include/nanotekspice.hpp"

static std::unique_ptr<nts::Component> list_find(const std::string &type,
    const std::string &value)
{
    if (type.compare("and") == 0)
        return (nts::and_Comp::creatAndComp(value));
    if (type.compare("or") == 0)
        return (nts::or_Comp::creatOrComp(value));
    if (type.compare("xor") == 0)
        return (nts::xor_Comp::creatXorComp(value));
    if (type.compare("nand") == 0)
        return (nts::nand_Comp::creatNandComp(value));
    if (type.compare("nor") == 0)
        return (nts::nor_Comp::creatNorComp(value));
    if (type.compare("xnor") == 0)
        return (nts::xnor_Comp::creatXnorComp(value));
    if (type.compare("not") == 0)
        return (nts::not_Comp::creatNotComp(value));
    if (type.compare("4081") == 0)
        return (nts::comp4081::creat4081Comp(value));
    if (type.compare("4071") == 0)
        return (nts::comp4071::creat4071Comp(value));
    if (type.compare("4011") == 0)
        return (nts::comp4011::creat4011Comp(value));
    if (type.compare("4001") == 0)
        return (nts::comp4001::creat4001Comp(value));
    if (type.compare("4030") == 0)
        return (nts::comp4030::creat4030Comp(value));
    if (type.compare("4069") == 0)
        return (nts::comp4069::creat4069Comp(value));
    if (type.compare("4013") == 0)
        return (nts::comp4013::creat4013Comp(value));
    if (type.compare("input") == 0)
        return (nts::input::creatInput(value));
    if (type.compare("true") == 0)
        return (nts::trueC::creatTrue(value));
    if (type.compare("false") == 0)
        return (nts::falseC::creatFalse(value));
    if (type.compare("output") == 0)
        return (nts::output::creatOutput(value));
    if (type.compare("clock") == 0)
        return (nts::clock::creatClock(value));
    return (nullptr);
}

std::unique_ptr<nts::Component> createComponent(const std::string &type
    ,const std::string &value)
{
    std::unique_ptr<nts::Component> res = list_find(type, value);

    return (res);
}