#include "MySound.hpp"
/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** sound
*/

MySound::MySound(std::string path)
{
    _valide = false;
    if (!_buffer.loadFromFile(path))
        return;
    _valide = true;
    _sound.setBuffer(_buffer);
}

MySound::~MySound()
{
}

void MySound::play()
{
    if (_valide)
        _sound.play();
}
