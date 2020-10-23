/*
** EPITECH PROJECT, 2020
** interface
** File description:
** Plazza
*/

#ifndef IPIZZA_HPP_
#define IPIZZA_HPP_

#include <vector>
#include <ctime>
#include <chrono>
#include <string>

enum PizzaType {
    T_UNDEFINED = -1,
    REGINA = 1,
    MARGARITA = 2,
    AMERICANA = 4,
    FANTASIA = 8,
};
enum PizzaSize {
    S_UNDEFINED = -1,
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16,
};
enum ingredient {
    Doe,
    Ham,
    Steak,
    Tomato ,
    Eggplant,
    Chieflove,
    Gruyere,
    Mushrooms,
    Goatcheese
};

class Ipizza {
    public:
        virtual ~Ipizza() {};

        virtual PizzaType getType() const = 0;
        virtual PizzaSize getSize() const = 0;
        virtual std::vector<ingredient> getIngredient() const = 0;
        virtual bool isCook() const = 0;
        virtual long getTime() const = 0;

        virtual void setCook(bool &) = 0;
};

#endif /* !IPIZZA_HPP_ */
