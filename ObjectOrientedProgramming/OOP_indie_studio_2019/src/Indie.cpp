/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Indie
*/

#include "Indie.hpp"
#include "Game.hpp"
#include "Menu.hpp"
#include "Settings.hpp"
#include "EndGame.hpp"
#include "Skin.hpp"

s32 newId()
{
    static s32 id = 0;
    id++;
    return (id);
}

Indie::Indie() : _current_state(Indie::MENU)
{
    this->_EventRecerver = new MyEventRecever(this->_window.getgui(), this->_window.getscean());
    this->_window.setEventRecever(this->_EventRecerver);
    _cam = _window.getscean()->getScenManger()->addCameraSceneNode();
    _settings = std::make_shared<GameSettings>();
    _skin = std::make_shared<Skin>(_cam, _current_state, _window.getscean()->getScenManger(), _window.getDriver(), _window.getDevice(), _settings);
    _game = std::make_shared<Game>(_cam, _current_state, _window.getscean()->getScenManger(), _window.getDriver(), _window.getDevice(), _settings);
    _endGame = std::make_shared<EndGame>(_cam, _current_state, _window.getscean()->getScenManger(), _window.getDriver(), _window.getDevice(), _settings);
    _menu = std::make_shared<Menu>(_cam, _current_state, _window, _window.getDevice(), _settings);
    _settingsPart = std::make_shared<Settings>(_cam, _current_state, _window, _window.getDevice(), _settings);
    _window.getscean()->addObj(_game);
    _window.getscean()->addEventHandeler(_game);
    _window.getscean()->addEventHandeler(_menu);
    _window.getscean()->addObj(_menu);
    _window.getscean()->addEventHandeler(_settingsPart);
    _window.getscean()->addObj(_settingsPart);
    _window.getscean()->addEventHandeler(_endGame);
    _window.getscean()->addObj(_endGame);
    _window.getscean()->addEventHandeler(_skin);
    _window.getscean()->addObj(_skin);
    // this->_partList.emplace(MENU, new Menu(this->_window, this->_window.getgui()));
    // this->_partList.emplace(GAME, new Game(this->_window));
}

Indie::~Indie()
{
    delete this->_EventRecerver;
}

void Indie::run()
{
    _window.drawGame();
}