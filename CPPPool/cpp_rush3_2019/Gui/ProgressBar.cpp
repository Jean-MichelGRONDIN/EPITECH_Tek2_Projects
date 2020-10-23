/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** ProgressBar
*/

#include "ProgressBar.hpp"

ProgressBar::ProgressBar(const std::string &texturBackBar, sf::Vector2f pos)
{
    this->_tLife = sf::Texture();
    this->_tLife.loadFromFile("Assets/life.png");
    this->_sLife = sf::Sprite(_tLife);
    _sLife.setPosition(sf::Vector2f(pos.x + 35, pos.y + 10));
    _sLife.setTextureRect(sf::IntRect(0, 0, 0, 30));
    _tBack = sf::Texture();
    _tBack.loadFromFile(texturBackBar);
    _sBack = sf::Sprite(_tBack);
    _sBack.setScale(sf::Vector2f(0.5, 0.5));
    _sLife.setScale(sf::Vector2f(0.5, 0.5));
    _sBack.setPosition(pos);
    _pos = pos;

}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::ChangeBar(int ress)
{
    _sLife.setTextureRect(sf::IntRect(0, 0, ress * 2, 30));
}

void ProgressBar::setNewPose(sf::Vector2f player)
{
    sf::Vector2f res(_pos);

    player.x -= 400;
    player.y -= 215;
    res += player;
    _sBack.setPosition(res);
    _sLife.setPosition(sf::Vector2f(res.x + 35, res.y + 10));
}

void ProgressBar::draw(sf::RenderWindow *window)
{
    window->draw(_sBack);
    window->draw(_sLife);
}