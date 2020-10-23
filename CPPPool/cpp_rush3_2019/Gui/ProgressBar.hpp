/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** ProgressBar
*/

#ifndef PROGRESSBAR_HPP_
#define PROGRESSBAR_HPP_

#include <iostream>
#include <cmath>

#include "SFML/Graphics.hpp"
class Player;

class ProgressBar {
	public:
		ProgressBar(const std::string &texturBackBar, sf::Vector2f pos);
		~ProgressBar();
                void draw(sf::RenderWindow *window);
                void ChangeBar(int ress);
                void setNewPose(sf::Vector2f pos);
	protected:
                sf::Texture _tBack;
                sf::Sprite _sBack;
                sf::Texture _tLife;
                sf::Sprite _sLife;
                sf::Vector2f _pos;

	private:
};

#endif /* !PROGRESSBAR_HPP_ */
