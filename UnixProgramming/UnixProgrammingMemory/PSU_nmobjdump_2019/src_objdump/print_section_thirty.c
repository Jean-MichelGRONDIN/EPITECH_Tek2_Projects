/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** print_section
*/

#include "../include/objdump.h"

static void print_section_pt_four(size_t i, size_t sec_i,
    Elf32_Shdr *sects, unsigned char *file)
{
    size_t i_p = 0;

    printf("  ");
    for (i_p = 0 ; i_p < 16 ; i_p++) {
        if (i_p + i < sects[sec_i].sh_size)
            printf("%c", (char)(isprint(file[i_p + i]) ? file[i_p + i] : '.'));
        else
            printf(" ");
    }
    printf("\n");
}

static void print_section_pt_three(size_t i, size_t sec_i,
    Elf32_Shdr *sects, unsigned char *file)
{
    size_t i_p = 0;
    size_t i_p_two = 0;

    for (; i_p < 16 ;) {
        if (i_p_two == 8 || i_p_two == 17 || i_p_two == 26) {
            printf(" ");
            i_p_two += 1;
        } else if (i_p + i >= sects[sec_i].sh_size) {
            printf("  ");
            i_p_two += 2;
            i_p++;
        } else {
            printf("%02x", file[i_p + i]);
            i_p_two += 2;
            i_p++;
        }
    }
    print_section_pt_four(i, sec_i, sects, file);
}

static int check_size(int size)
{
    int n = 0;

    while (size / 10 > 0) {
        size = size / 10;
        n++;
    }
    if (n < 4)
        return (4);
    return (n);
}

static void print_section_pt_two(Elf32_Shdr *sects, int sec_i, void *file)
{
    size_t i = 0;

    for (; i < sects[sec_i].sh_size ; i += 16) {
        printf(" %0*lx ", check_size(
        sects[sec_i].sh_addr + sects[sec_i].sh_size), sects[sec_i].sh_addr + i);
        print_section_pt_three(i, sec_i, sects, file + sects[sec_i].sh_offset);
    }
}

void print_section_thirty(void *file)
{
    Elf32_Ehdr *header = file;
    Elf32_Shdr *sects = file + header->e_shoff;
    char *sec_pt = file + sects[header->e_shstrndx].sh_offset;
    int i = 1;

    for (; i < header->e_shnum ; i++) {
        if (strncmp(&(sec_pt[sects[i].sh_name]), ".strtab", 7) != 0 &&
        sects[i].sh_type != SHT_NOBITS && sects[i].sh_type != SHT_SYMTAB &&
        sects[i].sh_offset != sects[header->e_shstrndx].sh_offset) {
            printf("Contents of section %s:\n", &(sec_pt[sects[i].sh_name]));
            print_section_pt_two(sects, i, file);
        }
    }
}