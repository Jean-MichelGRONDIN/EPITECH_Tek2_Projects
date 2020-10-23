/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** MiddleBuilding
*/

#include "MiddleBuilding.hpp"

MiddleBuilding::MiddleBuilding(sf::Vector2f pos, std::string spriteBroken, std::string spriteRepaired) : Building::Building(pos, spriteBroken, spriteRepaired, 2, 50, 5, 50, 10)
{
}

MiddleBuilding::~MiddleBuilding()
{
}
