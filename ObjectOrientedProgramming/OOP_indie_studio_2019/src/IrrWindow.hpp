/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** IrrWindow
*/

#ifndef IRRWINDOW_HPP_
#define IRRWINDOW_HPP_

#include <irrlicht.h>
#include "IrrGui.hpp"
#include "MyEventRecever.hpp"
#include "IrrScean.hpp"
#include "Player.hpp"
#include <memory>
#include "paths.hpp"

class IrrWindow {
    public:
        IrrWindow();
        ~IrrWindow();
        void drawGame();
        std::shared_ptr<IrrGui> getgui();
        std::shared_ptr<IrrScean> getscean();
        void setEventRecever(irr::IEventReceiver *eventReceiver);
        irr::video::IVideoDriver *getDriver() {return _driver;};
        irr::IrrlichtDevice *getDevice() {return _device;};
        void cleanAll();
        void cleanScene();
        void cleanEnv();
        bool isProgStillGoing();

    protected:
        irr::IrrlichtDevice *_device;
        irr::video::IVideoDriver *_driver;
        std::shared_ptr<IrrGui> _gui;
        std::shared_ptr<IrrScean> _scean;
        irr::video::ITexture *_image;
        irr::core::rect<irr::s32> _rect;
    
};

#endif /* !IRRWINDOW_HPP_ */
