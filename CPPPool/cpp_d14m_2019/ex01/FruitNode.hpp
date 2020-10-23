/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** FruitNode
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

#include "Fruit.hpp"

typedef struct FruitNode_s
{
    Fruit *fruit;
    struct FruitNode_s *next;
} FruitNode;


#endif