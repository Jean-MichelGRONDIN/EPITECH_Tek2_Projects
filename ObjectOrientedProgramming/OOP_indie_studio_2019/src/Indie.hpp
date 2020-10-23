/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Indie
*/

#ifndef INDIE_HPP_
#define INDIE_HPP_

#include <irrlicht.h>
#include "enums.hpp"
#include "IPart.hpp"
#include <iostream>
#include <memory>
#include <unordered_map>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class GamePart;
class GameSettings;
class Indie {
    public:
        enum STATE {
            MENU,
            GAME,
            SETTINGS,
            END,
            SKIN
        };
        Indie();
        ~Indie();
        void run();

    private:
        IrrWindow _window;
        MyEventRecever *_EventRecerver;
        ICameraSceneNode *_cam;
        std::shared_ptr<GamePart> _game;
        std::shared_ptr<GamePart> _menu;
        std::shared_ptr<GamePart> _settingsPart;
        std::shared_ptr<GamePart> _endGame;
        std::shared_ptr<GamePart> _skin;
        std::unordered_map<int, IPart *> _partList;
        STATE _current_state;
        std::shared_ptr<GameSettings> _settings;
};

#endif