/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Music
*/

#include "Music.hpp"

#include <iostream>
Musical::Musical(std::string path, bool repeat)
{
    _path = path;
    _repeat = repeat;
}

Musical::~Musical()
{
}

bool Musical::initMusic()
{
    if (!_music.openFromFile(_path))
        return false;
    _music.setLoop(_repeat);
    return true;
}

void Musical::playMusic()
{
    _music.play();
}

void Musical::stopMusic()
{
    _music.stop();
}

void Musical::pauseMusic()
{
    _music.pause();
}