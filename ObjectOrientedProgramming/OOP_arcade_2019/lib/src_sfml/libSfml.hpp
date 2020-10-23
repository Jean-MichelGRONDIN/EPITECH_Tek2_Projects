/*
** EPITECH PROJECT, 2020
** about1.cpp
** File description:
** lib_sfml
*/

#ifndef LIB_SFML_HPP_
#define LIB_SFML_HPP_

#include "../../include/ILib.hpp"
#include <unistd.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <unordered_map>

#include "./sfmlIncludes.hpp"

class sfmlObject {
    public:
        sfmlObject(std::string path, std::string name, int x = 0, int y = 0);
        ~sfmlObject();
        State refreshObj(sf::RenderWindow *window);
        State refreshPos();
        State draw(sf::RenderWindow *window);
        State setPos(float x, float y);
        float getPosX() const;
        float getPosY() const;
        State refreshRec();
        State setRec(int x, int y, int w, int h);
        float getRecX() const;
        float getRecY() const;
        float getRecW() const;
        float getRecH() const;
        std::string getName() const {return (_name);};
    private:
        sf::Texture *_texture;
        sf::Sprite *_sprite;
        sf::Vector2f _pos;
        std::string _name;
        sf::IntRect _rec;
};

class libSfml : public ILib {
    public:
        libSfml();
        ~libSfml();
        void test() const;
        State windowOpen();
        State windowClear();
        State windowDisplay();
        State windowClose();
        bool windowIsOpen() const;
        bool windowCloseEvent();
        bool switchLibEvent();
        State initAsset(std::string id, std::string path, int x = 0, int y = 0);
        State drawAsset(std::string id);
        State deleteAsset(std::string id);
        bool leftArrowEvent();
        bool rightArrowEvent();
        bool upArrowEvent();
        bool downArrowEvent();
        bool EnterEvent();
        bool backMenuEvent();
        std::string getName();
        State setPos(std::string id, float x, float y);
        float getPosX(std::string id) const;
        float getPosY(std::string id) const;
        State windowEvents();

    private:
        std::string _name;
        int _isEvent;
        sf::Keyboard::Key _key;
        int _closeEvent;
        bool isThisEventGoing(sf::Event::EventType e);
        bool isThisEventGoing(sf::Keyboard::Key e);
        sf::RenderWindow *_window;
        sf::Event _event;
        std::unordered_map<std::string, sfmlObject> object_list;
};
#endif