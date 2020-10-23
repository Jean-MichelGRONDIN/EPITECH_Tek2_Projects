/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "irrlicht.h"
#include <string>

class Musical {
    public:
        Musical(std::string path, bool repeat);
        ~Musical();
        bool initMusic();
        void playMusic();
        void stopMusic();

        void pauseMusic();

    protected:
    private:
        sf::Music _music;
        bool _repeat;
        std::string _path;
};

#endif /* !MUSIC_HPP_ */
