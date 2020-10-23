/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** endGame
*/

#ifndef END_GAME_HPP_
#define END_GAME_HPP_

#include "GamePart.hpp"

class EndGame : public GamePart {
	public:
		EndGame(ICameraSceneNode* cam, Indie::STATE& indieState, ISceneManager* smgr, IVideoDriver* driver, IrrlichtDevice* device, std::shared_ptr<GameSettings> settings,
			Indie::STATE curentState = Indie::END, vector3df pos = vector3df(2910.0F, 3050.0F, 2990.0F), vector3df tagret = vector3df(3000.0F, 3000.0F, 2990.0F));
		~EndGame();
		virtual void update() override;
		virtual bool onEvent(const irr::SEvent& event) override;

	private:
		Musical _music;


};
#endif /* !END_GAME_HPP_ */
