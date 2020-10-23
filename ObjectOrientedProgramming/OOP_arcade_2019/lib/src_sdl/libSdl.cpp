/*
** EPITECH PROJECT, 2020
** about1.cpp
** File description:
** libSdl
*/

#include "./libSdl.hpp"

libSdl::libSdl()
{
    this->_windowIsOpen = false;
    this->_window = NULL;
    this->_name = "SDL";
    this->_isEvent = -1;
    this->_key = -1;
    this->_closeEvent = -1;
}

libSdl::~libSdl()
{
    this->windowClose();
}

void libSdl::test() const
{
    std::cout << "[libSdl] i am here working and loaded as expected ^^" << std::endl;
}

State libSdl::windowOpen()
{
    if (this->_windowIsOpen == false) {
        if (SDL_Init(SDL_INIT_VIDEO) == -1) {
            return (FAILURE);
        }
        this->_window = SDL_CreateWindow("Arcade Window Sdl", 100, 100, WIDTH, HEIGTH, 0);
        this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
        this->_windowIsOpen = true;
        return (SUCCESS);
    }
    return (FAILURE);
}

State libSdl::windowClear()
{
    SDL_RenderClear(this->_renderer);
    return (SUCCESS);
}

State libSdl::windowDisplay()
{
    SDL_RenderPresent(this->_renderer);
    return (SUCCESS);
}

State libSdl::windowClose()
{
    if (this->_windowIsOpen == true) {
        this->_windowIsOpen = false;
        SDL_DestroyRenderer(this->_renderer);
        SDL_DestroyWindow(this->_window);
        this->_window = NULL;
        return (SUCCESS);
    }
    return (FAILURE);
}

bool libSdl::windowIsOpen() const
{
    return (this->_windowIsOpen);
}

bool libSdl::isThisEventGoing(int e) {
    SDL_Event event;
    SDL_WaitEvent(&event);

    if (event.key.keysym.sym == e) {
        return (true);
    }
    return (false);
}

bool libSdl::isThisEventGoing(SDL_EventType e) {
    SDL_Event event;
    SDL_WaitEvent(&event);

    if (event.type == e) {
        return (true);
    }
    return (false);
}

bool libSdl::windowCloseEvent()
{
    if (this->_isEvent != -1 && this->_closeEvent != -1) {
        this->_isEvent = -1;
        this->_closeEvent = -1;
        return (true);
    }
    if (this->_isEvent != -1 && this->_key == SDLK_ESCAPE) {
        this->_isEvent = -1;
        this->_key = -1;
        return (true);
    }
    return (false);
}

bool libSdl::switchLibEvent()
{
    if (this->_isEvent != -1 && this->_key == SDLK_c) {
        this->_isEvent = -1;
        this->_key = -1;
        return (true);
    }
    return (false);
}

State libSdl::initAsset(std::string id, std::string path, int x, int y)
{
    if (this->object_list.find(id) == this->object_list.end()) {
        this->object_list.emplace(id, sdlObject(path, id, this->_renderer));
        return (SUCCESS);
    }
    return (FAILURE);
}

State libSdl::drawAsset(std::string id)
{
    if (this->object_list.find(id) != this->object_list.end()) {
        this->object_list.find(id)->second.draw(this->_renderer);
        return (SUCCESS);
    }
    return (FAILURE);
}

State libSdl::deleteAsset(std::string id)
{
    return (FAILURE);
}

bool libSdl::leftArrowEvent()
{
    if (this->_isEvent != -1 && this->_key == SDLK_LEFT) {
        this->_isEvent = -1;
        this->_key = -1;
        return (true);
    }
    return (false);
}

bool libSdl::rightArrowEvent()
{
    if (this->_isEvent != -1 && this->_key == SDLK_RIGHT) {
        this->_isEvent = -1;
        this->_key = -1;
        return (true);
    }
    return (false);
}

bool libSdl::upArrowEvent()
{
    if (this->_isEvent != -1 && this->_key == SDLK_UP) {
        this->_isEvent = -1;
        this->_key = -1;
        return (true);
    }
    return (false);
}

bool libSdl::downArrowEvent()
{
    if (this->_isEvent != -1 && this->_key == SDLK_DOWN) {
        this->_isEvent = -1;
        this->_key = -1;
        return (true);
    }
    return (false);
}

bool libSdl::EnterEvent()
{
    if (this->_isEvent != -1 && this->_key == SDLK_KP_ENTER) {
        this->_isEvent = -1;
        this->_key = -1;
        return (true);
    }
    return (false);
}

bool libSdl::backMenuEvent()
{
    if (isThisEventGoing(SDLK_m) == true) {
        return (true);
    }
    return (false);
}

std::string libSdl::getName()
{
    return (this->_name);
}

State libSdl::setPos(std::string id, float x, float y)
{
    if (this->object_list.find(id) != this->object_list.end()) {
        this->object_list.find(id)->second.setPos(x, y);
        this->object_list.find(id)->second.refreshPos();
        return (SUCCESS);
    }
    return (FAILURE);
}

float libSdl::getPosX(std::string id) const
{
    if (this->object_list.find(id) != this->object_list.end()) {
        return (this->object_list.find(id)->second.getPosX());
    }
    return (FAILURE);
}

float libSdl::getPosY(std::string id) const
{
    if (this->object_list.find(id) != this->object_list.end()) {
        return (this->object_list.find(id)->second.getPosY());
    }
    return (FAILURE);
}

State libSdl::windowEvents()
{
    SDL_Event e;

    this->_isEvent = -1;
    this->_key = -1;
    if (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            this->_closeEvent = 1;
            this->_isEvent = 1;
        } else if (e.type == SDL_KEYUP) {
            this->_key = e.key.keysym.sym;
            this->_isEvent = 1;
        }
    }
    return (SUCCESS);
}

extern "C" {
    libSdl *constuct() {
        return new libSdl();
    }
}