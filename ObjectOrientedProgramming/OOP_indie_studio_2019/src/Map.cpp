/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Map
*/

#include "Map.hpp"
#include "Ground.hpp"
#include "Wall.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Bombe.hpp"
#include "Box.hpp"
#include "Player.hpp"
#include <algorithm>
#include "SpeedUp.hpp"
#include "ABonus.hpp"
#include "SpeedDown.hpp"
#include "RangeBombe.hpp"
MapManager::MapManager(irr::scene::ISceneManager *scenemgr, const std::string &pathMap, irr::video::IVideoDriver *driver, irr::IrrlichtDevice *device, int nbP)
{
    std::ifstream file(pathMap);
    int nb;
    std::string tmp;
    _nbP = nbP;

    if (file.is_open()) {
        getline(file, tmp);
        nb = std::stoi(tmp);
        _mapTxt = new std::string[nb];
        _sizeMap = nb;
        std::uint64_t i = 0;
        getline(file, tmp);
        initSym(tmp);
        while (getline(file, tmp)) {
            _mapTxt[i] = std::string(tmp);
            i++;
        }
        file.close();
    }
    _smgr = scenemgr;
    _driver = driver;
    _selectors.insert({ '1', scenemgr->createMetaTriangleSelector() });
    _selectors.insert({ '2', scenemgr->createMetaTriangleSelector() });
    _selectors.insert({ '3', scenemgr->createMetaTriangleSelector() });
    _selectors.insert({ '4', scenemgr->createMetaTriangleSelector()});
    _device = device;
    _syms.insert({WALL, 'W'});
    creatObsMap();
    addGroud();
}

MapManager::~MapManager()
{
}

void MapManager::removeBox(std::uint64_t row, std::uint64_t column)
{
    _mapObs[row][column] = ' ';
}

irr::scene::IMetaTriangleSelector *MapManager::getSelector(char sym)
{
    return (_selectors[sym]);
}

void MapManager::addGroud()
{
    std::shared_ptr<irr::s32> oui = std::make_shared<irr::s32>(_nbP);
    std::shared_ptr<irr::s32> non = std::make_shared<irr::s32>(5);
    irr::s32 row = 0;
    irr::s32 column = 0;
    std::srand(std::time(nullptr));
    std::unordered_map<int, EKEY_CODE> key = createMovKey(irr::KEY_KEY_Z, irr::KEY_KEY_S, irr::KEY_KEY_Q, irr::KEY_KEY_D, irr::KEY_SPACE);

    for (; row != _sizeMap; row++) {
        std::unordered_map<std::uint64_t, std::list<std::shared_ptr<IMapElem>>> mapRow;
        _map.insert({row, mapRow});
        for (auto col : _mapTxt[row]) {
            std::list<std::shared_ptr<IMapElem>> tmpList;
            tmpList.push_front(std::make_shared<Ground>(this, row, column, _smgr, _driver, _selectors));
            if (col == 'W')
                tmpList.push_front(std::make_shared<Wall>(this, row, column, _smgr, _driver, _selectors));
            if (col == ' ' && (std::rand() % 3) != 2) {
                tmpList.push_front(std::make_shared<Box>(this, row, column, _smgr, _driver, _selectors));
                _mapObs[row][column] = 'B';
                int r = (std::rand() % 5);
                if (r == 0 || r == 1)
                    addBonus(row, column, tmpList);
            }
            if (col >= '1' && col <= '4') {
                _playersPos.insert({ col, irr::core::vector2di(row, column) });
                _players.insert({col, std::make_shared<Player>(_smgr, _device, this, col, non, oui)});
                tmpList.push_front(_players[col]);

            }
            _map[row].insert({column, tmpList});
            column++;
        }
        column = 0;
    }
}

std::unordered_map<int, EKEY_CODE> MapManager::createMovKey(EKEY_CODE up, EKEY_CODE down, EKEY_CODE left, EKEY_CODE right, EKEY_CODE bomb)
{
    std::unordered_map<int, EKEY_CODE> key;
    key.insert({0, up});
    key.insert({1, down});
    key.insert({2, left});
    key.insert({3, right});
    key.insert({4, bomb});
    return key;
}

void MapManager::removeBombe(std::uint64_t& row, std::uint64_t& column)
{
    for (auto tmp : _map[row][column])
        if (tmp->getSym() == 'X') {
            _map[row][column].remove(tmp);
            removeBombe(row, column);
            return;
        }
}

void MapManager::placeBomb(char sym, std::shared_ptr<Bombe> bombe)
{
    std::uint64_t row = 0;
    std::uint64_t column = 0;

    getSymPos(sym, row, column);
    _mapObs[row][column] = bombe->getSymRange();
    _map[row][column].push_back(bombe);
    bombe->bombPlaced(row, column);
}

