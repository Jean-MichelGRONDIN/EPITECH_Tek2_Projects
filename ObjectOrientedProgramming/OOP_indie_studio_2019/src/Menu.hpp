/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "IPart.hpp"
#include "Button.hpp"
#include "enums.hpp"
#include "GamePart.hpp"
#include "Music.hpp"
#include "MySound.hpp"


class Menu : public GamePart {
    public:
        Menu(ICameraSceneNode *cam, Indie::STATE &indieState, IrrWindow &window, IrrlichtDevice *device, std::shared_ptr<GameSettings> settings,
            Indie::STATE curentState = Indie::MENU, vector3df pos = vector3df(80.0F, 166.0F, 25.0F), vector3df tagret = vector3df(800.0F, -50.0F, 100.0F));
        ~Menu();
        virtual bool onEvent(const irr::SEvent& event) override;
        virtual void update() override;
        void play();
        void quite();
        void hidElem();
        void display();
    private:
        IrrlichtDevice *_device;
        IrrWindow &_window;
        IGUIButton* _playMul;
        IGUIButton* _playSolo;
        IGUIButton *_settingsB;
        IGUIButton *_quit;
        std::shared_ptr<Musical> _musicMenu;
        int _ret;
        bool _first;
        MySound _sound;
        bool _isLost;
};

#endif /* !MENU_HPP_ */
