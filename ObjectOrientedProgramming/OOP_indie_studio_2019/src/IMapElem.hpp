/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** IMapElem
*/

#ifndef IMAPELEM_HPP_
#define IMAPELEM_HPP_

#include <memory>
#include <list>
#include <irrlicht.h>
class IMapElem {
    public:
        virtual ~IMapElem() = default;
        virtual std::list<std::shared_ptr<IMapElem>> getRightElem() = 0;
        virtual std::list<std::shared_ptr<IMapElem>> getTopElem() = 0;
        virtual std::list<std::shared_ptr<IMapElem>> getleftElem() = 0;
        virtual std::list<std::shared_ptr<IMapElem>> getBotomElem() = 0;
        virtual std::list<std::shared_ptr<IMapElem>> getCurElem() = 0;
        virtual std::uint64_t getCurrentRow() = 0;
        virtual std::uint64_t getCurrentCol() = 0;
        virtual char getSym() = 0;

        virtual irr::core::vector3df getPos() = 0;
        virtual void getHited() = 0;
        virtual bool isSolide() = 0;
        // virtual bool isOnMap() = 0;
    protected:
    private:
};

#endif /* !IMAPELEM_HPP_ */
