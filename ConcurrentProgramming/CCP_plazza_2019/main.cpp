/*
** EPITECH PROJECT, 2020
** base_cpp_project
** File description:
** main
*/

#include "src/plazza.hpp"

int main(int ac, char **av)
{
    try {
        Plazza test(ac, av);

        test.reception();
    } catch(MyError const &e) {
        std::cerr << "Error : " << e.what() << std::endl;
        return (84);
    }
    return (0);
}