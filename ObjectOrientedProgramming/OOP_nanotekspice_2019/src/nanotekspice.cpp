/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** nanotekspice
*/

#include "../include/nanotekspice.hpp"

int nanotekspice(int ac, char **av)
{
    if (ac < 2) {
        std::cerr << "Wrong number of arguments" << std::endl;
        return (84);
    }
    try {
        file_circuit(av[1], ac, av);
    } catch(const MyError& err) {
        std::cerr << err.what() << '\n';
        return (84);
    }
    return (0);
}