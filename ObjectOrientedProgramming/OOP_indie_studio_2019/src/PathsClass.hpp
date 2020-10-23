/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Paths
*/

#ifndef PATHS_CLASS_HPP_
#define PATHS_CLASS_HPP_

#include <vector>
#include <unordered_map>
#include <iostream>
#include <irrlicht.h>
#include "../include/enums.hpp"

class Paths {
    public:
        Paths();
        ~Paths();
        void pushBack(KeySet val);
        std::int64_t size();
        KeySet atIndex(std::int64_t i);
        void fusionAtBack(Paths &other);
        void setPlayerFound(bool val);
        void calcScore();
        std::int64_t getScore();
        irr::s32 distance(irr::core::vector2di target);
        void setPos(irr::core::vector2di newPos);
        irr::core::vector2di getPos();
        bool isPosSet();

    private:
        irr::core::vector2di _myPos;
        bool _isPosSet;
        std::int64_t _score;
        bool _isPlayerFound;
        std::vector<KeySet> _list;
};

#endif /* !PATHS_CLASS_HPP_ */