void MapManager::getSymPos(char sym, std::uint64_t &row, std::uint64_t &column)
{
    if (_playersPos.find(sym) != _playersPos.end()){
        row = _playersPos[sym].X;
        column = _playersPos[sym].Y;
    }
}

irr::core::vector3df MapManager::getPosPlayer(char sym)
{
    std::uint64_t row = 0;
    std::uint64_t column = 0;

    getSymPos(sym, row, column);

    return (irr::core::vector3df(row * CUBE_SIZE + 0.5, 0, column * CUBE_SIZE + 0.5));
}

const std::unordered_map<char, irr::core::vector2di> &MapManager::getPlayersPos()
{
    return (_playersPos);
}

void MapManager::updatePlayerPos(char sym, irr::core::vector3df newPos, std::uint64_t &current_row, std::uint64_t &current_col)
{
    std::uint64_t row = 0;
    std::uint64_t column = 0;
    if (newPos.X > 2000) {
        _playersPos.erase(sym);
        int nb = 0;
        int o = 0;
        for (auto r : _map) {
            o = 0;
            for (auto c : r.second) {
                for (auto l : c.second)
                    if (l->getSym() == sym) {
                        _map[nb][o].remove(_players[sym]);
                    }
                o++;
            }
            nb++;
        }
        return;
    }
    getSymPos(sym, row, column);
    _map[row][column].remove(_players[sym]);
//    _mapTxt[row][column] = ' ';
    row = (newPos.X + 4.2) / CUBE_SIZE;
    column = (newPos.Z + 4.2) / CUBE_SIZE;
    current_row = row;
    current_col = column;
    _playersPos[sym].X = row;
    _playersPos[sym].Y = column;
  //  _mapTxt[row][column] = sym;
    _map[row][column].push_front(_players[sym]);
    auto bonus = _bonusMap.find("" + std::to_string(row) + "+" + std::to_string(column));
    if (bonus != _bonusMap.end()) {
        if (bonus->second->isActiv()) {
            bonus->second->addBonusTo(_players[sym]);
            bonus->second->getHited();
        }
        _map[row][column].remove(bonus->second);
        _bonusMap.erase(bonus);
    }
}

std::string* MapManager::getMapObs()
{
    return (_mapObs);
}

void MapManager::creatObsMap()
{
    _mapObs = new std::string[_sizeMap];
    for (std::uint64_t i = 0; i < _sizeMap; i++) {
        _mapObs[i] = std::string(_mapTxt[i]);
        for (auto& c : _mapObs[i])
            if (c == 'o' || c == '1' || c == '2' || c == '3' || c == '4')
                c = ' ';
    }
}

std::list<std::shared_ptr<IMapElem>> MapManager::getElemAt(std::uint64_t row, std::uint64_t column)
{
    if (outOfRange(row, column))
        throw std::range_error("out of range");
    return (_map[row][column]);
}

std::shared_ptr<Player> MapManager::getPlayer(char sym)
{
    return (_players[sym]);
}

void MapManager::initSym(std::string tmp)
{
}

bool MapManager::outOfRange(std::uint64_t row, std::uint64_t column)
{
    if (row >= _sizeMap)
        return (true);
    if (_mapTxt[row].length() <= column)
        return (true);
    return (false);
}

bool MapManager::isAWall(std::list<std::shared_ptr<IMapElem>> elems)
{
    for (auto tmp : elems) {
        if (tmp->getSym() == _syms[WALL])
            return (true);
    }
    return (false);
}

std::string *MapManager::getMapTxt()
{
    return (_mapTxt);
}

std::uint64_t MapManager::getMapSize()
{
    return (_sizeMap);
}

irr::video::IVideoDriver *MapManager::getDriver()
{
    return _driver;
}

void MapManager::addBonus(std::uint64_t row, std::uint64_t column, std::list<std::shared_ptr<IMapElem>> &tmpList)
{
    int rand = (std::rand() % 6);
    std::shared_ptr<ABonus> tmp;

    switch (rand) {
        case 0:
             tmp = std::make_shared<SpeedUp>(this, row, column, _smgr, _smgr->getVideoDriver());
            break;
        case 1:
             tmp = std::make_shared<SpeedDown>(this, row, column, _smgr, _smgr->getVideoDriver());
            break;
        case 2:
            tmp = std::make_shared<RangeBombe>(this, row, column, _smgr, _smgr->getVideoDriver(), true, true);
            break;
        case 3:
            tmp = std::make_shared<RangeBombe>(this, row, column, _smgr, _smgr->getVideoDriver(), false, true);
            break;
        case 4:
            tmp = std::make_shared<RangeBombe>(this, row, column, _smgr, _smgr->getVideoDriver(), true, false);
            break;
        case 5:
            tmp = std::make_shared<RangeBombe>(this, row, column, _smgr, _smgr->getVideoDriver(), false, false);
            break;
    }


    _bonusMap.insert({ "" + std::to_string(row) + "+" + std::to_string(column), tmp });
    tmpList.push_front(tmp);
}
