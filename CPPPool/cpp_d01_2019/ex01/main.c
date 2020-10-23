/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** main
*/

#include "./ex01.h"

int check_level_multiple(int x, int i)
{
    if (x == i) {
        return (1);
    } else if (x > i) {
        return (check_level_multiple(x, (i*3)));
    } else {
        return (0);
    }
}

void    print_error_and_exit(char *str)
{
    fprintf(stderr, "%s\n", str);
    exit(84);
}

int is_number(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (isdigit(str[i]) == 0) {
            return (0);
        }
        i++;
    }
    return (1);
}

int main(int ac, char **av)
{
    int size = 0;
    int level = 0;

    if (ac != 3)
        print_error_and_exit("Wrong number of arguments !!");
    if (is_number(av[1]) == 0 || is_number(av[2]) == 0)
        print_error_and_exit("Arguments must be positives numbers !!");
    size = atoi(av[1]);
    level = atoi(av[2]);
    if (check_level_multiple(size, 1) == 0)
        print_error_and_exit(
        "Error size must be greater than 0 and multiple of 3level !!");
    menger(level, size);
    return (0);
}
