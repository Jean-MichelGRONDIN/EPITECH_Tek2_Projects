/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Game
*/

#include "Game.hpp"

Game::Game(ICameraSceneNode *cam, Indie::STATE &indieState, ISceneManager *smgr, IVideoDriver *driver, IrrlichtDevice *device, std::shared_ptr<GameSettings> settings,
            Indie::STATE curentState, vector3df pos, vector3df rot) : GamePart(cam, indieState, settings, curentState, pos, rot)
{
    _smgr = smgr;       
    _driver = driver;
    _device = device;
    _map = std::make_shared<MapManager>(_smgr, MAP_PATH, _driver, _device, _settings->getNbPlayer());

    _players.push_back(_map->getPlayer('1'));
    _players.back()->setPlayer(_settings->getKeyForP('1'));
    _players.push_back(_map->getPlayer('2'));
    if (_settings->getNbPlayer() == 2)
        _players.back()->setPlayer(_settings->getKeyForP('2'));
    _players.push_back(_map->getPlayer('3'));
    _players.push_back(_map->getPlayer('4'));
    for (auto tmp: _players)
        _alivePlayers.push_back(tmp);
    _settingsB = smgr->getGUIEnvironment()->addButton(recti(10, 10, 10 + 100, 10 + 25), 0, newId(), L"Settings", L"Go to settings");
    _settingsB->setVisible(false);
    _firstCome = true;
    _musicGame = std::make_shared<Musical>(GAME_MUSIC, true);
    _musicGame->initMusic();
    _updatePlayer = true;
    //_1 = smgr->getGUIEnvironment()->addButton(recti(10, 10, 40, 50), 0, 1, L"x+");
     //_2 = smgr->getGUIEnvironment()->addButton(recti(40, 10, 80, 50), 0, 2, L"y+");
     //_3 = smgr->getGUIEnvironment()->addButton(recti(80, 10, 120, 50), 0, 3, L"z+");
     //_4 = smgr->getGUIEnvironment()->addButton(recti(120, 10, 160, 50), 0, 4, L"x-");
     //_5 = smgr->getGUIEnvironment()->addButton(recti(160, 10, 200, 50), 0, 5, L"y-");
     //_6 = smgr->getGUIEnvironment()->addButton(recti(200, 10, 240, 50), 0, 6, L"z-");
     //_11 = smgr->getGUIEnvironment()->addButton(recti(10, 60, 40, 110), 0, 7, L"x+");
     //_21 = smgr->getGUIEnvironment()->addButton(recti(40, 60, 80, 110), 0, 8, L"y+");
     //_31 = smgr->getGUIEnvironment()->addButton(recti(80, 60, 120, 110), 0, 9, L"z+");
     //_41 = smgr->getGUIEnvironment()->addButton(recti(120, 60, 160, 110), 0, 10, L"x-");
     //_51 = smgr->getGUIEnvironment()->addButton(recti(160, 60, 200, 110), 0, 11, L"y-");
     //_61 = smgr->getGUIEnvironment()->addButton(recti(200, 60, 240, 110), 0, 12, L"z-");

}

Game::~Game()
{
}

void Game::endGame()
{
    for (auto player : _players)
        player->hide();
    _indieState = Indie::END;
    _settingsB->setVisible(false);
    _alivePlayers.front()->getHited();
    _musicGame->stopMusic();
    _firstCome = true;
}

void Game::updatePlayer()
{
    int idx = 0;
    for (auto tmp : _players) {
        tmp->setTexture(_settings->getTexForP(idx));
        idx++;
    }
    if (_settings->getNbPlayer() == 2) {
        for (auto pl : _players) {
            if (pl->getSym() == '2') {
                pl->setPlayer(_settings->getKeyForP('2'));
                pl->incP();
            }
        }
    }
    _updatePlayer = false;
}

bool Game::checkAlive()
{
    bool restart = false;
    for (auto tmp : _alivePlayers) {
        if (!tmp->isAlive()) {
            _alivePlayers.remove(tmp);
            restart = true;
            break;
        }
    }
    if (_alivePlayers.size() <= 1) {
        endGame();
        return false;
    }
    if (restart)
        return (checkAlive());
    return (true);
}


