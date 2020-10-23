/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** sdlObject
*/

#include "./libSdl.hpp"

sdlObject::sdlObject(std::string path, std::string name, SDL_Renderer *renderer)
{
    this->_name = name;
    this->_sprite = IMG_LoadTexture(renderer, path.c_str());
    this->_rec.x = 0;
    this->_rec.y = 0;
    SDL_QueryTexture(this->_sprite, NULL, NULL, &this->_rec.w, &this->_rec.h);
}

sdlObject::~sdlObject()
{
    SDL_DestroyTexture(this->_sprite);
}

State sdlObject::refreshObj(SDL_Renderer *renderer)
{
    this->refreshPos();
    this->refreshRec();
    this->draw(renderer);
    return (SUCCESS);
}

State sdlObject::refreshPos()
{
    return (FAILURE);
}

State sdlObject::draw(SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer, this->_sprite, NULL, &this->_rec);
    return (SUCCESS);
}

State sdlObject::setPos(float x, float y)
{
    this->_rec.x = x;
    this->_rec.y = y;
    return (SUCCESS);
}

float sdlObject::getPosX() const
{
    return (this->_rec.x);
}

float sdlObject::getPosY() const
{
    return (this->_rec.y);
}

State sdlObject::refreshRec()
{
    return (FAILURE);
}

State sdlObject::setRec(int x, int y, int w, int h)
{
    this->_rec.x = x;
    this->_rec.y = y;
    this->_rec.w = w;
    this->_rec.h = h;
    return (SUCCESS);
}

float sdlObject::getRecX() const
{
    return (this->_rec.x);
}

float sdlObject::getRecY() const
{
    return (this->_rec.y);
}

float sdlObject::getRecW() const
{
    return (this->_rec.w);
}

float sdlObject::getRecH() const
{
    return (this->_rec.h);
}