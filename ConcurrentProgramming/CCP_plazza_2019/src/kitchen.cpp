/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** kitchen
*/

#include "kitchen.hpp"
#include "plazza.hpp"

double t {};

Kitchen::Kitchen(Com *com, double mul, int nb, int msTime)
{
    this->_mul = mul;
    this->_nb = nb;
    this->_msTime = msTime;
    this->_isFull = 0;
    this->_kitchen = nullptr;
    this->_com = nullptr;
    this->_id = -1;
    this->_com = com;
    t = _mul;
}

Kitchen::~Kitchen()
{
    delete this->_kitchen;
}

void Kitchen::start(void)
{
    this->_id = fork();
    if (this->_id == 0) {
        this->kitchenLoop();
    }
}

void cook(std::string order)
{
    double time = 0;
    myClock clock;
    int to_wait = 0;

    if (strncasecmp(order.c_str(), "Regina", 6) == 0)
        time = 2;
    else if (strncasecmp(order.c_str(), "Fantasia", 8) == 0)
        time = 4;
    else if (strncasecmp(order.c_str(), "Americana", 9) == 0)
        time = 2;
    else if (strncasecmp(order.c_str(), "Margarita", 9) == 0)
        time = 1;
    to_wait = t * time * 1000;
    clock.restart();
    while (clock.isGreterThan(to_wait) != true);
    std::cout << "Here is your pizza: " << order << std::endl;
}

void Kitchen::kitchenLoop()
{
    int end = 1;
    myClock clock;

    while (end == 1 && this->isFull() == false ) {
        std::string msg = this->_com->getOrder();
        this->_isFull += 1;
        if (msg != "fakeOne") {
            this->_threads.push_back(new std::thread(cook, msg));
        } else {
            std::cout << "Delivery on hold..." << std::endl;
        }
    }
    clock.restart();
    while (clock.isGreterThan(this->_mul * 4 * 1000 + 150));
    for (auto thread : this->_threads) {
        thread->join();
    }
    this->_kitchen->QuitProcess(0);
}

pid_t Kitchen::getId(void) const
{
    return (this->_id);
}

bool Kitchen::isFull(void) const
{
    if (this->_isFull < this->_nb * 2) {
        return (false);
    }
    return (true);
}

int Kitchen::getIsFull(void)
{
    return (this->_isFull);
}

void Kitchen::setIsFull(int n)
{
    this->_isFull = n;
}


void Kitchen::isFullInc(void)
{
    this->_isFull += 1;
}

void Kitchen::isFullDec(void)
{
    this->_isFull -= 1;
}
