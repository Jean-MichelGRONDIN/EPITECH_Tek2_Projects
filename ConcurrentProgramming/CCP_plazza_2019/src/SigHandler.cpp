/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** SigHandler
*/

#include "SigHandler.hpp"
#include <iostream>

void emptyFunction(int n, siginfo_t *sigReq, void *s)
{
    n = n;
    sigReq = sigReq;
    s = s;
    return;
}

SigHandler::SigHandler()
{
    this->_sigStruc = new struct sigaction();
    this->_sigStruc->sa_flags = SA_SIGINFO;
    this->_sigStruc->sa_sigaction = &emptyFunction;
    sigaction(SIG_USER_ONE, _sigStruc, NULL);
    sigaction(SIG_USER_TWO, _sigStruc, NULL);
}

SigHandler::~SigHandler()
{
}

void SigHandler::waitSig()
{
    pause();
}


int SigHandler::sendSig(int pid, int sig)
{
    return (kill(pid, sig));
}
