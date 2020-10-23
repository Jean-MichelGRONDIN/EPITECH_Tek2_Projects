/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** gameSolarFox
*/

#include "./gameSolarFox.hpp"

gameSolarFox::gameSolarFox()
{
    this->_name = "SolarFox";
    this->_finished = GO_TO_GAME;
}


gameSolarFox::~gameSolarFox()
{
}

std::string gameSolarFox::getName()
{
    return (this->_name);
}

State gameSolarFox::initialiseMenu(ILib *lib)
{
    return (FAILURE);
}

State gameSolarFox::launchMenu(ILib *lib)
{
    return (FAILURE);
}

State gameSolarFox::closeMenu(ILib *lib)
{
    return (FAILURE);
}

State gameSolarFox::initialiseGame(ILib *lib)
{
    this->_finished = GO_TO_GAME;
    return (SUCCESS);
}

State gameSolarFox::launchGame(ILib *lib)
{
    lib->windowOpen();
    if (lib->windowIsOpen() == true) {
        return (SUCCESS);
    }
    return (FAILURE);
}

State gameSolarFox::closeGame(ILib *lib)
{
    lib->windowClose();
    if (lib->windowIsOpen() == false) {
        return (SUCCESS);
    }
    return (FAILURE);
}

State gameSolarFox::refreshWindow(ILib *lib)
{
    lib->windowClear();
    lib->windowDisplay();
    return (SUCCESS);
}

State gameSolarFox::gameMechanics(ILib *lib)
{
    lib->windowEvents();
    return (SUCCESS);
}

Action gameSolarFox::gameIsFinished(ILib *lib)
{
    return (this->_finished);
}

State gameSolarFox::gameEvents(ILib *lib)
{
    State ret = FAILURE;

    if (lib->windowCloseEvent() == true) {
        this->_finished = QUIT_PROG;
        ret = SUCCESS;
    }
    if (lib->switchLibEvent() == true) {
        this->_finished = SWITCH_LIB;
        ret = SUCCESS;
    }
    if (lib->backMenuEvent() == true) {
        this->_finished = GO_TO_MENU;
        ret = SUCCESS;
    }
    return (ret);
}

extern "C" {
    gameSolarFox *constuct() {
        return new gameSolarFox();
    }
}