/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** RangeBombe
*/

#ifndef RANGEBOMBE_HPP_
#define RANGEBOMBE_HPP_

#include "ABonus.hpp"
class RangeBombe : public ABonus {
public:
    RangeBombe(MapManager* map, std::uint64_t row, std::uint64_t column, irr::scene::ISceneManager* sceanManger, irr::video::IVideoDriver* driver, bool inc, bool nb);
    ~RangeBombe();
    virtual void addBonusTo(std::shared_ptr<Player>) override;
protected:
    bool _inc;
    bool _nb;

private:
};

#endif /* !RANGEBOMBE_HPP_ */
