/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** gameSolarFox
*/

#ifndef GAMESOLARFOX_HPP_
#define GAMESOLARFOX_HPP_

#include <string>
#include "../../include/IGame.hpp"

class gameSolarFox : public IGame {
    public:
        gameSolarFox();
        ~gameSolarFox();
        std::string getName();
        State initialiseMenu(ILib *lib);
        State launchMenu(ILib *lib);
        State closeMenu(ILib *lib);
        State initialiseGame(ILib *lib);
        State launchGame(ILib *lib);
        State closeGame(ILib *lib);
        State refreshWindow(ILib *lib);
        State gameMechanics(ILib *lib);
        Action gameIsFinished(ILib *lib);
        State gameEvents(ILib *lib);

    protected:
    private:
        std::string _name;
        Action _finished;
};

#endif