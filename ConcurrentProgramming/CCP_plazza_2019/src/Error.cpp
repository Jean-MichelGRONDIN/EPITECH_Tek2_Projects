/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Error
*/

#include "Error.hpp"

MyError::MyError(std::string error_msg)
{
    this->_message = error_msg;
}

MyError::~MyError()
{
}

const char *MyError::what() const noexcept
{
    return (this->_message.c_str());
}