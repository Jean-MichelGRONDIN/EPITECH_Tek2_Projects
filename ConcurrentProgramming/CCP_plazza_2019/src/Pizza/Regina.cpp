/*
** EPITECH PROJECT, 2020
** regina
** File description:
** Plazza
*/

#include "Regina.hpp"

Regina::Regina(PizzaSize const size, int mul)
{
    _cook = false;
    _type = REGINA;
    _needed_time = mul * 2.0;

    _size = size;
}

Regina::~Regina()
{
}

PizzaType Regina::getType() {return _type;};
PizzaSize Regina::getSize() {return _size;};
std::vector<ingredient> Regina::getIngredient() {return v_ingredient;};
long Regina::getTime() {return _time;};
bool Regina::isCook() {return _cook;};

void Regina::setCook(bool &cook) {_cook = cook;};