/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex04
*/

#ifndef EX04_HPP_
#define EX04_HPP_

#include <string>

template<typename T>
bool equal(const T &one, const T &two);

template<typename T>
class Tester
{
    public:
        bool equal(const T &one, const T &two) const;
};

#endif