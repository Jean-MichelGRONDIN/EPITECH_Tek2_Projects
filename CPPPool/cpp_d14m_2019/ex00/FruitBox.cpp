/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size)
{
    this->_size = size;
    this->list = nullptr;
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits()
{
    int i = 0;
    FruitNode *tmp = this->list;

    while (tmp != nullptr) {
        i++;
        tmp =tmp->next;
    }
    return (i);
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *new_s = new FruitNode;
    FruitNode *tmp = this->list;

    if (this->nbFruits() == this->_size || this->isAlreadyIn(f) == true)
        return (false);
    new_s->fruit = f;
    new_s->next = nullptr;
    if (tmp == nullptr) {
        this->list = new_s;
    } else {
        while (tmp->next != nullptr) {
            tmp =tmp->next;
        }
        tmp->next = new_s;
    }
    return (true);
}

Fruit *FruitBox::pickFruit()
{
    FruitNode *tmp = this->list;
    Fruit *tmp_f = nullptr;

    if (this->list != nullptr) {
        this->list = this->list->next;
        tmp_f = tmp->fruit;
        tmp->fruit = NULL;
        delete tmp;
        return (tmp_f);
    } else {
        return (nullptr);
    }
}

FruitNode *FruitBox::head()
{
    return (this->list);
}

bool FruitBox::isAlreadyIn(Fruit *f)
{
    FruitNode *tmp = this->list;

    while (tmp != nullptr) {
        if (tmp->fruit == f) {
            return (true);
        }
        tmp = tmp->next;
    }
    return (false);
}