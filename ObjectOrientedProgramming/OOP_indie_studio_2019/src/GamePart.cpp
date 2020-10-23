/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** GamePart
*/

#include "GamePart.hpp"

GamePart::GamePart(ICameraSceneNode *cam, Indie::STATE &indieState, std::shared_ptr<GameSettings> settings, Indie::STATE currentState, vector3df pos, vector3df target) :_indieState( indieState)
{
    _cam = cam;
    _currentState = currentState;
    _pos = pos;
    _target = target;
    _settings = settings;
}

GamePart::~GamePart()
{
}

void GamePart::update()
{
    if (isSwitching()) {
        moveCame();
    }
}

bool GamePart::isSwitching()
{
    if (_indieState != _currentState)
        return (false);
    if (_cam->getPosition() != _pos || _cam-> getTarget() != _target)
        return (true);
    return (false);
}

bool GamePart::isActive() {
    if (!isSwitching() && _indieState == _currentState)
        return (true);
    return (false);
}

void GamePart::moveCame()
{
    _cam->setPosition(_pos);
    _cam->setTarget(_target);
}

bool GamePart::onEvent(const irr::SEvent& event)
{
    return (false);
}