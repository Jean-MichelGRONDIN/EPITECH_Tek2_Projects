/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** SpeedDown
*/

#ifndef SPEEDDOWN_HPP_
#define SPEEDSOWN_HPP_

#include "ABonus.hpp"
class SpeedDown : public ABonus {
public:
    SpeedDown(MapManager* map, std::uint64_t row, std::uint64_t column, irr::scene::ISceneManager* sceanManger, irr::video::IVideoDriver* driver);
    ~SpeedDown();
    virtual void addBonusTo(std::shared_ptr<Player>) override;
protected:
private:
};

#endif /* !SPEEDUP_HPP_ */
