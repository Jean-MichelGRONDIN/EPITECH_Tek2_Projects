/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "FruitNode.hpp"
#include "Fruit.hpp"
#include "Lemon.hpp"
#include "Lime.hpp"
#include "Banana.hpp"

class FruitBox {
	public:
		explicit FruitBox(int size);
		~FruitBox();
        int nbFruits() const;
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head();

	protected:
	private:
        bool isAlreadyIn(Fruit *f);
        FruitNode *list;
        int _size;
};

#endif