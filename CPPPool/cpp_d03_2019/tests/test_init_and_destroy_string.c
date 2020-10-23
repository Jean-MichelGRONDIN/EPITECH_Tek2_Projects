/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** test_init_and_destroy_string
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(string_init, check_basic_case)
{
    string_t    toto;
    char    str[] = "hey brother !!";

    string_init(&toto, "hey brother !!");
    cr_assert_str_eq(toto.str, str);
    string_destroy(&toto);
}

Test(string_destroy, check_basic_case)
{
    string_t    toto;

    string_init(&toto, "hey brother !!");
    string_destroy(&toto);
    cr_assert_eq(toto.str, NULL);
}