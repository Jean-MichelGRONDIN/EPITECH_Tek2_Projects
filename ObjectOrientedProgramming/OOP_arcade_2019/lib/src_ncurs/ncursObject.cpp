/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ncursObject
*/

#include "./libNcurs.hpp"

static void readFile(std::vector<std::string> &res, const std::string &path, int mode)
{
    std::string s;
    std::ifstream file_content;
    int a;

    file_content.open(path.data());
    a = file_content.is_open();
    if(a == 0) {
        return;
    }
    while(getline(file_content, s)) {
        if (mode == 1 && s.length() != 0) {
            res.push_back(s);
        } else {
            res.push_back(s);
        }
    }
    file_content.close();
}

ncursObject::ncursObject(std::string path, std::string name, int x, int y)
{
    this->_name = name;
    this->_x = x;
    this->_y = y;
    readFile(this->_sprite, path, 0);
}

ncursObject::~ncursObject()
{
}

State ncursObject::refreshObj(WINDOW *window)
{
    return (FAILURE);
}

State ncursObject::refreshPos()
{
    return (FAILURE);
}

State ncursObject::draw(WINDOW *window)
{
    for (int i = 0 ; i < this->_sprite.size() ; i++) {
        wprintw(window, this->_sprite[i].c_str());
        wprintw(window, "\n");
    }
    return (SUCCESS);
}

State ncursObject::setPos(float x, float y)
{
    return (FAILURE);
}

float ncursObject::getPosX() const
{
    return (FAILURE);
}

float ncursObject::getPosY() const
{
    return (FAILURE);
}

State ncursObject::refreshRec()
{
    return (FAILURE);
}

State ncursObject::setRec(int x, int y, int w, int h)
{
    return (FAILURE);
}

float ncursObject::getRecX() const
{
    return (FAILURE);
}

float ncursObject::getRecY() const
{
    return (FAILURE);
}

float ncursObject::getRecW() const
{
    return (FAILURE);
}

float ncursObject::getRecH() const
{
    return (FAILURE);
}