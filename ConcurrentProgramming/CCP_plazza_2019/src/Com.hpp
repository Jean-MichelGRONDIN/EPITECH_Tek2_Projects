/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Com
*/

#ifndef COM_HPP_
#define COM_HPP_

#include <string>

#include "Ipc.hpp"
#include "SigHandler.hpp"

#define FIFO_FILE_PATH "fifoFile.txt"

class Com {
    public:
        Com();
        ~Com();
        int sendOrderTo(pid_t pid, std::string msg);
        std::string getOrder(void);
        std::string &operator>>(std::string &msg);
        void operator<<(const std::string &) const;

    private:
        Ipc *_ipc;
        SigHandler *_sigManag;
};

#endif