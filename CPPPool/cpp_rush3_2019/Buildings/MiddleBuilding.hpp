/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** MiddleBuilding
*/

#ifndef MIDDLEBUILDING_HPP_
#define MIDDLEBUILDING_HPP_

#include "Building.hpp"

class MiddleBuilding : public Building {
	public:
		MiddleBuilding(sf::Vector2f pos, std::string spriteBroken = "Assets/hp2brk.png", std::string spriteRepaired = "Assets/hp2.png");
		~MiddleBuilding();

	protected:
	private:
};

#endif /* !MIDDLEBUILDING_HPP_ */
