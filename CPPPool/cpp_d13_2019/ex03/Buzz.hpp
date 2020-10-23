/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy {
	public:
		Buzz(std::string name, const std::string file = "./buzz.txt");
		~Buzz();
		void speak(std::string statement);

	protected:
	private:
};

#endif