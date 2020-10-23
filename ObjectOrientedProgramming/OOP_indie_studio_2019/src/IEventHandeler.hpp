/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** IEventHandeler
*/

#ifndef IEVENTHANDELER_HPP_
#define IEVENTHANDELER_HPP_

#include <irrlicht.h>

class IEventHandeler {
    public:
        virtual ~IEventHandeler() = default;
        virtual bool onEvent(const irr::SEvent& event) = 0;
};

#endif /* !IEVENTHANDELER_HPP_ */
