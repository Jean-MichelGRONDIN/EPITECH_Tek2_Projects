/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_
#include <unordered_map>
#include <list>
#include "IMapElem.hpp"
#include <irrlicht.h>
#include <iostream>
#include <fstream>

class ABonus;

using namespace irr;

class Bombe;
class Player;

class MapManager {
    public:
        enum TPYE_ELEM {
            GROUND,
            WALL,
            ITEM,
            BOX,
            PLAYER_ONE,
            PLAYER_TWO,
            PLAYER_THREE,
            PLAYER_FOR,
            BOMBE
        };
        void initSym(std::string tmp);
        MapManager(irr::scene::ISceneManager *scenemgr, const std::string &pathMap, irr::video::IVideoDriver *driver, irr::IrrlichtDevice *device, int nbP);
        ~MapManager();
        void addGroud();
        void update();
        void update(std::uint64_t row);
        void placeBomb(char sym, std::shared_ptr<Bombe>);
        std::unordered_map<int, EKEY_CODE> createMovKey(EKEY_CODE up, EKEY_CODE down, EKEY_CODE left, EKEY_CODE right, EKEY_CODE bomb);
        void removeBombe(std::uint64_t& row, std::uint64_t& column);
        void getSymPos(char sym, std::uint64_t &row, std::uint64_t &column);
        irr::core::vector3df getPosPlayer(char sym);
        const std::unordered_map<char, irr::core::vector2di> &getPlayersPos();
        void updatePlayerPos(char sym, irr::core::vector3df newPos, std::uint64_t &current_row, std::uint64_t &current_col);
        std::list<std::shared_ptr<IMapElem>> getElemAt(std::uint64_t row, std::uint64_t column);
        irr::scene::IMetaTriangleSelector *getSelector(char sym);
        std::shared_ptr<Player> getPlayer(char sym);
        bool outOfRange(std::uint64_t row, std::uint64_t column);
        bool isAWall(std::list<std::shared_ptr<IMapElem>>);
        std::string *getMapTxt();
        std::string* getMapObs();
        void creatObsMap();
        void removeBox(std::uint64_t row, std::uint64_t column);
        std::uint64_t getMapSize();
        irr::video::IVideoDriver *getDriver();
        void addBonus(std::uint64_t row, std::uint64_t column, std::list<std::shared_ptr<IMapElem>> &);
    protected:
        std::unordered_map<char, irr::scene::IMetaTriangleSelector *> _selectors;
        irr::video::IVideoDriver *_driver;
        std::unordered_map<std::uint64_t, std::unordered_map<std::uint64_t, std::list<std::shared_ptr<IMapElem>>>> _map;
        std::string *_mapTxt;
        std::string* _mapObs;
        std::uint64_t _sizeMap;
        irr::IrrlichtDevice *_device;
        irr::scene::ISceneManager *_smgr;
        std::unordered_map<char, std::shared_ptr<Player>> _players;
        std::unordered_map<char, irr::core::vector2di> _playersPos;
        std::unordered_map<TPYE_ELEM, char> _syms;
        std::unordered_map< std::string, std::shared_ptr<ABonus>> _bonusMap;
        int _nbP;
    private:
};

#endif /* !MAP_HPP_ */
