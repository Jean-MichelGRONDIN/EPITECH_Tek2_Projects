/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(const std::string &name, const std::string &texture, sf::Vector2f pos)
{
    this->_name = name;
    this->_texture = sf::Texture();
    _texture.loadFromFile(texture);
    _sprite = sf::Sprite(_texture);
    _sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
    _sprite.setPosition(pos);
}

Character::~Character()
{
}

std::string Character::getName() const
{
    return this->_name;
}

sf::Sprite &Character::getSprite()
{
    return (this->_sprite);
}