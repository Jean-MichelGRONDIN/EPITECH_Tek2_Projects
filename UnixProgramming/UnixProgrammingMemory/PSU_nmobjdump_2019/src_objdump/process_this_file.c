/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** process_this_file
*/

#include "../include/objdump.h"

static int print_like_fs(void *file, char const *path)
{
    size_t bits = 64;

    if (print_header(path, bits, file) != 0)
        return (1);
    if (bits == 64)
        print_section(file);
    else
        print_section_thirty(file);
    return (0);
}

int process_this_file(char const *path)
{
    int fd = open(path, O_RDONLY);
    struct stat buffer;
    void *file = NULL;
    int ret = 0;

    if (fd == -1) {
        dprintf(2, "objdump: \'%s\': No such file\n", path);
        return (1);
    }
    lstat(path, &buffer);
    file = mmap(NULL, buffer.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (file) {
        ret = print_like_fs(file, path);
    } else {
        ret = 1;
    }
    close(fd);
    return (ret);
}