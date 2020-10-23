/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** Encryption
*/

#include "Encryption.hpp"

Encryption::Encryption(IEncryptionMethod &encrypt_method,
    void (IEncryptionMethod::*func)(char))
{
    this->_encrypt_method = encrypt_method;
    this->_func = func;
}

Encryption::~Encryption()
{
}

void Encryption::operator()(char c)
{
    (this->_encrypt_method.*this->_func)(c);
}

void Encryption::encryptString(IEncryptionMethod &em, std::string const &s)
{
	em.reset();
	std::for_each(s.begin(), s.end(), [&](char c) { em.encryptChar(c); });
	std::cout << std::endl;
}

void Encryption::decryptString(IEncryptionMethod &em, std::string const &s)
{
	em.reset();
	std::for_each(s.begin(), s.end(), [&](char c) { em.decryptChar(c); });
	std::cout << std::endl;
}