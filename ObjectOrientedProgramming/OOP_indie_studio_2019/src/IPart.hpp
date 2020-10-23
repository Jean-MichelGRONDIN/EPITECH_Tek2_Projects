/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Part
*/

#ifndef PART_HPP_
#define PART_HPP_

#include "IrrWindow.hpp"

class IPart {
    public:
        virtual void loadAll() = 0;
        virtual void releaseAll() = 0;
        virtual int getRet() = 0;
        virtual int &getRetRef() = 0;
};

#endif /* !PART_HPP_ */
