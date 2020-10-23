/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Com
*/

#include "Com.hpp"
#include "plazza.hpp"

Com::Com()
{
    this->_sigManag = new SigHandler();
    this->_ipc = new Ipc(FIFO_FILE_PATH);
}

Com::~Com()
{
    delete this->_sigManag;
    delete this->_ipc;
}

int Com::sendOrderTo(pid_t pid, std::string msg)
{
    this->_sigManag->sendSig(pid, SIG_USER_ONE);
    this->_ipc->writeIn(msg);
    this->_sigManag->waitSig();
    sleep(10);
    return (0);
}

std::string Com::getOrder(void)
{
    std::vector<std::string> ret;
    std::string msg;

    this->_sigManag->waitSig();
    msg = this->_ipc->readIn();
    ret = Plazza::explode(msg, '#');
    sleep(10);
    this->_sigManag->sendSig(std::atoi(ret[0].c_str()), SIG_USER_ONE);
    return (ret[1]);
}

std::string &Com::operator>>(std::string &msg)
{
    msg = _ipc->readIn();
    return msg;
}

void Com::operator<<(const std::string &msg) const
{
    _ipc->writeIn(msg);
}