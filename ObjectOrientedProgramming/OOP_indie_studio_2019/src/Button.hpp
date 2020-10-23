/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <string>
#include <memory>
#include "ISceanObject.hpp"
#include "IEventHandeler.hpp"
#include "IrrGui.hpp"

using namespace irr;

class Button : public IEventHandeler {
    public:
        Button(std::shared_ptr<IrrGui> &gui, int &res, int action, irr::core::rect<irr::s32> rec);
        ~Button() override;
        bool onEvent(const irr::SEvent& event) override;
        void setText(const wchar_t *text);

    private:
        irr::gui::IGUIButton *_self;
        std::shared_ptr<IrrGui> &_gui;
        int &_res;
        int _action;
};

#endif /* !BUTTON_HPP_ */
