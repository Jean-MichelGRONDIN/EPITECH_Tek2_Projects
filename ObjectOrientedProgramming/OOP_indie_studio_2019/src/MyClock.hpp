/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MyClock
*/

#ifndef MYCLOCK_HPP_
#define MYCLOCK_HPP_

#include <chrono>

class MyClock {
    public:
        MyClock();
        ~MyClock();
        bool isGreterThan(int64_t milliseconds);
        void restart();
    protected:
        #ifdef __linux__ 
            std::chrono::system_clock::time_point _time;
        #elif _WIN32
            std::chrono::time_point<std::chrono::steady_clock> _time;
        #endif
    private:
};

#endif /* !MYCLOCK_HPP_ */
