/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Ressoureces
*/

#ifndef RESSOURECES_HPP_
#define RESSOURECES_HPP_

#include "../includeSFML.hpp"
#include "../Characters/Player.hpp"

class Ressoureces {
		public:
		Ressoureces(sf::Vector2f pos, const std::string &texture = "Assets/Rock.png");
		virtual ~Ressoureces();
        virtual void animeRess();
        void animeRessDestroy();
        virtual void growRess();
        sf::Sprite getRessTodraw();
        virtual void _is_cliked(sf::Vector2f, Player *);
        static bool is_player_there(sf::Sprite Ress, sf::Sprite player);
        sf::Vector2f getPos() const;


	protected:
        int _giveRess;
        int _currentHp;
        int _HP;
        sf::Vector2f _pos;
        bool _isBreakable;
        bool _isAnimating;
        bool _isDrawable;
        bool _isGrowing;
        bool _isGiven;
        sf::Clock _clockAnime;
        sf::Time  _timeAnime;
        sf::Clock _clockRepop;
        sf::Time  _timeRepop;
        sf::Sprite _RessCurrent;
        sf::Texture _RessTextureCurrent;
        sf::Sprite _Ress;
        sf::Texture _RessTexture;
	private:
};

#endif /* !RESSOURECES_HPP_ */
