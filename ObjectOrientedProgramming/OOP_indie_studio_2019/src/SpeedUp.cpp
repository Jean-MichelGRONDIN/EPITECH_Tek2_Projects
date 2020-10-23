/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** SpeedUp
*/

#include "SpeedUp.hpp"
#include "Player.hpp"

SpeedUp::SpeedUp(MapManager* map, std::uint64_t row, std::uint64_t column, irr::scene::ISceneManager* sceanManger, irr::video::IVideoDriver* driver) : ABonus(map, row, column, sceanManger, driver)
{
	_bonus->setMaterialTexture(0, driver->getTexture(SPEEDUP_TEXTURE));
}

SpeedUp::~SpeedUp()
{
}

void SpeedUp::addBonusTo(std::shared_ptr<Player> player)
{
	player->setMoveSpeed(0.3F);
}
