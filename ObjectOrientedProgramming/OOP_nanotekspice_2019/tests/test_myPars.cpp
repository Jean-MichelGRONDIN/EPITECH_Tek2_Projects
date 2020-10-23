/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_myPars
*/

#include <criterion/criterion.h>
#include "../include/myPars.hpp"

// cl_mults_septrs

Test(cl_mults_chr, check_when_usual)
{
    std::string str = "1234aaaaaaaaaaaaaaaaaaabcdef1234";

    myPars::myStrMng::cl_mults_chr(str, 'a');
    cr_assert_str_eq(str.c_str(), "1234abcdef1234");
}

Test(cl_mults_chr, check_when_at_begining)
{
    std::string str = "111111111111111111234abcdef1234";

    myPars::myStrMng::cl_mults_chr(str, '1');
    cr_assert_str_eq(str.c_str(), "1234abcdef1234");
}

Test(cl_mults_chr, check_when_at_the_end)
{
    std::string str = "1234abcdef12344444444444";

    myPars::myStrMng::cl_mults_chr(str, '4');
    cr_assert_str_eq(str.c_str(), "1234abcdef1234");
}

Test(cl_mults_chr, check_when_everywhere_at_the_same_time)
{
    std::string str = "111111123411111111111abcdef1111111112341111111111";

    myPars::myStrMng::cl_mults_chr(str, '1');
    cr_assert_str_eq(str.c_str(), "12341abcdef12341");
}

Test(cl_mults_chr, check_when_nothing_to_clean)
{
    std::string str = "1234abcdef1234";

    myPars::myStrMng::cl_mults_chr(str, '1');
    cr_assert_str_eq(str.c_str(), "1234abcdef1234");
}

Test(cpy_cl_mults_chr, check_cpy_version_of_the_function)
{
    std::string str = "111111123411111111111abcdef1111111112341111111111";
    std::string res = "";

    res = myPars::myStrMng::cpy_cl_mults_chr(str, '1');
    cr_assert_str_eq(res.c_str(), "12341abcdef12341");
    cr_assert_str_neq(res.c_str(), str.c_str());
}

// cl_mults_septrs

Test(cl_mults_septrs, check_when_usual)
{
    std::string str = "ioabbc bcaio";

    myPars::myStrMng::cl_mults_septrs(str, "abc ");
    cr_assert_str_eq(str.c_str(), "ioaio");
}

Test(cl_mults_septrs, check_when_at_begining)
{
    std::string str = "ioaio abcbcbabcabc";

    myPars::myStrMng::cl_mults_septrs(str, "a bc");
    cr_assert_str_eq(str.c_str(), "ioaioa");
}

Test(cl_mults_septrs, check_when_at_the_end)
{
    std::string str = " abcbcbabcabcioaio";

    myPars::myStrMng::cl_mults_septrs(str, "abc ");
    cr_assert_str_eq(str.c_str(), "aioaio");
}

Test(cl_mults_septrs, check_when_everywhere_at_the_same_time)
{
    std::string str = "abcabca bcabcabcaio acabcabcbacbioacbacbca abcab";

    myPars::myStrMng::cl_mults_septrs(str, "abc ");
    cr_assert_str_eq(str.c_str(), "aioaioa");
}

Test(cl_mults_septrs, check_when_nothing_to_clean)
{
    std::string str = "ioaio";

    myPars::myStrMng::cl_mults_septrs(str, "abc ");
    cr_assert_str_eq(str.c_str(), "ioaio");
}

Test(cpy_cl_mults_septrs, check_cpy_version_of_the_function)
{
    std::string str = "abcabca bcabcabcaio acabcabcbacbioacbacbca abcab";
    std::string res = "";

    res = myPars::myStrMng::cpy_cl_mults_septrs(str, "abc ");
    cr_assert_str_eq(res.c_str(), "aioaioa");
    cr_assert_str_neq(res.c_str(), str.c_str());
}

// cl_in_line_cmmts

Test(cl_in_line_cmmts, check_when_usual_end_line_commment)
{
    std::string str = "toto = titi ***#   initialisation";

    myPars::myStrMng::cl_in_line_cmmts(str, '#', " *");
    cr_assert_str_eq(str.c_str(), "toto = titi");
}

