/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Menu
*/

#include "./menu.hpp"

Menu::Menu()
{
    this->_name = "menu";
    this->_finished = GO_TO_GAME;
    this->_iMenu = 1;
}

Menu::~Menu()
{
}

std::string Menu::getName()
{
    return (this->_name);
}

State Menu::initialiseMenu(ILib *lib)
{
    return (FAILURE);
}

State Menu::launchMenu(ILib *lib)
{
    return (FAILURE);
}

State Menu::closeMenu(ILib *lib)
{
    return (FAILURE);
}

State Menu::initialiseGame(ILib *lib)
{
    this->_finished = GO_TO_GAME;
    if (lib->initAsset("menu1", "./Assets/menu/1.png", 0, 0) == FAILURE)
        return (FAILURE);
    if (lib->initAsset("menu2", "./Assets/menu/2.png", 0, 0) == FAILURE)
        return (FAILURE);
    if (lib->initAsset("menu3", "./Assets/menu/3.png", 0, 0) == FAILURE)
        return (FAILURE);
    if (lib->initAsset("menu4", "./Assets/menu/4.png", 0, 0) == FAILURE)
        return (FAILURE);
    if (lib->initAsset("menu5", "./Assets/menu/5.png", 0, 0) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

State Menu::launchGame(ILib *lib)
{
    lib->windowOpen();
    if (lib->windowIsOpen() == true) {
        return (SUCCESS);
    }
    return (FAILURE);
}

State Menu::closeGame(ILib *lib)
{
    lib->windowClose();
    if (lib->windowIsOpen() == false) {
        return (SUCCESS);
    }
    return (FAILURE);
}

State Menu::drawMenu(ILib *lib)
{
    if (this->_iMenu == 1) {
        lib->drawAsset("menu1");
        return (SUCCESS);
    }
    if (this->_iMenu == 2) {
        lib->drawAsset("menu2");
        return (SUCCESS);
    }
    if (this->_iMenu == 3) {
        lib->drawAsset("menu3");
        return (SUCCESS);
    }
    if (this->_iMenu == 4) {
        lib->drawAsset("menu4");
        return (SUCCESS);
    }
    if (this->_iMenu == 5) {
        lib->drawAsset("menu5");
        return (SUCCESS);
    }
    return (FAILURE);
}

State Menu::refreshWindow(ILib *lib)
{
    lib->windowClear();
    this->drawMenu(lib);
    lib->windowDisplay();
    return (SUCCESS);
}

State Menu::gameMechanics(ILib *lib)
{
    lib->windowEvents();
    return (SUCCESS);
}

Action Menu::gameIsFinished(ILib *lib)
{
    return (this->_finished);
}

State Menu::changeLabel()
{
    if (this->_iMenu > 2) {
        this->_iMenu = 1;
    } else {
        this->_iMenu = 3;
    }
    return (SUCCESS);
}

State Menu::moveList(int action)
{
    if (this->_iMenu < 3) {
        this->_iMenu += action;
        if (this->_iMenu < 1) {
            this->_iMenu = 2;
        } else if (this->_iMenu > 2) {
            this->_iMenu = 1;
        }
    } else {
        this->_iMenu += action;
        if (this->_iMenu < 3) {
            this->_iMenu = 5;
        } else if (this->_iMenu > 5) {
            this->_iMenu = 3;
        }
    }
    return (SUCCESS);
}

Action Menu::getSwitchAction()
{
    if (this->_iMenu == 1) {
        return (GO_TO_NIBBLER);
    }
    if (this->_iMenu == 2) {
        return (GO_TO_SOLARFOX);
    }
    if (this->_iMenu == 3) {
        return (SWITCH_SFML);
    }
    if (this->_iMenu == 4) {
        return (SWITCH_SDL);
    }
    return (SWITCH_NCURS);
}

State Menu::gameEvents(ILib *lib)
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
    if (lib->leftArrowEvent() == true) {
        this->changeLabel();
        ret = SUCCESS;
    }
    if (lib->rightArrowEvent() == true) {
        this->changeLabel();
        ret = SUCCESS;
    }
    if (lib->upArrowEvent() == true) {
        this->moveList(-1);
        ret = SUCCESS;
    }
    if (lib->downArrowEvent() == true) {
        this->moveList(1);
        ret = SUCCESS;
    }
    if (lib->EnterEvent() == true) {
        this->_finished = this->getSwitchAction();
        ret = SUCCESS;
    }
    return (ret);
}

extern "C" {
    Menu *constuct() {
        return new Menu();
    }
}