/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** pathFinder
*/

#include "./pathFinder.hpp"

pathFinder::pathFinder(char player, std::shared_ptr<irr::s32> pa,
    std::shared_ptr<irr::s32> bombrange,
    std::shared_ptr<irr::f32> movespeed) : _bombrange(bombrange), _movespeed(movespeed), _player(player), _pa(pa)
{
    _playersList.push_back('1');
    _playersList.push_back('2');
    _playersList.push_back('3');
    _playersList.push_back('4');
}

pathFinder::~pathFinder()
{
}

std::vector<std::string> pathFinder::copyMap(std::string *mapObj, std::uint64_t size)
{
    std::vector<std::string> newmap;

    for (std::uint64_t i = 0; i < size; i++) {
        newmap.push_back(std::string(mapObj[i].c_str()));
    }
    return (newmap);
}

std::vector<std::string> pathFinder::copyMap(std::vector<std::string> mapObj, std::uint64_t size)
{
    std::vector<std::string> newmap;

    for (std::uint64_t i = 0; i < size; i++) {
        newmap.push_back(std::string(mapObj[i].c_str()));
    }
    return (newmap);
}

void pathFinder::emptyMap()
{
    for (; _map.size() != 0;) {
        _map.pop_back();
    }
}

void pathFinder::explodeLeft(std::int64_t i, std::int64_t iTwo, irr::s32 range)
{
    std::int64_t left = -1;

    for (size_t index = 0; index < *_bombrange - 1; index++) {
        iTwo = iTwo + left;
        if (iTwo <= 0 || iTwo >= _map[0].length() || i <= 0 || i >= _map.size() || _map[i][iTwo] == 'W') {
            return;
        }
        if (_map[i].at(iTwo) != 'B') {
            _map[i].at(iTwo) = 'X';
        }
    }
    // if (iTwo - 1 <= 0 || iTwo - 1 > _map[0].length() || i <= 0 || i > _map.size()) {
    //     return;
    // }
    // if (iTwo - 1 >= 0 && _map[i][iTwo - 1] != 'W' && iTwo - 1 >= 0 && _map[i][iTwo - 1] != 'B') {
    //     _map[i].at(iTwo - 1) = 'X';
    // }
    // if (iTwo - 2 <= 0 || iTwo - 2 > _map[0].length() || i <= 0 || i > _map.size() || iTwo - 2 >= 0 && _map[i][iTwo - 2] == 'W') {
    //     return;
    // }
    // if (iTwo - 2 >= 0 && _map[i][iTwo - 2] != 'W' && iTwo - 2 >= 0 && _map[i][iTwo - 2] != 'B') {
    //     _map[i].at(iTwo - 2) = 'X';
    // }
}

void pathFinder::explodeRigth(std::int64_t i, std::int64_t iTwo, irr::s32 range)
{
    std::int64_t right = 1;

    for (size_t index = 0; index < *_bombrange - 1; index++) {
        iTwo = iTwo + right;
        if (iTwo <= 0 || iTwo >= _map[0].length() || i <= 0 || i >= _map.size() || _map[i][iTwo] == 'W') {
            return;
        }
        if (_map[i].at(iTwo) != 'B') {
            _map[i].at(iTwo) = 'X';
        }
    }
    // if (iTwo + 1 <= 0 || iTwo + 1 > _map[0].length() || i <= 0 || i > _map.size()) {
    //     return;
    // }
    // if (iTwo + 1 < _map[i].length() && _map[i][iTwo + 1] != 'W' && iTwo + 1 < _map[i].length() && _map[i][iTwo + 1] != 'B') {
    //     _map[i].at(iTwo + 1) = 'X';
    // }
    // if (iTwo + 2 <= 0 || iTwo + 2 > _map[0].length() || i <= 0 || i > _map.size() || iTwo + 2 < _map[i].length() && _map[i][iTwo + 2] == 'W') {
    //     return;
    // }
    // if (iTwo + 2 < _map[i].length() && _map[i][iTwo + 2] != 'W' && iTwo + 2 < _map[i].length() && _map[i][iTwo + 2] != 'B') {
    //     _map[i].at(iTwo + 2) = 'X';
    // }
}

