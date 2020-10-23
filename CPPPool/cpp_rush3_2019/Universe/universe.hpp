/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** universe
*/

#ifndef UNIVERSE_HPP_
#define UNIVERSE_HPP_

#include "../includeSFML.hpp"
#include "game.hpp"

class universe {
    public:
        universe();
        ~universe();
        sf::RenderWindow *_window;
        class game *_game;
        void unzoom_camera(void);
        void rezoom_camera(void);
        sf::View &getView();

    private:
        const int _zoom;
        int _actual_zoom;
        sf::View _cam;
};


#endif