/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex01
*/

#ifndef EX01_HPP_
#define EX01_HPP_

#include <cstring>

template<typename T>
int compare(const T &one, const T &two)
{
    if (one == two)
        return (0);
    if (one > two)
        return (1);
    return (-1);
}

int compare(const char *one, const char *two)
{
    int res = std::strcmp(one, two);

    if (res == 0)
        return (0);
    if (res > 0)
        return (1);
    return (-1);
}

#endif