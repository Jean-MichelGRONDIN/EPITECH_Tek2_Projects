/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** PizzaFactory
*/

#include "PizzaFactory.hpp"
#include "Regina.hpp"
#include "Americana.hpp"
#include "Fantasia.hpp"
#include "Margarita.hpp"
#include <iostream>

AbPizza *PizzaFactory::NewPizza(const std::string& type,
    const std::string& size, const double& mul)
{
    if (type == "Americana")
        return (new Americana(AbPizza::strToPizSize(size), mul));
    if (type == "Regina")
        return (new Regina(AbPizza::strToPizSize(size), mul));
    if (type == "Fantasia")
        return (new Fantasia(AbPizza::strToPizSize(size), mul));
    if (type == "Margarita")
        return (new Margarita(AbPizza::strToPizSize(size), mul));
    return (nullptr);
}