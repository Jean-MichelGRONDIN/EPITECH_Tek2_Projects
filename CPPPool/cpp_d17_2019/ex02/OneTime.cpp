/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** OneTime
*/

#include "OneTime.hpp"

OneTime::OneTime(std::string key)
{
    this->_key = key;
    this->_index_crypt = 0;
    this->_index_uncrypt = 0;
}

OneTime::~OneTime()
{
}

static char crypt(char c, int index)
{
    int to_sub = 65;

    if (c >= 'a')
        to_sub = 97;
    c = c - to_sub;
    c = c + index;
    c = (c + 26) % 26;
    c = c + to_sub;
    return (c);
}

static char uncrypt(char c, int index)
{
    int to_sub = 65;

    if (c >= 'a')
        to_sub = 97;
    c = c - to_sub;
    c = c - index;
    c = (c + (26 * index)) % 26;
    c = c + to_sub;
    return (c);
}

void OneTime::encryptChar(char plainchar)
{
    size_t tmp_index = 0;

        if (this->_index_crypt >= this->_key.length())
            this->_index_crypt = 0;
        if (_key[_index_crypt] >= 'a') {
            tmp_index = _key[_index_crypt] - 97;
        } else {
            tmp_index = _key[_index_crypt] - 65;
        }


    if ((plainchar >= 'A' && plainchar <= 'Z')
    || (plainchar >= 'a' && plainchar <= 'z')) {
        plainchar = crypt(plainchar, tmp_index);
    }
    this->_index_crypt += 1;
    std::cout << plainchar;
}

void OneTime::decryptChar(char cipherchar)
{
    size_t tmp_index = 0;


        if (this->_index_uncrypt >= this->_key.length())
            this->_index_uncrypt = 0;
        if (_key[_index_uncrypt] >= 'a') {
            tmp_index = _key[_index_uncrypt] - 97;
        } else {
            tmp_index = _key[_index_uncrypt] - 65;
        }


    if ((cipherchar >= 'A' && cipherchar <= 'Z')
    || (cipherchar >= 'a' && cipherchar <= 'z')) {
        cipherchar = uncrypt(cipherchar, tmp_index);
    }
    this->_index_uncrypt += 1;
    std::cout << cipherchar;
}

void OneTime::reset()
{
    this->_index_crypt = 0;
    this->_index_uncrypt = 0;
}