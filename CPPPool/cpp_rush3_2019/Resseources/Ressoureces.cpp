/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Ressoureces
*/

#include "Ressoureces.hpp"

Ressoureces::Ressoureces(sf::Vector2f pos, const std::string &texture)
{
    this->_RessTexture = sf::Texture();
    this->_RessTexture.loadFromFile(texture);
    this->_Ress = sf::Sprite(_RessTexture);
    this->_Ress.setPosition(pos);
    this->_RessCurrent = _Ress;
    _RessTextureCurrent = _RessTexture;
    _isBreakable = true;
    _isAnimating = false;
    _isDrawable = true;
    _isGrowing = false;
    _isGiven = false;
    _HP = 200;
    _currentHp = 200;
    _giveRess = 15;
    _pos = pos;
    _clockAnime = sf::Clock();
    _timeAnime = sf::Time();
    _clockRepop = sf::Clock();
    _timeRepop = sf::Time();
}

Ressoureces::~Ressoureces()
{
}


sf::Sprite Ressoureces::getRessTodraw()
{
    if (_isAnimating == true) {
        if (!(_currentHp > 0))
  //          animeRess();
//        else
            animeRessDestroy();
    }
    if (_isGrowing)
        growRess();
    return (this->_RessCurrent);
}

bool Ressoureces::is_player_there(sf::Sprite Ress, sf::Sprite player)
{
    if (player.getPosition().x + 8 > Ress.getPosition().x - 20 &&
        player.getPosition().x - 8 < (Ress.getPosition().x + Ress.getTextureRect().width))
        if (player.getPosition().y + 8 > Ress.getPosition().y - 20 &&
        player.getPosition().y - 8 < (Ress.getPosition().y + Ress.getTextureRect().height))
            return (true);
    return (false);
}

void Ressoureces::_is_cliked(sf::Vector2f mouse, Player *p)
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
                        p->setRock(p->getRock() + this->_giveRess);
                        _isGiven = true;
                    }
                    _isAnimating = false;
                    animeRessDestroy();
                }
            }
        }
    }
}

void Ressoureces::growRess()
{
    _timeRepop = _clockRepop.getElapsedTime();
    if (_timeRepop.asSeconds() > 600 && this->_isBreakable == true) {
        this->_isBreakable = true;
        _isGrowing = false;
        _RessCurrent = _Ress;
        _currentHp = 200;
        _giveRess = 15;
        _isGiven = false;
    }
}

void Ressoureces::animeRessDestroy()
{
    if (_isAnimating == false) {
        _isAnimating = true;
        this->_clockAnime.restart();
        this->_clockRepop.restart();
    }
    if (_RessCurrent.getColor().a  <= 0) {
        _isAnimating = false;
        _isBreakable = false;
        _clockRepop.restart();
        _isGrowing = true;
        growRess();
    }
    _timeAnime = _clockAnime.getElapsedTime();
    if (_timeAnime.asMilliseconds() > 10) {
        sf::Color tmp = sf::Color(_RessCurrent.getColor());
        tmp.a -= 5;
        this->_RessCurrent.setColor(tmp);
        _clockAnime.restart();
    }
}

void Ressoureces::animeRess()
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
        if (_RessCurrent.getPosition().x < _Ress.getPosition().x)
            _RessCurrent.setPosition(sf::Vector2f(_Ress.getPosition().x + 1, _Ress.getPosition().y));
        else
            _RessCurrent.setPosition(sf::Vector2f(_Ress.getPosition().x - 1, _Ress.getPosition().y));
        _clockAnime.restart();
    }
}

sf::Vector2f Ressoureces::getPos() const
{
    return (this->_pos);
}