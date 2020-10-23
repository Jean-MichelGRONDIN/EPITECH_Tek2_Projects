/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** ObjectSlot
*/

#ifndef OBJECTSLOT_HPP_
#define OBJECTSLOT_HPP_

#define SLOT_WIDTH 192
#define SLOT_HEIGHT 192
#define SLOT_X 200
#define SLOT_Y 200

#include "SFML/Graphics.hpp"

class ObjectSlot {
	public:
		ObjectSlot(sf::Sprite object);
		~ObjectSlot();

        void update(sf::Sprite object);
        void render(sf::RenderWindow *window);
	protected:
	private:
        sf::Sprite _object;
        sf::RectangleShape _back;
};

#endif /* !OBJECTSLOT_HPP_ */
