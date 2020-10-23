/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** GameSettings
*/

#ifndef GAMESETTINGS_HPP_
#define GAMESETTINGS_HPP_

#include <irrlicht.h>
#include <unordered_map>
#include "Player.hpp"
#include "enums.hpp"
#include "Indie.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class GameSettings {
    public:
        GameSettings();
        ~GameSettings();
        s32 getNbPlayer();
        void setNbPlayer(s32 nb);
        void setKeyForP(char p, KeySet, EKEY_CODE);
        std::shared_ptr<std::unordered_map<KeySet, EKEY_CODE>> getKeyForP(char p);
        void setPlayerTexture(std::string);
        std::string getTexForP(int);
        void setPreveState(Indie::STATE);
        Indie::STATE getPrevState();
    protected:
        s32 _nbPlayer;
        std::shared_ptr<std::unordered_map<KeySet, EKEY_CODE>> _keysMapOne;
        std::shared_ptr<std::unordered_map<KeySet, EKEY_CODE>> _keysMapTwo;
        std::shared_ptr<std::unordered_map<KeySet, EKEY_CODE>> _keysMapThree;
        std::shared_ptr<std::unordered_map<KeySet, EKEY_CODE>> _keysMapFor;
        std::vector<std::string> _playerTex;
        Indie::STATE _preveState;
    private:
};

#endif /* !GAMESETTINGS_HPP_ */