void pathFinder::explodeUp(std::int64_t i, std::int64_t iTwo, irr::s32 range)
{
    std::int64_t up = -1;

    for (size_t index = 0; index < *_bombrange - 1; index++) {
        i = i + up;
        if (iTwo <= 0 || iTwo >= _map[0].length() || i <= 0 || i >= _map.size() || _map[i][iTwo] == 'W') {
            return;
        }
        if (_map[i].at(iTwo) != 'B') {
            _map[i].at(iTwo) = 'X';
        }
    }
    // if (iTwo <= 0 || iTwo > _map[0].length() || i - 1 <= 0 || i - 1 > _map.size()) {
    //     return;
    // }
    // if (i - 1 >= 0 && _map[i - 1][iTwo] != 'W' && i - 1 >= 0 && _map[i - 1][iTwo] != 'B') {
    //     _map[i - 1].at(iTwo) = 'X';
    // }
    // if (iTwo <= 0 || iTwo > _map[0].length() || i - 2 <= 0 || i - 2 > _map.size() || i - 2 >= 0 && _map[i - 2][iTwo] == 'W') {
    //     return;
    // }
    // if (i - 2 >= 0 && _map[i - 2][iTwo] != 'W' && i - 2 >= 0 && _map[i - 2][iTwo] != 'B') {
    //     _map[i - 2].at(iTwo) = 'X';
    // }
}

void pathFinder::explodeBot(std::int64_t i, std::int64_t iTwo, irr::s32 range)
{
    std::int64_t bot = 1;

    for (size_t index = 0; index < *_bombrange - 1; index++) {
        i = i + bot;
        if (iTwo <= 0 || iTwo >= _map[0].length() || i <= 0 || i >= _map.size() || _map[i][iTwo] == 'W') {
            return;
        }
        if (_map[i].at(iTwo) != 'B') {
            _map[i].at(iTwo) = 'X';
        }
    }
    // if (iTwo <= 0 || iTwo > _map[0].length() || i + 1 <= 0 || i + 1 > _map.size()) {
    //     return;
    // }
    // if (i + 1 < _map.size() && _map[i + 1][iTwo] != 'W' && i + 1 < _map.size() && _map[i + 1][iTwo] != 'B') {
    //     _map[i + 1].at(iTwo) = 'X';
    // }
    // if (iTwo <= 0 || iTwo > _map[0].length() || i + 2 <= 0 || i + 2 > _map.size() || i + 2 < _map.size() && _map[i + 2][iTwo] == 'W') {
    //     return;
    // }
    // if (i + 2 < _map.size() && _map[i + 2][iTwo] != 'W' && i + 2 < _map.size() && _map[i + 2][iTwo] != 'B') {
    //     _map[i + 2].at(iTwo) = 'X';
    // }
}

static irr::s32 ctos32(char c)
{
    if (c < '0' || c > '9') {
        return (-1);
    }
    switch (c)
    {
    case '0':
        return (0);
        break;
    case '1':
        return (1);
        break;
    case '2':
        return (2);
        break;
    case '3':
        return (3);
        break;
    case '4':
        return (4);
        break;
    case '5':
        return (5);
        break;
    case '6':
        return (6);
        break;
    case '7':
        return (7);
        break;
    case '8':
        return (8);
        break;
    case '9':
        return (9);
        break;
    default:
        return (-1);
        break;
    }
    // if (iTwo <= 0 || iTwo > _map[0].length() || i + 1 <= 0 || i + 1 > _map.size()) {
    //     return;
    // }
    // if (i + 1 < _map.size() && _map[i + 1][iTwo] != 'W' && i + 1 < _map.size() && _map[i + 1][iTwo] != 'B') {
    //     _map[i + 1].at(iTwo) = 'X';
    // }
    // if (iTwo <= 0 || iTwo > _map[0].length() || i + 2 <= 0 || i + 2 > _map.size() || i + 2 < _map.size() && _map[i + 2][iTwo] == 'W') {
    //     return;
    // }
    // if (i + 2 < _map.size() && _map[i + 2][iTwo] != 'W' && i + 2 < _map.size() && _map[i + 2][iTwo] != 'B') {
    //     _map[i + 2].at(iTwo) = 'X';
    // }
}

