/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include "KoalaNurse.hpp"

class KoalaDoctor {
	public:
		KoalaDoctor(std::string news_name);
		~KoalaDoctor();
        void diagnose(SickKoala *patient);
        void timeCheck(void);

	private:
        std::string name;
        bool isWorking;
};

#endif