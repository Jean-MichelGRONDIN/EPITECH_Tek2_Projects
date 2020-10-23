/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** Pnj
*/

#ifndef PNJ_HPP_
#define PNJ_HPP_

#include "Character.hpp"
#include "../Map/Map.hpp"

class Pnj : public Character {
	public:
		Pnj(const std::string &name, sf::Vector2f pos);
		~Pnj();

	protected:
	private:
};

#endif /* !PNJ_HPP_ */
