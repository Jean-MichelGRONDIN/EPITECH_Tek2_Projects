/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** prog_loop
*/

#include "../include/nanotekspice.hpp"

static void read_cmds(size_t &end, std::string &cmds)
{
    int breack = 1;

    while (breack == 1 && end == 0) {
        std::cout << "> ";
        std::cin>>cmds;
        if (cmds.length() == 0) {
            end = 1;
            std::cout << std::endl;
        }
        if (cmds.compare("\n") != 0) {
            breack = 0;
        }
    }
}

static void do_cmds(size_t &end, std::string &cmds,
    std::map<std::string, std::unique_ptr<nts::Component>> &objs)
{
    if (cmds.compare("exit") == 0) {
        end = 1;
        return;
    }
    if (cmds.compare("dumb") == 0) {
        prog_dumb(objs);
        return;
    }
    if (cmds.compare("display") == 0) {
        prog_display(objs);
        return;
    }
    if (cmds.compare("simulate") == 0) {
        prog_simulate(objs);
        return;
    }
    if (cmds.compare("loop") == 0) {
        prog_loop_cmds(objs);
        return;
    }
    if (cmds.find('=') != -1) {
        prog_intput_definition(cmds, objs);
        return;
    }
    std::cout << "wrong commande !" << std::endl;
}

void prog_loop(
    std::map<std::string, std::unique_ptr<nts::Component>> &objs,
    std::vector<nts::Cable> &links)
{
    size_t end = 0;
    std::string cmds = "";

    read_cmds(end, cmds);
    while (end == 0) {
        do_cmds(end, cmds, objs);
        cmds = "";
        read_cmds(end, cmds);
    }
}