/*
** EPITECH PROJECT, 2020
** americana
** File description:
** pizza
*/

#ifndef AMERICANA_HPP_
#define AMERICANA_HPP_

#include "Ipizza.hpp"
#include "AbPizza.hpp"

class Americana : public AbPizza {
    public:
        Americana(PizzaSize const, int);
        ~Americana();
        PizzaType getType();
        PizzaSize getSize();
        std::vector<ingredient> getIngredient();
        long getTime();
        bool isCook();

        void setCook(bool &cook);
};

#endif /* !AMERICANA_HPP_ */
