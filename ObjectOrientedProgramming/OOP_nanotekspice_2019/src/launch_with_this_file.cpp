/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** launch_with_this_file
*/

#include "../include/nanotekspice.hpp"

static void new_component(std::vector<std::string>& line,
    std::map<std::string, std::unique_ptr<nts::Component>>& objs)
{
    if (objs.find(line[1]) != objs.end()) {
        throw MyError("Error," + line[1] + ": this component already exist");
    }
    objs.emplace(line[1], createComponent(line[0], line[1]));
}

static size_t get_direction(std::vector<std::string> &one,
    std::vector<std::string> &two,
    nts::PutsType &type_one, nts::PutsType &type_two)
{
    std::string tmp;

    if (type_one == nts::PutsType::OUTPUT && type_two == nts::PutsType::INPUT) {
        return (1);
    } else if (type_one == nts::PutsType::INPUT && type_two == nts::PutsType::OUTPUT) {
        std::swap(one[0], two[0]);
        std::swap(one[1], two[1]);
        return (0);
    } else {
        throw MyError("Wrong connection detected in config file !");
    }
}

static void connect_right_direction(std::vector<std::string> &one,
    std::vector<std::string> &two,
    std::map<std::string, std::unique_ptr<nts::Component>>& objs,
    std::vector<nts::Cable>& links)
{
    int i_one = std::atoi(one[1].c_str()) - 1;
    int i_two = std::atoi(two[1].c_str()) - 1;
    nts::Cable *new_link = new nts::Cable;
    size_t directtion = get_direction(one, two, objs[one[0]]->getThisPutType(i_one), objs[two[0]]->getThisPutType(i_two));

    if (directtion == 0) {
        std::swap(i_one, i_two);
    }
    new_link->setIn(objs.find(one[0])->second.get(), i_one);
    new_link->setOut(objs.find(two[0])->second.get(), i_two);
    objs.find(one[0])->second->addLink(i_one, *new_link);
    objs.find(two[0])->second->addLink(i_two, *new_link);
    links.push_back(*new_link);
}

static void new_link(std::vector<std::string>& line,
    std::map<std::string, std::unique_ptr<nts::Component>>& objs,
    std::vector<nts::Cable>& links)
{
    std::vector<std::string> one = myPars::myStrMng::myStrTab(line[0], ":");
    std::vector<std::string> two = myPars::myStrMng::myStrTab(line[1], ":");

    if (one.size() != 2 || two.size() != 2 || !myPars::myStrMng::is_number(one[1]) ||
    !myPars::myStrMng::is_number(two[1])
    || objs.find(one[0]) == objs.end()
    || objs.find(two[0]) == objs.end()) {
        throw MyError("Lien invalid in configuration file !");
    }
    connect_right_direction(one, two, objs, links);
}

static void launch_with_this_file_pt_two(
    std::vector<std::string> &line, size_t &part,
    std::map<std::string, std::unique_ptr<nts::Component>> &objs,
    std::vector<nts::Cable>& links)
{
    if (part == nts::PartsType::CHIPSET && line.size() == 2) {
        new_component(line, objs);
    } else if (part == nts::PartsType::LINKS && line.size() == 2) {
        new_link(line, objs, links);
    } else {
        throw MyError("Error detected in the configuration file !");
    }
}

void launch_with_this_file(std::vector<std::string> &f,
    std::vector<std::string>& args)
{
    std::vector<std::string> line;
    size_t part = nts::Tristate::UNDEFINED;
    std::map<std::string, std::unique_ptr<nts::Component>> objs;
    std::vector<nts::Cable> links;

    for (std::string tmp : f) {
        line = myPars::myStrMng::myStrTab(tmp, " ");
        if (line[0].compare(".chipsets:") == 0) {
            part = nts::PartsType::CHIPSET;
        } else if (line[0].compare(".links:") == 0) {
            part = nts::PartsType::LINKS;
        } else {
            launch_with_this_file_pt_two(line, part, objs, links);
        }
    }
    if (args.size() != 0)
        check_prog_arguments(args, objs);
    prog_simulate(objs);
    check_links(objs, links);
    prog_loop(objs, links);
}