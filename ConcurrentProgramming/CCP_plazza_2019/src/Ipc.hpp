/*
** EPITECH PROJECT, 2020
** nms
** File description:
** nms
*/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <fstream>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdio.h"

#include "Error.hpp"

#ifndef IPC_HPP_
#define IPC_HPP_

class Ipc {
    public:
        Ipc(std::string path);
        ~Ipc();
        void writeIn(std::string);
        std::string readIn(void);
    private:
        std::string _path;
};

#endif /* !IPC_HPP_ */
