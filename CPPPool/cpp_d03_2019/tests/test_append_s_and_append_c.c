/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** test_append_s_and_append_c
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(append_s, check_when_usual)
{
    string_t s;
    string_t c;

    string_init(&s, "toto");
    string_init(&c, "titi");
    s.append_s(&s, &c);
    cr_assert_str_eq(s.str, c.str);
}

Test(append_c, check_when_usual)
{
    string_t s;

    string_init(&s, "toto");
    s.append_c(&s, "titi");
    cr_assert_str_eq(s.str, "titi");
}