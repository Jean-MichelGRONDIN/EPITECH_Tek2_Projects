/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Settings
*/

#include "Settings.hpp"

Settings::Settings(ICameraSceneNode *cam, Indie::STATE &indieState, IrrWindow &window, IrrlichtDevice *device, std::shared_ptr<GameSettings> settings,
            Indie::STATE curentState, vector3df pos, vector3df rot) : GamePart(cam, indieState, settings, curentState, pos, rot), _music(MUSIC_SETTINGS, true)
{
    _guiEnv = window.getgui()->getGuiEnv();
    _music.initMusic();
    _playButton = _guiEnv->addButton(irr::core::rect<irr::s32>(60,10,60 + 150, 10 + 20),0, newId(), L"Go Back");

    _playersTab = _guiEnv->addTabControl(irr::core::rect<irr::s32>(60,60,60 + 300, 60 + 250), 0, true);
    _p1Tab = _playersTab->addTab(L"Player 1");
    _p2Tab = _playersTab->addTab(L"Player 2");
    _guiEnv->addStaticText(L"Go up", irr::core::rect<irr::s32>(10,10,10 + 150, 10 + 25), false, true, _p1Tab);
    s32 tmp = newId();
    _keyToBind.insert({tmp, {'1', KeySet::UP}});
    _buttonSave.insert({tmp, _guiEnv->addButton(irr::core::rect<irr::s32>(160,10,160 + 20, 10 + 25), _p1Tab, tmp, L"Z", L"Up Key")});

    _guiEnv->addStaticText(L"Go Right", irr::core::rect<irr::s32>(10,30,10 + 150, 30 + 25), false, true, _p1Tab);
    tmp = newId();
    _keyToBind.insert({tmp, {'1', KeySet::RIGHT}});
    _buttonSave.insert({tmp, _guiEnv->addButton(irr::core::rect<irr::s32>(160, 30,160 + 20, 30 + 25), _p1Tab, tmp, L"D", L"Right Key")});

    _guiEnv->addStaticText(L"Go left", irr::core::rect<irr::s32>(10,50,10 + 150, 50 + 25), false, true, _p1Tab);
    tmp = newId();
    _keyToBind.insert({tmp, {'1', KeySet::LEFT}});
    _buttonSave.insert({tmp, _guiEnv->addButton(irr::core::rect<irr::s32>(160,50,160 + 20, 50 + 25), _p1Tab, tmp, L"Q", L"Left Key")});

    _guiEnv->addStaticText(L"Go down", irr::core::rect<irr::s32>(10,70,10 + 150, 70 + 25), false, true, _p1Tab);
    tmp = newId();
    _keyToBind.insert({tmp, {'1', KeySet::DOWN}});
    _buttonSave.insert({tmp, _guiEnv->addButton(irr::core::rect<irr::s32>(160,70,160 + 20, 70 + 25), _p1Tab, tmp, L"S", L"Down Key")});

    _guiEnv->addStaticText(L"Place Bombe", irr::core::rect<irr::s32>(10,90,10 + 150, 90 + 25), false, true, _p1Tab);
    tmp = newId();
    _keyToBind.insert({tmp, {'1', KeySet::BOMBE}});
    _buttonSave.insert({tmp, _guiEnv->addButton(irr::core::rect<irr::s32>(160,90,160 + 20, 90 + 25), _p1Tab, tmp, L"E", L"Bombe Key")});



    _guiEnv->addStaticText(L"Go up", irr::core::rect<irr::s32>(10,10,10 + 150, 10 + 25), false, true, _p2Tab);
    tmp = newId();
    _keyToBind.insert({tmp, {'2', KeySet::UP}});
    _buttonSave.insert({tmp, _guiEnv->addButton(irr::core::rect<irr::s32>(160,10,160 + 20, 10 + 25), _p2Tab, tmp, L"Z", L"Up Key")});

    _guiEnv->addStaticText(L"Go Right", irr::core::rect<irr::s32>(10,30,10 + 150, 30 + 25), false, true, _p2Tab);
    tmp = newId();
    _keyToBind.insert({tmp, {'2', KeySet::RIGHT}});
    _buttonSave.insert({tmp, _guiEnv->addButton(irr::core::rect<irr::s32>(160, 30,160 + 20, 30 + 25), _p2Tab, tmp, L"D", L"Right Key")});

    _guiEnv->addStaticText(L"Go left", irr::core::rect<irr::s32>(10,50,10 + 150, 50 + 25), false, true, _p2Tab);
    tmp = newId();
    _keyToBind.insert({tmp, {'2', KeySet::LEFT}});
    _buttonSave.insert({tmp, _guiEnv->addButton(irr::core::rect<irr::s32>(160,50,160 + 20, 50 + 25), _p2Tab, tmp, L"Q", L"Left Key")});

    _guiEnv->addStaticText(L"Go down", irr::core::rect<irr::s32>(10,70,10 + 150, 70 + 25), false, true, _p2Tab);
    tmp = newId();
    _keyToBind.insert({tmp, {'2', KeySet::DOWN}});
    _buttonSave.insert({tmp, _guiEnv->addButton(irr::core::rect<irr::s32>(160,70,160 + 20, 70 + 25), _p2Tab, tmp, L"S", L"Down Key")});

    _guiEnv->addStaticText(L"Place Bombe", irr::core::rect<irr::s32>(10,90,10 + 150, 90 + 25), false, true, _p2Tab);
    tmp = newId();
    _keyToBind.insert({tmp, {'2', KeySet::BOMBE}});
    _buttonSave.insert({tmp, _guiEnv->addButton(irr::core::rect<irr::s32>(160,90,160 + 20, 90 + 25), _p2Tab, tmp, L"E", L"Bombe Key")});

    _binding = false;
    hidElem();
}

Settings::~Settings()
{
}

void Settings::hidElem()
{
    _playersTab->setVisible(false);
    _playButton->setVisible(false);
    _music.stopMusic();
    _first = true;
}

void Settings::dispElem()
{
    _playersTab->setVisible(true);
    _playButton->setVisible(true);
    _music.playMusic();
}

void Settings::update()
{
    GamePart::update();
    if (!isActive())
        return;
    if (_first)
        dispElem();
    _first = false;
}
bool Settings::onEvent(const irr::SEvent& event)
{
    if (!isActive())
        return (false);
    if (event.EventType == irr::EET_GUI_EVENT) {
        if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED && event.GUIEvent.Caller->getID() == _playButton->getID()) {
            hidElem();
            _indieState = _settings->getPrevState();
            return (true);
        }
        if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
            if (_binding)
                _buttonSave[_idButton]->setText(_tmp.c_str());
            _idButton = event.GUIEvent.Caller->getID();
            _tmp = _buttonSave[_idButton]->getText();
            _buttonSave[_idButton]->setText(L"_");
            _binding = true;
            return (true);
        }
    }
    if (event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.PressedDown && _binding == true) {
        std::wstring tmp = L"";
        tmp += event.KeyInput.Char;
        _buttonSave[_idButton]->setText(tmp.c_str());
        _binding = false;
        _settings->setKeyForP( _keyToBind[_idButton].first, _keyToBind[_idButton].second, event.KeyInput.Key);
    }
    return (false);
}