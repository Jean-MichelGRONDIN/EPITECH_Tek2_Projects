/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** GameSettings
*/

#include "GameSettings.hpp"

GameSettings::GameSettings() : _preveState(Indie::MENU)
{
    _nbPlayer = 1;
    _keysMapOne = std::make_shared<std::unordered_map<KeySet, EKEY_CODE>>();
    _keysMapOne->insert({KeySet::UP, EKEY_CODE::KEY_KEY_Z});
    _keysMapOne->insert({KeySet::DOWN, EKEY_CODE::KEY_KEY_S});
    _keysMapOne->insert({KeySet::RIGHT, EKEY_CODE::KEY_KEY_D});
    _keysMapOne->insert({KeySet::LEFT, EKEY_CODE::KEY_KEY_Q});
    _keysMapOne->insert({KeySet::BOMBE, EKEY_CODE::KEY_KEY_E});
    _keysMapTwo = std::make_shared<std::unordered_map<KeySet, EKEY_CODE>>();
    _keysMapTwo->insert({KeySet::UP, EKEY_CODE::KEY_KEY_Z});
    _keysMapTwo->insert({KeySet::DOWN, EKEY_CODE::KEY_KEY_S});
    _keysMapTwo->insert({KeySet::RIGHT, EKEY_CODE::KEY_KEY_D});
    _keysMapTwo->insert({KeySet::LEFT, EKEY_CODE::KEY_KEY_Q});
    _keysMapTwo->insert({KeySet::BOMBE, EKEY_CODE::KEY_KEY_E});

    _keysMapThree = std::make_shared<std::unordered_map<KeySet, EKEY_CODE>>();
    _keysMapFor = std::make_shared<std::unordered_map<KeySet, EKEY_CODE>>();
}

GameSettings::~GameSettings()
{
}

s32 GameSettings::getNbPlayer()
{
    return (_nbPlayer);
}

void GameSettings::setNbPlayer(s32 nb)
{
    _nbPlayer = nb;
}

void GameSettings::setKeyForP(char p, KeySet keyToBind, EKEY_CODE key)
{
    switch (p)
    {
    case '1':
        _keysMapOne->at(keyToBind) = key;
        break;
    case '2':
        _keysMapTwo->at(keyToBind) = key;
        break;
    default:
        break;
    }
}

std::shared_ptr<std::unordered_map<KeySet, EKEY_CODE>> GameSettings::getKeyForP(char p)
{
    switch (p)
    {
    case '1':
        return (_keysMapOne);
    case '2':
        return (_keysMapTwo);
    default:
        break;
    }
    return (_keysMapTwo);
}

void GameSettings::setPlayerTexture(std::string str)
{
    _playerTex.push_back(str);
}

std::string GameSettings::getTexForP(int idx)
{
    return _playerTex[idx];
}

void GameSettings::setPreveState(Indie::STATE s)
{
    _preveState = s;
}

Indie::STATE GameSettings::getPrevState()
{
	return _preveState;
}
