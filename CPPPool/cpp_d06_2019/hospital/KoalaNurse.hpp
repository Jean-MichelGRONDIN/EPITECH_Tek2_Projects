/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include "SickKoala.hpp"

class KoalaNurse {
    public:
        KoalaNurse(int news_ID);
        ~KoalaNurse();
        void giveDrug(std::string drug, SickKoala *patient);
        std::string readReport(std::string filename);
        void timeCheck(void);

    private:
        int ID;
        bool isWorking;
};

#endif