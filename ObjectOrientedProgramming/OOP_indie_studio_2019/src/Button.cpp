/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Button
*/

#include "Button.hpp"

Button::Button(std::shared_ptr<IrrGui> &gui, int &res, int action, irr::core::rect<irr::s32> rec) : _gui(gui), _res(res), _action(action)
{
    _self = _gui->getGuiEnv()->addButton(rec, 0, _gui->getNewId());
    _gui->addItem(_self->getID(), this);
}

Button::~Button()
{
    _self->drop();
    // delete _self;
}

bool Button::onEvent(const irr::SEvent& event)
{
    if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
        if (this->_self->getID() == event.GUIEvent.Caller->getID()) {
            _res = _action;
        }
    }
	return (false);
}

void Button::setText(const wchar_t *text)
{
    _self->setText(text);
}
