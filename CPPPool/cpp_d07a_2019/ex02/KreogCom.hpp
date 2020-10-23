/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

#include "stddef.h"
#include <iostream>

class KreogCom {
    public :
        KreogCom(int x, int y, int serial);
        ~ KreogCom();
        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom();
        void ping() const;
        void locateSquad() const;

    private :
        const int m_serial;
        const int m_x;
        const int m_y;
        KreogCom *_linked;
};

#endif