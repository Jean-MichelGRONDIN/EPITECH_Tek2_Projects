/*
** EPITECH PROJECT, 2020
** fantasia
** File description:
** Plazza
*/

#include "Fantasia.hpp"

Fantasia::Fantasia(PizzaSize const size, int mul)
{
    _cook = false;
    _type = FANTASIA;
    _needed_time = mul * 4.0;

    _size = size;
}

Fantasia::~Fantasia()
{
}

PizzaType Fantasia::getType() {return _type;};
PizzaSize Fantasia::getSize() {return _size;};
std::vector<ingredient> Fantasia::getIngredient() {return v_ingredient;};
long Fantasia::getTime() {return _time;};
bool Fantasia::isCook() {return _cook;};

void Fantasia::setCook(bool &cook) {_cook = cook;};