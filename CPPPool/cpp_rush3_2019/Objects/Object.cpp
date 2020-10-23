/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** Object
*/

#include "Object.hpp"

Object::Object(const std::string &name, int maxDurability, std::string sprite)
{
    this->_name = name;
    this->_maxDurability = maxDurability;
    this->_currentDurability = maxDurability;

    this->_texture = sf::Texture();
    this->_texture.loadFromFile(sprite);
    this->_sprite = sf::Sprite(this->_texture);
}

Object::~Object()
{
}

/* GETTERS */

std::string Object::getName() const
{
    return this->_name;
}

int Object::getCurrentDurability() const
{
    return this->_currentDurability;
}

int Object::getMaxDurability() const
{
    return this->_maxDurability;
}

sf::Sprite Object::getSprite() const
{
    return this->_sprite;
}

/* SETTERS */

void Object::setMaxDurability(int max)
{
    this->_maxDurability = max;
}

void Object::setCurrentDurability(int current)
{
    if (current <= 0)
        return breakObject();
    this->_currentDurability = current;
}

/* OTHERS */

void Object::repairObject()
{
    this->_currentDurability = this->_maxDurability;
}

void Object::breakObject()
{
    this->~Object();
}