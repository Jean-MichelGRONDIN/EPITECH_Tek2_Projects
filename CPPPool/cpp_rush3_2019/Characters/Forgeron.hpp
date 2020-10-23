/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Forgeron
*/

#ifndef FORGERON_HPP_
#define FORGERON_HPP_

#include "Character.hpp"
#include "Player.hpp"
#include "../Resseources/Ressoureces.hpp"
#include <iostream>

class Forgeron : public Character {
	public:
		Forgeron();
		~Forgeron();
        void popMenu();
        void isClicked(sf::Vector2f mouse);
        void drawMenu(sf::RenderWindow *window, Player *p);
        bool isPopped(void);
        void order(Player *p);
        bool getPopped(Player *p);

	protected:
	private:
        bool _menuPopped;
        int _needRock;
        sf::Sprite _spriteMenu;
        sf::Texture _textureMenu;
};

#endif