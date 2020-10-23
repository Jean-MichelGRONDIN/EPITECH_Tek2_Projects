/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** KoalaDoctor
*/

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string news_name) : name(news_name), isWorking(false)
{
    std::cout << "Dr." << name << ": I'm Dr."
    << name << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    std::string patients_name = patient->getName();
    std::string reports_name = patients_name;
    std::string medoc_list[] = {"Mars", "Buronzand", "Viagra",
        "Extasy", "Eucalyptus leaf"};

    std::cout << "Dr." << name << ": So what's goerking you Mr."
    << patients_name << "?" << std::endl;
    patient->poke();
    reports_name += ".report";
    std::ofstream offile(reports_name.c_str());
    if (offile)
        offile << medoc_list[random()% 5];
}

void KoalaDoctor::timeCheck()
{
    if (!isWorking) {
        std::cout << "Dr." << this->name
        << ": Time to get to work!" << std::endl;
        isWorking = true;
    } else {
        std::cout << "Dr." << this->name
        << ": Time to go home to my eucalyptus forest!" << std::endl;
        isWorking = false;
    }
}