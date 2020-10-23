/*
** EPITECH PROJECT, 2020
** margarita
** File description:
** Plazza
*/

#include "Margarita.hpp"

Margarita::Margarita(PizzaSize const size, int mul)
{
    _cook = false;
    _type = MARGARITA;
    _needed_time = mul * 1.0;

    _size = size;
}

Margarita::~Margarita()
{
}

PizzaType Margarita::getType() {return _type;};
PizzaSize Margarita::getSize() {return _size;};
std::vector<ingredient> Margarita::getIngredient() {return v_ingredient;};
long Margarita::getTime() {return _time;};
bool Margarita::isCook() {return _cook;};

void Margarita::setCook(bool &cook) {_cook = cook;};