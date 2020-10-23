/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Wall
*/

#ifndef WALL_HPP_
#define WALL_HPP_

#include "paths.hpp"
#include "MapElement.hpp"
#include <irrlicht.h>

class Wall : public MapElement{
    public:
        Wall(MapManager *map, std::uint64_t, std::uint64_t, irr::scene::ISceneManager *scenemgr, irr::video::IVideoDriver *driver, std::unordered_map<char, irr::scene::IMetaTriangleSelector*> _selectors);
        Wall(MapManager* map, std::uint64_t row, std::uint64_t column, irr::scene::ISceneManager* sceanManger, irr::video::IVideoDriver* driver, irr::scene::IMetaTriangleSelector* selectorMap);
        ~Wall();

    protected:
        irr::scene::IMeshSceneNode *_cube_wall;
        irr::video::IVideoDriver *_driver;
    private:
};

#endif /* !WALL_HPP_ */
