/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** check_links
*/

#include "../include/nanotekspice.hpp"

static bool check_if_linked(
    std::string obj_name, std::vector<nts::Cable>& links)
{
    for (auto& tmp : links) {
        if (tmp.getOut()->getName().compare(obj_name) == 0 ||
            tmp.getIn()->getName().compare(obj_name) == 0) {
            return (true);
        }
    }
    return (false);
}

void check_links(
    std::map<std::string, std::unique_ptr<nts::Component>> &objs,
    std::vector<nts::Cable>& links)
{
    for (auto& tmp : objs) {
        if (tmp.second->getComponentType() == nts::Componenttype::OUTPUTC &&
        check_if_linked(tmp.first, links) == false) {
            throw MyError("Output: " + tmp.first + " is not linked to anything");
        }
    }
    prog_display(objs);
}