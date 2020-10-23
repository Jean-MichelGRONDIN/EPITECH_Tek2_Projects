/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** user_commands
*/

#include "../include/nanotekspice.hpp"

void prog_simulate(
    std::map<std::string, std::unique_ptr<nts::Component>> &objs)
{
    for (auto& tmp : objs) {
        if (tmp.second->getComponentType() == nts::Componenttype::INPUTC ||
            tmp.second->getComponentType() == nts::Componenttype::CLOCKC ||
            tmp.second->getComponentType() == nts::Componenttype::TRUEC ||
            tmp.second->getComponentType() == nts::Componenttype::FALSEC) {
            tmp.second->compute();
        }
    }
}

void prog_display(
    std::map<std::string, std::unique_ptr<nts::Component>> &objs)
{
    for (auto& tmp : objs) {
        if (tmp.second->getComponentType() == nts::Componenttype::OUTPUTC) {
            tmp.second->print_compute();
        }
    }
}

void prog_loop_cmds(
    std::map<std::string, std::unique_ptr<nts::Component>> &objs)
{
    prog_simulate(objs);
}

void prog_dumb(
    std::map<std::string, std::unique_ptr<nts::Component>> &objs)
{
    for (auto& tmp : objs) {
        tmp.second->dump();
    }
}


void prog_intput_definition(std::string &cmds,
    std::map<std::string, std::unique_ptr<nts::Component>> &objs)
{
    std::vector<std::string>cutted = myPars::myStrMng::myStrTab(cmds, "=");
    nts::Tristate state = nts::Tristate::UNDEFINED;

    if (cutted.size() != 2 || objs.find(cutted[0]) == objs.end() ||
        cutted[1].compare("1") != 0 && cutted[1].compare("0") != 0) {
        std::cout << "Syntaxe error in input modification commande !" << std::endl;
        return;
    }
    state = cutted[1].compare("1") == 0 ? nts::Tristate::TRUE : nts::Tristate::FALSE;
    objs.find(cutted[0])->second->setThisPutStatu(0, state);
}