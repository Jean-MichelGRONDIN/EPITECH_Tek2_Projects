/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>
#include <string>
#include "../includeSFML.hpp"

class Character {
	public:
		Character(const std::string &name, const std::string &texture, sf::Vector2f pos);
		~Character();
		std::string getName() const;
		sf::Sprite &getSprite();
	protected:
		std::string _name;
		sf::Sprite _sprite;
		sf::Texture _texture;
		sf::Clock _clock;
		sf::Vector2f _position;
		sf::Time _time;
	private:
};

#endif /* !CHARACTER_HPP_ */
