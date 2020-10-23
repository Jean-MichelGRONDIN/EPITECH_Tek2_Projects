/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Coconut
*/

#ifndef COCONUT_HPP_
#define COCONUT_HPP_

#include "Fruit.hpp"

class Coconut : public Fruit {
	public:
		Coconut();
		~Coconut();
        int getVitamins() const;
		std::string getName() const;

	protected:
	private:
};

#endif