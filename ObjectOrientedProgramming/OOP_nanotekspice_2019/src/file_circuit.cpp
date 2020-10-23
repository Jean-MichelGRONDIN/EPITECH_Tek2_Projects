/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** file_circuit
*/

#include "../include/nanotekspice.hpp"

static void get_prog_args(std::vector<std::string>& args, int ac, char **av)
{
    int i = 2;
    std::vector<std::string> tmp;

    while (i != ac) {
        tmp = myPars::myStrMng::myStrTab(av[i], "=");
        if (tmp.size() != 2 || tmp[1].compare("0") != 0
        && tmp[1].compare("1") != 0) {
            throw MyError("Bad argument detected !");
        }
        args.push_back(av[i]);
        i++;
    }
}

static std::string get_this_line_but_clean(std::ifstream &content)
{
    std::string s;

    while (std::getline(content, s)) {
        if (s.length() != 0)
            myPars::myStrMng::cl_in_line_cmmts(s, '#', " \t");
        if (s.length() != 0) {
            std::replace(s.rbegin(), s.rend(), '\t', ' ');
            myPars::myStrMng::cl_mults_chr(s, ' ');
            return (s);
        }
    }
    return ("");
}

void file_circuit(std::string file_name, int ac, char **av)
{
    std::ifstream content;
    std::string ret = "";
    std::vector<std::string> s;
    std::vector<std::string> args;

    content.open(file_name.data());
    if (content.is_open() == -1)
        throw MyError("Cannot open the configuration file !");
    ret = get_this_line_but_clean(content);
    while (ret.length() != 0) {
        s.push_back(ret);
        ret = get_this_line_but_clean(content);
    }
    content.close();
    get_prog_args(args, ac, av);
    launch_with_this_file(s, args);
}