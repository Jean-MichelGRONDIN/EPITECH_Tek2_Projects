/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex00
*/

#ifndef EX00_HPP_
#define EX00_HPP_

template<typename T>
void swap(T &one, T &two)
{
    T tmp = two;

    two = one;
    one = tmp;
}

template<typename T>
T min(T one, T two)
{
    if (one > two)
        return (two);
    return (one);
}

template<typename T>
T max(T one, T two)
{
    if (one < two)
        return (two);
    return (one);
}

template<typename T>
T add(T one, T two)
{
    return (one + two);
}

#endif