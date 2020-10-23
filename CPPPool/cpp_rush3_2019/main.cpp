/*
** EPITECH PROJECT, 2020
** map
** File description:
** main
*/

#include "Map/Map.hpp"
#include <iostream>
#include <fstream>
#include "Resseources/Tree.hpp"
#include "Loops/Game_loop.hpp"


int main (){
    srandom(time(NULL));
    game_loop();
    return 0;
}
