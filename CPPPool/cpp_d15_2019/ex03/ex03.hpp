/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex03
*/

#ifndef EX03_HPP_
#define EX03_HPP_

#include <iostream>

template<typename T>
void print(const T &obj)
{
    std::cout << obj << std::endl;
}

template<typename T>
void foreach(T *list, void (&func)(const T &obj), size_t &size)
{
    size_t i = 0;

    if (list == NULL)
        return;
    while (i < size) {
        func(list[i]);
        i++;
    }
}

#endif