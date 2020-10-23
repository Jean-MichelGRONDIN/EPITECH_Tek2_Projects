/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** SickKoala
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include <string>
#include <iostream>
#include <fstream>

class SickKoala {
    public:
        SickKoala(std::string news_name);
        ~SickKoala();
        void poke();
        bool takeDrug(std::string drug);
        void overDrive(std::string msg);
        std::string getName(void);

    private:
        std::string name;
};

#endif