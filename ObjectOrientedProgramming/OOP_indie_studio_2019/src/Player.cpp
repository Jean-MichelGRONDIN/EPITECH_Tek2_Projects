/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** main
*/

#include "Player.hpp"
#include "paths.hpp"

Player::Player(scene::ISceneManager* smgr, IrrlichtDevice* device, MapManager *mapManager, char sym, std::shared_ptr<irr::s32> pos, std::shared_ptr<irr::s32> pa) : MapElement(mapManager, sym)
{
    _node = smgr->addAnimatedMeshSceneNode(smgr->getMesh(PLAYER_ASSETS));
	if (_node)
	{
        _node->setFrameLoop(6, 6);
		_node->setAnimationSpeed(0);
		_node->setScale(core::vector3df(8.f,8.f,8.f));
		_node->setRotation(core::vector3df(0,-90,0));
        _node->setPosition(_map->getPosPlayer(_sym));
		_node->setMaterialFlag(video::EMF_LIGHTING, false);
        _current_row = (_node->getPosition().X + 4.2) / CUBE_SIZE;
        _current_column = (_node->getPosition().Z + 4.2) / CUBE_SIZE;
	}
    _animCol = smgr->createCollisionResponseAnimator(
    _map->getSelector(sym), _node, core::vector3df(2,0.1,2),
            core::vector3df(0,-10,0), core::vector3df(0,0,0));
    _node->addAnimator(_animCol);
    then = device->getTimer()->getTime();
    for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
		_keyIsDown[i] = false;
    _device = device;
    step = 0;
    _solide = true;
    _rangeBombe = std::make_shared<irr::s32>(2);
    _bombs.push_front(std::make_shared<Bombe>(_map, 300, 300, smgr, smgr->getVideoDriver(), _rangeBombe));
    _bombs.push_front(std::make_shared<Bombe>(_map, 300, 300, smgr, smgr->getVideoDriver(), _rangeBombe));
    _bombs.push_front(std::make_shared<Bombe>(_map, 300, 300, smgr, smgr->getVideoDriver(), _rangeBombe));
    _placing = false;
    _solide = false;
    _is_player = false;
    _newPos = false;
    _newAction = true;
    _alive = true;
    _moveSpeed = std::make_shared<irr::f32>(0.5F);
    _pos = pos;
    _pa = pa;
    _smgr = smgr;
    if (_sym == '1') {
        _dsipB.push_back(smgr->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(100, 50, 100 + 50, 50 + 50)));
        _dsipB.push_back(smgr->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(155, 50, 155 + 50, 50 + 50)));
        _dsipB.push_back(smgr->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(210, 50, 210 + 50, 50 + 50)));
        _dsipB.push_back(smgr->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(265, 50, 265 + 50, 50 + 50)));
        _dsipB.push_back(smgr->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(320, 50, 320 + 100, 50 + 100)));
    }
    if (_sym == '2') {
        _dsipB.push_back(smgr->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(1100 + 200, 50, 1100 + 50 + 200, 50 + 50)));
        _dsipB.push_back(smgr->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(1155 + 200, 50, 1155 + 50 + 200, 50 + 50)));
        _dsipB.push_back(smgr->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(1210 + 200, 50, 1210 + 50 + 200, 50 + 50)));
        _dsipB.push_back(smgr->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(1265 + 200, 50, 1265 + 50 + 200, 50 + 50)));
        _dsipB.push_back(smgr->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(1320 + 200, 50, 1320 + 50 + 200, 50 + 50)));
    }
    for (auto tmp : _dsipB) {
        tmp->setImage(smgr->getVideoDriver()->getTexture(BBB_T));
        tmp->setVisible(false);
    }
    _nbBombe = 3;
    _pathFinder = new pathFinder(_sym, _pa, _rangeBombe, _moveSpeed);
}

void Player::setPlayer(std::shared_ptr<std::unordered_map<KeySet, EKEY_CODE>> key)
{
    _is_player = true;
    _key = key;
    // delete _pathFinder;
    // _pathFinder = nullptr;
}

void Player::IncRangBombe()
{
    if (*_rangeBombe == 4)
        return;
    *_rangeBombe += 1;
}

void Player::DecRangBombe()
{
    if (*_rangeBombe == 1)
        return;
    *_rangeBombe -= 1;
}

void Player::addBombe()
{
    if (_nbBombe == 5)
        return;
    _bombs.push_front(std::make_shared<Bombe>(_map, 300, 300, _smgr, _smgr->getVideoDriver(), _rangeBombe));
    _nbBombe += 1;
    if (!_is_player)
        return;
    int inc = 0;
    for (auto tmp : _dsipB) {
        if (inc < _nbBombe)
            tmp->setVisible(true);
        else
            tmp->setVisible(false);
        inc++;
    }
}

