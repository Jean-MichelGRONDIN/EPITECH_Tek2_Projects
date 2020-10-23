/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** LittleBuilding
*/

#include "LittleBuilding.hpp"

LittleBuilding::LittleBuilding(sf::Vector2f pos, std::string spriteBroken, std::string spriteRepaired) : Building::Building(pos, spriteBroken, spriteRepaired, 1, 50, 10)
{
}

LittleBuilding::~LittleBuilding()
{
}
