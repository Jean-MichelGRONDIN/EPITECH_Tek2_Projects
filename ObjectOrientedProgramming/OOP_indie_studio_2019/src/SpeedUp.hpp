/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** SpeedUp
*/

#ifndef SPEEDUP_HPP_
#define SPEEDUP_HPP_

#include "ABonus.hpp"
class SpeedUp : public ABonus {
public:
    SpeedUp(MapManager* map, std::uint64_t row, std::uint64_t column, irr::scene::ISceneManager* sceanManger, irr::video::IVideoDriver* driver);
    ~SpeedUp();
    virtual void addBonusTo(std::shared_ptr<Player>) override;
protected:
private:
};

#endif /* !SPEEDUP_HPP_ */
