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

static int get_double_coconut_size(Coconut const * const *coconuts)
{
    int i = 0;

    while (coconuts[i] != nullptr) {
        i++;
    }
    return (i);
}

FruitBox * const *LittleHand::organizeCoconut(Coconut const * const *coconuts)
{
    int nb_coco = get_double_coconut_size(coconuts);
    int tab_size = nb_coco % 6 == 0 ? nb_coco / 6 : nb_coco / 6 + 1;
    FruitBox **tab = new FruitBox*[tab_size + 1];
    int i = 0;
    int i_coco = 0;
    const Fruit *tmp_f;

    while (i != tab_size) {
        tab[i] = new FruitBox(6);
        while (i_coco != tab_size * 6 && i_coco != nb_coco) {
            tmp_f = coconuts[i_coco];
            tab[i]->putFruit(const_cast<Fruit *>(tmp_f));
            i_coco++;
        }
        i++;
    }
    tab[tab_size] = NULL;
    return (tab);
}