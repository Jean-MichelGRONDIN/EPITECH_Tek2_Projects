/*
** EPITECH PROJECT, 2020
** americana
** File description:
** Plazza
*/

#include "Americana.hpp"

Americana::Americana(PizzaSize const size, int mul)
{
    _cook = false;
    _type = AMERICANA;
    _needed_time = mul * 2.0;

    _size = size;
}

Americana::~Americana()
{
}

PizzaType Americana::getType() {return _type;};
PizzaSize Americana::getSize() {return _size;};
std::vector<ingredient> Americana::getIngredient() {return v_ingredient;};
long Americana::getTime() {return _time;};
bool Americana::isCook() {return _cook;};

void Americana::setCook(bool &cook) {_cook = cook;};