void Player::removeBombe()
{
    if (_nbBombe == 1)
        return;
    _nbBombe--;
    if (!_is_player)
        return;
    int inc = 0;
    for (auto tmp : _dsipB) {
        if (inc < _nbBombe)
            tmp->setVisible(true);
        else
            tmp->setVisible(false);
        inc++;
    }
}

void Player::getHited()
{
    if (_is_player)
        *_pa -= 1;
    *_pos -= 1;
    switch (*_pos) {
        case 1:
            _node->setPosition(irr::core::vector3df(3000.0F, 3010.0F, 3000.0F));
            break;
        case 2:
            _node->setPosition(irr::core::vector3df(3005.0F, 3010, 3000.0F + CUBE_SIZE));
            break;
        case 3:
            _node->setPosition(irr::core::vector3df(3010.0F, 3010, 3000.0F - CUBE_SIZE));
            break;
        case 4:
            _node->setPosition(irr::core::vector3df(3015.0F, 3010, 3000.0F - 2 * CUBE_SIZE));
            break;
    }
    _map->updatePlayerPos(_sym, _node->getPosition(), _current_row, _current_column);
    _alive = false;
    _node->removeAnimator(_animCol);
    step = 0;
    _node->setFrameLoop(10, 10);
    _node->setAnimationSpeed(0);
    _node->setRotation(core::vector3df(0, 90, 0));
}

bool Player::isAlive()
{
    return _alive;
}


void Player::setMoveSpeed(f32 speed)
{
    if (*_moveSpeed + speed > 1.0F || *_moveSpeed + speed < 0.0F)
        return;
    *_moveSpeed += speed;
}

void Player::incP()
{
    *_pa += 1;
}

void Player::move()
{
    const u32 now = _device->getTimer()->getTime();
	then = now;
    if (IsKeyDown((*_key.get())[KeySet::BOMBE]) && _placing == false)
        placeBombe();
    if (IsKeyDown((*_key.get())[KeySet::RIGHT]) && moveRight(_frameDeltaTime)  == 1)
        return;
    if (IsKeyDown((*_key.get())[KeySet::UP]) && moveUp(_frameDeltaTime) == 1)
        return;
    if (IsKeyDown((*_key.get())[KeySet::DOWN]) && moveDown(_frameDeltaTime) == 1)
        return;
    if (IsKeyDown((*_key.get())[KeySet::LEFT]) && moveLeft(_frameDeltaTime) == 1)
        return;
    step = 0;
    _node->setFrameLoop(10, 10);
	_node->setAnimationSpeed(0);
}

int Player::placeBombe()
{
    _placing = true;
    int inc = 0;
    for (auto b : _bombs) {
        if (_nbBombe == inc)
            break;
        if (!b->isActive()) {
            _map->placeBomb(_sym, b);
            _newPos = true;
            _newAction = true;
            return 1;
        }
        inc++;
    }
    return 0;
}

int Player::moveDown(const f32 frameDeltaTime)
{
    core::vector3df nodePosition = _node->getPosition();
        nodePosition.X += *_moveSpeed;
        _node->setRotation(core::vector3df(0, -90, 0));
        _node->setPosition(nodePosition);
        if ((_current_row * CUBE_SIZE > nodePosition.X + 4.2 || _current_row * CUBE_SIZE + CUBE_SIZE < nodePosition.X + 4.2) ||
            (_current_column * CUBE_SIZE > nodePosition.Z + 4.2 || _current_column * CUBE_SIZE + CUBE_SIZE < nodePosition.Z + 4.2)) {
            _map->updatePlayerPos(_sym, nodePosition, _current_row, _current_column);
            _newPos = true;
        }
        if (_newPos) {
            if (_current_row * CUBE_SIZE + 5 < nodePosition.X + 4.2)
                _newAction = true;
        }
        if (step == 0) {
            _node->setAnimationSpeed(50);
            _node->setFrameLoop(0, 13);
            step = 1;
        }
        return 1;
}

int Player::moveUp(const f32 frameDeltaTime)
{
    core::vector3df nodePosition = _node->getPosition();
    nodePosition.X -= *_moveSpeed;
    _node->setRotation(core::vector3df(0, 90, 0));
    _node->setPosition(nodePosition);
    if ((_current_row * CUBE_SIZE > nodePosition.X + 4.2 || _current_row * CUBE_SIZE + CUBE_SIZE < nodePosition.X + 4.2) ||
        (_current_column * CUBE_SIZE > nodePosition.Z + 4.2 || _current_column * CUBE_SIZE + CUBE_SIZE < nodePosition.Z + 4.2)) {
        _map->updatePlayerPos(_sym, nodePosition, _current_row, _current_column);
        _newPos = true;
    }
    if (_newPos) {
        if (_current_row * CUBE_SIZE + CUBE_SIZE - 5 > nodePosition.X + 4.2) {
            _newAction = true;
        }
    }
    if (step == 0) {
        _node->setAnimationSpeed(50);
        _node->setFrameLoop(0, 13);
        step = 1;
    }
    return 1;
}

