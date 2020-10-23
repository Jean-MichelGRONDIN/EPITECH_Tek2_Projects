/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu(ICameraSceneNode *cam, Indie::STATE &indieState, IrrWindow &window, IrrlichtDevice *device, std::shared_ptr<GameSettings> settings,
            Indie::STATE curentState, vector3df pos, vector3df rot) : _window(window), GamePart(cam, indieState, settings, curentState, pos, rot), _sound(SOUND_BUTTON_TOUCH)
{
    _settingsB = window.getgui()->getGuiEnv()->addButton(irr::core::rect<irr::s32>(960, 320, 960 + 78, 320 + 56), 0, newId(), L"settings");
    _playSolo = window.getgui()->getGuiEnv()->addButton(irr::core::rect<irr::s32>(960, 400, 960 + 78, 400 + 56), 0, newId(), L"Solo", L"GO solo!");
    _playMul = window.getgui()->getGuiEnv()->addButton(irr::core::rect<irr::s32>(960,480,960 + 78, 480 + 56), 0, newId(), L"Mul", L"GO Mul!");
    _quit = window.getgui()->getGuiEnv()->addButton(irr::core::rect<irr::s32>(960,560,960 + 78, 560 + 56), 0, newId(), L"Quite", L"By!");
    _device = device;
    _musicMenu = std::make_shared<Musical>(MENUE_MUSIC, true); 
    _musicMenu->initMusic();
    _first = true;
    _isLost = true;
}

Menu::~Menu()
{
}

void Menu::hidElem()
{
    _playMul->setVisible(false);
    _playSolo->setVisible(false);
    _quit->setVisible(false);
    _settingsB->setVisible(false);
    _musicMenu->stopMusic();
    _first = true;
}

void Menu::display()
{
    if (!_first)
        return;
    _playMul->setVisible(true);
    _playSolo->setVisible(true);
    _quit->setVisible(true);
    _settingsB->setVisible(true);
    _musicMenu->playMusic();
    _first = false;
}

void Menu::play()
{
    hidElem();
    _indieState = Indie::SKIN;
}

void Menu::quite()
{
    _device->closeDevice();
}

bool Menu::onEvent(const irr::SEvent& event)
{
    if (!isActive())
        return (false);
    if (!event.EventType == irr::EET_GUI_EVENT)
        return (false);
    if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
        if (event.GUIEvent.Caller->getID() == _playMul->getID()) {
            _settings->setNbPlayer(2);
            play();
            return (true);
        }
        if (event.GUIEvent.Caller->getID() == _playSolo->getID()) {
            _settings->setNbPlayer(1);
            play();
            return (true);
        }
        if (event.GUIEvent.Caller->getID() == _quit->getID()) {
            quite();
            return (true);
        }
        if (event.GUIEvent.Caller->getID() == _settingsB->getID()) {
            hidElem();
            _settings->setPreveState(Indie::MENU);
            _indieState = Indie::SETTINGS;
            return (true);
        }
    }
    if (event.GUIEvent.Caller->getID() >= _settingsB->getID() && event.GUIEvent.Caller->getID() <= _quit->getID()) {
        if (event.GUIEvent.EventType == 2 ) {
            _sound.play();
        }
    }
    return (false);
}

void Menu::update()
{
    GamePart::update();
    if (!isActive())
        return;
    display();
}
