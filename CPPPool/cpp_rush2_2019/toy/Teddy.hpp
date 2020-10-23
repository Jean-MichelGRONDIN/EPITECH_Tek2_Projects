/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Teddy
*/

#ifndef TEDDY_HPP_
#define TEDDY_HPP_

#include "Toy.hpp"
#include <string>
#include <iostream>

class Teddy  : public Toy {
	public:
		Teddy(std::string title);
		~Teddy();
        void isTaken() { std::cout << "gar hu" << std::endl; }
	protected:
	private:
};

#endif /* !TEDDY_HPP_ */
