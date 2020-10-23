/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Ipc
*/

#include "Ipc.hpp"

Ipc::Ipc(std::string path)
{
    mkfifo(path.c_str(), 0666);
    this->_path = path;
}

Ipc::~Ipc()
{
    remove(this->_path.c_str());
}

void Ipc::writeIn(std::string msg)
{
    std::ofstream file(this->_path);

    if (!file) {
        throw MyError(FIFO_OPEN_FAILED);
    }
    file << getpid() << "#" << msg << std::endl;
    file.close();
}

std::string Ipc::readIn()
{
    std::string ret;
    std::ifstream file(this->_path);

    if (!file) {
        throw MyError(FIFO_OPEN_FAILED);
    }
    std::getline(file, ret);
    file.close();
    return (ret);
}
