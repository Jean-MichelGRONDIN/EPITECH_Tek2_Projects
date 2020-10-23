/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Box
*/

#ifndef BOX_HPP_
#define BOX_HPP_

#include "paths.hpp"
#include "MapElement.hpp"
#include "Particle.hpp"
#include <irrlicht.h>

class Box  : public MapElement{
    public:
        Box(MapManager *map, std::uint64_t row, std::uint64_t column, irr::scene::ISceneManager *sceanManger, irr::video::IVideoDriver *driver, std::unordered_map<char, irr::scene::IMetaTriangleSelector*> _selectors);
        ~Box();
        void getHited() override;

    protected:
        irr::scene::ITriangleSelector* _s;
        irr::scene::IMeshSceneNode *_cube_box;
        irr::video::IVideoDriver *_driver;
        std::unordered_map<char, irr::scene::IMetaTriangleSelector*> _selectors;
        irr::scene::ISceneManager *_sceanManger;
    private:
};

#endif /* !BOX_HPP_ */
