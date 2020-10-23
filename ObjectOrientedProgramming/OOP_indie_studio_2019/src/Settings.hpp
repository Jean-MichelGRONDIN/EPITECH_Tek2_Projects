/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include "GamePart.hpp"

class Settings : public GamePart{
    public:
        Settings(ICameraSceneNode *cam, Indie::STATE &indieState, IrrWindow &window, IrrlichtDevice *device, std::shared_ptr<GameSettings> settings,
            Indie::STATE curentState = Indie::SETTINGS, vector3df pos = vector3df(80.0F, 166.0F, 25.0F), vector3df tagret = vector3df(-800.0F, -50.0F, 100.0F));
        ~Settings();
        virtual void update() override;
        //        virtual void update() override;
        virtual bool onEvent(const irr::SEvent& event) override;
        void hidElem();
        void dispElem();

    protected:
        IGUIEnvironment *_guiEnv;
        const wchar_t* _saveKey;
        std::wstring _tmp;
        bool _binding;
        std::unordered_map<s32, std::pair<char, KeySet>> _keyToBind;
        IGUITabControl *_playersTab;
        IGUITab *_p1Tab;
        IGUITab *_p2Tab;
        s32 _idButton;
        std::unordered_map<s32, IGUIButton *> _buttonSave;
        IGUIButton *_playButton;
        Musical _music;
        bool _first;
    private:
};

#endif /* !SETTINGS_HPP_ */
