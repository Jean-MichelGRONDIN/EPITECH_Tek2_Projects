/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy {
	public:
		Woody(std::string name, const std::string file = "./woody.txt");
		~Woody();
		void speak(std::string statement);

	protected:
	private:
};

#endif