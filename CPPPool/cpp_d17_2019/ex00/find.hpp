/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** find
*/

#ifndef FIND_HPP_
#define FIND_HPP_

#include <string>
#include <algorithm>
#include <iostream>

template<typename T>
class T::iterator do_find(T &ref, int n)
{
    return (std::find(ref.begin(), ref.end(), n));
}

#endif