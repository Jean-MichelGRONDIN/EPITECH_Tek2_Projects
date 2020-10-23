/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Lemon
*/

#ifndef LEMON_HPP_
#define LEMON_HPP_

#include "Fruit.hpp"

class Lemon : public Fruit {
	public:
		Lemon();
		~Lemon() final;
		int getVitamins() const final;
		std::string getName() const final;

	protected:
	private:
};

#endif