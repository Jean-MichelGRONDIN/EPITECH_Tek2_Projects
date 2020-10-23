/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** test_at_string
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(at, check_when_usual)
{
    string_t s;
    size_t pos = 0;

    string_init(&s, "toto");
    cr_assert_eq(s.at(&s, pos), 't');
}