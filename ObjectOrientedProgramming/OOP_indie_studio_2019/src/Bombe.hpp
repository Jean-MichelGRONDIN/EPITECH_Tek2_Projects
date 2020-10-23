/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Bombe
*/

#ifndef BOMBE_HPP_
#define BOMBE_HPP_

#include "MapElement.hpp"
#include "paths.hpp"
#include "MyClock.hpp"
#include "Music.hpp"
#include "path.h"
#include "Particle.hpp"

class Bombe : public MapElement {
    public:
        Bombe(MapManager *map, std::uint64_t row, std::uint64_t column, irr::scene::ISceneManager *sceanManger, irr::video::IVideoDriver *driver, std::shared_ptr<s32> range);
        ~Bombe();
        void getHited() override;
        void bombPlaced(std::uint64_t row, std::uint64_t column);
        bool canDestroy();
        void exploseTop();
        void exploseBot();
        void exploseLeft();
        void exploseRight();
        char getSymRange();
        bool isActive();
        void update();
        void explos();

    protected:
        MyClock _clock;
        irr::scene::IMeshSceneNode *_bombe;
        irr::video::IVideoDriver *_driver;
        bool _placed;
        bool _actived;
        std::shared_ptr<Musical> _posBomb;
        std::shared_ptr<Musical> _explosion;
        std::vector<std::shared_ptr<Particle>> _particls;
        std::shared_ptr<s32> _range;
    private:
};

#endif /* !BOMBE_HPP_ */
