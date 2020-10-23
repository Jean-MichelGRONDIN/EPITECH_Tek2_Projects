/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Sorcerer
*/

#ifndef SORCERER_HPP_
#define SORCERER_HPP_

#include <string>
#include <iostream>
#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer {
    public:
        Sorcerer(std::string name, std::string title);
        ~Sorcerer();
        std::string getname() const;
        std::string gettitle() const;
        void polymorph(const Victim &victim) const;
        void polymorph(const Peon &peon) const;

    protected:
    private:
        std::string _name;
        std::string _title;
};

std::ostream &operator<<(std::ostream &s, Sorcerer obj);

#endif