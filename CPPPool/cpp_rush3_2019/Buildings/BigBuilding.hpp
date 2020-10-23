/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** BigBuilding
*/

#ifndef BIGBUILDING_HPP_
#define BIGBUILDING_HPP_

#include "Building.hpp"

class BigBuilding : public Building {
	public:
		BigBuilding(sf::Vector2f pos, std::string spriteBroken = "Assets/hm2brk.png", std::string spriteRepaired = "Assets/hm1.png");
		~BigBuilding();

	protected:
	private:
};

#endif /* !BIGBUILDING_HPP_ */
