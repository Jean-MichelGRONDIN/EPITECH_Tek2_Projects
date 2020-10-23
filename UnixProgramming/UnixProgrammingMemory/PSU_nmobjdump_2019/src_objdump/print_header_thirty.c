/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** print_header_thirty
*/

#include "../include/objdump.h"

static unsigned int get_flag(Elf32_Ehdr *header)
{
    unsigned int ret = 0;

    switch (header->e_type) {
    case ET_REL:
        ret = HAS_RELOC + HAS_SYMS;
        break;
    case ET_DYN:
        ret = HAS_SYMS + DYNAMIC + D_PAGED;
        break;
    case ET_EXEC:
        ret = EXEC_P + HAS_SYMS + D_PAGED;
        break;
    default:
        ret = BFD_NO_FLAGS;
        break;
    }
    return (ret);
}

static void print_format(Elf32_Ehdr *header)
{
    if (header->e_machine == EM_386) {
        printf("file format elf32-i386\n");
    } else if (header->e_machine == EM_X86_64) {
        printf("file format elf64-x86-64\n");
    }
}

static void print_architecture(Elf32_Ehdr *header)
{
    printf("architecture: ");
    if (header->e_machine == EM_386) {
        printf("i386, ");
    } else if (header->e_machine == EM_X86_64) {
        printf("i386:x86-64, ");
    }
}

static void print_flag(unsigned int flag)
{
    printf("flags 0x%08x:\n", flag);
    if (flag == HAS_RELOC + HAS_SYMS) {
        printf("HAS_RELOC, HAS_SYMS\n");
        return;
    }
    if (flag == HAS_SYMS + DYNAMIC + D_PAGED) {
        printf("HAS_SYMS, DYNAMIC, D_PAGED\n");
        return;
    }
    if (flag == EXEC_P + HAS_SYMS + D_PAGED) {
        printf("EXEC_P, HAS_SYMS, D_PAGED\n");
        return;
    }
}

int print_header_thirty(char const *path, void *file)
{
    Elf32_Ehdr *header = file;
    unsigned int flag = get_flag(header);

    if (flag == BFD_NO_FLAGS) {
        dprintf(2, "objdump: %s: File format not recognized\n", path);
        return (1);
    }
    printf("\n%s:\t", path);
    print_format(header);
    print_architecture(header);
    print_flag(flag);
    printf("start address 0x%016x\n\n", header->e_entry);
    return (0);
}