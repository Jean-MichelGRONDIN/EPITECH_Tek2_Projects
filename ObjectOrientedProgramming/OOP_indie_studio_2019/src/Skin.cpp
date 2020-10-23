/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** Skin
*/

#include "Skin.hpp"

Skin::Skin(ICameraSceneNode* cam, Indie::STATE& indieState, ISceneManager* smgr, IVideoDriver* driver, IrrlichtDevice* device, std::shared_ptr<GameSettings> settings,
    Indie::STATE curentState, vector3df pos, vector3df rot) : GamePart(cam, indieState, settings, curentState, pos, rot), _music(MUSIC_MELEE, true)
{
    _music.initMusic();
    _p1 = smgr->getGUIEnvironment()->addStaticText(L"Player 1", recti(875 -15, 340, 875 + 80 - 15, 340 + 50));
    _p2 = smgr->getGUIEnvironment()->addStaticText(L"Player 2", recti(790 - 15, 330, 790 + 80 - 15, 330 + 50));
    _settingsB = smgr->getGUIEnvironment()->addButton(recti(10, 10, 10 + 100, 10 + 25), 0, newId(), L"Settings", L"Go to settings");
    _settingsB->setVisible(false);
    _node1 = smgr->addAnimatedMeshSceneNode(smgr->getMesh(PLAYER_ASSETS));
    _node1->setMaterialTexture(0, driver->getTexture(PINK_BOMBER));
    _node1->setFrameLoop(6, 6);
	_node1->setAnimationSpeed(0);
	_node1->setScale(core::vector3df(8.f,8.f,8.f));
	_node1->setRotation(core::vector3df(0,90,0));
    _node1->setPosition(irr::core::vector3df(3000.0F, 3010.0F, 3000.0F));


    _node2 = smgr->addAnimatedMeshSceneNode(smgr->getMesh(PLAYER_ASSETS));
    _node2->setMaterialTexture(0, driver->getTexture(BLACK_BOMBER));
    _node2->setFrameLoop(6, 6);
	_node2->setAnimationSpeed(0);
	_node2->setScale(core::vector3df(8.f,8.f,8.f));
	_node2->setRotation(core::vector3df(0,90,0));
    _node2->setPosition(irr::core::vector3df(3005.0F, 3010, 3000.0F + CUBE_SIZE));


    _node3 = smgr->addAnimatedMeshSceneNode(smgr->getMesh(PLAYER_ASSETS));
    _node3->setMaterialTexture(0, driver->getTexture(RED_BOMBER));
    _node3->setFrameLoop(6, 6);
	_node3->setAnimationSpeed(0);
	_node3->setScale(core::vector3df(8.f,8.f,8.f));
	_node3->setRotation(core::vector3df(0,90,0));
    _node3->setPosition(irr::core::vector3df(3010.0F, 3010, 3000.0F - CUBE_SIZE));


    _node4 = smgr->addAnimatedMeshSceneNode(smgr->getMesh(PLAYER_ASSETS));
    _node4->setMaterialTexture(0, driver->getTexture(BOMBER));
    _node4->setFrameLoop(6, 6);
	_node4->setAnimationSpeed(0);
	_node4->setScale(core::vector3df(8.f,8.f,8.f));
	_node4->setRotation(core::vector3df(0,90,0));
    _node4->setPosition(irr::core::vector3df(3015.0F, 3010, 3000.0F - 2 * CUBE_SIZE));

    _next = smgr->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(200,300,200 + 78, 300 + 56), 0, newId(), L"Next");
    _prev = smgr->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(200,400,200 + 78, 400 + 56), 0, newId(), L"Previous");
    _play = smgr->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(400,400,400 + 78, 400 + 56), 0, newId(), L"Play");
    _skin.push_back(PINK_BOMBER);
    _skin.push_back(BLACK_BOMBER);
    _skin.push_back(RED_BOMBER);
    _skin.push_back(BOMBER);
    _current = 0;
    _driver = driver;
    hide();
    _first = true;
}

Skin::~Skin()
{
}

void Skin::update()
{
    GamePart::update();
    if (!isActive())
        return;
    if (_first == true)
        display();
    _first = false;
}

bool Skin::onEvent(const irr::SEvent& event)
{
    if (!isActive())
        return (false);
    if (!event.EventType == irr::EET_GUI_EVENT)
        return (false);
    if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
        if (event.GUIEvent.Caller->getID() == _settingsB->getID()) {
            _settings->setPreveState(Indie::SKIN);
            _indieState = Indie::SETTINGS;
            hide();
            return (true);
        }
        if (event.GUIEvent.Caller->getID() == _next->getID()) {
            _current = next_idx(_current);
            int tmp = _current;
            _node1->setMaterialTexture(0, _driver->getTexture(_skin[tmp].c_str()));
            tmp = next_idx(tmp);
            _node2->setMaterialTexture(0, _driver->getTexture(_skin[tmp].c_str()));
            tmp = next_idx(tmp);
            _node3->setMaterialTexture(0, _driver->getTexture(_skin[tmp].c_str()));
            tmp = next_idx(tmp);
            _node4->setMaterialTexture(0, _driver->getTexture(_skin[tmp].c_str()));
            return true;
        }
        if (event.GUIEvent.Caller->getID() == _prev->getID()) {
            _current = prev_idx(_current);
            int tmp = _current;
            _node1->setMaterialTexture(0, _driver->getTexture(_skin[tmp].c_str()));
            tmp = prev_idx(tmp);
            _node2->setMaterialTexture(0, _driver->getTexture(_skin[tmp].c_str()));
            tmp = prev_idx(tmp);
            _node3->setMaterialTexture(0, _driver->getTexture(_skin[tmp].c_str()));
            tmp = prev_idx(tmp);
            _node4->setMaterialTexture(0, _driver->getTexture(_skin[tmp].c_str()));
            return true;
        }
        if (event.GUIEvent.Caller->getID() == _play->getID()) {
            hide();
            int tmp = _current;
            _settings->setPlayerTexture(_skin[tmp]);
            tmp = next_idx(tmp);
            _settings->setPlayerTexture(_skin[tmp]);
            tmp = next_idx(tmp);
            _settings->setPlayerTexture(_skin[tmp]);
            tmp = next_idx(tmp);
            _settings->setPlayerTexture(_skin[tmp]);
            _indieState = Indie::GAME;
            return true;
        }
    }
    return false;
}

void Skin::hide()
{
    _settingsB->setVisible(false);
    _node1->setVisible(false);
    _node2->setVisible(false);
    _node3->setVisible(false);
    _node4->setVisible(false);
    _prev->setVisible(false);
    _next->setVisible(false);
    _play->setVisible(false);
    _music.pauseMusic();
    _p1->setVisible(false);
    _p2->setVisible(false);
    _first = true;
}

void Skin::display()
{
    _p1->setVisible(true);
    if (_settings->getNbPlayer() == 2)
        _p2->setVisible(true);
    _music.playMusic();
    _settingsB->setVisible(true);
    _node1->setVisible(true);
    _node2->setVisible(true);
    _node3->setVisible(true);
    _node4->setVisible(true);
    _prev->setVisible(true);
    _next->setVisible(true);
    _play->setVisible(true);
}

int Skin::next_idx(int idx)
{
    idx++;
    if (idx > 3)
        idx = 0;
    return idx;
}

int Skin::prev_idx(int idx)
{
    idx--;
    if (idx < 0)
        idx = 3;
    return idx;
}