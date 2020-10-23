/*
** EPITECH PROJECT, 2020
** about1.cpp
** File description:
** libNcurs
*/

#include "./libNcurs.hpp"

libNcurs::libNcurs()
{
    this->_windowIsOpen = false;
    this->_name = "NCURS";
    this->_window = nullptr;
    this->_isEvent = -1;
    this->_key = -1;
}

libNcurs::~libNcurs()
{
    this->windowClose();
}

void libNcurs::test() const
{
    std::cout << "[libNcurs] i am here working and loaded as expected ^^" << std::endl;
}
State libNcurs::windowOpen()
{
    if (this->_windowIsOpen == false) {
        initscr();
        this->_window = newwin(32, 80, 0, 0);
        cbreak();
        keypad(this->_window, TRUE);
        keypad(stdscr, TRUE);
        noecho();
        wtimeout(this->_window, 1000);
        timeout(1000);
        raw();
        curs_set(0);
        this->_windowIsOpen = true;
        return (SUCCESS);
    }
    return (FAILURE);
}

State libNcurs::windowClear()
{
    clear();
    wclear(this->_window);
    return (SUCCESS);
}

State libNcurs::windowDisplay()
{
    refresh();
    wrefresh(this->_window);
    return (SUCCESS);
}

State libNcurs::windowClose()
{
    if (this->_windowIsOpen == true) {
        delwin(this->_window);
        endwin();
        this->_window = nullptr;
        this->_windowIsOpen = false;
        return (SUCCESS);
    }
    return (FAILURE);
}

bool libNcurs::windowIsOpen() const
{
    return (this->_windowIsOpen);
}

bool libNcurs::isThisEventGoing(char e)
{
    int ch = getch();

    if (ch == e) {
        return (true);
    }
    return (false);
}

bool libNcurs::windowCloseEvent()
{
    if (this->_isEvent != -1 && this->_key == 27) {
        this->_isEvent = -1;
        this->_key = -1;
        std::cerr << "Escape detected\n" << std::endl;
        return (true);
    }
    return (false);
}

bool libNcurs::switchLibEvent()
{
    if (this->_isEvent != -1 && this->_key == 'c') {
        this->_isEvent = -1;
        this->_key = -1;
        std::cerr << "C detected\n" << std::endl;
        return (true);
    }
    return (false);
}

State libNcurs::initAsset(std::string id, std::string path, int x, int y)
{
    std::string realPath = path.substr(0, path.find_last_of('.')) + ".txt";

    if (this->object_list.find(id) == this->object_list.end()) {
        this->object_list.emplace(id, ncursObject(realPath, id, x, y));
        return (SUCCESS);
    }
    return (FAILURE);
}

State libNcurs::drawAsset(std::string id)
{
    if (this->object_list.find(id) != this->object_list.end()) {
        this->object_list.find(id)->second.draw(this->_window);
        return (SUCCESS);
    }
    return (FAILURE);
}

State libNcurs::deleteAsset(std::string id)
{
    return (FAILURE);
}

bool libNcurs::leftArrowEvent()
{
    if (this->_isEvent != -1 && this->_key == KEY_LEFT) {
        this->_isEvent = -1;
        this->_key = 0;
        std::cerr << "Left detected\n" << std::endl;
        return (true);
    }
    return (false);
}

bool libNcurs::rightArrowEvent()
{
    if (this->_isEvent != -1 && this->_key == KEY_RIGHT) {
        this->_isEvent = -1;
        this->_key = 0;
        std::cerr << "Rigth detected\n" << std::endl;
        return (true);
    }
    return (false);
}

bool libNcurs::upArrowEvent()
{
    if (this->_isEvent != -1 && this->_key == KEY_UP) {
        this->_isEvent = -1;
        this->_key = 0;
        std::cerr << "Up detected\n" << std::endl;
        return (true);
    }
    return (false);
}

bool libNcurs::downArrowEvent()
{
    if (this->_isEvent != -1 && this->_key == KEY_DOWN) {
        this->_isEvent = -1;
        this->_key = 0;
    std::cerr << "Down detected\n" << std::endl;
        return (true);
    }
    return (false);
}

bool libNcurs::EnterEvent()
{
    if (this->_isEvent != -1 && this->_key == '\n') {
        this->_isEvent = -1;
        this->_key = 0;
        std::cerr << "Enter detected\n" << std::endl;
        return (true);
    }
    return (false);
}

bool libNcurs::backMenuEvent()
{
    if (this->_isEvent != -1 && this->_key == 'm') {
        this->_isEvent = -1;
        this->_key = 0;
        std::cerr << "M detected\n" << std::endl;
        return (true);
    }
    return (false);
}

std::string libNcurs::getName()
{
    return (this->_name);
}

State libNcurs::setPos(std::string id, float x, float y)
{
    return (FAILURE);
}

float libNcurs::getPosX(std::string id) const
{
    return (FAILURE);
}

float libNcurs::getPosY(std::string id) const
{
    return (FAILURE);
}

State libNcurs::windowEvents()
{
    this->_isEvent = -1;
    this->_key = -1;
    this->_key = wgetch(this->_window);
    if (this->_key != -1) {
        this->_isEvent = 1;
    }
    return (SUCCESS);
}

extern "C" {
    libNcurs *constuct() {
        return new libNcurs();
    }
}