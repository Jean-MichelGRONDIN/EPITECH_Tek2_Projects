/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "../include/arcade.hpp"

int arcade(int ac, char **av)
{
    std::vector<std::shared_ptr<libLoader<ILib>>> lib_list =
        libLoader<ILib>::getAllThisFolderLibs("./lib/");
    std::vector<std::shared_ptr<libLoader<IGame>>> game_list =
        libLoader<IGame>::getAllThisFolderLibs("./games/");
    std::string requested = av[1];
    int checked = -1;
    int i_lib = 0;
    int i_game = 0;

    i_game = getLibIndex<IGame>(game_list, "menu.so");
    requested = requested.substr(requested.find_last_of('/') + 1);
    i_lib = getLibIndex<ILib>(lib_list, requested);
    if (i_lib == -1) {
        std::cerr << "This library doesn't exist in /lib folder !" << std::endl;
        return (84);
    }
    while (core_loop(lib_list, game_list, i_lib, i_game) != QUIT_PROG);
    return (0);
}

int main(int ac, char **av)
{
    char *err = NULL;

    if (ac != 2) {
        std::cerr << "Wrong number of arguments !" << std::endl;
        return (84);
    }
    err = dlerror();
    dlopen("tooto.so", RTLD_LAZY);
    if (err != NULL) {
        std::cout << err << std::endl;
    }
    return (arcade(ac, av));
}