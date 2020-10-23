/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** ABonus
*/

#include "SpeedUp.hpp"
#include "Player.hpp"

ABonus::ABonus(MapManager* map, std::uint64_t row, std::uint64_t column, irr::scene::ISceneManager* sceanManger, irr::video::IVideoDriver* driver)
	: MapElement(map, 'S', row, column)

{
	_pos = irr::core::vector3df(row * CUBE_SIZE, 3, column * CUBE_SIZE);
	_bonus = sceanManger->addCubeSceneNode(CUBE_SIZE / 2 , 0, -1, _pos);
	_bonus->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_bonus->setMaterialTexture(0, driver->getTexture(BOMBE_TEXTURE));
	_visble = false;
	_bonus->setVisible(_visble);
	
}

ABonus::~ABonus()
{
}

void ABonus::getHited()
{
	if (!_visble) {
		_bonus->setVisible(true);
		_visble = true;
		return;
	}
	_bonus->setVisible(false);
	_bonus->setPosition(irr::core::vector3df(3000, 3000, 3000));
}

void ABonus::addBonusTo(std::shared_ptr<Player> p)
{
}

bool ABonus::isActiv()
{
	return _bonus->isVisible();
}
