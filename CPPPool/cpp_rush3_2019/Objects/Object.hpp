/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>

#include "SFML/Graphics.hpp"

class Object {
	public:
		Object(const std::string &name, int maxDurability, std::string sprite);
		~Object();

        /* GETTERS */
        std::string getName() const;
        int getCurrentDurability() const;
        int getMaxDurability() const;
        sf::Sprite getSprite() const;

        /* SETTERS */
        void setCurrentDurability(int current);
        void setMaxDurability(int max);

        /* OTHERS */
        void repairObject();
        void breakObject();
	protected:
	private:
        std::string _name;
        int _maxDurability;
        int _currentDurability;
        sf::Texture _texture;
        sf::Sprite _sprite;
};

#endif /* !OBJECT_HPP_ */
