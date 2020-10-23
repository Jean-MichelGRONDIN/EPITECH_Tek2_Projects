/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** LittleBuilding
*/

#ifndef LITTLEBUILDING_HPP_
#define LITTLEBUILDING_HPP_

#include "Building.hpp"

class LittleBuilding : public Building {
	public:
		LittleBuilding(sf::Vector2f pos, std::string spriteBroken = "Assets/hfbrk.png", std::string spriteRepair = "Assets/hb7.png");
		~LittleBuilding();

	protected:
	private:
};

#endif /* !LITTLEBUILDING_HPP_ */
