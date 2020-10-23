/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** Player
*/

#include "Player.hpp"
#include "../City/City.hpp"

Player::Player(const std::string &name, sf::VertexArray map) : Character::Character(name, "Assets/Forgeron.png", sf::Vector2f(2000,1184))
{
    this->_level = 1;
    this->_wood = 0;
    this->_rock = 0;
    this->_iron = 0;
    this->_position.x = 2000;
    this->_position.y = 1184;
    this->_clock = sf::Clock();
    this->_time = sf::Time();
    this->dir = 0;
    this->map_c = map;
    this->idx_rec = 0;
    this->isAdded = false;
}

Player::~Player()
{
    std::cout << "RIP" << std::endl;
}

/* GETTERS */

int Player::getLevel() const
{
    return this->_level;
}


int Player::getWood() const
{
    return this->_wood;
}

int Player::getRock() const
{
    return this->_rock;
}

int Player::getIron() const
{
    return this->_iron;
}

Object *Player::getObject() const
{
    return this->_object;
}

/* SETTERS */

void Player::setLevel(int level)
{
    this->_level = level;
    if (_level > 100)
        _level = 100;
}

void Player::setWood(int wood)
{
    isAdded = true;
    this->_wood = wood;
    if  (_wood > 100)
        this->_wood = MAX_WOOD;
}

void Player::setRock(int rock)
{
    isAdded = true;
    this->_rock = rock;
    if  (_rock > 100)
        this->_rock = MAX_ROCK;
}

void Player::setIron(int iron)
{
    isAdded = true;
    this->_iron = iron;
    if  (_iron > 100)
        this->_iron = MAX_IRON;
}


void Player::setObject(Object *object)
{
    this->_object = object;
}

int Player::getPosTexture(int x, int y)
{
    sf::Vertex tmp = this->map_c[((x / 16) + (y / 16) * 191) * 4];

    if ((int)tmp.texCoords.x == 16 && (int)tmp.texCoords.y == 0)
        return (0);
    return 1;
}

void Player::moveDown(std::vector<Tree *> tree, std::vector<Ressoureces *> rock)
{
    int x = this->_position.x;
    int y = this->_position.y + 16;
    int size;

    for (Tree *t : tree) {
        if (t->getRessTodraw().getColor().a > 0) {
            size = t->getRessTodraw().getTextureRect().width;
            if (x + 16 > t->getPos().x && x < (t->getPos().x + size) && (y + 2) > (t->getPos().y) && (y + 2) < (t->getPos().y + size))
                return;
        }
    }
    for (Ressoureces *tmp : rock) {
        if (tmp->getRessTodraw().getColor().a > 0) {
            size = tmp->getRessTodraw().getTextureRect().width;
            if (x + 16 > tmp->getPos().x && x < (tmp->getPos().x + size) && (y + 2) > (tmp->getPos().y) && (y + 2) < (tmp->getPos().y + size))
                return;
        }
    }
    y -= 16;
    if (getPosTexture(x + (x % 16), y + 16 - (y % 16)) == 1) {
        this->dir = 0;
        this->idx_rec += 16;
        if (this->idx_rec > 48)
            this->idx_rec = 0;
        this->_position.y += 2;
        this->_sprite.setTextureRect(sf::IntRect(this->idx_rec, this->dir, 16, 16));
        this->_sprite.setPosition(this->_position);
    }
}

void Player::moveUp(std::vector<Tree *> tree, std::vector<Ressoureces *> rock)
{
    int x = this->_position.x ;
    int y = this->_position.y + 16;
    int size;
    for (Tree *t : tree) {
        if (t->getRessTodraw().getColor().a > 0) {
            size = t->getRessTodraw().getTextureRect().width;
            if (x + 16> t->getPos().x && x < (t->getPos().x + size) && (y - 2) > (t->getPos().y) && (y - 2) < (t->getPos().y + size))
                return;
        }
    }
    for (Ressoureces *tmp : rock) {
        if (tmp->getRessTodraw().getColor().a > 0) {
            size = tmp->getRessTodraw().getTextureRect().width;
            if (x + 16 > tmp->getPos().x && x < (tmp->getPos().x + size) && (y - 2) > (tmp->getPos().y) && (y - 2) < (tmp->getPos().y + size))
                return;
        }
    }
    y -= 16;
    if (getPosTexture(x + (x % 16), y - (y % 16)) == 1) {
    this->dir = 48;
    this->idx_rec += 16;
    if (this->idx_rec > 48)
        this->idx_rec = 0;
    this->_position.y -= 2;
    this->_sprite.setTextureRect(sf::IntRect(this->idx_rec, this->dir, 16, 16));
    this->_sprite.setPosition(this->_position);
    }
}

