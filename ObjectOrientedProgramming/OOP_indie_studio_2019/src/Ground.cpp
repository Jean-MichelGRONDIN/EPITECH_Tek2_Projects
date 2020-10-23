/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Ground
*/

#include "Ground.hpp"

Ground::Ground(MapManager *map, std::uint64_t row, std::uint64_t column, irr::scene::ISceneManager *sceanManger, irr::video::IVideoDriver *driver, std::unordered_map<char, irr::scene::IMetaTriangleSelector*> selectors)
: MapElement(map, ' ', row, column)
{
    _pos = irr::core::vector3df(row * CUBE_SIZE, -CUBE_SIZE , column * CUBE_SIZE);
    _cube_ground = sceanManger->addCubeSceneNode(CUBE_SIZE, 0, 0, _pos);
    _driver = driver;
    _solide;
    irr::scene::ITriangleSelector* s = sceanManger->createTriangleSelector(_cube_ground->getMesh(), _cube_ground);
    for (auto& kv : selectors)
        kv.second->addTriangleSelector(s);
    _cube_ground->setTriangleSelector(s);

}

Ground::~Ground()
{
}
