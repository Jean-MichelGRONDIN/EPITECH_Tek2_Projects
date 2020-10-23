/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <string>
#include <iostream>
#include "Destination.hpp"

namespace WarpSystem
{
    class QuantumReactor;
    class Core;
}

namespace Borg
{
    class Ship;
}

namespace Federation
{
    namespace Starfleet
    {
        class Ensign {
            public:
                Ensign(std::string name);
                ~Ensign();
            private:
            std::string _name;
        };
        class Captain {
            public:
                Captain(std::string name);
                ~Captain();
                std::string getName();
                int getAge();
                void setAge(int age);
            private:
                std::string _name;
                int _age;
        };
        class Ship {
            public:
                Ship(int length = 0, int width = 0, std::string name = "toto",
                    short maxWarp = 0, int torpedo = 0);
                ~Ship();
                void setupCore(WarpSystem::Core *core);
                void checkCore();
                void promote(Captain *captain);
                bool move(int warp = 0, Destination d = EARTH);
                int getShield();
                void setShield(int shield);
                int getTorpedo();
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *target);
                void fire(int torpedoes, Borg::Ship *target);

            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core;
                Captain *_captain;
                Destination _location;
                Destination _home;
                int _shield;
                int _photonTorpedo;
        };
    }
    class Ship {
            public:
                Ship(int length, int width, std::string name);
                ~Ship();
                void setupCore(WarpSystem::Core *core);
                void checkCore();
                bool move(int warp = 0, Destination d = VULCAN);
                WarpSystem::Core *getCore();

            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core;
                Destination _location;
                Destination _home;
        };
}

#endif