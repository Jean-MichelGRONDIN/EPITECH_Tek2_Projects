/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** nanotekspice
*/

#ifndef NANOTEKSPICE_H_
#define NANOTEKSPICE_H_

#include "./myPars.hpp"
#include "./Component.hpp"

class MyError : public std::exception
{
    public:
        MyError(std::string const &message);
        const char *what() const noexcept;

    private:
        std::string _message;
        std::string _component;
};

void prog_display(
    std::map<std::string, std::unique_ptr<nts::Component>> &objs);
void prog_simulate(
    std::map<std::string, std::unique_ptr<nts::Component>> &objs);
void prog_loop_cmds(
    std::map<std::string, std::unique_ptr<nts::Component>> &objs);
void prog_dumb(
    std::map<std::string, std::unique_ptr<nts::Component>> &objs);
void prog_intput_definition(std::string &cmds,
    std::map<std::string, std::unique_ptr<nts::Component>> &objs);



void check_links(
    std::map<std::string, std::unique_ptr<nts::Component>> &objs,
    std::vector<nts::Cable>& links);

void check_prog_arguments(std::vector<std::string>& args,
    std::map<std::string, std::unique_ptr<nts::Component>>& objs);

void prog_loop(
    std::map<std::string, std::unique_ptr<nts::Component>> &objs,
    std::vector<nts::Cable> &links);

std::unique_ptr<nts::Component> createComponent(const std::string &type
    ,const std::string &value);

void launch_with_this_file(std::vector<std::string> &f,
    std::vector<std::string>& args);

void file_circuit(std::string file_name, int ac, char **av);

int nanotekspice(int ac, char **av);

#endif