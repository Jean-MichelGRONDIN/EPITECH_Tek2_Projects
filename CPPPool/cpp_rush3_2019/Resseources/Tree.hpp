/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Tree
*/

#ifndef TREE_HPP_
#define TREE_HPP_
#include "../includeSFML.hpp"
// #include "../Characters/Player.hpp"
#include "Ressoureces.hpp"

class Tree:public Ressoureces{
	public:
		Tree(sf::Vector2f pos, const std::string &texture = "Assets/tree.png");
		~Tree();
                void animeRess() override;
                void growRess() override;
                void _is_cliked(sf::Vector2f mouse, Player *p) override;



	protected:
        sf::Sprite _treeB;
        sf::Texture _treeTextureB;
	private:
};

#endif /* !TREE_HPP_ */
