/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** main
*/

#include "Indie.hpp"

int main ()
{
    Indie *prog = nullptr;
    try {
        prog = new Indie();
        prog->run();
        delete prog;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return (84);
    }
    return (0);
}


// #include <irrlicht.h>
// #include "IrrWindow.hpp"
// #include "CamManager.hpp"
// #include "Player.hpp"
// #include <iostream>
// #include <memory>
// #include "Map.hpp"
// using namespace irr;
// using namespace core;
// using namespace scene;
// using namespace video;
// using namespace io;
// using namespace gui;

// int main ()
// {
//     IrrWindow window;
//     MyEventRecever mv(window.getgui(), window.getscean());
//     MapManager ok(window.getscean()->getScenManger(), "../map.txt", window.getDriver());
//     window.setEventRecever(&mv);
//     window.getscean()->getScenManger()->addCameraSceneNodeMaya();
//     ISceneManager* smgr = window.getscean()->getScenManger();
//     std::shared_ptr<Player> player = std::make_shared<Player>(smgr, window.getDevice(), &ok);
//     window.getscean()->addObj(player);
//     window.getscean()->addEventHandeler(player);

//     window.drawGame();