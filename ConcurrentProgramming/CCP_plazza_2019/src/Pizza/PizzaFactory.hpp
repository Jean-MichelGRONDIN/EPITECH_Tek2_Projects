/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** PizzaFactory
*/

#ifndef PIZZAFACTORY_HPP_
#define PIZZAFACTORY_HPP_

#include <memory>

#include "AbPizza.hpp"

class PizzaFactory {
    public:
        static AbPizza *NewPizza(const std::string& type,
            const std::string& size, const double& mul);

    protected:
    private:
};

#endif