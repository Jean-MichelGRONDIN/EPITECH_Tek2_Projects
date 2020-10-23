/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** LittlePony
*/

#ifndef LITTLEPONY_HPP_
#define LITTLEPONY_HPP_

#include "Toy.hpp"
#include <iostream>
#include <string>

class LittlePony : public Toy {
	public:
		LittlePony(std::string title);
		~LittlePony();
        void isTaken() { std::cout << "yo man" << std::endl;};

	protected:
	private:
};

#endif /* !LITTLEPONY_HPP_ */
