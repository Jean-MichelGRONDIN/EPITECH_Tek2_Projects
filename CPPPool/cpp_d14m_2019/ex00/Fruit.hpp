/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <string>

class Fruit {
	public:
		Fruit();
		virtual ~Fruit() = 0;
        virtual int getVitamins() const = 0;
        virtual std::string getName() const = 0;

	protected:
        int _vitamins;
        std::string _name;
	private:
};

#endif