/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Peon
*/

#ifndef PEON_HPP_
#define PEON_HPP_

#include <string>
#include <iostream>

class Peon {
	public:
		Peon(std::string name);
		~Peon();
		std::string getname() const;
        void getPolymorphed() const;

	protected:
	private:
        std::string _name;
};

std::ostream &operator<<(std::ostream &s, Peon obj);

#endif