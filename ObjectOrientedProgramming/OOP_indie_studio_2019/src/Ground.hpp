/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Ground
*/

#ifndef GROUND_HPP_
#define GROUND_HPP_

#include "MapElement.hpp"
#include <irrlicht.h>

class Ground : public MapElement{
    public:
        Ground(MapManager *map, std::uint64_t, std::uint64_t, irr::scene::ISceneManager *scenemgr, irr::video::IVideoDriver *driver, std::unordered_map<char, irr::scene::IMetaTriangleSelector*> _selectors);
        ~Ground();

    protected:
        irr::video::IVideoDriver *_driver;
        irr::scene::IMeshSceneNode *_cube_ground;
    private:
};

#endif /* !GROUND_HPP_ */
