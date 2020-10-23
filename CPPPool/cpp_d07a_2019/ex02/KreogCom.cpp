/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** KreogCom
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) : m_serial(serial), m_x(x), m_y(y)
{
    this->_linked = NULL;
    std::cout << "KreogCom " << this->m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << this->m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *new_KC = new KreogCom(x, y, serial);

    if (this->_linked != NULL)
        new_KC->_linked = this->_linked;
    this->_linked = new_KC;
}

void KreogCom::removeCom()
{
    KreogCom *tmp = this->_linked;

    if (this->_linked != NULL) {
        this->_linked = this->_linked->_linked;
        delete(tmp);
        tmp = NULL;
    }
}

KreogCom *KreogCom::getCom()
{
    return (this->_linked);
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << this->m_serial << " currently at "
    << this->m_x << " " << this->m_y << std::endl;
}

void KreogCom::locateSquad() const
{
    KreogCom *tmp = this->_linked;

    while (tmp != NULL) {
        tmp->ping();
        tmp = tmp->_linked;
    }
    this->ping();
}