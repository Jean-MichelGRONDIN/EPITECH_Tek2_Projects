/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** sound
*/

#ifndef MYSOUND_HPP_
#define MYSOUND_HPP_

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>


class MySound
{
	public:
		MySound(std::string path);
		~MySound();
		void play();

	private:
		sf::SoundBuffer _buffer;
		sf::Sound _sound;
		bool _valide;
};

#endif