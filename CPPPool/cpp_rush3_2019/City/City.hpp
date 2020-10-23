/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** City
*/

#ifndef CITY_HPP_
#define CITY_HPP_

#include "../Map/Map.hpp"
#include "../Resseources/Ressoureces.hpp"
#include "../Resseources/Tree.hpp"
#include "../Buildings/Building.hpp"
#include "../Buildings/LittleBuilding.hpp"
#include "../Buildings/BigBuilding.hpp"
#include "../Buildings/MiddleBuilding.hpp"
#include "../Characters/Pnj.hpp"
#include "../Characters/Forgeron.hpp"
#include "../Characters/Bucheron.hpp"
#include "../Characters/Mineur.hpp"
#include <vector>
#include <iostream>
#include <fstream>

class City {
    public:
        City();
        ~City();
        TileMap getMap() const;
        std::vector<Tree *> getTrees() const;
        std::vector<Ressoureces *> getRocks() const;
        std::vector<Building *> getBuldings() const;
        Player *getPlayer() const;
        void manage(sf::RenderWindow *window);
        void cityGetCliked(sf::RenderWindow *window);
        void cityGetKeyCliked();

    protected:
        TileMap _map;
        TileMap _colision;
        std::vector<Tree *> _trees;
        std::vector<Ressoureces *> _rocks;
        std::vector<Building *> _buldings;
        Player *_player;
        ProgressBar *_woodBar;
        ProgressBar *_ironBar;
        ProgressBar *_rockBar;
        std::vector<Pnj *> _Pnjs;
        Forgeron *_forgeron;
        Bucheron *_bucheron;
        Mineur *_mineur;

    private:
        void read_and_init_all_buildings();
        void read_and_init_all_tree();
        void read_and_init_all_ressources();
};

#endif /* !CITY_HPP_ */
