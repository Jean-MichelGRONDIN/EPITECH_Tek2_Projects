/*
** EPITECH PROJECT, 2020
** fork
** File description:
** Plazza
*/

#ifndef FORK_HPP_
#define FORK_HPP_

#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include "Error.hpp"

class Plazza;

class MyFork {
    public:
        MyFork();
        ~MyFork();
        pid_t getId();
        void QuitProcess(int) const;
    private:
        int _status;
        pid_t _id;
        pid_t wpid;
};

#endif /* !FORK_HPP_ */
