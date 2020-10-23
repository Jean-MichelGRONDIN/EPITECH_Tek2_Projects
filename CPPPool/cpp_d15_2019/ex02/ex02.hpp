/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex02
*/

#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>

template<typename T>
T min(T &one, T &two)
{
    std::cout << "template min" << std::endl;
    if (one > two)
        return (two);
    return (one);
}

int min(int one, int two)
{
    std::cout << "non-template min" << std::endl;
    if (one > two)
        return (two);
    return (one);
}

template<typename T>
T templateMin(T *tab, int size)
{
    int i = 1;
    T res;

    res = tab[0];
    while (i != size) {
        res = min<T>(tab[i], res);
        i++;
    }
    return (res);
}

int nonTemplateMin(int *tab, int size)
{
    int i = 1;
    int res;

    res = tab[0];
    while (i != size) {
        res = min(tab[i], res);
        i++;
    }
    return (res);
}

#endif