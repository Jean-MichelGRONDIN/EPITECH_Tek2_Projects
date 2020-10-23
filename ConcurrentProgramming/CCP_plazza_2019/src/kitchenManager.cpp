/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** kitchenManager
*/

#include "kitchenManager.hpp"

kitchenManager::kitchenManager(double mul, int nb, int msTime)
{
    this->_mul = mul;
    this->_nb = nb;
    this->_msTime = msTime;
    this->_com = new Com();
}

kitchenManager::~kitchenManager()
{
}

int kitchenManager::addNewKitchen()
{
    Kitchen *tmp = new Kitchen(this->_com, this->_mul, this->_nb, this->_msTime);

    tmp->start();
    this->_kitchens.push_back(tmp);
    sleep(10);
    return (0);
}

int kitchenManager::dumpKitchenList(void)
{
    while (this->_kitchens.size() != 0) {
        this->_kitchens.pop_back();
    }
    return (0);
}

int kitchenManager::processThisOrder(std::vector<std::string> &orders)
{
    Kitchen *tmp;
    int left = orders.size() % (this->_nb * 2);
    this->dumpKitchenList();

    if (left != 0) {
        for (int i = 0 ; i < (this->_nb * 2 - left); i++) {
            orders.push_back("fakeOne");
        }
    }
    std::cout << "Please wait until we register your order." << std::endl;
    for (std::string order : orders) {
        if (this->_kitchens.size() == 0 || this->_kitchens[this->_kitchens.size() - 1]->isFull() == true) {
            this->addNewKitchen();
        }
        tmp = this->_kitchens[this->_kitchens.size() - 1];
        this->_com->sendOrderTo(tmp->getId(), order);
        tmp->isFullInc();
    }
    std::cout << "Thank you for waiting your order has been registered." << std::endl;
    return (0);
}
