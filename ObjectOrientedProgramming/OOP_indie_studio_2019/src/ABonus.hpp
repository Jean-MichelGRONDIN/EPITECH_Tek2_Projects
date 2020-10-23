/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** ABonus
*/

#ifndef ABONUS_HPP_
#define ABONUS_HPP_

#include "MapElement.hpp"
#include "paths.hpp"
#include "MyClock.hpp"
#include "Music.hpp"
#include "path.h"
#include "Particle.hpp"
#include "IBonus.hpp"

class ABonus : public MapElement, public IBonus {
public:
    ABonus(MapManager* map, std::uint64_t row, std::uint64_t column, irr::scene::ISceneManager* sceanManger, irr::video::IVideoDriver* driver);
    ~ABonus();
    void getHited() override;
    virtual void addBonusTo(std::shared_ptr<Player>) override;
    bool isActiv();
protected:
    irr::scene::IMeshSceneNode* _bonus;
    bool _visble;
private:
};

#endif /* !ABONUS_HPP_ */
