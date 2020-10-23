/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** MyError
*/

#include "../include/nanotekspice.hpp"

MyError::MyError(std::string const &message) : _message(message)
{
}

const char *MyError::what() const noexcept
{
	return (this->_message.c_str());
}