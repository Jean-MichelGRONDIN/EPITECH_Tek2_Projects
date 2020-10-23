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
#include <fstream>
#include <iomanip>
#include <vector>
#include <unordered_map>

#include "./ncursIncludes.hpp"

class ncursObject {
    public:
        ncursObject(std::string path, std::string name, int x = 0, int y = 0);
        ~ncursObject();
        State refreshObj(WINDOW *window);
        State refreshPos();
        State draw(WINDOW *window);
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
        int _x;
        int _y;
        std::string _name;
        std::vector<std::string> _sprite;
};

class libNcurs : public ILib {
    public:
        libNcurs();
        ~libNcurs();
        void test() const;
        State windowOpen();
        State windowClear();
        State windowDisplay();
        State windowClose();
        bool windowIsOpen() const;
        bool windowCloseEvent();
        bool switchLibEvent();
        State initAsset(std::string id, std::string path, int x, int y);
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
        int _isEvent;
        int _key;
        WINDOW *_window;
        std::string _name;
        bool _windowIsOpen;
        bool isThisEventGoing(char e);
        std::unordered_map<std::string, ncursObject> object_list;
};

#endif