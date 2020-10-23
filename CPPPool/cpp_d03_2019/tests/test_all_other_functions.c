/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** test_all_other_functions
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(size, chack_when_usual)
{
    string_t s;

    string_init(&s, "toto");
    cr_assert_eq(s.size(&s), 4);
}

Test(size, chack_when_str_empty)
{
    string_t s;

    string_init(&s, "toto");
    s.clear(&s);
    cr_assert_eq(s.size(&s), 0);
}

Test(size, chack_when_str_null)
{
    string_t s;

    string_init(&s, "toto");
    string_destroy(&s);
    cr_assert_eq(s.size(&s), -1);
}

Test(compare_s, check_when_usual)
{
    string_t s;
    string_t c;

    string_init(&s, "toto");
    string_init(&c, "toto");
    cr_assert_eq(s.compare_s(&s, &c), 0);
}

Test(compare_c, check_when_usual)
{
    string_t s;

    string_init(&s, "toto");
    cr_assert_neq(s.compare_c(&s, "titi"), 0);
}

Test(copy, chack_when_str_null)
{
    string_t s;
    char *two = strdup("toto");

    string_init(&s, "ti");
    s.copy(&s, two, 2, 2);
    cr_assert_str_eq(two, "toti");
}

Test(c_str, chack_when_str_null)
{
    string_t s;

    string_init(&s, "toto");
    cr_assert_str_eq(s.c_str(&s), "toto");
}

Test(empty, check_when_str_not_empty)
{
    string_t s;

    string_init(&s, "toto");
    cr_assert_eq(s.empty(&s), 0);
}

Test(empty, check_when_str_is_empty)
{
    string_t s;

    string_init(&s, "toto");
    s.clear(&s);
    cr_assert_eq(s.empty(&s), 1);
}

Test(find_s, check_when_usual)
{
    string_t s;
    string_t c;

    string_init(&s, "tototitoti");
    string_init(&c, "ti");
    cr_assert_eq(s.find_s(&s, &c, 0), 4);
}

Test(find_c, check_when_usual)
{
    string_t s;

    string_init(&s, "tototitoti");
    cr_assert_eq(s.find_c(&s, "ti", 0), 4);
}

Test(find_c, check_when_pos_too_great)
{
    string_t s;

    string_init(&s, "tototitoti");
    cr_assert_eq(s.find_c(&s, "ti", 55), -1);
}

Test(find_c, check_when_no_match)
{
    string_t s;

    string_init(&s, "tototitoti");
    cr_assert_eq(s.find_c(&s, "vi", 4), -1);
}

Test(find_c, check_when_to_match_is_too_long)
{
    string_t s;

    string_init(&s, "tototitoti");
    cr_assert_eq(s.find_c(&s, "tiiiiiiiiiiiiiiiiiiii", 4), -1);
}

Test(insert_s, check_when_usual)
{
    string_t s;
    string_t c;

    string_init(&s, "tototitoti");
    string_init(&c, "ti");
    s.insert_s(&s, 2, &c);
    cr_assert_str_eq(s.str, "totitotitoti");
}

Test(insert_c, check_when_usual)
{
    string_t s;

    string_init(&s, "tototitoti");
    s.insert_c(&s, 2, "ti");
    cr_assert_str_eq(s.str, "totitotitoti");
}

Test(to_int, check_when_usual)
{
    string_t s;

    string_init(&s, "44");
    cr_assert_eq(s.to_int(&s), 44);
}