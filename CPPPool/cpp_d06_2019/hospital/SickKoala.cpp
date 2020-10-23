/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** SickKoala
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string news_name) : name(news_name)
{
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << this->name
    << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke()
{
    std::cout << "Mr." << this->name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string drug)
{
    if (drug.compare("Mars") == 0) {
        std::cout << "Mr." << this->name
        << ": Mars, and it kreogs!" << std::endl;
        return (true);
    }
    if (drug.compare("Buronzand") == 0) {
        std::cout << "Mr." << this->name
        << ": And you'll sleep right away!" << std::endl;
        return (true);
    }
    std::cout << "Mr." << this->name << ": Goerkreog!" << std::endl;
    return (false);
}

void SickKoala::overDrive(std::string msg)
{
    int pos = msg.find("Kreog!", 0);

    while (pos != -1) {
        msg.replace(pos, 6, "1337!");
        pos++;
        pos = msg.find("Kreog!", 0);
    }
    std::cout << "Mr." << this->name << ": " << msg << std::endl;
}

std::string SickKoala::getName(void)
{
    return (name);
}