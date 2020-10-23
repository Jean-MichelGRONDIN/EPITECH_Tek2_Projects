/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** myClock
*/

#include "myClock.hpp"

myClock::myClock()
{
    this->_time = std::chrono::high_resolution_clock::now();
}

myClock::~myClock()
{
}

bool myClock::isGreterThan(int64_t ms)
{
    auto now = std::chrono::high_resolution_clock::now();
    auto past_time = now - this->_time;

    auto ms_n = std::chrono::duration_cast<std::chrono::milliseconds>(past_time).count();
    if ( ms_n > ms)
        return (true);
    return (false);
}

void myClock::restart()
{
    this->_time = std::chrono::high_resolution_clock::now();
}