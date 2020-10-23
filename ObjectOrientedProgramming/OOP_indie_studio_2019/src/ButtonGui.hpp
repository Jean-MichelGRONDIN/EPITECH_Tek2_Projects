/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** ButtonGui
*/

#ifndef BUTTONGUI_HPP_
#define BUTTONGUI_HPP_

#include "IItemGui.hpp"
#include <irrlicht.h>

class ButtonGui : public IItemGui{
    public:
        ButtonGui(  irr::gui::IGUIEnvironment *guiEnv,
                    const irr::core::rect<irr::s32> &rect,
                    void (*)(void),
                    irr::gui::IGUIElement *parent = 0,
                    irr::s32 id = -1, 
                    const wchar_t *text = 0,
                    const wchar_t *tooltiptext = 0
                );
        ~ButtonGui();
        void onEvent() override;
        void getButton();

    protected:
        void (*_callOnEvent)(void);
        irr::gui::IGUIButton *_button;
    private:
};

#endif /* !BUTTONGUI_HPP_ */