Test(cl_in_line_cmmts, check_when_only_comment_in_line)
{
    std::string str = "# initialisation";

    myPars::myStrMng::cl_in_line_cmmts(str, '#', " *");
    cr_assert_str_eq(str.c_str(), "");
}

Test(cl_in_line_cmmts, check_when_only_comment_in_line_and_left_sprts)
{
    std::string str = " **  # initialisation";

    myPars::myStrMng::cl_in_line_cmmts(str, '#', " *");
    cr_assert_str_eq(str.c_str(), "");
}

Test(cl_in_line_cmmts, check_when_no_comments)
{
    std::string str = "toto = titi";

    myPars::myStrMng::cl_in_line_cmmts(str, '#', " *");
    cr_assert_str_eq(str.c_str(), "toto = titi");
}

Test(cl_in_line_cmmts, check_when_no_comments_and_sprts_at_the_end)
{
    std::string str = "toto = titi   *  * * *";

    myPars::myStrMng::cl_in_line_cmmts(str, '#', " *");
    cr_assert_str_eq(str.c_str(), "toto = titi");
}

Test(cpy_cl_in_line_cmmts, check_copy_version_of_the_function)
{
    std::string str = "toto = titi ***#   initialisation";
    std::string res = "";

    res = myPars::myStrMng::cpy_cl_in_line_cmmts(str, '#', " *");
    cr_assert_str_eq(res.c_str(), "toto = titi");
    cr_assert_str_neq(res.c_str(), str.c_str());
}

// myStrTab

Test(myStrTab, check_simple_test)
{
    std::string str = "oui\nnon";
    std::vector<std::string> res;

    res = myPars::myStrMng::myStrTab(str, "\n");
    cr_assert_eq(res.size(), 2);
    cr_assert_str_eq(res.back().c_str(), "non");
    res.pop_back();
    cr_assert_str_eq(res.back().c_str(), "oui");
    res.clear();
}

Test(myStrTab, check_septrs_at_beginning)
{
    std::string str = "\noui\nnon";
    std::vector<std::string> res;

    res = myPars::myStrMng::myStrTab(str, "\n");
    cr_assert_eq(res.size(), 2);
    cr_assert_str_eq(res.back().c_str(), "non");
    res.pop_back();
    cr_assert_str_eq(res.back().c_str(), "oui");
    res.clear();
}

Test(myStrTab, check_multiple_septrs)
{
    std::string str = "\noui\n\t\nnon";
    std::vector<std::string> res;

    res = myPars::myStrMng::myStrTab(str, "\n\t");
    cr_assert_eq(res.size(), 2);
    cr_assert_str_eq(res.back().c_str(), "non");
    res.pop_back();
    cr_assert_str_eq(res.back().c_str(), "oui");
    res.clear();
}

// myStrTabEmptyLine

Test(myStrTabEmptyLine, check_simple_test)
{
    std::string str = "oui\nnon";
    std::vector<std::string> res;

    res = myPars::myStrMng::myStrTabEmptyLine(str, "\n");
    cr_assert_eq(res.size(), 2);
    cr_assert_str_eq(res.back().c_str(), "non");
    res.pop_back();
    cr_assert_str_eq(res.back().c_str(), "oui");
    res.clear();
}

Test(myStrTabEmptyLine, check_septrs_at_beginning)
{
    std::string str = "\noui\nnon";
    std::vector<std::string> res;

    res = myPars::myStrMng::myStrTabEmptyLine(str, "\n");
    cr_assert_eq(res.size(), 3);
    cr_assert_str_eq(res.back().c_str(), "non");
    res.pop_back();
    cr_assert_str_eq(res.back().c_str(), "oui");
    res.pop_back();
    cr_assert_str_eq(res.back().c_str(), "");
    res.clear();
}

Test(myStrTabEmptyLine, check_multiple_septrs)
{
    std::string str = "\noui\nnon";
    std::vector<std::string> res;

    res = myPars::myStrMng::myStrTabEmptyLine(str, "\n");
    cr_assert_eq(res.size(), 3);
    cr_assert_str_eq(res.back().c_str(), "non");
    res.pop_back();
    cr_assert_str_eq(res.back().c_str(), "oui");
    res.pop_back();
    cr_assert_str_eq(res.back().c_str(), "");
    res.clear();
}