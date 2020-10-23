/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** RangeBombe
*/

#include "RangeBombe.hpp"
#include "Player.hpp"

RangeBombe::RangeBombe(MapManager* map, std::uint64_t row, std::uint64_t column, irr::scene::ISceneManager* sceanManger, irr::video::IVideoDriver* driver, bool inc, bool nb) : ABonus(map, row, column, sceanManger, driver)
{
	if (nb) {
		if (inc)
			_bonus->setMaterialTexture(0, driver->getTexture(INCR_TEXTURE));
		else
			_bonus->setMaterialTexture(0, driver->getTexture(DECR_TEXTURE));
	}
	else {
		if (inc)
			_bonus->setMaterialTexture(0, driver->getTexture(INCB_TEXTURE));
		else
			_bonus->setMaterialTexture(0, driver->getTexture(DECB_TEXTURE));
	}
	_inc = inc;
	_nb = nb;
}

RangeBombe::~RangeBombe()
{
}

void RangeBombe::addBonusTo(std::shared_ptr<Player> player)
{
	if (_nb) {
		if (_inc)
			player->IncRangBombe();
		else
			player->DecRangBombe();
	}
	else {
		if (_inc)
			player->addBombe();
		else
			player->removeBombe();
	}
}
