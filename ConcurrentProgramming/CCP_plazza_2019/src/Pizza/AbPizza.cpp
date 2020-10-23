/*
** EPITECH PROJECT, 2020
** abpizza
** File description:
** Plazza
*/

#include <iostream>
#include "AbPizza.hpp"
#include "Regina.hpp"
#include "Americana.hpp"
#include "Fantasia.hpp"
#include "Margarita.hpp"
#include "PizzaFactory.hpp"
#include "../plazza.hpp"

AbPizza::AbPizza()
{
    _cook = false;
    _type = T_UNDEFINED;
    _needed_time = 0;
    _size = S_UNDEFINED;
}

AbPizza::~AbPizza()
{
}

PizzaType AbPizza::getType() const {return _type;};
PizzaSize AbPizza::getSize() const {return _size;};
std::vector<ingredient> AbPizza::getIngredient() const {return v_ingredient;};
long AbPizza::getTime() const {return _time;};
bool AbPizza::isCook() const {return _cook;};

void AbPizza::setCook(bool &cook) {_cook = cook;};


AbPizza *AbPizza::unpack(std::string str, double mul)
{
    std::vector<std::string> t = Plazza::explode(str, ' ');
    return (PizzaFactory::NewPizza(t[0], t[1], mul));
}

std::string AbPizza::getPizTypStr(PizzaType type)
{
    switch (type)
    {
    case (PizzaType::REGINA):
        return ("Regina");
        break;
    case (PizzaType::MARGARITA):
        return ("Margarita");
        break;
    case (PizzaType::AMERICANA):
        return ("Americana");
        break;
    case (PizzaType::FANTASIA):
        return ("Fantasia");
        break;
    default:
        return ("Type undefined");
        break;
    }
}

std::string AbPizza::getPizSizStr(PizzaSize size)
{
    switch (size)
    {
    case (PizzaSize::S):
        return ("S");
        break;
    case (PizzaSize::M):
        return ("M");
        break;
    case (PizzaSize::L):
        return ("L");
        break;
    case (PizzaSize::XL):
        return ("XL");
        break;
    case (PizzaSize::XXL):
        return ("XXL");
        break;
    default:
        return ("Size undefined");
        break;
    }
}

PizzaType AbPizza::strToPizType(std::string type)
{
    if (type == "Regina")
        return (PizzaType::REGINA);
    if (type == "Margarita")
        return (PizzaType::MARGARITA);
    if (type == "Americana")
        return (PizzaType::AMERICANA);
    if (type == "Fantasia")
        return (PizzaType::FANTASIA);
    return (PizzaType::T_UNDEFINED);
}

PizzaSize AbPizza::strToPizSize(std::string size)
{
    if (size == "S")
        return (PizzaSize::S);
    if (size == "M")
        return (PizzaSize::M);
    if (size == "L")
        return (PizzaSize::L);
    if (size == "XL")
        return (PizzaSize::XL);
    if (size == "XXL")
        return (PizzaSize::XXL);
    return (PizzaSize::S_UNDEFINED);
}


std::string AbPizza::pack(AbPizza *piz)
{
    std::string ret = AbPizza::getPizTypStr(piz->getType()) + " " + AbPizza::getPizSizStr(piz->getSize());
    return (ret);
}