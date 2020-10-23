/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** main
*/

#include <fstream>
#include <string>
#include <iostream>

void my_cat(std::string path)
{
    std::string s;
    std::ifstream file_content;
    int a;

    file_content.open(path.data());
    a = file_content.is_open();
    if(a == 0) {
        std::cerr <<"my_cat: "
        << path
        << ": No such file or directory" << std::endl;
        return;
    }
    while(getline(file_content, s)) {
        std::cout << s << std::endl;
    }
    file_content.close();
}

int main(int ac, char **av)
{
    std::string str;
    int i = 0;

    if(ac == 1)
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
    for (i = 1; i < ac; i++) {
        str=av[i];
        my_cat(str);
    }
    return 0;
}