/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** kitchenManager
*/

#ifndef KITCHENMANAGER_HPP_
#define KITCHENMANAGER_HPP_

#include "kitchen.hpp"

#include <vector>

class kitchenManager {
    public:
        kitchenManager(double mul, int nb, int msTime);
        ~kitchenManager();
        int processThisOrder(std::vector<std::string> &orders);
        int dumpKitchenList(void);
    private:
        int addNewKitchen(void);
        std::vector<std::thread *> _threads;
        Com *_com;
        double _mul;
        int _nb;
        int _msTime;
        std::vector<Kitchen *> _kitchens;
};

#endif