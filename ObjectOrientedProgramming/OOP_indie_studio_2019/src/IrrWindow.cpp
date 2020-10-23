/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** IrrWindow
*/

#include "IrrWindow.hpp"

IrrWindow::IrrWindow()
{
    #ifdef __linux__ 
        _device = irr::createDevice(irr::video::EDT_OPENGL,
            irr::core::dimension2d<irr::u32>(1920,1080), 16,
            false, false, false, 0);
    #elif _WIN32
        _device = irr::createDevice(irr::video::EDT_OPENGL,
            irr::core::dimension2d<irr::u32>(1920,1080), 16,
            false, false, false, 0);
    #else
        exit (0);
    #endif
    _device->setWindowCaption(L"LOLOLOLOLOLOL");
    _driver = _device->getVideoDriver();
    _gui = std::make_shared<IrrGui>(_device);
    _scean = std::make_shared<IrrScean>(_device);
    _image = _driver->getTexture(FONT);
    irr::core::dimension2d<irr::u32> i_size = _image->getSize();
    irr::core::position2d<irr::s32> pos0 (0, 0);
    irr::core::position2d<irr::s32> pos1 ( _image->getSize().Width, _image->getSize().Height);
    _rect = {pos0, pos1};
}

IrrWindow::~IrrWindow()
{
    _device->drop();
}

void IrrWindow::drawGame() {
    while (_device->run()) {
        _scean->updateObjs();
        _driver->beginScene(true, true, irr::video::SColor(255,113,113,133));
        _driver->draw2DImage(_image, irr::core::position2d<irr::s32>(0, 0),
        _rect, 0);
        _scean->getScenManger()->drawAll();
        _gui->getGuiEnv()->drawAll();
        _driver->endScene();
    }
}

void IrrWindow::setEventRecever(irr::IEventReceiver *eventReceiver)
{
    _device->setEventReceiver(eventReceiver);
}

std::shared_ptr<IrrGui> IrrWindow::getgui()
{
    return (_gui);
}

std::shared_ptr<IrrScean> IrrWindow::getscean()
{
    return (_scean);
}

void IrrWindow::cleanAll()
{
    this->cleanEnv();
    this->cleanScene();
}

void IrrWindow::cleanScene()
{
    this->_scean->clean();
}

void IrrWindow::cleanEnv()
{
//    this->_gui->clean();
}

bool IrrWindow::isProgStillGoing()
{
    if (!this->_device->run()) {
        return (false);
    }
    return (true);
}