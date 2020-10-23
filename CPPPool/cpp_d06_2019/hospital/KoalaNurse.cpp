/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** KoalaNurse
*/

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int news_ID) : ID(news_ID), isWorking(false)
{
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << this->ID
    << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
    patient->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::ifstream file_content;
    int a = 0;
    std::string s;
    std::string name;
    int pos = filename.find('.', 0);

    name = filename.substr(0, filename.rfind(".report"));
    file_content.open(filename.data());
    a = file_content.is_open();
    if (a == 0 || pos == -1)
        return ("");
    getline(file_content, s);
    std::cout << "Nurse " << this->ID
    << ": Kreog! Mr." << name
    << " needs a " << s
    << "!"<< std::endl;
    file_content.close();
    return (s);
}

void KoalaNurse::timeCheck()
{
    if (!isWorking) {
        std::cout << "Nurse " << this->ID
        << ": Time to get to work!" << std::endl;
        isWorking = true;
    } else {
        std::cout << "Nurse " << this->ID
        << ": Time to go home to my eucalyptus forest!" << std::endl;
        isWorking = false;
    }
}