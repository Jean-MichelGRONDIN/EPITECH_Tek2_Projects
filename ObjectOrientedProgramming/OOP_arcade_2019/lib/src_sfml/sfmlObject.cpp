/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SfmlObject
*/

#include "./libSfml.hpp"

sfmlObject::sfmlObject(std::string path, std::string name, int x, int y)
{
    this->_name = name;
    this->_pos = sf::Vector2f(x, y);
    this->_rec = sf::IntRect();
    this->_texture = new sf::Texture();
    this->_texture->loadFromFile(path);
    this->_sprite = new sf::Sprite();
    this->_sprite->setTexture(*(this->_texture));
    this->_sprite->setPosition(this->_pos);
}

sfmlObject::~sfmlObject()
{
}

State sfmlObject::refreshObj(sf::RenderWindow *window)
{
    this->refreshPos();
    this->refreshRec();
    this->draw(window);
    return (SUCCESS);
}

State sfmlObject::refreshPos()
{
    this->_sprite->setPosition(this->_pos.x, this->_pos.y);
    return (SUCCESS);
}

State sfmlObject::draw(sf::RenderWindow *window)
{
    window->draw(*(this->_sprite));
    return (SUCCESS);
}

State sfmlObject::setPos(float x, float y)
{
    this->_pos.x = x;
    this->_pos.y = y;
    return (SUCCESS);
}

float sfmlObject::getPosX() const
{
    return (this->_pos.x);
}

float sfmlObject::getPosY() const
{
    return (this->_pos.y);
}

State sfmlObject::refreshRec()
{
    this->_sprite->setTextureRect(this->_rec);
    return (SUCCESS);
}

State sfmlObject::setRec(int x, int y, int w, int h)
{
    this->_rec.left = x;
    this->_rec.top = y;
    this->_rec.width = w;
    this->_rec.height = h;
    return (SUCCESS);
}

float sfmlObject::getRecX() const
{
    return (this->_rec.left);
}

float sfmlObject::getRecY() const
{
    return (this->_rec.top);
}

float sfmlObject::getRecW() const
{
    return (this->_rec.width);
}

float sfmlObject::getRecH() const
{
    return (this->_rec.height);
}