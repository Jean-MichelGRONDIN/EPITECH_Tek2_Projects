/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Mineur
*/

#ifndef MINEUR_HPP_
#define MINEUR_HPP_

#include "Character.hpp"
#include "Player.hpp"
#include "../Resseources/Ressoureces.hpp"
#include <iostream>

class Mineur : public Character {
    public:
        Mineur();
        ~Mineur();
        void popMenu();
        void isClicked(sf::Vector2f mouse);
        void drawMenu(sf::RenderWindow *window);
        bool isPopped(void);
        void order(Player *p);
        bool getPopped(Player *p);
        void get_ressources(void);

    protected:
    private:
        bool _menuPopped;
        int _curent_stock;
        int _max_stock;
        sf::Sprite _spriteMenu;
        sf::Texture _textureMenu;
};

#endif /* !MINEUR_HPP_ */
