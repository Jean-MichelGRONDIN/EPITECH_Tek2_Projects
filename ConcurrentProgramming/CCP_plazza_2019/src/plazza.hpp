/*
** EPITECH PROJECT, 2020
** CCP
** File description:
** Plazza
*/

#ifndef PLAZZA_HPP_
#define PLAZZA_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <cstring>
#include <deque>
#include <cstring>
#include <cctype>

#include "Pizza/Regina.hpp"
#include "Pizza/Fantasia.hpp"
#include "Pizza/Margarita.hpp"
#include "Pizza/Americana.hpp"
#include "Pizza/Ipizza.hpp"
#include "Pizza/AbPizza.hpp"
#include "Com.hpp"
#include "kitchenManager.hpp"

#include "Ipc.hpp"
#include "Fork.hpp"

std::vector<std::string> explode(std::string &, char);

class Plazza {
    public:
        void reception();
        Plazza(int ac, char**av);
        ~Plazza();
        static std::vector<std::string> explode(std::string &, char);
        bool CheckInputName(std::vector<std::string>);
        bool CheckInputSize(std::vector<std::string>);
        bool CheckInputNum(std::vector<std::string>);
        bool CheckInput(std::vector<std::string>);
        void FileVector();
        double GetMul() {return _mul;};

    private:
        kitchenManager *_manager;
        double _mul;
        int _nb;
        int _msTime;
        std::vector<std::string> _NameP;
        std::vector<std::string> _SizeP;
        std::string getInput(void);
        std::vector<std::string> parseInput(std::string &);
};


#endif /* !PLAZZA_HPP_ */
