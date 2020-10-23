/*
** EPITECH PROJECT, 2020
** pizza
** File description:
** Plazza
*/

#ifndef REGINA_HPP_
#define REGINA_HPP_

#include "Ipizza.hpp"
#include "AbPizza.hpp"

class Regina : public AbPizza {
    public:
        Regina(PizzaSize const, int);
        ~Regina();
        
        PizzaType getType();
        PizzaSize getSize();
        std::vector<ingredient> getIngredient();
        long getTime();
        bool isCook();

        void setCook(bool &cook);
};

#endif /* !REGINA_HPP_ */