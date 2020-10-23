/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** BigBuilding
*/

#include "BigBuilding.hpp"

BigBuilding::BigBuilding(sf::Vector2f pos, std::string spriteBroken, std::string spriteRepaired) : Building::Building(pos, spriteBroken, spriteRepaired, 3, 100, 0, 50, 5, 50, 10)
{
}

BigBuilding::~BigBuilding()
{
}
