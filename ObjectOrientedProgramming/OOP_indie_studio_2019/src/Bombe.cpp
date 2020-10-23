/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Bombe
*/

#include "Bombe.hpp"

Bombe::Bombe(MapManager *map, std::uint64_t row, std::uint64_t column, irr::scene::ISceneManager *sceanManger, irr::video::IVideoDriver *driver, std::shared_ptr<s32> range)
: MapElement(map, 'X', row, column)
{
    _pos = irr::core::vector3df(row * CUBE_SIZE, 0, column * CUBE_SIZE);
    _bombe = sceanManger->addSphereSceneNode(3.0F,16, 0, -1, _pos);
    _driver = driver;
    _bombe->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _bombe->setMaterialTexture(0, driver->getTexture(BOMBE_TEXTURE));
    _placed = false;
    _actived = false;
    _posBomb = std::make_shared<Musical>(BOMBE_SOUND_POS, false);
    _posBomb->initMusic();
    _explosion = std::make_shared<Musical>(BOMBE_SOUND_EXP, false);
    _explosion->initMusic();
    for (int i = 0; i != 17; i++)
        _particls.push_back(std::make_shared<Particle>(sceanManger, driver));
    _range = range;
}

Bombe::~Bombe()
{
}

void Bombe::getHited()
{
    if (_placed == true)
        explos();
    _bombe->setVisible(false);
}

void Bombe::bombPlaced(std::uint64_t row, std::uint64_t column)
{
    _posBomb->playMusic();
    _actived = true;
    _pos = irr::core::vector3df(row * CUBE_SIZE + 0.5, 0, column * CUBE_SIZE + 0.5);
    _current_column = column;
    _current_row = row;
    _bombe->setPosition(_pos);
    _placed = true;
    _bombe->setVisible(true);
    _clock.restart();
}

bool Bombe::canDestroy()
{

    return false;
}

void Bombe::exploseTop()
{
    try {
        std::list<std::shared_ptr<IMapElem>> top = getTopElem();
        if (!_map->isAWall(top))
            _particls[1]->active(top.front()->getCurrentRow() * CUBE_SIZE, top.front()->getCurrentCol() * CUBE_SIZE);
        for (auto tmp : top)
            tmp->getHited();
            if (!_map->isAWall(top)) {
                for (s32 i = 1; i != *_range; i++) {
                    try {
                    top = top.front()->getTopElem();
                    if (_map->isAWall(top))
                        break;
                    _particls[i + 1]->active(top.front()->getCurrentRow() * CUBE_SIZE, top.front()->getCurrentCol() * CUBE_SIZE);
                    for (auto tmp : top)
                        tmp->getHited();
                }
                catch (const std::exception& e) {
                    break;
                }
            }
        }
    }
    catch(const std::exception& e) {
    }    

}
void Bombe::exploseBot()
{
    try {
        std::list<std::shared_ptr<IMapElem>> top = getBotomElem();
        if (!_map->isAWall(top))
            _particls[5]->active(top.front()->getCurrentRow() * CUBE_SIZE, top.front()->getCurrentCol() * CUBE_SIZE);
        for (auto tmp : top)
            tmp->getHited();
            if (!_map->isAWall(top)) {
                for (s32 i = 1; i != *_range; i++) {
                    try {
                    top = top.front()->getBotomElem();
                    if (_map->isAWall(top))
                        break;
                    _particls[i + 5]->active(top.front()->getCurrentRow() * CUBE_SIZE, top.front()->getCurrentCol() * CUBE_SIZE);
                    for (auto tmp : top)
                        tmp->getHited();
                }
                catch (const std::exception& e) {
                    break;
                }
            }
        }
    }
    catch (const std::exception& e) {
    }
}
void Bombe::exploseLeft()
{
    try {
        std::list<std::shared_ptr<IMapElem>> top = getleftElem();
        if (!_map->isAWall(top))
            _particls[9]->active(top.front()->getCurrentRow() * CUBE_SIZE, top.front()->getCurrentCol() * CUBE_SIZE);
        for (auto tmp : top)
            tmp->getHited();
        if (!_map->isAWall(top)) {
            for (s32 i = 1; i != *_range; i++) {
                try {
                    top = top.front()->getleftElem();
                    if (_map->isAWall(top))
                        break;
                    _particls[i + 9]->active(top.front()->getCurrentRow() * CUBE_SIZE, top.front()->getCurrentCol() * CUBE_SIZE);
                    for (auto tmp : top)
                        tmp->getHited();
                }
                catch (const std::exception& e) {
                    break;
                }
            }
        }
    }
    catch (const std::exception& e) {
    }
}
void Bombe::exploseRight()
{
    try {
        std::list<std::shared_ptr<IMapElem>> top = getRightElem();
        if (!_map->isAWall(top))
            _particls[13]->active(top.front()->getCurrentRow() * CUBE_SIZE, top.front()->getCurrentCol() * CUBE_SIZE);
        for (auto tmp : top)
            tmp->getHited();
        if (!_map->isAWall(top)) {
            for (s32 i = 1; i != *_range; i++) {
                try {
                    top = top.front()->getRightElem();
                    if (_map->isAWall(top))
                        break;
                    _particls[i + 13]->active(top.front()->getCurrentRow() * CUBE_SIZE, top.front()->getCurrentCol() * CUBE_SIZE);
                    for (auto tmp : top)
                        tmp->getHited();
                }
                catch (const std::exception& e) {
                    break;
                }
            }
        }
    }
    catch (const std::exception& e) {
    }
}

void Bombe::explos()
{
    _placed = false;
    exploseTop();
    exploseLeft();
    exploseBot();
    exploseRight();
    _explosion->playMusic();
    _particls[0]->active(_current_row * CUBE_SIZE, _current_column * CUBE_SIZE);
    _map->getMapObs()[_current_row][_current_column] = ' ';
    _clock.restart();
    try {
        for (auto tmp : getCurElem())
            tmp->getHited();
    } catch (const std::exception& e) {}
    _map->removeBombe(_current_row, _current_column);
}

char Bombe::getSymRange()
{
    return std::to_string (*_range)[0];
}

void Bombe::update()
{
    if (_placed)
        if (_clock.isGreterThan(1600) && _placed == true)
            explos();
    if (_actived && !_placed) {
        if (_clock.isGreterThan(800)) {
            _explosion->stopMusic();
            _posBomb->stopMusic();
            for (auto tmp : _particls)
                tmp->stop();
        }
        if (_clock.isGreterThan(1000))
            _actived = false;
    }
}

bool Bombe::isActive()
{
    return (_actived);
}