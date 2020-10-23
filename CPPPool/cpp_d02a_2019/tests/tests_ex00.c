/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** test_double_list_get_size
*/

#include "../double_list.h"
#include <criterion/criterion.h>
#include <stdio.h>

double_list_t   put_all_in_list(int n)
{
    double_list_t list = NULL;
    int i = 0;

    while (i != n) {
        double_list_add_elem_at_front(&list, (double)i);
        i++;
    }
    return (list);
}

Test(double_list_get_size, when_size_is_four)
{
    double_list_t list = put_all_in_list(4);

    cr_assert_eq(double_list_get_size(list), 4);
}

Test(double_list_get_size, when_size_is_1)
{
    double_list_t list = put_all_in_list(1);

    cr_assert_eq(double_list_get_size(list), 1);
}

Test(double_list_get_size, when_size_is_zero)
{
    double_list_t list = NULL;

    cr_assert_eq(double_list_get_size(list), 0);
}

Test(double_list_add_elem_at_front, check_when_add_one)
{
    double_list_t list = put_all_in_list(1);

    double_list_add_elem_at_front(&list, (double)85);
    cr_assert_eq(list->value, 85.0);
    list = list->next;
    cr_assert_eq(list->value, 0.0);
}

Test(double_list_add_elem_at_front, check_when_list_is_null)
{
    double_list_t list = NULL;

    double_list_add_elem_at_front(&list, (double)85);
    cr_assert_eq(list->value, 85.0);
}

Test(double_list_add_elem_at_back, check_when_add_one)
{
    double_list_t list = put_all_in_list(1);

    double_list_add_elem_at_back(&list, (double)21);
    cr_assert_eq(list->value, 0.0);
    cr_assert_eq(list->next->value, 21.0);
}

Test(double_list_add_elem_at_back, check_when_list_is_null)
{
    double_list_t list = NULL;

    double_list_add_elem_at_back(&list, (double)21);
    cr_assert_eq(list->value, 21.0);
}

Test(double_list_add_elem_at_position, check_when_add_at_position_two)
{
    double_list_t list = put_all_in_list(4);

    double_list_add_elem_at_position(&list, (double)21, 1);
    cr_assert_eq(list->value, 3.0);
    list = list->next;
    cr_assert_eq(list->value, 21.0);
    list = list->next;
    cr_assert_eq(list->value, 2.0);
    list = list->next;
    cr_assert_eq(list->value, 1.0);
    list = list->next;
    cr_assert_eq(list->value, 0.0);
}

Test(double_list_add_elem_at_position, check_when_add_at_last_elem)
{
    double_list_t list = put_all_in_list(4);

    double_list_add_elem_at_position(&list, (double)21, 3);
    cr_assert_eq(list->value, 3.0);
    list = list->next;
    cr_assert_eq(list->value, 2.0);
    list = list->next;
    cr_assert_eq(list->value, 1.0);
    list = list->next;
    cr_assert_eq(list->value, 21.0);
    list = list->next;
    cr_assert_eq(list->value, 0.0);
}

Test(double_list_add_elem_at_position, check_when_add_at_end)
{
    double_list_t list = put_all_in_list(4);

    double_list_add_elem_at_position(&list, (double)21, 4);
    cr_assert_eq(list->value, 3.0);
    list = list->next;
    cr_assert_eq(list->value, 2.0);
    list = list->next;
    cr_assert_eq(list->value, 1.0);
    list = list->next;
    cr_assert_eq(list->value, 0.0);
    list = list->next;
    cr_assert_eq(list->value, 21.0);
}

Test(double_list_add_elem_at_position, check_when_add_at_first_elem)
{
    double_list_t list = put_all_in_list(4);

    double_list_add_elem_at_position(&list, (double)21, 0);
    cr_assert_eq(list->value, 21.0);
    list = list->next;
    cr_assert_eq(list->value, 3.0);
    list = list->next;
    cr_assert_eq(list->value, 2.0);
    list = list->next;
    cr_assert_eq(list->value, 1.0);
    list = list->next;
    cr_assert_eq(list->value, 0.0);
}

Test(double_list_del_elem_at_front, check_when_2)
{
    double_list_t list = put_all_in_list(2);

    double_list_del_elem_at_front(&list);
    cr_assert_eq(list->value, 0.0);
    list = list->next;
    cr_assert_eq(list, NULL);
}

