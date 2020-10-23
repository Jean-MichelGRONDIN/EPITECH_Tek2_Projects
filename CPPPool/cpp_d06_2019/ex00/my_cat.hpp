/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** my_cat
*/

#ifndef MY_CAT_HPP_
#define MY_CAT_HPP_

#include <iostream>
#include <fstream>

bool check_this_file(std::string *path);
std::string read_this_file(char *path);
bool check_all_files(int ac, char **av);

#endif /* !MY_CAT_HPP_ */