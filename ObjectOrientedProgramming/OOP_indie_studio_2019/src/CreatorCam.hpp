/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** CreatCam
*/

#ifndef CREATORCAM_HPP_
#define CREATORCAM_HPP_

#include <irrlicht.h>
#include "IrrGui.hpp"
#include "IrrScean.hpp"
#include <memory>
#include <list>
#include <unordered_map>

class CreatorCam : public IEventHandeler{
    public:
        enum CAM_TYPE {
            FPS,
            MAYA,
            STATIC
        };
        CreatorCam(std::shared_ptr<IrrGui> gui, std::shared_ptr<IrrScean> scean);
        ~CreatorCam();
        virtual bool onEvent(const irr::SEvent& event) override;
        void displayWin();
        void addCam();
        void addCam(std::wstring name, CAM_TYPE type);
        void hideWindow();
        void fpsChecked();
        void mayaChecked();
        void statChecked();
//        void unValidCam();

    protected:
        std::shared_ptr<IrrScean> _scean;
        std::shared_ptr<IrrGui> _gui;
        irr::gui::IGUIWindow *_window;
        irr::gui::IGUIButton *_ValidButton;
        irr::gui::IGUIButton *_hidButton;
        irr::gui::IGUIEditBox *_editBox;
        irr::gui::IGUICheckBox *_fps;
        irr::gui::IGUICheckBox *_maya;
        irr::gui::IGUICheckBox *_stat;
        std::unordered_map<std::wstring, irr::scene::ICameraSceneNode *> _camsName;
        irr::gui::IGUIComboBox *_comboBox;
    private:
};

#endif /* !CREATORCAM_HPP_ */
