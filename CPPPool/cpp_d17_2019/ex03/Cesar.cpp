/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** Cesar
*/

#include "Cesar.hpp"

Cesar::Cesar()
{
    this->_shift_crypt = 3;
    this->_shift_uncrypt = 3;
}

Cesar::~Cesar()
{
}

static char crypt(char c, int shift)
{
    int to_sub = 65;

    if (c >= 'a')
        to_sub = 97;
    c = c - to_sub;
    c = c + shift;
    c = (c + 26) % 26;
    c = c + to_sub;
    return (c);
}

static char uncrypt(char c, int shift)
{
    int to_sub = 65;

    if (c >= 'a')
        to_sub = 97;
    c = c - to_sub;
    c = c - shift;
    c = (c + (26 * shift)) % 26;
    c = c + to_sub;
    return (c);
}

void Cesar::encryptChar(char plainchar)
{
    if ((plainchar >= 'A' && plainchar <= 'Z')
    || (plainchar >= 'a' && plainchar <= 'z')) {
        plainchar = crypt(plainchar, this->_shift_crypt);
    }
    this->_shift_crypt += 1;
    std::cout << plainchar;
}

void Cesar::decryptChar(char cipherchar)
{
    if ((cipherchar >= 'A' && cipherchar <= 'Z')
    || (cipherchar >= 'a' && cipherchar <= 'z')) {
        cipherchar = uncrypt(cipherchar, this->_shift_uncrypt);
    }
    this->_shift_uncrypt += 1;
    std::cout << cipherchar;
}

void Cesar::reset()
{
    this->_shift_crypt = 3;
    this->_shift_uncrypt = 3;
}