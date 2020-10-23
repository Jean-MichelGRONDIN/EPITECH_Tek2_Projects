/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** gameNibbler
*/

#include "./gameNibbler.hpp"

gameNibbler::gameNibbler()
{
    this->_name = "Nibbler";
    this->_finished = GO_TO_GAME;
}


gameNibbler::~gameNibbler()
{
}

std::string gameNibbler::getName()
{
    return (this->_name);
}

State gameNibbler::initialiseMenu(ILib *lib)
{
    return (FAILURE);
}

State gameNibbler::launchMenu(ILib *lib)
{
    return (FAILURE);
}

State gameNibbler::closeMenu(ILib *lib)
{
    return (FAILURE);
}

State gameNibbler::initialiseGame(ILib *lib)
{
    this->_finished = GO_TO_GAME;

    if (lib->initAsset("background", "./Assets/nibbler/baskground_nibller.png", 0, 0) == SUCCESS) {
    }
    if (lib->initAsset("player", "./Assets/nibbler/player_nibller.png", 0, 0) == SUCCESS) {
        lib->setPos("player", 27, 59);
    }
    return (SUCCESS);
}

State gameNibbler::launchGame(ILib *lib)
{
    lib->windowOpen();
    if (lib->windowIsOpen() == true) {
        return (SUCCESS);
    }
    return (FAILURE);
}

State gameNibbler::closeGame(ILib *lib)
{
    lib->windowClose();
    if (lib->windowIsOpen() == false) {
        return (SUCCESS);
    }
    return (FAILURE);
}

State gameNibbler::refreshWindow(ILib *lib)
{
    lib->windowClear();
    lib->drawAsset("background");
    lib->drawAsset("player");
    lib->windowDisplay();
    return (SUCCESS);
}

State gameNibbler::gameMechanics(ILib *lib)
{
    lib->windowEvents();
    return (SUCCESS);
}

Action gameNibbler::gameIsFinished(ILib *lib)
{
    return (this->_finished);
}

State gameNibbler::gameEvents(ILib *lib)
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
    if (lib->leftArrowEvent() == true && lib->getPosX("player") - 16 >= 27) {
        lib->setPos("player", lib->getPosX("player") - 16, lib->getPosY("player"));
        ret = SUCCESS;
    }
    if (lib->rightArrowEvent() == true && lib->getPosX("player") + 16 <= 874) {
        lib->setPos("player", lib->getPosX("player") + 16, lib->getPosY("player"));
        ret = SUCCESS;
    }
    if (lib->upArrowEvent() == true && lib->getPosY("player") - 16 >= 59) {
        lib->setPos("player", lib->getPosX("player"), lib->getPosY("player") - 16);
        ret = SUCCESS;
    }
    if (lib->downArrowEvent() == true && lib->getPosY("player") + 16 < 427) {
        lib->setPos("player", lib->getPosX("player"), lib->getPosY("player") + 16);
        ret = SUCCESS;
    }
    return (ret);
}

extern "C" {
    gameNibbler *constuct() {
        return new gameNibbler();
    }
}