/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** universe
*/

#include "universe.hpp"

universe::universe(): _zoom(2)
{
    this->_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Tilemap");
    this->_game = new game();
    this->_cam = sf::View();
    this->_cam.setCenter(1500, 1500);
    this->_cam.setSize(1920, 1080);
    this->_actual_zoom = 2;
    this->_cam.zoom(1 / (_zoom * 1.20));
    this->_window->setView(_cam);
    this->_window->setFramerateLimit(144);
}

universe::~universe()
{
    delete this->_window;
    delete this->_game;
}

void universe::unzoom_camera(void)
{
    if (_actual_zoom == _zoom) {
        this->_cam.zoom(_zoom * 1.20);
        _actual_zoom = 0;
        this->_window->setView(_cam);
    }
}

void universe::rezoom_camera(void)
{
    if (_actual_zoom == 0) {
        this->_cam.zoom(1 / (_zoom * 1.20));
        _actual_zoom = _zoom;
        this->_window->setView(_cam);
    }
}

sf::View &universe::getView()
{
    return (this->_cam);
}