/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** main
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "ISceanObject.hpp"
#include "enums.hpp"
#include "IEventHandeler.hpp"
#include "MapElement.hpp"
#include "Bombe.hpp"
#include "Music.hpp"
#include <string>
#include <unordered_map>
#include "MyClock.hpp"
#include "pathFinder.hpp"
#include <vector>

using namespace irr;

class Player: public ISceanObject, public IEventHandeler, public MapElement
{
    public:
        Player(scene::ISceneManager* smgr, IrrlichtDevice* device, MapManager *map, char player, std::shared_ptr<irr::s32>, std::shared_ptr<irr::s32>);
        void move();
        void moveBot();
        void move_sec_player();
        void setTexture(std::string);
        int moveRight(const f32 frameDeltaTime);
        int moveLeft(const f32 frameDeltaTime);
        int moveUp(const f32 frameDeltaTime);
        int moveDown(const f32 frameDeltaTime);
        void addAction(KeySet);
        int placeBombe();
        scene::IAnimatedMeshSceneNode *getNode();
        void update() override;
        bool onEvent(const irr::SEvent& event) override;
        void disp();
        void hide();
        bool IsKeyDown(EKEY_CODE keyCode) const;
        void setPlayer(std::shared_ptr<std::unordered_map<KeySet, EKEY_CODE>> _key);
        void IncRangBombe();
        void DecRangBombe();
        void addBombe();
        void removeBombe();
        void getHited() override;
        bool isAlive();
        void setMoveSpeed(f32 speed);
        void incP();

    private:
        scene::ISceneManager* _smgr;
        scene::IAnimatedMeshSceneNode *_node;
        std::shared_ptr<irr::f32> _moveSpeed;
        scene::ISceneNodeAnimator* _animCol;
        u32 then;
        bool _keyIsDown[KEY_KEY_CODES_COUNT];
        IrrlichtDevice* _device;
        int step;
        std::list<std::shared_ptr<Bombe>> _bombs;
        bool _placing;
        bool _is_player;
        bool _newPos;
        std::shared_ptr<std::unordered_map<KeySet, EKEY_CODE>> _key;
        bool _newAction;
        KeySet _action;
        std::list<KeySet> _listK;
        pathFinder *_pathFinder;
        f32 _frameDeltaTime;
        bool _alive;
        std::shared_ptr<irr::s32> _pos;
        std::shared_ptr<irr::s32> _pa;
        std::shared_ptr<irr::s32> _rangeBombe;
        s32 _nbBombe;
        s32 _currentDisp;
        std::list< irr::gui::IGUIButton*> _dsipB;
};

#endif