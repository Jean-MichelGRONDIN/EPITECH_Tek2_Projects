/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** objdump
*/

#ifndef OBJDUMP_H_
#define OBJDUMP_H_

#include "include.h"

void print_section_thirty(void *file);

void print_section(void *file);

int print_header_thirty(char const *path, void *file);

int print_header_sixty(char const *path, void *file);

int print_header(char const *path, size_t bits, void *file);

int process_this_file(char const *path);

int objdump(int ac, char **av);

#endif