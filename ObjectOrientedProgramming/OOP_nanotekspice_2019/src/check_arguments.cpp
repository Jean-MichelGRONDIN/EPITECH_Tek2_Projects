/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** check_arguments
*/

#include "../include/nanotekspice.hpp"

void check_prog_arguments(std::vector<std::string>& args,
    std::map<std::string, std::unique_ptr<nts::Component>>& objs)
{
    std::vector<std::string> cuted;
    nts::Tristate state = nts::Tristate::UNDEFINED;

    for (std::string tmp : args) {
        cuted = myPars::myStrMng::myStrTab(tmp, "=");
        state = cuted[1].compare("1") == 0 ? nts::Tristate::TRUE : nts::Tristate::FALSE;
        if (objs.find(cuted[0]) == objs.end()) {
            throw MyError("Error, cannot set " + cuted[0] + " because it do not exist !");
        } else {
            objs.find(cuted[0])->second->setThisPutStatu(0, state);
        }
    }
}