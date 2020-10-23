/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** CamManager
*/

#include "CamManager.hpp"
#include <iostream>

CamManager::CamManager(std::shared_ptr<IrrGui> gui, std::shared_ptr<IrrScean> scean)
{
    _gui = gui;
    _creatCam = std::make_shared<CreatorCam>(_gui, scean);
    _DispWin = _gui->getGuiEnv()->addButton(irr::core::rect<irr::s32>(10,10,10 + 78, 10 + 56), 0, _gui->getNewId());
    _gui->addItem(_DispWin->getID(), this);
    _DispWin->setImage(_gui->getGuiEnv()->getVideoDriver()->getTexture("../assets/icons8-video-camera-100.png"));
}

CamManager::~CamManager()
{
}

void CamManager::addCam()
{
    return (_creatCam->displayWin());
}


bool CamManager::onEvent(const irr::SEvent& event) {
    if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
        if (_DispWin->getID() == event.GUIEvent.Caller->getID()) {
            addCam();
            return (true);
        }
    }
    return (false);
}