void pathFinder::drawBombsRange(std::string *mapTxt, std::uint64_t size)
{
    std::uint64_t i = 0;
    std::uint64_t iTwo = 0;
    irr::s32 tmp = -1;

    for (; i < size; i++) {
        for (; iTwo < mapTxt[i].length(); iTwo++) {
            if (mapTxt[i].at(iTwo) >= '0' && mapTxt[i].at(iTwo) <= '9') {
                tmp = ctos32(mapTxt[i].at(iTwo));
                _map[i].at(iTwo) = 'X';
                explodeLeft(i, iTwo, tmp);
                explodeRigth(i, iTwo, tmp);
                explodeUp(i, iTwo, tmp);
                explodeBot(i, iTwo, tmp);
            }
        }
        iTwo = 0;
    }
}

void pathFinder::drawBombsRange(std::vector<std::string> mapTxt, std::uint64_t size)
{
    std::uint64_t i = 0;
    std::uint64_t iTwo = 0;
    irr::s32 tmp = -1;

    for (; i < size; i++) {
        for (; iTwo < mapTxt[i].length(); iTwo++) {
            if (mapTxt[i].at(iTwo) >= '0' && mapTxt[i].at(iTwo) <= '9') {
                tmp = ctos32(mapTxt[i].at(iTwo));
                _map[i].at(iTwo) = 'X';
                explodeLeft(i, iTwo, tmp);
                explodeRigth(i, iTwo, tmp);
                explodeUp(i, iTwo, tmp);
                explodeBot(i, iTwo, tmp);
            }
        }
        iTwo = 0;
    }
}

irr::core::vector2di pathFinder::getThisPlayerPos(char p,
    const std::unordered_map<char, irr::core::vector2di> &playerList, std::uint64_t size)
{
    std::uint64_t i = 0;
    std::uint64_t iTwo = 0;
    irr::core::vector2di res;

    res.X = -1;
    res.Y = -1;
    for (std::pair<char, irr::core::vector2di> tmp : playerList) {
        if (tmp.first == p) {
            res.X = tmp.second.Y;
            res.Y = tmp.second.X;
            return (res);
        }
    }
    return (res);
}

irr::core::vector2di pathFinder::getUpPos(irr::core::vector2di pos)
{
    irr::core::vector2di res;

    res.X = pos.X;
    res.Y = pos.Y - 1;
    return (res);
}

irr::core::vector2di pathFinder::getDownPos(irr::core::vector2di pos)
{
    irr::core::vector2di res;

    res.X = pos.X;
    res.Y = pos.Y + 1;
    return (res);
}

irr::core::vector2di pathFinder::getLeftPos(irr::core::vector2di pos)
{
    irr::core::vector2di res;

    res.X = pos.X - 1;
    res.Y = pos.Y;
    return (res);
}

irr::core::vector2di pathFinder::getRigthPos(irr::core::vector2di pos)
{
    irr::core::vector2di res;

    res.X = pos.X + 1;
    res.Y = pos.Y;
    return (res);
}

std::int64_t pathFinder::getThisDistance(irr::core::vector2di one,
    irr::core::vector2di two)
{
    std::int64_t res = -1;
    if (one.X != -1 && two.X != -1 && one.Y != -1 && two.Y != -1) {
        res = two.getDistanceFrom(one);
        if (res < 0) {
            res = res * (-1);
        }
    }
    return (res);
}

char pathFinder::getclosestEnemy(char p, irr::core::vector2di pos,
    const std::unordered_map<char, irr::core::vector2di> &playerList, std::uint64_t size)
{
    char res = _player;
    std::int64_t closestDisdance = 1000;
    std::int64_t tmpDisdance = 1000;

    for (char tmp : _playersList) {
        tmpDisdance = getThisDistance(pos, getThisPlayerPos(tmp, playerList, size));
        if (tmpDisdance != -1 && tmp != p && tmpDisdance < closestDisdance) {
            res = tmp;
            closestDisdance = tmpDisdance;
        }
    }
    return (res);
}

