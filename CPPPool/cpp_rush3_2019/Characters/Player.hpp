/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#define MAX_WOOD 100
#define MAX_ROCK 100
#define MAX_IRON 100

#include "../Objects/Object.hpp"
#include "Character.hpp"
#include "../includeSFML.hpp"
#include "../Map/Map.hpp"
// #include "../City/City.hpp"
class Tree;

class Ressoureces;

class Player : public Character {
    public:
        Player(const std::string &name, sf::VertexArray map);
        ~Player();

        /* GETTERS */
        int getLevel() const;
        int getWood() const;
        int getRock() const;
        int getIron() const;
        Object *getObject() const;

        /* SETTERS */
        void setLevel(int level);
        void setWood(int level);
        void setRock(int rock);
        void setIron(int iron);
        void setObject(Object *object);
        void moveUp(std::vector<Tree *> tree, std::vector<Ressoureces *> rock);
        void moveDown(std::vector<Tree *> tree, std::vector<Ressoureces *> rock);
        void moveLeft(std::vector<Tree *> tree, std::vector<Ressoureces *> rock);
        void moveRight(std::vector<Tree *> tree, std::vector<Ressoureces *> rock);
        void move(std::vector<Tree *> tree, std::vector<Ressoureces *> rock);
        int getPosTexture(int x, int y);
        bool isAdded;

    protected:
    private:
        int _level;
        int _wood;
        int _rock;
        int _iron;
        Object *_object;
        int dir;
        int idx_rec;
        sf::VertexArray map_c;
};

#endif /* !PLAYER_HPP_ */
