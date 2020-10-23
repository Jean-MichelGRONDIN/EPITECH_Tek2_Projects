/*
** EPITECH PROJECT, 2020
** about1.cpp
** File description:
** libSdl
*/

#ifndef LIBSDL_HPP_
#define LIBSDL_HPP_

#include "../../include/ILib.hpp"
#include "../../include/enums.hpp"
#include <unistd.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>

#include "./sdlIncludes.hpp"

class sdlObject {
    public:
        sdlObject(std::string path, std::string name, SDL_Renderer *renderer);
        ~sdlObject();
        State refreshObj(SDL_Renderer *renderer);
        State refreshPos();
        State draw(SDL_Renderer *renderer);
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
        SDL_Surface *_surface;
        SDL_Texture *_sprite;
        SDL_Rect _rec;
        std::string _name;
};

class libSdl : public ILib {
    public:
        libSdl();
        ~libSdl();
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
        int _closeEvent;
        std::string _name;
        bool _windowIsOpen;
        bool isThisEventGoing(int e);
        bool isThisEventGoing(SDL_EventType e);
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        std::unordered_map<std::string, sdlObject> object_list;
};

#endif