bool pathFinder::wasAlreadyHere(irr::core::vector2di player,
    std::vector<irr::core::vector2di> oldPos)
{
    for (irr::core::vector2di &tmp : oldPos) {
        if (tmp.X == player.X && tmp.Y == player.Y) {
            return (true);
        }
    }
    return (false);
}

irr::core::vector2di pathFinder::reverseMove(irr::core::vector2di player, KeySet action)
{
    switch (action)
    {
    case UP:
        return (getDownPos(player));
        break;
    case DOWN:
        return (getUpPos(player));
        break;
    case LEFT:
        return (getRigthPos(player));
        break;
    case RIGHT:
        return (getLeftPos(player));
        break;
    default:
        return (player);
        break;
    }
}

Paths pathFinder::findShortestPathAnalyse(irr::core::vector2di player,
    irr::core::vector2di enemy, KeySet action, std::vector<irr::core::vector2di> oldPos)
{
    Paths list;
    Paths ret;
    std::vector<std::string> save_map;
    std::vector<std::string> tmp_map;
    irr::core::vector2di tmp_pos;
    std::vector<irr::core::vector2di> newOldPos;

    if (player.X <= 0 || player.X > _map[0].length() || player.Y <= 0 || player.Y > _map.size()) {
        return (list);
    }
    if (_map[player.Y].at(player.X) == 'B' || (player.X == enemy.X && player.Y == enemy.Y)) {
        save_map = copyMap(_map, _map.size());
        tmp_pos = oldPos[oldPos.size() - 1];
        _map[tmp_pos.Y].at(tmp_pos.X) = 'X';
        explodeLeft(tmp_pos.Y, tmp_pos.X, *_bombrange);
        explodeRigth(tmp_pos.Y, tmp_pos.X, *_bombrange);
        explodeUp(tmp_pos.Y, tmp_pos.X, *_bombrange);
        explodeBot(tmp_pos.Y, tmp_pos.X, *_bombrange);
        newOldPos.push_back(player);
        ret = runShortestPath(tmp_pos, enemy, newOldPos);
        if (
        ret.size() != 0
        &&
        _map[ret.getPos().Y].at(ret.getPos().X) == ' '
        &&
        (
        *_pa == 0
        ||
        ret.size() == 2
        ||
        (
        ret.size() == 3
        &&
        *_bombrange == 3
        &&
        *_movespeed >= 0.5F
        &&
        ret.atIndex(ret.size() - 1) == ret.atIndex(ret.size() - 2)
        &&
        ret.atIndex(ret.size() - 2) == ret.atIndex(0)
        )
        )
        ) {
            list.pushBack(BOMBE);
        }
        _map = copyMap(save_map, save_map.size());
        if (player.X == enemy.X && player.Y == enemy.Y) {
            list.setPlayerFound(true);
        }
    }
    if (_map[player.Y].at(player.X) != ' ' || wasAlreadyHere(player, oldPos) == true) {
        return(list);
    }
    list.pushBack(action);
    list.setPos(player);
    oldPos.push_back(player);
    ret = findShortestPath(player, enemy, oldPos);
    list.fusionAtBack(ret);
    return (list);
}

Paths pathFinder::findShortestPath(irr::core::vector2di player,
    irr::core::vector2di enemy, std::vector<irr::core::vector2di> oldPos)
{
    std::vector<Paths> tab;
    Paths res;
    res.calcScore();
    if (oldPos.size() <= 20) {
        tab.push_back(findShortestPathAnalyse(getUpPos(player), enemy, UP, oldPos));
        tab.push_back(findShortestPathAnalyse(getLeftPos(player), enemy, LEFT, oldPos));
        tab.push_back(findShortestPathAnalyse(getRigthPos(player), enemy, RIGHT, oldPos));
        tab.push_back(findShortestPathAnalyse(getDownPos(player), enemy, DOWN, oldPos));
    }
    for (Paths tmp : tab) {
        tmp.calcScore();
        if (
            res.getScore() == 0
            ||
            (
            tmp.getScore() != 0
            &&
            tmp.distance(enemy) < res.distance(enemy)
            )
        ) {
            res = tmp;
        }
    }
    return (res);
}

