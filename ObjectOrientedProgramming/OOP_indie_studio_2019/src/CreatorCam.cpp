/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** CreatorCam
*/

#include "CreatorCam.hpp"

CreatorCam::CreatorCam(std::shared_ptr<IrrGui> gui, std::shared_ptr<IrrScean> scean)
{
    _gui = gui;
    _scean = scean;
    _comboBox = _gui->getGuiEnv()->addComboBox(irr::core::rect<irr::s32>(100,10,60 + 140, 10 + 20), 0, _gui->getNewId());
    _gui->addItem(_comboBox->getID(), this);
    _window = _gui->getGuiEnv()->addWindow(irr::core::rect<irr::s32>(100,100,400,300), false, L"Add a new cam");
    _ValidButton = _gui->getGuiEnv()->addButton(irr::core::rect<irr::s32>(50, 140,150,180), _window, _gui->getNewId(), L"Add ", L"Add this new cam");
    _gui->addItem(_ValidButton->getID(), this);
    _hidButton = _gui->getGuiEnv()->addButton(irr::core::rect<irr::s32>(160, 140,260,180), _window, _gui->getNewId(), L"cancel");
    _gui->addItem(_hidButton->getID(), this);
    _editBox = _gui->getGuiEnv()->addEditBox(L"name", irr::core::rect<irr::s32>(5, 30, 200, 60), true, _window);
    _fps = _gui->getGuiEnv()->addCheckBox(false, irr::core::rect<irr::s32>(5, 65 , 150, 80), _window, _gui->getNewId(), L"fps mode");
    _gui->addItem(_fps->getID(), this);
    _maya = _gui->getGuiEnv()->addCheckBox(true, irr::core::rect<irr::s32>(5, 85 , 150, 100), _window, _gui->getNewId(), L"maya mode");
    _gui->addItem(_maya->getID(), this);
    _stat = _gui->getGuiEnv()->addCheckBox(false, irr::core::rect<irr::s32>(5, 105, 150, 120), _window, _gui->getNewId(), L"static mode");
    _gui->addItem(_stat->getID(), this);
    _window->setVisible(false);
    _window->getCloseButton()->setVisible(false);
}

CreatorCam::~CreatorCam()
{
}

void CreatorCam::fpsChecked()
{
    _maya->setChecked(false);
    _stat->setChecked(false);
}

void CreatorCam::mayaChecked()
{
    _fps->setChecked(false);
    _stat->setChecked(false);
}

void CreatorCam::statChecked()
{
    _maya->setChecked(false);
    _fps->setChecked(false);
}

bool CreatorCam::onEvent(const irr::SEvent& event)
{
    irr::s32 id = event.GUIEvent.Caller->getID();

    if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
        if (_ValidButton->getID() == id) {
            addCam();
            return (true);
        }
        if (_hidButton->getID() == id) {
            hideWindow();
            return (true);
        }
    }
    if (event.GUIEvent.EventType == irr::gui::EGET_CHECKBOX_CHANGED) {
        if (_fps->getID() == id) {
            if (_fps->isChecked())
                fpsChecked();
            return (true);
        }
        if (_maya->getID() == id) {
            if (_maya->isChecked())
                mayaChecked();
            return (true);
        }
        if (_stat->getID() == id) {
            if (_stat->isChecked())
                statChecked();
            return (true);
        }
    }
    if (event.GUIEvent.EventType == irr::gui::EGET_COMBO_BOX_CHANGED) {
        _camsName[_comboBox->getItem(_comboBox->getSelected())]->setVisible(true);
        _scean->getScenManger()->setActiveCamera(_camsName[_comboBox->getItem(_comboBox->getSelected())]);
        return (true);
    }
    return (false);
}

void CreatorCam::addCam()
{
    std::wstring name = _editBox->getText();
    for (auto &tmp : _camsName) {
        if (tmp.first == name) {
            _window->setVisible(false);
            return;
        }
    }
    if (_fps->isChecked()) {
        _camsName.insert({name, _scean->getScenManger()->addCameraSceneNodeFPS()});
    }
    if (_maya->isChecked()) {
        _camsName.insert({name, _scean->getScenManger()->addCameraSceneNodeMaya()});
    }
    if (_stat->isChecked()) {
        _camsName.insert({name, _scean->getScenManger()->addCameraSceneNode()});
    }
    _comboBox->addItem(name.c_str());
    _scean->getScenManger()->setActiveCamera(_camsName[_comboBox->getItem(_comboBox->getSelected())]);
    hideWindow();
}

void CreatorCam::addCam(std::wstring name, CAM_TYPE type)
{
    for (auto tmp : _camsName) {
        if (tmp.first == name) {
            return;
        }
    }
    switch (type)
    {
        case FPS:
            _camsName.insert({name, _scean->getScenManger()->addCameraSceneNodeFPS()});
            break;
        case MAYA:
            _camsName.insert({name, _scean->getScenManger()->addCameraSceneNodeFPS()});
            break;
        case STATIC:
            _camsName.insert({name, _scean->getScenManger()->addCameraSceneNodeFPS()});
            break;
        default:
            break;
    }
    _comboBox->addItem(name.c_str());
}

void CreatorCam::displayWin()
{
    _window->setVisible(true);
}

void CreatorCam::hideWindow()
{
    _hidButton->setPressed(false);
    _ValidButton->setPressed(false);
    _window->setVisible(false);
}