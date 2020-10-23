/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** IrrScean
*/

#ifndef IRRSCEAN_HPP_
#define IRRSCEAN_HPP_

#include <irrlicht.h>
#include <list>
#include <unordered_map>
#include "ISceanObject.hpp"
#include <memory>
#include "IEventHandeler.hpp"

class IrrScean {
    public:
        enum CAME_TYPE{
            DEF,
            FPS,
            MAYA,
        };
        IrrScean(irr::IrrlichtDevice *device);
        ~IrrScean();
        irr::scene::ISceneManager *getScenManger();
        bool onEvent(const irr::SEvent& event);
        void updateObjs();
        void addObj(std::shared_ptr<ISceanObject>);
        void addEventHandeler(std::shared_ptr<IEventHandeler>);
        void clean();
    protected:
        irr::scene::ISceneManager *_scenemgr;
        std::list<std::shared_ptr<ISceanObject>> _objs;
        std::list<std::shared_ptr<IEventHandeler>> _eventHandelers;
    private:
};

#endif /* !IRRSCEAN_HPP_ */