Paths pathFinder::runShortestPathAnalyse(irr::core::vector2di player,
    irr::core::vector2di enemy, KeySet action, std::vector<irr::core::vector2di> oldPos)
{
    Paths list;
    Paths ret;
    if (player.X <= 0 || player.X > _map[0].length() || player.Y <= 0 || player.Y > _map.size()) {
        return (list);
    }
    if ((_map[player.Y].at(player.X) != ' ' && _map[player.Y].at(player.X) != 'X')) {
        return(list);
    }
    if (wasAlreadyHere(player, oldPos) == true) {
        return (list);
    }
    if (_map[player.Y].at(player.X) == ' ') {
        list.pushBack(action);
        list.setPos(player);
        oldPos.push_back(player);
        return (list);
    }
    list.pushBack(action);
    list.setPos(player);
    oldPos.push_back(player);
    ret = runShortestPath(player, enemy, oldPos);
    list.fusionAtBack(ret);
    return (list);
}

Paths pathFinder::runShortestPath(irr::core::vector2di player,
    irr::core::vector2di enemy, std::vector<irr::core::vector2di> oldPos)
{
    std::vector<Paths> tab;
    Paths res;
    res.calcScore();
    if (oldPos.size() <= 20) {
        tab.push_back(runShortestPathAnalyse(getUpPos(player), enemy, UP, oldPos));
        tab.push_back(runShortestPathAnalyse(getLeftPos(player), enemy, LEFT, oldPos));
        tab.push_back(runShortestPathAnalyse(getRigthPos(player), enemy, RIGHT, oldPos));
        tab.push_back(runShortestPathAnalyse(getDownPos(player), enemy, DOWN, oldPos));
    }
    for (Paths tmp : tab) {
        tmp.calcScore();
        tmp.calcScore();
        if (
        res.size() == 0
        ||
        (
        tmp.size() != 0
        &&
        (
        (
        _map[tmp.getPos().Y].at(tmp.getPos().X) == ' '
        &&
        _map[res.getPos().Y].at(res.getPos().X) != ' '
        )
        ||
        (
        _map[tmp.getPos().Y].at(tmp.getPos().X) == ' '
        &&
        tmp.size() < res.size()
        )
        )
        )
        ) {
            res = tmp;
        }
    }
    return (res);
}

KeySet pathFinder::getPath(const std::unordered_map<char, irr::core::vector2di> &playerList,
    std::string *mapObjs, std::uint64_t size)
{
    irr::core::vector2di myPos;
    irr::core::vector2di enemyPos;
    std::vector<irr::core::vector2di> allPos;
    char enemy = 0;
    KeySet res = NOTHING;
    Paths shortest;

    if (playerList.size() <= 1) {
        return (NOTHING);
    }
    _map = copyMap(mapObjs, size);

    drawBombsRange(mapObjs, size);

    myPos = getThisPlayerPos(_player, playerList, size);
    enemy = getclosestEnemy(_player, myPos, playerList, size);
    enemyPos = getThisPlayerPos(enemy, playerList, size);
    if (myPos.X == -1 || myPos.Y == -1 || enemyPos.X == -1 || enemyPos.Y == -1) {
        return (res);
    }
    allPos.push_back(myPos);
    if (_map[myPos.Y].at(myPos.X) == 'X') {
        shortest = runShortestPath(myPos, enemyPos, allPos);
    } else if (myPos.X == enemyPos.X && myPos.Y == enemyPos.Y) {
        return (BOMBE);
    } else {
        shortest = findShortestPath(myPos, enemyPos, allPos);
    }
    if (shortest.size() > 0) {
        res = shortest.atIndex(0);
    }
    emptyMap();
    return (res);
}
