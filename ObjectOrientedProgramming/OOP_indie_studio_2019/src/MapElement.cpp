/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** MapElement
*/
#include "Map.hpp"

#include "MapElement.hpp"
MapElement::MapElement(MapManager *map, char sym,  std::uint64_t row, std::uint64_t column)
{
    _map = map;
    _current_row = row;
    _current_column = column;
    _sym = sym;
}

MapElement::~MapElement()
{
}


std::list<std::shared_ptr<IMapElem>> MapElement::getRightElem()
{
    std::list<std::shared_ptr<IMapElem>> res;
    try {
        res = _map->getElemAt(_current_row, _current_column + 1);
        return (res);
    }
    catch(const std::exception& e) {
        throw std::range_error("out of range");
    }
}

std::list<std::shared_ptr<IMapElem>> MapElement::getBotomElem()
{
    std::list<std::shared_ptr<IMapElem>> res;
    try {
        res = _map->getElemAt(_current_row + 1, _current_column);
        return (res);
    }
    catch(const std::exception& e) {
        throw std::range_error("out of range");
    }
}

std::list<std::shared_ptr<IMapElem>> MapElement::getleftElem()
{
    std::list<std::shared_ptr<IMapElem>> res;
    try {
        res = _map->getElemAt(_current_row, _current_column - 1);
        return (res);
    }
    catch(const std::exception& e) {
        throw std::range_error("out of range");
    }
}

std::list<std::shared_ptr<IMapElem>> MapElement::getCurElem()
{
    std::list<std::shared_ptr<IMapElem>> res;
    try {
        res = _map->getElemAt(_current_row, _current_column);
        return (res);
    }
    catch(const std::exception& e) {
        throw std::range_error("out of range");
    }
}

std::uint64_t MapElement::getCurrentRow()
{
    return _current_row;
}

std::uint64_t MapElement::getCurrentCol()
{
    return _current_column;
}

MapManager *MapElement::getMap()
{
    return (_map);
}


std::list<std::shared_ptr<IMapElem>> MapElement::getTopElem()
{
    std::list<std::shared_ptr<IMapElem>> res;
    try {
        res = _map->getElemAt(_current_row - 1, _current_column);
        return (res);
    }
    catch(const std::exception& e) {
        throw std::range_error("out of range");
    }
}

void MapElement::getHited()
{
    
}

bool MapElement::isSolide()
{
    return (_solide);
}

irr::core::vector3df MapElement::getPos()
{
    return (_pos);
}

char MapElement::getSym()
{
    return _sym;
}