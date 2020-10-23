/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Particle
*/

#include "Particle.hpp"

Particle::Particle(irr::scene::ISceneManager *sceanManger, irr::video::IVideoDriver *driver)
{
    _ps = sceanManger->addParticleSystemSceneNode(false);
    _em = _ps->createBoxEmitter(
        core::aabbox3d<f32>(-7,0,-7,7,1,7), // emitter size
        core::vector3df(0.0f,0.06f,0.0f),   // initial direction
        80,
        800,                             // emit rate
        video::SColor(0,255,255,255),       // darkest color
        video::SColor(0,255,255,255),       // brightest color
        80,200,0,                         // min and max age, angle
        core::dimension2df(10.f,10.f),         // min size
        core::dimension2df(20.f,20.f));        // max size

    scene::IParticleAffector* paf = _ps->createFadeOutParticleAffector();

    _ps->addAffector(paf); // same goes for the affector
    paf->drop();
    _ps->setScale(core::vector3df(0.12, 0.12, 0.12));
    _ps->setMaterialFlag(video::EMF_LIGHTING, false);
    _ps->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
    _ps->setMaterialTexture(0, driver->getTexture(PARTICLE));
    _ps->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
}

Particle::~Particle()
{
}

void Particle::stop()
{
    _ps->setEmitter(0);
}

void Particle::active(std::uint64_t row, std::uint64_t column)
{
    _ps->setPosition(core::vector3df(row,0,column));
    _ps->setEmitter(_em);
}
