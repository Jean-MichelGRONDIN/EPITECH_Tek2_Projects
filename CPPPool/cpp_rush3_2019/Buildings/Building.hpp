/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** Building
*/

#ifndef BUILDING_HPP_
#define BUILDING_HPP_

#include "../Universe/universe.hpp"
#include "../Characters/Player.hpp"
#include "../Gui/ProgressBar.hpp"
#include "../includeSFML.hpp"
#include "../Characters/Player.hpp"

class Building {
	public:
		Building(sf::Vector2f pos, std::string spriteBroken, std::string spriteRepaired, int size, int needWood, int gotWood = 0, int needRock = 0, int gotRock = 0, int needIron = 0, int gotIron = 0);
		~Building();

        /* GETTERS */
        int getNeedWood() const;
        int getGotWood() const;
        int getNeedRock() const;
        int getGotRock() const;
        int getNeedIron() const;
        int getGotIron() const;
        bool isRepaired() const;
        int getSize() const;
		sf::Sprite getSprite() const;
        bool getPopped(Player *p);
        sf::Sprite getMenuSprite() const;

        /* SETTERS */
        void setGotWood(int wood);
        void setGotRock(int rock);
        void setGotIron(int iron);

        /* OTHERS */
        void popMenu();
        void isClicked(sf::Vector2f mouse);
		void repair(Player *player);
        void drawMenu(sf::RenderWindow *window);
        bool _isHabitate;

	protected:
        int _needWood;
        int _gotWood;
        int _needRock;
        int _gotRock;
        int _needIron;
        int _gotIron;
        bool _isRepaired;
        int _size;
		sf::Vector2f _pos;
		sf::Texture _textureBroken;
		sf::Texture _textureRepaired;
		sf::Sprite _spriteBroken;
		sf::Sprite _spriteRepaired;
		sf::Texture _textureMenu;
		sf::Sprite _spriteMenu;
        bool _menuPopped;
	private:
};

#endif /* !BUILDING_HPP_ */
