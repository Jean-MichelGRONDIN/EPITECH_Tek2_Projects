/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MyClock
*/

#include "MyClock.hpp"
#include <iostream>

MyClock::MyClock()
{
    _time = std::chrono::high_resolution_clock::now();
}

MyClock::~MyClock()
{
}

bool MyClock::isGreterThan(int64_t ms)
{
    auto now = std::chrono::high_resolution_clock::now();
    auto past_time = now - _time;

    auto ms_n = std::chrono::duration_cast<std::chrono::milliseconds>(past_time).count();
    if ( ms_n > ms)
        return (true);
    return (false);
}

void MyClock::restart()
{
    _time = std::chrono::high_resolution_clock::now();
}