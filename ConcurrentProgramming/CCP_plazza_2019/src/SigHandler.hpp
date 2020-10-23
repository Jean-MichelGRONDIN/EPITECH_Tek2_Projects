/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** SigHandler
*/

#ifndef SIGHANDLER_HPP_
#define SIGHANDLER_HPP_

#include <signal.h>
#include <unistd.h>
#include <time.h>

#define SIG_USER_ONE 10
#define SIG_USER_TWO 12

class SigHandler {
    public:
        SigHandler();
        ~SigHandler();
        void waitSig();
        int sendSig(int pid, int sig);

    private:
        struct sigaction *_sigStruc;
};

#endif