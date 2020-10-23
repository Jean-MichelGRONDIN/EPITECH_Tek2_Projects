/*
** EPITECH PROJECT, 2020
** margarita
** File description:
** pizza
*/

#ifndef MARGARITA_HPP_
#define MARGARITA_HPP_

#include "Ipizza.hpp"
#include "AbPizza.hpp"

class Margarita : public AbPizza {
    public:
        Margarita(PizzaSize const, int);
        ~Margarita();
        PizzaType getType();
        PizzaSize getSize();
        std::vector<ingredient> getIngredient();
        long getTime();
        bool isCook();

        void setCook(bool &cook);
};

#endif /* !MARGARITA_HPP_ */
