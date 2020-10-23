/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** GamePart
*/

#ifndef GAMEPART_HPP_
#define GAMEPART_HPP_

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#include "Indie.hpp"
#include "ISceanObject.hpp"
#include "GameSettings.hpp"

s32 newId();


class GamePart : public IEventHandeler, public ISceanObject {
    public:
        GamePart(ICameraSceneNode *_cam, Indie::STATE &indieState, std::shared_ptr<GameSettings> settings, Indie::STATE currentState, vector3df pos, vector3df target);
        ~GamePart();
        virtual void update() override;
        virtual bool onEvent(const irr::SEvent& event) override;
        bool isSwitching();
        bool isActive();
        void moveCame();


    protected:
        std::shared_ptr<GameSettings> _settings;
        ICameraSceneNode *_cam;
        Indie::STATE &_indieState;
        Indie::STATE _currentState;
        vector3df _pos;
        vector3df _target;
    private:
};

#endif /* !GAMEPART_HPP_ */
