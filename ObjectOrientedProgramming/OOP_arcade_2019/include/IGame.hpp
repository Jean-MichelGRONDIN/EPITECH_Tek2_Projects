/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "./ILib.hpp"

class IGame {
    public:
        virtual State initialiseMenu(ILib *lib) = 0;
        virtual State launchMenu(ILib *lib) = 0;
        virtual State closeMenu(ILib *lib) = 0;
        virtual State initialiseGame(ILib *lib) = 0;
        virtual State launchGame(ILib *lib) = 0;
        virtual State closeGame(ILib *lib) = 0;
        virtual State refreshWindow(ILib *lib) = 0;
        virtual State gameMechanics(ILib *lib) = 0;
        virtual Action gameIsFinished(ILib *lib) = 0;
        virtual State gameEvents(ILib *lib) = 0;
        virtual std::string getName() = 0;

    protected:
    private:
};

#endif