/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** IrrGui
*/

#ifndef IRRGUI_HPP_
#define IRRGUI_HPP_

#include <irrlicht.h>
#include "IItemGui.hpp"
#include <unordered_map>
#include "IEventHandeler.hpp"

class IrrGui {
    public:
        IrrGui(irr::IrrlichtDevice *device);
        ~IrrGui();
        irr::u32 getNewId();
        irr::gui::IGUIEnvironment *getGuiEnv();
        bool manageEvent(const irr::SEvent& event);
        void addItem(irr::u32 id, IEventHandeler *);

    protected:
        irr::gui::IGUIEnvironment *_guiEnv;
        std::unordered_map<int, IEventHandeler *> _guiEvent;
    private:
};

#endif /* !IRRGUI_HPP_ */
