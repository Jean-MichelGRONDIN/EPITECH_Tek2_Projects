/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** myClock
*/

#ifndef MYCLOCK_HPP_
#define MYCLOCK_HPP_

#include <chrono>

class myClock {
    public:
        myClock();
        ~myClock();
        bool isGreterThan(int64_t milliseconds);
        void restart();
    protected:
        std::chrono::_V2::system_clock::time_point _time;
    private:
};

#endif