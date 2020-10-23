/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** arcade
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

#include "../include/LibLoader.hpp"
#include "../include/includes.hpp"

template <typename T>
int getLibIndex(std::vector<std::shared_ptr<libLoader<T>>> &lib, std::string cmp)
{
    int i = 0;

    for (; i != lib.size() ;) {
        if (cmp.compare(lib[i]->getName()) == 0)
            return (i);
        i++;
    }
    return (-1);
};

void nextlib(int &iLib, int size);
void handleActionLib(Action &ret, int &iLib,
    std::vector<std::shared_ptr<libLoader<ILib>>> &libs);
void handleActionGame(Action &ret, int &iGame,
    std::vector<std::shared_ptr<libLoader<IGame>>> &games);
Action core_loop(std::vector<std::shared_ptr<libLoader<ILib>>> &libs,
    std::vector<std::shared_ptr<libLoader<IGame>>> &games,
    int &iLib, int &iGame);

#endif