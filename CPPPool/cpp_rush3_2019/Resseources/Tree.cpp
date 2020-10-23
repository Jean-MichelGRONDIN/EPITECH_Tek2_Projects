/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Tree
*/

#include "Tree.hpp"

Tree::Tree(sf::Vector2f pos, const std::string &str) : Ressoureces(pos, str)
{
    this->_treeTextureB = sf::Texture();
    this->_treeTextureB.loadFromFile("Assets/treeB.png");
    this->_treeB = sf::Sprite(_treeTextureB);
    this->_treeB.setPosition(pos.x + 16, pos.y + 16);
    this->_giveRess = 30;
}

Tree::~Tree()
{
}

void Tree::growRess()
{
    _timeRepop = _clockRepop.getElapsedTime();
    if (_timeRepop.asSeconds() > 5 && this->_isBreakable == false) {
        this->_isBreakable = true;
        _RessCurrent = _treeB;
        _currentHp = 50;
        _giveRess = 15;
        _isGiven = false;
    }
    if (_timeRepop.asSeconds() > 15 && this->_isBreakable == true) {
        _isGrowing = false;
        _RessCurrent = _Ress;
        _currentHp += 50;
        _giveRess = 30;
    }
}

void Tree::_is_cliked(sf::Vector2f mouse, Player *p)
{
    if (mouse.x >= _RessCurrent.getPosition().x && mouse.x <= _RessCurrent.getPosition().x + _RessCurrent.getTextureRect().width) {
        if (mouse.y >= _RessCurrent.getPosition().y && mouse.y <= _RessCurrent.getPosition().y + _RessCurrent.getTextureRect().height) {
            if (!is_player_there(_Ress, p->getSprite()))
                return;
            if (_isBreakable == true) {
                if (_currentHp > 0) {
                    animeRess();
                } else {
                    if (!_isGiven) {
                        p->setWood(p->getWood() + this->_giveRess);
                        p->isAdded = true;
                        _isGiven = true;
                    }
                    _isAnimating = false;
                    animeRessDestroy();
                }
            }
        }
    }
}
void Tree::animeRess()
{
    if (_isAnimating == false) {
        _isAnimating = true;
        this->_clockAnime.restart();
        this->_clockRepop.restart();
    }
    _timeAnime = _clockAnime.getElapsedTime();
    if (_timeAnime.asMilliseconds() > 10) {
        if (_currentHp > 0)
            _currentHp -= 1;
        sf::Vector2f tmp(_Ress.getPosition());
        if (_isGrowing) {
            tmp.x = _treeB.getPosition().x;
            tmp.y = _treeB.getPosition().y;
        }
        if (_RessCurrent.getPosition().x < tmp.x)
            _RessCurrent.setPosition(sf::Vector2f(tmp.x + 1, tmp.y));
        else
            _RessCurrent.setPosition(sf::Vector2f(tmp.x - 1, tmp.y));
        _clockAnime.restart();
    }
}