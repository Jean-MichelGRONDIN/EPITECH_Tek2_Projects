/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** enums
*/

#ifndef ENUMS_HPP_
#define ENUMS_HPP_

enum State {
    SUCCESS = 1,
    FAILURE = -1
};

enum Action {
    QUIT_PROG = 51,
    GO_TO_GAME = 52,
    GO_TO_MENU = 53,
    SWITCH_LIB = 54,
    GO_TO_NIBBLER = 55,
    GO_TO_SOLARFOX = 56,
    SWITCH_SFML = 57,
    SWITCH_SDL = 58,
    SWITCH_NCURS = 59,
    NOTHING = -51
};

#define WIDTH 900
#define HEIGTH 500

#endif