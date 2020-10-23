/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** LittleHand
*/

#include "LittleHand.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}

void  LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons,
    FruitBox &bananas, FruitBox &limes)
{
    FruitNode *tmp = unsorted.head();
    FruitBox *tempo_unsortable = new FruitBox(unsorted.nbFruits());

    while (tmp != NULL) {
        if (tmp->fruit->getName() == "lemon") {
            lemons.putFruit(unsorted.pickFruit());
        } else if (tmp->fruit->getName() == "banana") {
            bananas.putFruit(unsorted.pickFruit());
        } else if (tmp->fruit->getName() == "lime") {
            limes.putFruit(unsorted.pickFruit());
        } else {
            tempo_unsortable->putFruit(unsorted.pickFruit());
        }
        tmp = unsorted.head();
    }
    tmp = tempo_unsortable->head();
    while (tmp != NULL) {
        unsorted.putFruit(tempo_unsortable->pickFruit());
        tmp = tempo_unsortable->head();
    }
}