void Player::moveLeft(std::vector<Tree *> tree, std::vector<Ressoureces *> rock)
{
    int x = this->_position.x;
    int y = this->_position.y + 16;
    int size;
    for (Tree *t : tree) {
        if (t->getRessTodraw().getColor().a > 0) {
            size = t->getRessTodraw().getTextureRect().width;
            if (x - 2 > t->getPos().x && x - 2 < (t->getPos().x + size) && (y) > (t->getPos().y) && (y) < (t->getPos().y + size))
                return;
        }
    }
    for (Ressoureces *tmp : rock) {
        if (tmp->getRessTodraw().getColor().a > 0) {
            size = tmp->getRessTodraw().getTextureRect().width;
            if (x - 2 > tmp->getPos().x && x - 2 < (tmp->getPos().x + size) && (y) > (tmp->getPos().y) && (y) < (tmp->getPos().y + size))
                return;
        }
    }
    y -= 16;
    if (getPosTexture(x - (x % 16), y + (y % 16)) == 1) {
    this->dir = 32;
    this->idx_rec += 16;
    if (this->idx_rec > 48)
        this->idx_rec = 0;
    this->_position.x -= 2;
    this->_sprite.setTextureRect(sf::IntRect(this->idx_rec, this->dir, 16, 16));
    this->_sprite.setPosition(this->_position);
    }
}

void Player::moveRight(std::vector<Tree *> tree, std::vector<Ressoureces *> rock)
{
    int x = this->_position.x + 16;
    int y = this->_position.y + 16;
    int size;
    for (Tree *t : tree) {
        if (t->getRessTodraw().getColor().a > 0) {
            size = t->getRessTodraw().getTextureRect().width;
            if (x + 2 > t->getPos().x && x + 2 < (t->getPos().x + size) && (y) > (t->getPos().y) && (y) < (t->getPos().y + size))
                return;
        }
    }
    for (Ressoureces *tmp : rock) {
        if (tmp->getRessTodraw().getColor().a > 0) {
            size = tmp->getRessTodraw().getTextureRect().width;
            if (x + 2 > tmp->getPos().x && x + 2 < (tmp->getPos().x + size) && (y) > (tmp->getPos().y) && (y) < (tmp->getPos().y + size))
                return;
        }
    }
    y -= 16;
    x -= 16;
    if (getPosTexture(x + 16 - (x % 16), y + (y % 16)) == 1) {
    this->dir = 16;
    this->idx_rec += 16;
    if (this->idx_rec > 48)
        this->idx_rec = 0;
    this->_position.x += 2;
    this->_sprite.setTextureRect(sf::IntRect(this->idx_rec, this->dir, 16, 16));
    this->_sprite.setPosition(this->_position);
    }
}

void Player::move(std::vector<Tree *> tree, std::vector<Ressoureces *> rock)
{
    sf::Keyboard a;
    this->_time = this->_clock.getElapsedTime();

    if (this->_time.asMilliseconds() >= 20) {
        if (a.isKeyPressed(sf::Keyboard::Z) || a.isKeyPressed(sf::Keyboard::Up)) {
            moveUp(tree, rock);
            this->_clock.restart();
        }
        else if (a.isKeyPressed(sf::Keyboard::S) || a.isKeyPressed(sf::Keyboard::Down)) {
            moveDown(tree, rock);
            this->_clock.restart();
        }
        else if (a.isKeyPressed(sf::Keyboard::Q) || a.isKeyPressed(sf::Keyboard::Left)) {
            moveLeft(tree, rock);
            this->_clock.restart();
        }
        else if (a.isKeyPressed(sf::Keyboard::D) || a.isKeyPressed(sf::Keyboard::Right)) {
            moveRight(tree, rock);
            this->_clock.restart();
        }
    }
}