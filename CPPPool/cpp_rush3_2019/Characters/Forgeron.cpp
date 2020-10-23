/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Forgeron
*/

#include "Forgeron.hpp"

Forgeron::Forgeron() : Character("Forgeron", "Assets/Forgeron.png", sf::Vector2f(1994 ,933))
{
    _menuPopped = false;
    _needRock = 10;
    this->_textureMenu = sf::Texture();
    this->_textureMenu.loadFromFile("Assets/BuildingMenu.png");
    this->_spriteMenu = sf::Sprite(this->_textureMenu);
    this->_position = sf::Vector2f(1994,933);
    this->_spriteMenu.setPosition(sf::Vector2f(_position.x + 16, _position.y + 16));
}

Forgeron::~Forgeron()
{
}

void Forgeron::popMenu()
{
    this->_menuPopped = !this->_menuPopped;
}

void Forgeron::isClicked(sf::Vector2f mouse)
{
    if (mouse.x >= this->_position.x && mouse.x <= this->_position.x + this->_sprite.getTextureRect().width) {
        if (mouse.y >= this->_position.y && mouse.y <= this->_position.y + this->_sprite.getTextureRect().height) {
            this->popMenu();
        }
    }
}

void Forgeron::drawMenu(sf::RenderWindow *window, Player *p)
{
    window->draw(this->_spriteMenu);
    sf::Font font;
    font.loadFromFile("Assets/arialbi.ttf");
    std::string stringRock = "Rock: " + std::to_string(p->getRock()) + "/" + std::to_string(this->_needRock);
    sf::Text textRock;
    textRock.setFont(font);
    textRock.setCharacterSize(8);
    textRock.setPosition(this->_spriteMenu.getPosition().x + 10, this->_spriteMenu.getPosition().y + 13);
    textRock.setString(stringRock);
    window->draw(textRock);
    std::string string = "Press R to order";
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(8);
    text.setFillColor(sf::Color::Red);
    text.setPosition(this->_spriteMenu.getPosition().x + 10, this->_spriteMenu.getPosition().y + 33);
    text.setString(string);
    window->draw(text);
}

bool Forgeron::isPopped()
{
    return (this->_menuPopped);
}

void Forgeron::order(Player *p)
{
    if (p->getRock() >= 10 && p->getIron() < MAX_IRON) {
        p->setRock(p->getRock() - 10);
        p->setIron(p->getIron() + 1);
    }
}

bool Forgeron::getPopped(Player *p)
{
    if (!Ressoureces::is_player_there(this->_sprite, p->getSprite()))
        this->_menuPopped = false;
    return this->_menuPopped;
}