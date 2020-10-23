/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Wall
*/

#include "Wall.hpp"

Wall::Wall(MapManager *map, std::uint64_t row, std::uint64_t column, irr::scene::ISceneManager *sceanManger, irr::video::IVideoDriver *driver, std::unordered_map<char, irr::scene::IMetaTriangleSelector*> selectors)
: MapElement(map, 'W', row, column)
{
    _pos = irr::core::vector3df(row * CUBE_SIZE, 0, column * CUBE_SIZE);
    _cube_wall = sceanManger->addCubeSceneNode(CUBE_SIZE, 0, 0, _pos);
    _driver = driver;
    _cube_wall->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _cube_wall->setMaterialTexture(0, driver->getTexture(WALL_TEXTURE));
    _solide = true;
    irr::scene::ITriangleSelector* s = sceanManger->createTriangleSelector(_cube_wall->getMesh(), _cube_wall);
    for (auto& kv : selectors)
        kv.second->addTriangleSelector(s);
    _cube_wall->setTriangleSelector(s);
}

Wall::~Wall()
{
}
