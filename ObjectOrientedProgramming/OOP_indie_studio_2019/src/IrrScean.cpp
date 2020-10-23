/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** IrrScean
*/

#include "IrrScean.hpp"

IrrScean::IrrScean(irr::IrrlichtDevice *device)
{
    _scenemgr = device->getSceneManager();
}

IrrScean::~IrrScean()
{
}

irr::scene::ISceneManager *IrrScean::getScenManger()
{
    return (_scenemgr);
}

bool IrrScean::onEvent(const irr::SEvent& event)
{
    for (auto eventHandeler : _eventHandelers) {
        if (eventHandeler->onEvent(event))
            return (true);
    }
    return (false);
}

void IrrScean::updateObjs()
{
    for (auto obj : _objs) {
        obj->update();
    }
}

void IrrScean::addObj(std::shared_ptr<ISceanObject> obj)
{
    _objs.push_front(obj);
}

void IrrScean::addEventHandeler(std::shared_ptr<IEventHandeler> eh)
{
    _eventHandelers.push_front(eh);
}

void IrrScean::clean()
{
    this->_objs.clear();
    this->_eventHandelers.clear();
}