Test(double_list_del_elem_at_front, check_when_list_is_null)
{
    double_list_t list = NULL;

    double_list_del_elem_at_front(&list);
    cr_assert_eq(list, NULL);
}

Test(double_list_del_elem_at_back, check_when_list_is_3)
{
    double_list_t list = put_all_in_list(3);

    double_list_del_elem_at_back(&list);
    cr_assert_eq(list->value, 2.0);
    list = list->next;
    cr_assert_eq(list->value, 1.0);
    list = list->next;
    cr_assert_eq(list, NULL);
}

Test(double_list_del_elem_at_back, check_when_list_is_1)
{
    double_list_t list = put_all_in_list(1);
    int ret = double_list_del_elem_at_back(&list);

    cr_assert_eq(list, NULL);
    cr_assert_eq(ret, true);
}

Test(double_list_del_elem_at_back, check_when_list_is_null)
{
    double_list_t list = NULL;
    int ret = double_list_del_elem_at_back(&list);

    cr_assert_eq(list, NULL);
    cr_assert_eq(ret, false);
}

Test(double_list_del_elem_at_position, check_when_add_at_position_two)
{
    double_list_t list = put_all_in_list(4);
    int ret = double_list_del_elem_at_position(&list, 1);

    cr_assert_eq(list->value, 3.0);
    list = list->next;
    cr_assert_eq(list->value, 1.0);
    list = list->next;
    cr_assert_eq(list->value, 0.0);
    list = list->next;
    cr_assert_eq(list, NULL);
    cr_assert_eq(ret, true);
}

Test(double_list_del_elem_at_position, check_when_add_at_last_elem)
{
    double_list_t list = put_all_in_list(4);
    int ret = double_list_del_elem_at_position(&list, 3);

    cr_assert_eq(list->value, 3.0);
    list = list->next;
    cr_assert_eq(list->value, 2.0);
    list = list->next;
    cr_assert_eq(list->value, 1.0);
    list = list->next;
    cr_assert_eq(list, NULL);
    cr_assert_eq(ret, true);
}

Test(double_list_del_elem_at_position, check_when_add_at_end)
{
    double_list_t list = put_all_in_list(4);
    int ret = double_list_del_elem_at_position(&list, 4);

    cr_assert_eq(list->value, 3.0);
    list = list->next;
    cr_assert_eq(list->value, 2.0);
    list = list->next;
    cr_assert_eq(list->value, 1.0);
    list = list->next;
    cr_assert_eq(list->value, 0.0);
    list = list->next;
    cr_assert_eq(list, NULL);
    cr_assert_eq(ret, false);
}

Test(double_list_del_elem_at_position, check_when_add_at_first_elem)
{
    double_list_t list = put_all_in_list(4);
    int ret = double_list_del_elem_at_position(&list, 0);

    cr_assert_eq(list->value, 2.0);
    list = list->next;
    cr_assert_eq(list->value, 1.0);
    list = list->next;
    cr_assert_eq(list->value, 0.0);
    list = list->next;
    cr_assert_eq(list, NULL);
    cr_assert_eq(ret, true);
}

Test(double_list_get_elem_at_position, check_value_first)
{
    double_list_t list = put_all_in_list(4);
    double ret = double_list_get_elem_at_position(list, 0);

    cr_assert_eq(ret, 3.0);
}

Test(double_list_get_elem_at_position, check_value_midle)
{
    double_list_t list = put_all_in_list(4);
    double ret = double_list_get_elem_at_position(list, 1);

    cr_assert_eq(ret, 2.0);
}

Test(double_list_get_elem_at_position, check_value_last)
{
    double_list_t list = put_all_in_list(4);
    double ret = double_list_get_elem_at_position(list, 3);

    cr_assert_eq(ret, 0.0);
}

Test(double_list_get_elem_at_position, check_when_list_is_null)
{
    double_list_t list = NULL;
    double ret = double_list_get_elem_at_position(list, 2);

    cr_assert_eq(ret, 0.0);
}

Test(double_list_get_elem_at_position, check_when_nb_greater_than_list_size)
{
    double_list_t list = put_all_in_list(4);
    double ret = double_list_get_elem_at_position(list, 7);

    cr_assert_eq(ret, 0.0);
}