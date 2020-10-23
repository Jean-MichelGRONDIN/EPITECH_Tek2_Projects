/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex04
*/

#include "ex04.hpp"

template<typename T>
bool equal(const T &one, const T &two)
{
    if (one == two)
        return (true);
    return (false);
}

template<typename T>
bool Tester<T>::equal(const T &one, const T &two) const
{
    if (one == two)
        return (true);
    return (false);
}

template bool equal<int>(const int &one, const int &two);
template bool equal<float>(const float &one, const float &two);
template bool equal<double>(const double &one, const double &two);
template bool equal<std::string>(const std::string &one, const std::string &two);
template class Tester<int>;
template class Tester<float>;
template class Tester<double>;
template class Tester<std::string>;