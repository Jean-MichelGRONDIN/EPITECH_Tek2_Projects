/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "IPart.hpp"
#include "enums.hpp"
#include "paths.hpp"

#include <irrlicht.h>
#include "IrrWindow.hpp"
#include "CamManager.hpp"
#include "Player.hpp"
#include <iostream>
#include <memory>
#include "Map.hpp"
#include "GamePart.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


class Game : public GamePart {
    public:
        Game(ICameraSceneNode *cam, Indie::STATE &indieState, ISceneManager *smgr, IVideoDriver *driver, IrrlichtDevice *device, std::shared_ptr<GameSettings> settings,
            Indie::STATE curentState = Indie::GAME, vector3df pos = vector3df(140.0F, 160.0F, 70.0F), vector3df tagret = vector3df(90.0F, 0.0F, 70.0F));
        ~Game();
        void endGame();
        void updatePlayer();
        virtual void update() override;
        virtual bool onEvent(const irr::SEvent& event) override;
        bool checkAlive();
    private:
        std::shared_ptr<MapManager> _map;
        IVideoDriver *_driver;
        IrrlichtDevice *_device;
        ISceneManager* _smgr;
        std::list<std::shared_ptr<Player>> _players;
        std::list<std::shared_ptr<Player>> _alivePlayers;
        IGUIButton *_settingsB;
        std::shared_ptr<Musical> _musicGame;
        bool _firstCome;
        bool _updatePlayer;
         //IGUIButton *_1;
         //IGUIButton *_2;
         //IGUIButton *_3;
         //IGUIButton *_4;
         //IGUIButton *_5;
         //IGUIButton *_6;

         //IGUIButton *_11;
         //IGUIButton *_21;
         //IGUIButton *_31;
         //IGUIButton *_41;
         //IGUIButton *_51;
         //IGUIButton *_61;

};


#endif /* !GAME_HPP_ */
