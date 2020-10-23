/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Paths
*/

#include "PathsClass.hpp"

Paths::Paths() : _isPlayerFound(false), _score(0), _isPosSet(false)
{
}

Paths::~Paths()
{
}

void Paths::pushBack(KeySet val)
{
    _list.push_back(val);
}

std::int64_t Paths::size()
{
    return (_list.size());
}

KeySet Paths::atIndex(std::int64_t i)
{
    return (_list[i]);
}

void Paths::fusionAtBack(Paths &other)
{
    for (size_t i = 0; i < other.size(); i++) {
        _list.push_back(other.atIndex(i));
    }
    if (other.isPosSet() == true) {
        this->setPos(other.getPos());
    }
}

void Paths::setPlayerFound(bool val)
{
    _isPlayerFound = val;
}

void Paths::calcScore()
{
    _score += _list.size();
    if (_list.size() == 0) {
        return;
    }
}

std::int64_t Paths::getScore()
{
    return (_score);
}

irr::s32 Paths::distance(irr::core::vector2di target)
{
    irr::s32 res = -1;

    if (_isPosSet == false) {
        return (-1);
    }
    res = target.getDistanceFrom(_myPos);
    if (res < 0) {
        res = res * (-1);
    }
    return (res);
}

irr::core::vector2di Paths::getPos()
{
    return (_myPos);
}

void Paths::setPos(irr::core::vector2di newPos)
{
    _myPos.X = newPos.X;
    _myPos.Y = newPos.Y;
    _isPosSet = true;
}

bool Paths::isPosSet()
{
    return (_isPosSet);
}
