/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** symbols
*/

#include "../include/ftrace.h"

Elf_Scn * get_symbol_section_tab(Elf *elf_file, GElf_Shdr *sec_head_tab)
{
    Elf_Scn *ret = NULL;

    while ((ret = elf_nextscn(elf_file, ret)) != NULL) {
        gelf_getshdr(ret, sec_head_tab);
        if (sec_head_tab->sh_type == SHT_SYMTAB)
            return (ret);
    }
    return (NULL);
}

static ftrace_t *print_entering_function(ftrace_t *vars,
    GElf_Shdr sec_head_tab, GElf_Sym tmp_symbol)
{
    printf("Entering function %s at = 0x%lx\n", elf_strptr(vars->elf_file,
        sec_head_tab.sh_link, tmp_symbol.st_name), tmp_symbol.st_value);
    vars->func_list = add_new_elem(elf_strptr(vars->elf_file,
        sec_head_tab.sh_link, tmp_symbol.st_name), vars->func_list);
    return (vars);
}

void search_in_sec_tab_symbol(ftrace_t *vars, unsigned int addres)
{
    GElf_Shdr sec_head_tab;
    Elf_Scn *sect_tab = get_symbol_section_tab(vars->elf_file, &sec_head_tab);
    Elf_Data *data;
    int max;
    int i = 0;
    GElf_Sym tmp_symbol;

    if (sect_tab == NULL) {
        fprintf(stderr, "Error no section head tab found when asked\n");
        return;
    }
    data = elf_getdata(sect_tab, NULL);
    max = sec_head_tab.sh_size / sec_head_tab.sh_entsize;
    while (i < max) {
        gelf_getsym(data, i, &tmp_symbol);
        if (addres == tmp_symbol.st_value) {
            vars = print_entering_function(vars, sec_head_tab, tmp_symbol);
        }
        i++;
    }
}

void print_all_symbols(ftrace_t *vars)
{
    GElf_Shdr sec_head_tab;
    Elf_Scn *sect_tab = get_symbol_section_tab(vars->elf_file, &sec_head_tab);
    Elf_Data *data;
    int max;
    int i = 0;
    GElf_Sym tmp_symbol;

    if (sect_tab == NULL) {
        fprintf(stderr, "Error no section head tab found when asked\n");
        return;
    }
    data = elf_getdata(sect_tab, NULL);
    max = sec_head_tab.sh_size / sec_head_tab.sh_entsize;
    while (i < max) {
        gelf_getsym(data, i, &tmp_symbol);
        printf("Syscall %s() = 0x%lx\n", elf_strptr(vars->elf_file,
            sec_head_tab.sh_link, tmp_symbol.st_name), tmp_symbol.st_value);
        i++;
    }
}