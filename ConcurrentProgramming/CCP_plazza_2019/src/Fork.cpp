/*
** EPITECH PROJECT, 2020
** fork
** File description:
** fork it
*/

#include "Fork.hpp"
#include "plazza.hpp"
#include "kitchen.hpp"

MyFork::MyFork()
{
    try {
        this->_id = fork();
        if (_id == -1)
            throw MyError(ERR_FORK);
    } catch(MyError const &e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }
}

MyFork::~MyFork()
{
}

pid_t MyFork::getId()
{
    return (_id);
}

void MyFork::QuitProcess(int val) const
{
    if (_id == 0) {
        exit(val);
    }
}
