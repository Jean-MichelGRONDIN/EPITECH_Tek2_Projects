/*
** EPITECH PROJECT, 2020
** fantasia
** File description:
** pizza
*/

#ifndef FANTASIA_HPP_
#define FANTASIA_HPP_

#include "Ipizza.hpp"
#include "AbPizza.hpp"

class Fantasia : public AbPizza {
    public:
        Fantasia(PizzaSize const, int);
        ~Fantasia();
        PizzaType getType();
        PizzaSize getSize();
        std::vector<ingredient> getIngredient();
        long getTime();
        bool isCook();

        void setCook(bool &cook);
};

#endif /* !FANTASIA_HPP_ */
