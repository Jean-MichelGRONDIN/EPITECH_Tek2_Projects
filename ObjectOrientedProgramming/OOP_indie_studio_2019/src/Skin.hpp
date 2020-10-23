/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Skin
*/

#ifndef SKIN_HPP_
#define SKIN_HPP_

#include "GamePart.hpp"

class Skin : public GamePart {
	public:
		Skin(ICameraSceneNode* cam, Indie::STATE& indieState, ISceneManager* smgr, IVideoDriver* driver, IrrlichtDevice* device, std::shared_ptr<GameSettings> settings,
			Indie::STATE curentState = Indie::SKIN, vector3df pos = vector3df(2910.0F, 3050.0F, 2990.0F), vector3df tagret = vector3df(3000.0F, 3000.0F, 2990.0F));
		~Skin();
		virtual void update() override;
		virtual bool onEvent(const irr::SEvent& event) override;
        void hide();
        void display();
        int next_idx(int idx);
        int prev_idx(int idx);

	private:
        scene::IAnimatedMeshSceneNode *_node1;
        scene::IAnimatedMeshSceneNode *_node2;
        scene::IAnimatedMeshSceneNode *_node3;
        scene::IAnimatedMeshSceneNode *_node4;
        IGUIButton *_next;
        IGUIButton *_prev;
        int _current;
        IVideoDriver* _driver;
        std::vector<std::string> _skin;
        IGUIButton *_play;
        IGUIButton* _settingsB;
        bool _first;
        Musical _music;
        IGUIStaticText* _p1;
        IGUIStaticText* _p2;
};

#endif /* !SKIN_HPP_ */
