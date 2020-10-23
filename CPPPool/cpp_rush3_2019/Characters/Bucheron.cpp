/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Bucheron
*/

#include "Bucheron.hpp"

Bucheron::Bucheron() : Character("Bucheron", "Assets/Bucheron.png", sf::Vector2f(1394 ,1033))
{
    _menuPopped = false;
    _curent_stock = 0;
    _max_stock = 100;
    this->_textureMenu = sf::Texture();
    this->_textureMenu.loadFromFile("Assets/BuildingMenu.png");
    this->_spriteMenu = sf::Sprite(this->_textureMenu);
    this->_position = sf::Vector2f(1394 ,1033);
    this->_spriteMenu.setPosition(sf::Vector2f(_position.x + 16, _position.y + 16));
    this->_clock = sf::Clock();
    this->_time = sf::Time();
}

Bucheron::~Bucheron()
{
}

void Bucheron::popMenu()
{
    this->_menuPopped = !this->_menuPopped;
}

void Bucheron::isClicked(sf::Vector2f mouse)
{
    if (mouse.x >= this->_position.x && mouse.x <= this->_position.x + this->_sprite.getTextureRect().width) {
        if (mouse.y >= this->_position.y && mouse.y <= this->_position.y + this->_sprite.getTextureRect().height) {
            this->popMenu();
        }
    }
}

void Bucheron::drawMenu(sf::RenderWindow *window)
{
    window->draw(this->_spriteMenu);
    sf::Font font;
    font.loadFromFile("Assets/arialbi.ttf");
    std::string stringRock = "I have: " + std::to_string(this->_curent_stock) + " Woods";
    sf::Text textRock;
    textRock.setFont(font);
    textRock.setCharacterSize(8);
    textRock.setPosition(this->_spriteMenu.getPosition().x + 10, this->_spriteMenu.getPosition().y + 13);
    textRock.setString(stringRock);
    window->draw(textRock);
    std::string string = "Press R to claim";
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(8);
    text.setFillColor(sf::Color::Red);
    text.setPosition(this->_spriteMenu.getPosition().x + 10, this->_spriteMenu.getPosition().y + 33);
    text.setString(string);
    window->draw(text);
}

bool Bucheron::isPopped()
{
    return (this->_menuPopped);
}

void Bucheron::order(Player *p)
{
    int missing = MAX_WOOD - p->getWood();

    if (p->getWood() < MAX_WOOD) {
        if (this->_curent_stock >= missing) {
            p->setWood(p->getWood() + missing);
            this->_curent_stock = this->_curent_stock - missing;
        } else {
            p->setWood(p->getWood() + _curent_stock);
            this->_curent_stock = 0;
        }
    }
}

bool Bucheron::getPopped(Player *p)
{
    if (!Ressoureces::is_player_there(this->_sprite, p->getSprite()))
        this->_menuPopped = false;
    return this->_menuPopped;
}

void Bucheron::get_ressources()
{
    this->_time = this->_clock.getElapsedTime();
    if (this->_time.asMilliseconds() >= 90000) {
        if (this->_curent_stock < this->_max_stock) {
            this->_curent_stock += 10;
        }
        this->_clock.restart();
    }
}