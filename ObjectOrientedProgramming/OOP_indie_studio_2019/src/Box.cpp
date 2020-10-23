/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Box
*/

#include "Box.hpp"

#include <iostream>
Box::Box(MapManager *map, std::uint64_t row, std::uint64_t column, irr::scene::ISceneManager *sceanManger, irr::video::IVideoDriver *driver, std::unordered_map<char, irr::scene::IMetaTriangleSelector*> selectors)
: MapElement(map, 'B', row, column)
{
    _pos = irr::core::vector3df(row * CUBE_SIZE, 0, column * CUBE_SIZE);
    _cube_box = sceanManger->addCubeSceneNode(CUBE_SIZE, 0, 0, _pos);
    _driver = driver;
    _cube_box->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _cube_box->setMaterialTexture(0, driver->getTexture(BOX_TEXTURE));
    _solide = true;
    _selectors = selectors;
    _s = sceanManger->createTriangleSelector(_cube_box->getMesh(), _cube_box);
    for (auto &kv : selectors)
        kv.second->addTriangleSelector(_s);
    _cube_box->setTriangleSelector(_s);
    _sceanManger = sceanManger;
}

Box::~Box()
{
}

void Box::getHited()
{
    for (auto& kv : _selectors)
        kv.second->removeTriangleSelector(_s);
    _cube_box->setVisible(false);
    _cube_box->setPosition(irr::core::vector3df(3000, 3000, 3000));
    _map->removeBox(_current_row, _current_column);
}
