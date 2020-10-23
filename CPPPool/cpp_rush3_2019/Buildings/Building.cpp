/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** Building
*/

#include "Building.hpp"
#include "../Resseources/Ressoureces.hpp"

Building::Building(sf::Vector2f pos, std::string spriteBroken, std::string spriteRepaired, int size, int needWood, int gotWood, int needRock, int gotRock, int needIron, int gotIron)
{
    this->_needWood = needWood;
    this->_gotWood = gotWood;
    this->_needRock = needRock;
    this->_gotRock = gotRock;
    this->_needIron = needIron;
    this->_gotIron = gotIron;
    this->_isRepaired = false;
    this->_size = size;
    this->_pos = pos;
    this->_textureBroken = sf::Texture();
    this->_textureBroken.loadFromFile(spriteBroken);
    this->_spriteBroken = sf::Sprite(this->_textureBroken);
    this->_spriteBroken.setPosition(pos);
    this->_textureRepaired = sf::Texture();
    this->_textureRepaired.loadFromFile(spriteRepaired);
    this->_spriteRepaired = sf::Sprite(this->_textureRepaired);
    this->_spriteRepaired.setPosition(pos);
    this->_textureMenu = sf::Texture();
    this->_textureMenu.loadFromFile("Assets/BuildingMenu.png");
    this->_spriteMenu = sf::Sprite(this->_textureMenu);
    this->_spriteMenu.setPosition(sf::Vector2f(pos.x + this->_spriteBroken.getTextureRect().width - 16, pos.y + this->_spriteBroken.getTextureRect().height - 16));
    this->_menuPopped = false;
    _isHabitate = false;
}

Building::~Building()
{
}

/* GETTERS */

int Building::getNeedWood() const
{
    return this->_needWood;
}

int Building::getGotWood() const
{
    return this->_gotWood;
}

int Building::getNeedRock() const
{
    return this->_needRock;
}

int Building::getSize()const
{
    return (this->_size);
}

int Building::getGotRock() const
{
    return this->_gotRock;
}

int Building::getNeedIron() const
{
    return this->_needIron;
}

int Building::getGotIron() const
{
    return this->_gotIron;
}

bool Building::isRepaired() const
{
    return this->_isRepaired;
}

sf::Sprite Building::getSprite() const
{
    return (this->_isRepaired ? this->_spriteRepaired : this->_spriteBroken);
}

bool Building::getPopped(Player *p)
{
    if (!Ressoureces::is_player_there(this->_spriteBroken, p->getSprite()))
        this->_menuPopped = false;
    return this->_menuPopped;
}

sf::Sprite Building::getMenuSprite() const
{
    return this->_spriteMenu;
}


/* SETTERS */

void Building::setGotWood(int wood)
{
    this->_gotWood = wood;
}

void Building::setGotRock(int rock)
{
    this->_gotRock = rock;
}

void Building::setGotIron(int iron)
{
    this->_gotIron = iron;
}

void Building::popMenu()
{
    this->_menuPopped = !this->_menuPopped;
}

void Building::isClicked(sf::Vector2f mouse)
{
    if (mouse.x >= this->_pos.x && mouse.x <= this->_pos.x + this->_spriteBroken.getTextureRect().width) {
        if (mouse.y >= this->_pos.y && mouse.y <= this->_pos.y + this->_spriteBroken.getTextureRect().height) {
            popMenu();
        }
    }
}

void Building::repair(Player *player)
{
    if (this->_gotWood + player->getWood() < _needWood) {
        this->_gotWood += player->getWood();
        player->setWood(0);
    } else {
        player->setWood(player->getWood() - (_needWood - _gotWood));
        _gotWood = _needWood;
    }
    if (this->_gotIron + player->getIron() < _needIron) {
        this->_gotIron += player->getIron();
        player->setIron(0);
    } else {
        player->setIron(player->getIron() - (_needIron - _gotIron));
        _gotIron = _needIron;
    }
    if (this->_gotRock + player->getRock() < _needRock) {
        this->_gotRock += player->getRock();
        player->setRock(0);
    } else {
        player->setRock(player->getRock() - (_needRock - _gotRock));
        _gotRock = _needRock;
    }
    if (_gotRock == _needRock && _gotIron == _needIron && _gotWood == _needWood)
        this->_isRepaired = true;
}

void Building::drawMenu(sf::RenderWindow *window)
{
    window->draw(this->_spriteMenu);
    sf::Font font;
    font.loadFromFile("Assets/arialbi.ttf");
    std::string stringWood = "Wood: " + std::to_string(this->_gotWood) + "/" + std::to_string(this->_needWood);
    sf::Text textWood;
    textWood.setFont(font);
    textWood.setCharacterSize(8);
    textWood.setPosition(this->_spriteMenu.getPosition().x + 10, this->_spriteMenu.getPosition().y + 3);
    textWood.setString(stringWood);
    window->draw(textWood);
    if (this->_needRock > 0) {
        std::string stringRock = "Rock: " + std::to_string(this->_gotRock) + "/" + std::to_string(this->_needRock);
        sf::Text textRock;
        textRock.setFont(font);
        textRock.setCharacterSize(8);
        textRock.setPosition(this->_spriteMenu.getPosition().x + 10, this->_spriteMenu.getPosition().y + 13);
        textRock.setString(stringRock);
        window->draw(textRock);
    }
    if (this->_needIron > 0) {
        std::string stringIron = "Iron: " + std::to_string(this->_gotIron) + "/" + std::to_string(this->_needIron);
        sf::Text textIron;
        textIron.setFont(font);
        textIron.setCharacterSize(8);
        textIron.setPosition(this->_spriteMenu.getPosition().x + 10, this->_spriteMenu.getPosition().y + 23);
        textIron.setString(stringIron);
        window->draw(textIron);
    }
    std::string string = "Press R to repair";
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(8);
    text.setFillColor(sf::Color::Red);
    text.setPosition(this->_spriteMenu.getPosition().x + 10, this->_spriteMenu.getPosition().y + 33);
    text.setString(string);
    window->draw(text);
}