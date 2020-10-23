/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include <sys/time.h>
#include <vector>
#include <thread>
#include <deque>
#include <stdlib.h>
#include <mutex>

#include "Ipc.hpp"
#include "Fork.hpp"
#include "Com.hpp"
#include "myClock.hpp"

class Plazza;

class Kitchen {
    public:
        Kitchen(Com *com, double mul, int nb, int msTime);
        ~Kitchen();
        void start(void);
        pid_t getId(void) const;
        void kitchenLoop(void);
        bool isFull(void) const;
        int getIsFull(void);
        void setIsFull(int n);
        void isFullInc(void);
        void isFullDec(void);
        double getMul(void) {return _mul;};

    private:
        std::vector<std::thread *> _threads;
        int _isFull;
        double _mul;
        int _nb;
        int _msTime;
        MyFork *_kitchen;
        Com *_com;
        pid_t _id;
};

#endif /* !KITCHEN_HPP_ */
