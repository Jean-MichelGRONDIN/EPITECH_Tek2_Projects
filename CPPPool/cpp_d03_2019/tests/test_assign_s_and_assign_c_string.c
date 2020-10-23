/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** test_assign_s_and_assign_c_string
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(assign_s, check_when_usual)
{
    string_t s;
    string_t c;

    string_init(&s, "toto");
    string_init(&c, "titi");
    s.assign_s(&s, &c);
    cr_assert_str_eq(s.str, c.str);
}

Test(assign_c, check_when_usual)
{
    string_t s;

    string_init(&s, "toto");
    s.assign_c(&s, "titi");
    cr_assert_str_eq(s.str, "titi");
}