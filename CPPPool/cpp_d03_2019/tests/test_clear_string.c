/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** test_clear_string
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(clear, chack_when_usual)
{
    string_t s;

    string_init(&s, "toto");
    s.clear(&s);
    cr_assert_eq(s.str[0], '\0');
}