void Player::setTexture(std::string str)
{
    _node->setMaterialTexture(0, _map->getDriver()->getTexture(str.c_str()));
}

int Player::moveRight(const f32 frameDeltaTime)
{
    core::vector3df nodePosition = _node->getPosition();
    nodePosition.Z += *_moveSpeed;
    _node->setRotation(core::vector3df(0, 180, 0));
    _node->setPosition(nodePosition);
    if ((_current_row * CUBE_SIZE > nodePosition.X + 4.2 || _current_row * CUBE_SIZE + CUBE_SIZE < nodePosition.X + 4.2) ||
        (_current_column * CUBE_SIZE > nodePosition.Z + 4.2 || _current_column * CUBE_SIZE + CUBE_SIZE < nodePosition.Z + 4.2)) {
        _map->updatePlayerPos(_sym, nodePosition, _current_row, _current_column);
        _newPos = true;
    }
    if (_newPos) {
        if (_current_column * CUBE_SIZE + 5 < nodePosition.Z + 4.2)
            _newAction = true;
    }
    if (step == 0) {
        _node->setFrameLoop(0, 13);
        _node->setAnimationSpeed(50);
        step = 1;
    }
    return 1;
}

int Player::moveLeft(const f32 frameDeltaTime)
{
    core::vector3df nodePosition = _node->getPosition();
    nodePosition.Z -= *_moveSpeed;
        _node->setRotation(core::vector3df(0,0,0));
        _node->setPosition(nodePosition);
        if ((_current_row * CUBE_SIZE > nodePosition.X + 4.2 ||_current_row * CUBE_SIZE + CUBE_SIZE < nodePosition.X + 4.2) || 
        (_current_column * CUBE_SIZE > nodePosition.Z + 4.2 ||_current_column * CUBE_SIZE + CUBE_SIZE < nodePosition.Z + 4.2)) {
            _map->updatePlayerPos(_sym, nodePosition, _current_row, _current_column);
            _newPos = true;
        }
        if (_newPos) {
            if ( _current_column * CUBE_SIZE + CUBE_SIZE - 5 > nodePosition.Z + 4.2)
                _newAction = true;
        }
        if (step == 0) {
            _node->setAnimationSpeed(50);
            _node->setFrameLoop(0, 13);
            step = 1;
        }
        return 1;
}

scene::IAnimatedMeshSceneNode *Player::getNode()
{
    return _node;
}

bool Player::IsKeyDown(EKEY_CODE keyCode) const
{
	return _keyIsDown[keyCode];
}

bool Player::onEvent(const SEvent& event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
		_keyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
        if (_is_player && !IsKeyDown((*_key.get())[KeySet::BOMBE]))
            _placing = false;
    }
	return false;
}

void Player::disp()
{
    if (!_is_player)
        return;
    int inc = 0;
    for (auto tmp : _dsipB) {
        if (inc < _nbBombe)
            tmp->setVisible(true);
        else
            tmp->setVisible(false);
        inc++;
    }
}

void Player::hide()
{

    if (!_is_player)
        return;
    for (auto tmp : _dsipB) {
        tmp->setVisible(false);
    }
}

void Player::update()
{
    if (_alive) {
        irr::u32 now = _device->getTimer()->getTime();
        if ( now - then > 20) {
            if (_is_player)
                move();
            else
                moveBot();
            then = now;
        }
    }
    for (auto tmp : _bombs) {
        tmp->update();
    }
}

void Player::moveBot()
{
    if (_newAction) {
        _action = _pathFinder->getPath(_map->getPlayersPos(), _map->getMapObs(), _map->getMapSize());
        step = 0;
        _node->setFrameLoop(10, 10);
        _node->setAnimationSpeed(0);
        // if (_listK.size() <= 0)
        //     return;
        // _action = _listK.back();
        // _listK.pop_back();
        // std::cout << "En dehors du bot action: " << _action << std::endl;
        // std::cout << "En dehors du bot up: " << KeySet::UP << std::endl;
        // std::cout << "En dehors du bot up: " << UP << std::endl;
        if (_action == KeySet::NOTHING) {
            return;
        }
        _newAction = false;
        _newPos = false;
    }
    switch (_action)
    {
    case KeySet::UP:
        moveUp(_frameDeltaTime);
        break;
    case KeySet::DOWN:
        moveDown(_frameDeltaTime);
        break;
    case KeySet::RIGHT:
        moveRight(_frameDeltaTime);
        break;
    case KeySet::LEFT:
        moveLeft(_frameDeltaTime);
        break;
    case KeySet::BOMBE:
        placeBombe();
        break;
    default:
        break;
    }

}