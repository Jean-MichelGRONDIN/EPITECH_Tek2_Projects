/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

#include <string>
#include <iostream>
#include "Destination.hpp"

namespace WarpSystem
{
    class QuantumReactor;
    class Core;
}

namespace Federation
{
    namespace Starfleet
    {
        class Ensign ;
        class Ship;
    }
    class Ship;
}

namespace Borg
{
    class Ship {
            public:
                Ship(int weaponFrequency = 20, short repair = 3);
                ~Ship();
                void setupCore(WarpSystem::Core *core);
                void checkCore();
                bool move(int warp = 0, Destination d = UNICOMPLEX);
                int getShield();
                void setShield(int shield);
                int getWeaponFrequency();
                void setWeaponFrequency(int frequency);
                short getRepair();
                void setRepair(short repair);
                void fire(Federation::Starfleet::Ship *target);
                void fire(Federation::Ship *target);
                void repair();

            private:
                int _side;
                short _maxWarp;
                WarpSystem::Core *_core;
                Destination _location;
                Destination _home;
                int _shield;
                int _weaponFrequency;
                short _repair;
    };
}

#endif