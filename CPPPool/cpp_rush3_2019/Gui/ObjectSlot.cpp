/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** ObjectSlot
*/

#include "ObjectSlot.hpp"

ObjectSlot::ObjectSlot(sf::Sprite object)
{
    this->_back.setSize(sf::Vector2f(SLOT_WIDTH, SLOT_HEIGHT));
    this->_back.setFillColor(sf::Color::Black);
    this->_back.setOutlineThickness(2);
    this->_back.setOutlineColor(sf::Color::White);
    this->_back.setPosition(SLOT_X, SLOT_Y);

    object.setScale(sf::Vector2f(SLOT_WIDTH / 16, SLOT_HEIGHT / 16));
    object.setPosition(SLOT_X, SLOT_Y);
    this->_object = object;
}

ObjectSlot::~ObjectSlot()
{
}

void ObjectSlot::update(sf::Sprite object)
{
    object.setScale(sf::Vector2f(SLOT_WIDTH / 16, SLOT_HEIGHT / 16));
    object.setPosition(SLOT_X, SLOT_Y);
    this->_object = object;
}

void ObjectSlot::render(sf::RenderWindow *window)
{
    window->draw(this->_back);
    window->draw(this->_object);
}