/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Particle
*/

#ifndef PARTICLE_HPP_
#define PARTICLE_HPP_

#include "MapElement.hpp"
#include "paths.hpp"
#include "MyClock.hpp"
#include "Music.hpp"
#include "path.h"

class Particle {
    public:
        Particle(irr::scene::ISceneManager *sceanManger, irr::video::IVideoDriver *driver);
        ~Particle();
        void stop();
        void active(std::uint64_t row, std::uint64_t column);
    private:
        scene::IParticleSystemSceneNode* _ps;
        scene::IParticleEmitter* _em;
};

#endif /* !PARTICLE_HPP_ */
