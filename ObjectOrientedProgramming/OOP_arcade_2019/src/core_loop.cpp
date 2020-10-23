/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** core_loop
*/

#include "../include/arcade.hpp"

void nextlib(int &iLib, int size)
{
    if (iLib == size - 1) {
        iLib = 0;
    } else {
        iLib++;
    }
}

void handleActionLib(Action &ret, int &iLib,
    std::vector<std::shared_ptr<libLoader<ILib>>> &libs)
{
    switch (ret)
    {
    case SWITCH_SFML:
        iLib = getLibIndex<ILib>(libs, "lib_arcade_sfml.so");
        break;
    case SWITCH_SDL:
        iLib = getLibIndex<ILib>(libs, "lib_arcade_sdl2.so");
        break;
    case SWITCH_NCURS:
        iLib = getLibIndex<ILib>(libs, "lib_arcade_ncurses.so");
        break;
    }
}

void handleActionGame(Action &ret, int &iGame,
    std::vector<std::shared_ptr<libLoader<IGame>>> &games)
{
    switch (ret)
    {
    case GO_TO_MENU:
        iGame = getLibIndex<IGame>(games, "menu.so");
        break;
    case GO_TO_NIBBLER:
        iGame = getLibIndex<IGame>(games, "lib_arcade_nibbler.so");
        break;
    case GO_TO_SOLARFOX:
        iGame = getLibIndex<IGame>(games, "lib_arcade_solarfox.so");
        break;
    }
}

Action core_loop(std::vector<std::shared_ptr<libLoader<ILib>>> &libs,
    std::vector<std::shared_ptr<libLoader<IGame>>> &games,
    int &iLib, int &iGame)
{
    ILib *lib = libs[iLib]->getlib();
    IGame *game = games[iGame]->getlib();
    Action ret = GO_TO_GAME;

    game->initialiseGame(lib);
    game->launchGame(lib);
    while ((ret = game->gameIsFinished(lib)) == GO_TO_GAME) {
        game->gameMechanics(lib);
        game->gameEvents(lib);
        game->refreshWindow(lib);
    }
    game->closeGame(lib);
    if (ret == SWITCH_LIB) {
        nextlib(iLib, libs.size());
    }
    if (ret != QUIT_PROG && ret != SWITCH_LIB) {
        handleActionGame(ret, iGame, games);
        handleActionLib(ret, iLib, libs);
    }
    return (ret);
}