void Game::update()
{
    GamePart::update();
    if (!isActive())
        return;
    else if (_firstCome) {
        if (_updatePlayer)
            updatePlayer();
        for (auto player : _players)
            player->disp();
        _musicGame->playMusic();
        _settingsB->setVisible(true);
        _firstCome = false;
    }
    if (!checkAlive())
        return;
    for (auto player : _players)
        player->update();
}

bool Game::onEvent(const irr::SEvent& event)
{
    if (!isActive())
        return (false);
    if (!event.EventType == irr::EET_GUI_EVENT) {
        for (auto player : _players)
            player->onEvent(event);
    } else if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
        if (event.GUIEvent.Caller->getID() == _settingsB->getID()) {
            _settingsB->setVisible(false);
            for (auto player : _players)
                player->hide();
            _settings->setPreveState(Indie::GAME);
            _indieState = Indie::SETTINGS;
            _musicGame->pauseMusic();
            _firstCome = true;
            return (true);
        }
    }
 //    if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
 //    s32 id = event.GUIEvent.Caller->getID();
 //    vector3df tmp = _cam->getPosition();
 //    vector3df tmp2 = _cam->getTarget();

 //    if (id == 1)
 //        tmp.X  += INC_CAM;
 //    if (id == 2)
 //        tmp.Y  += INC_CAM;
 //    if (id == 3)
 //        tmp.Z  += INC_CAM;
 //    if (id == 4)
 //        tmp.X  -= INC_CAM;
 //    if (id == 5)
 //        tmp.Y  -= INC_CAM;
 //    if (id == 6)
 //        tmp.Z  -= INC_CAM;
 //    if (id == 7)
 //        tmp2.X  += INC_CAM;
 //    if (id == 8)
 //        tmp2.Y  += INC_CAM;
 //    if (id == 9)
 //        tmp2.Z  += INC_CAM;
 //    if (id == 10)
 //        tmp2.X  -= INC_CAM;
 //    if (id == 11)
 //        tmp2.Y  -= INC_CAM;
 //    if (id == 12)
 //        tmp2.Z  -= INC_CAM;

 //    _cam->setPosition(tmp);
 //    _cam->setTarget(tmp2);
 ////    80.000000 166.000000 25.000000 | 80.000000 -50.000000 100.000000
 //    printf ("%f %f %f | %f %f %f \n", tmp.X, tmp.Y, tmp.Z, tmp2.X, tmp2.Y, tmp2.Z);
 //    }
    return (false);
}
// void Game::loadAll()
// {
//     _ret = GAME;

//     _map = new MapManager(_window.getscean()->getScenManger(), MAP_PATH, _window.getDriver(), _window.getDevice());///
//     _window.getscean()->getScenManger()->addCameraSceneNodeMaya();
//     _smgr = _window.getscean()->getScenManger();///
// //    _player = std::make_shared<Player>(_smgr, _window.getDevice(), _map);///
//     _window.getscean()->addObj(_map->getPlayer('1'));
//     _window.getscean()->addEventHandeler(_map->getPlayer('1'));
//     _window.getscean()->addObj(_map->getPlayer('2'));
//     _window.getscean()->addEventHandeler(_map->getPlayer('2'));

//     // _window.drawGame();


//     // this->_window.getscean()->getScenManger()->addCameraSceneNodeMaya();
//     // ISceneManager* smgr = this->_window.getscean()->getScenManger();
//     // std::shared_ptr<Player> player = std::make_shared<Player>(smgr, this->_window.getDevice());
//     // this->_window.getscean()->addObj(player);
//     // this->_window.getscean()->addEventHandeler(player);
//     // IMeshSceneNode* mesh = smgr->addCubeSceneNode();

//     // if (mesh)
//     // {
//     //     smgr->getMeshManipulator()->makePlanarTextureMapping(
//     //             mesh->getMesh(), 0.003f);
//     //     mesh->setMaterialFlag(EMF_LIGHTING, false);
//     //     mesh->setMaterialTexture( 0, this->_window.getDriver()->getTexture("../assets/sydney.bmp") );
//     // }
// }

// void Game::releaseAll()
// {
// }

// int Game::getRet()
// {
//     return (_ret);
// }

// int &Game::getRetRef()
// {
//     return (_ret);
// }
