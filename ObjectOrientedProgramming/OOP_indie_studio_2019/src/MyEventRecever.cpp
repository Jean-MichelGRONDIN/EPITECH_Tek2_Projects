/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** MyEventRecever
*/

#include "MyEventRecever.hpp"
#include "paths.hpp"
#include <iostream>

MyEventRecever::MyEventRecever(std::shared_ptr<IrrGui> irrGui, std::shared_ptr<IrrScean> irrScean) : _sound(SOUND_CLICK)
{
    _irrGui = irrGui;
    _irrScean = irrScean;
}

MyEventRecever::~MyEventRecever()
{
}

bool MyEventRecever::OnEvent(const irr::SEvent& event)
{
    // if (event.EventType == irr::EET_GUI_EVENT) {
    //     return (_irrGui->manageEvent(event));
    // }
    if (event.EventType == irr::EET_GUI_EVENT) {
        if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
            _sound.play();
    }
    return (_irrScean->onEvent(event));
}
