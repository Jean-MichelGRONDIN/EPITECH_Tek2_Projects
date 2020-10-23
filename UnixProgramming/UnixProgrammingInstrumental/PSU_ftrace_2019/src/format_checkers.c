/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** format_check
*/

#include "../include/ftrace.h"

int check_elf_file_struc(Elf *elf_file)
{
    char *file_ident_fata = NULL;

    file_ident_fata = elf_getident(elf_file, NULL);
    if (file_ident_fata != NULL && file_ident_fata[0] == 127 &&
        strncmp(&(file_ident_fata[1]), "ELF", 3) == 0) {
        return (0);
    }
    return (84);
}

int is_sixty_bits(Elf *elf_file)
{
    if (elf32_getehdr(elf_file) != NULL) {
        return (84);
    }
    if (elf64_getehdr(elf_file) == NULL) {
        return (84);
    }
    return (0);
}