/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** pathFinder
*/

#ifndef PATHFINDER_HPP_
#define PATHFINDER_HPP_

#include <vector>
#include <iostream>
#include <memory>
#include <irrlicht.h>

#include "../include/enums.hpp"

#include "PathsClass.hpp"

#define BOMBE_RANGE 3

class pathFinder
{
    public:
        pathFinder(char player, std::shared_ptr<irr::s32> pa, std::shared_ptr<irr::s32> bombrange, std::shared_ptr<irr::f32> movespeed);
        ~pathFinder();
        std::vector<std::string> copyMap(std::string *mapObj, std::uint64_t size);
        std::vector<std::string> copyMap(std::vector<std::string> mapObj, std::uint64_t size);
        void emptyMap();
        void drawBombsRange(std::string *mapTxt, std::uint64_t size);
        void drawBombsRange(std::vector<std::string> mapTxt, std::uint64_t size);
        KeySet getPath(const std::unordered_map<char, irr::core::vector2di> &playerList,
            std::string *mapObjs, std::uint64_t size);
        void explodeLeft(std::int64_t i, std::int64_t iTwo, irr::s32 range);
        void explodeRigth(std::int64_t i, std::int64_t iTwo, irr::s32 range);
        void explodeUp(std::int64_t i, std::int64_t iTwo, irr::s32 range);
        void explodeBot(std::int64_t i, std::int64_t iTwo, irr::s32 range);
        irr::core::vector2di getThisPlayerPos(char p,
            const std::unordered_map<char, irr::core::vector2di> &playerList, std::uint64_t size);
        irr::core::vector2di getUpPos(irr::core::vector2di pos);
        irr::core::vector2di getDownPos(irr::core::vector2di pos);
        irr::core::vector2di getLeftPos(irr::core::vector2di pos);
        irr::core::vector2di getRigthPos(irr::core::vector2di pos);
        Paths findShortestPathAnalyse(irr::core::vector2di player,
            irr::core::vector2di enemy, KeySet action, std::vector<irr::core::vector2di> oldPos);
        Paths findShortestPath(irr::core::vector2di player,
            irr::core::vector2di enemy, std::vector<irr::core::vector2di> oldPos);
        Paths runShortestPathAnalyse(irr::core::vector2di player,
            irr::core::vector2di enemy, KeySet action, std::vector<irr::core::vector2di> oldPos);
        Paths runShortestPath(irr::core::vector2di player,
            irr::core::vector2di enemy, std::vector<irr::core::vector2di> oldPos);
        char getclosestEnemy(char p, irr::core::vector2di pos,
            const std::unordered_map<char, irr::core::vector2di> &playerList, std::uint64_t size);
        std::int64_t getThisDistance(irr::core::vector2di one, irr::core::vector2di two);
        bool wasAlreadyHere(irr::core::vector2di player, std::vector<irr::core::vector2di> oldPos);
        irr::core::vector2di reverseMove(irr::core::vector2di player, KeySet action);
    private:
        std::vector<std::string> _map;
        // const std::uint64_t _bombRange;
        const char _player;
        std::vector<char> _playersList;
        std::shared_ptr<irr::s32> _pa;
        std::shared_ptr<irr::s32> _bombrange;
        std::shared_ptr<irr::f32> _movespeed;
};


#endif