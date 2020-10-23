/**
** EPITECH PROJECT, 2019
** LibTest
** File description:
** LibTest
*/

#ifndef _ILIB_HPP_
#define _ILIB_HPP_

#include "./enums.hpp"
#include <string>

class ILib {
    public:
        virtual void test() const = 0;
        virtual State windowOpen() = 0;
        virtual State windowClose() = 0;
        virtual State windowClear() = 0;
        virtual State windowDisplay() = 0;
        virtual bool windowIsOpen() const = 0;
        virtual bool windowCloseEvent() = 0;
        virtual bool switchLibEvent() = 0;
        virtual State initAsset(std::string id, std::string path, int x, int y) = 0;
        virtual State drawAsset(std::string id) = 0;
        virtual State deleteAsset(std::string id) = 0;
        virtual bool leftArrowEvent() = 0;
        virtual bool rightArrowEvent() = 0;
        virtual bool upArrowEvent() = 0;
        virtual bool downArrowEvent() = 0;
        virtual bool EnterEvent() = 0;
        virtual bool backMenuEvent() = 0;
        virtual std::string getName() = 0;
        virtual State setPos(std::string id, float x, float y) = 0;
        virtual float getPosX(std::string id) const = 0;
        virtual float getPosY(std::string id) const = 0;
        virtual State windowEvents() = 0;
    protected:
    private:
};

#endif