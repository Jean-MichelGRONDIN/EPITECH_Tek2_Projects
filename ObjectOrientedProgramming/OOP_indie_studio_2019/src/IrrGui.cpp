/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** IrrGui
*/

#include "IrrGui.hpp"

IrrGui::IrrGui(irr::IrrlichtDevice *device)
{
    _guiEnv = device->getGUIEnvironment();
    irr::gui::IGUISkin* skin = _guiEnv->getSkin();
    irr::gui::IGUIFont* font = _guiEnv->getFont("../assets/NineteenNinetySeven-11XB.png");
    skin->setFont(font);
    skin->setFont(_guiEnv->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
}

IrrGui::~IrrGui()
{
}

irr::u32 IrrGui::getNewId()
{
    return (_guiEvent.size() + 1);
}

irr::gui::IGUIEnvironment *IrrGui::getGuiEnv()
{
    return (_guiEnv);
} 

bool IrrGui::manageEvent(const irr::SEvent& event)
{
    irr::s32 id = event.GUIEvent.Caller->getID();

    if (_guiEvent[id])
        return (_guiEvent[id]->onEvent(event));
    return (false);
}

void IrrGui::addItem(irr::u32 id, IEventHandeler *event)
{
    _guiEvent.insert({id, event});
}
