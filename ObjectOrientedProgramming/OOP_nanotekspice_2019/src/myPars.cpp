/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** myPars
*/

#include "../include/myPars.hpp"

void myPars::myStrMng::cl_in_line_cmmts(std::string &s,
    const char comment_s_char, const std::string seprts)
{
    size_t ret;

    ret = s.find(comment_s_char, 0);
    if (ret == 0) {
        s = "";
        return;
    }
    if (ret != -1)
        s = s.substr(0, ret - 1);
    std::reverse(s.rbegin(), s.rend());
    ret = s.find_first_not_of(seprts);
    if (ret == -1) {
        s = "";
        return;
    }
    s = s.substr(ret);
    std::reverse(s.rbegin(), s.rend());
}

std::string myPars::myStrMng::cpy_cl_in_line_cmmts(std::string s,
    const char comment_s_char, const std::string seprts)
{
    size_t ret;

    ret = s.find(comment_s_char, 0);
    if (ret == 0) {
        s = "";
        return (s);
    }
    if (ret != -1)
        s = s.substr(0, ret - 1);
    std::reverse(s.rbegin(), s.rend());
    ret = s.find_first_not_of(seprts);
    if (ret == -1) {
        s = "";
        return (s);
    }
    s = s.substr(ret);
    std::reverse(s.rbegin(), s.rend());
    return (s);
}

void myPars::myStrMng::cl_mults_chr(std::string &s, const char c)
{
    int i = 0;
    int n;
    std::string tmp;

    while (i != s.length()) {
        if (s[i] == c && i + 1 != s.length() && s[i + 1] == c) {
            tmp = s.c_str();
            n = tmp.find_first_not_of(c, i);
            tmp = (n != tmp.length() && n != -1)
            ? tmp.substr(n, tmp.length()) : "";
            s = s.substr(0, i) + c + tmp;
            i = 0;
        } else
            i++;
    }
}

std::string myPars::myStrMng::cpy_cl_mults_chr(std::string s, const char c)
{
    int i = 0;
    int n;
    std::string tmp;

    while (i != s.length()) {
        if (s[i] == c && i + 1 != s.length() && s[i + 1] == c) {
            tmp = s.c_str();
            n = tmp.find_first_not_of(c, i);
            tmp = (n != tmp.length() && n != -1)
            ? tmp.substr(n, tmp.length()) : "";
            s = s.substr(0, i) + c + tmp;
            i = 0;
        } else
            i++;
    }
    return (s);
}

void myPars::myStrMng::cl_mults_septrs(std::string &s, const std::string septrs)
{
    int i = 1;

    if (septrs.length() > 1) {
        while (i != septrs.length()) {
            std::replace(s.rbegin(), s.rend(), septrs[i], septrs[0]);
            i++;
        }
    }
    myPars::myStrMng::cl_mults_chr(s, septrs[0]);
}

std::string myPars::myStrMng::cpy_cl_mults_septrs(std::string s, const std::string septrs)
{
    int i = 1;

    if (septrs.length() > 1) {
        while (i != septrs.length()) {
            std::replace(s.rbegin(), s.rend(), septrs[i], septrs[0]);
            i++;
        }
    }
    return (myPars::myStrMng::cpy_cl_mults_chr(s, septrs[0]));
}

std::vector<std::string> myPars::myStrMng::myStrTab(const std::string &s,
    const std::string septrs)
{
    std::string cpyed = myPars::myStrMng::cpy_cl_mults_septrs(s, septrs);
    std::istringstream split(cpyed);
    std::vector<std::string> tab;

    for (std::string each; std::getline(split, each, septrs[0]);) {
        if (each.length() > 0)
            tab.push_back(each);
    }
    return (tab);
}

std::vector<std::string> myPars::myStrMng::myStrTabEmptyLine(const std::string &s,
    const std::string septrs)
{
    std::string cpyed = myPars::myStrMng::cpy_cl_mults_septrs(s, septrs);
    std::istringstream split(cpyed);
    std::vector<std::string> tab;

    for (std::string each; std::getline(split, each, septrs[0]); tab.push_back(each));
    return (tab);
}

bool myPars::myStrMng::is_digit(const char c)
{
    return (std::isdigit(c));
}

bool myPars::myStrMng::is_number(const std::string &str)
{
    return (std::for_each(str.rbegin(), str.rend(), is_digit));
}