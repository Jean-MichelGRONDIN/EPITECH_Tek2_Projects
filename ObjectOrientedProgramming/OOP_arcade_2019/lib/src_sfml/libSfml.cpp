/*
** EPITECH PROJECT, 2020
** libSfml.cpp
** File description:
** lib_sfml
*/

#include "./libSfml.hpp"

libSfml::libSfml()
{
    this->_window = new sf::RenderWindow();
    this->_event = sf::Event();
    this->_name = "SFML";
    this->_isEvent = -1;
    this->_closeEvent = -1;
}

libSfml::~libSfml()
{
    this->windowClose();
}

void libSfml::test() const
{
    std::cout << "[libSfml] i am here working and loaded as expected ^^" << std::endl;
}

State libSfml::windowOpen()
{
    if (this->_window->isOpen() == false) {
        this->_window->create(sf::VideoMode(WIDTH, HEIGTH), "libsfml_window");
        this->_window->setFramerateLimit(60);
        return (SUCCESS);
    }
    return (FAILURE);
}

State libSfml::windowClear()
{
    _window->clear(sf::Color::Black);
    return (SUCCESS);
}

State libSfml::windowDisplay()
{
    this->_window->display();
    return (SUCCESS);
}

State libSfml::windowClose()
{
    if (this->_window->isOpen() == true) {
        this->_window->close();
        return (SUCCESS);
    }
    return (FAILURE);
}

bool libSfml::windowIsOpen() const
{
    return (this->_window->isOpen());
}

bool libSfml::isThisEventGoing(sf::Event::EventType e) {
    while (this->_window->pollEvent(this->_event)) {
        if (this->_event.type == e) {
            return (true);
        } else {
            return (false);
        }
    }
    return (false);
}

bool libSfml::isThisEventGoing(sf::Keyboard::Key e) {
    while (this->_window->pollEvent(this->_event)) {
        if (this->_event.key.code == e) {
            return (true);
        } else {
            return (false);
        }
    }
    return (false);
}

bool libSfml::windowCloseEvent()
{
    if (this->_isEvent != -1 && this->_closeEvent != -1) {
        this->_isEvent = -1;
        this->_closeEvent = -1;
        return (true);
    }
    if (this->_isEvent != -1 && this->_key == sf::Keyboard::Escape) {
        this->_isEvent = -1;
        return (true);
    }
    return (false);
}

bool libSfml::switchLibEvent()
{
    if (this->_isEvent != -1 && this->_key == sf::Keyboard::C) {
        this->_isEvent = -1;
        return (true);
    }
    return (false);
}

State libSfml::initAsset(std::string id, std::string path, int x, int y)
{
    if (this->object_list.find(id) == this->object_list.end()) {
        this->object_list.emplace(id, sfmlObject(path, id, x, y));
        return (SUCCESS);
    }
    return (FAILURE);
}

State libSfml::drawAsset(std::string id)
{
    if (this->object_list.find(id) != this->object_list.end()) {
        this->object_list.find(id)->second.draw(this->_window);
        return (SUCCESS);
    }
    return (FAILURE);
}

State libSfml::deleteAsset(std::string id)
{
    return (FAILURE);
}

bool libSfml::leftArrowEvent()
{
    if (this->_isEvent != -1 && this->_key == sf::Keyboard::Left) {
        this->_isEvent = -1;
        return (true);
    }
    return (false);
}

bool libSfml::rightArrowEvent()
{
    if (this->_isEvent != -1 && this->_key == sf::Keyboard::Right) {
        this->_isEvent = -1;
        return (true);
    }
    return (false);
}

bool libSfml::upArrowEvent()
{
    if (this->_isEvent != -1 && this->_key == sf::Keyboard::Up) {
        this->_isEvent = -1;
        return (true);
    }
    return (false);
}

bool libSfml::downArrowEvent()
{
    if (this->_isEvent != -1 && this->_key == sf::Keyboard::Down) {
        this->_isEvent = -1;
        return (true);
    }
    return (false);
}

bool libSfml::EnterEvent()
{
    if (this->_isEvent != -1 && this->_key == sf::Keyboard::Enter) {
        this->_isEvent = -1;
        return (true);
    }
    return (false);
}

bool libSfml::backMenuEvent()
{
    if (this->_isEvent != -1 && this->_key == sf::Keyboard::M) {
        this->_isEvent = -1;
        return (true);
    }
    return (false);
}

std::string libSfml::getName()
{
    return (this->_name);
}

State libSfml::setPos(std::string id, float x, float y)
{
    if (this->object_list.find(id) != this->object_list.end()) {
        this->object_list.find(id)->second.setPos(x, y);
        this->object_list.find(id)->second.refreshPos();
        return (SUCCESS);
    }
    return (FAILURE);
}

float libSfml::getPosX(std::string id) const
{
    if (this->object_list.find(id) != this->object_list.end()) {
        return (this->object_list.find(id)->second.getPosX());
    }
    return (FAILURE);
}

float libSfml::getPosY(std::string id) const
{
    if (this->object_list.find(id) != this->object_list.end()) {
        return (this->object_list.find(id)->second.getPosY());
    }
    return (FAILURE);
}

State libSfml::windowEvents()
{
    this->_isEvent = -1;
    while (this->_window->pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::EventType::KeyPressed) {
            this->_key = this->_event.key.code;
            this->_isEvent = 1;
        }
        if (this->_event.type == sf::Event::Closed) {
            this->_closeEvent = 1;
            this->_isEvent = 1;
        }
    }
    return (SUCCESS);
}

extern "C" {
    libSfml *constuct() {
        return new libSfml();
    }
}
