/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Espace de travail)
** File description:
** AbPizza
*/

#ifndef ABPIZZA_HPP_
#define ABPIZZA_HPP_

#include <vector>
#include <ctime>
#include <chrono>
#include <string>
#include <string.h>
#include "Ipizza.hpp"

class AbPizza : public Ipizza {
    public:
        AbPizza();
        virtual ~AbPizza();
        virtual PizzaType getType() const;
        virtual PizzaSize getSize() const;
        virtual std::vector<ingredient> getIngredient() const;
        virtual bool isCook() const;
        virtual long getTime() const;

        virtual void setCook(bool &);
        static AbPizza *unpack(std::string str, double);
        static std::string pack(AbPizza *piz);
        static std::string getPizTypStr(PizzaType type);
        static std::string getPizSizStr(PizzaSize size);
        static PizzaSize strToPizSize(std::string size);
        static PizzaType strToPizType(std::string type);
    protected:
        bool _cook;
        PizzaType _type;
        PizzaSize _size;
        double _needed_time;
        long _time;
        std::chrono::system_clock _clock;
        std::vector<ingredient> v_ingredient;
    private:
};
#endif /* !ABPIZZA_HPP_ */
