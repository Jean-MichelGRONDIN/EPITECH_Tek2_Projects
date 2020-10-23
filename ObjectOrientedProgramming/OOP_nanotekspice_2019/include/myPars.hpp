/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** myPars
*/

#ifndef MYPARS_HPP_
#define MYPARS_HPP_

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

namespace myPars {
    class myStrMng {
        public:
            // clear multiple suscesive chars
            static void cl_mults_chr(std::string &s, const char c);
            static std::string cpy_cl_mults_chr(std::string s,
                const char c);
            // clear coment's on lines, find them by a given char and clean sperarators left before them
            static void cl_in_line_cmmts(std::string &s,
                const char comment_s_char, const std::string seprts);
            static std::string cpy_cl_in_line_cmmts(std::string s,
                const char comment_s_char, const std::string seprts);
            // clear multiple suscesive separator in a string, separators gieven
            static void cl_mults_septrs(std::string &s, const std::string septrs);
            static std::string cpy_cl_mults_septrs(std::string s,
                const std::string septrs);
            // return a array of string from a string by cutting by words, with all possible separators given
            static std::vector<std::string> myStrTab(const std::string &s,
                const std::string septrs);
            static std::vector<std::string> myStrTabEmptyLine(const std::string &s,
                const std::string septrs);
            // return true if this char is a digtal
            static bool is_digit(const char c);
            // return true if this string is made of digit only
            static bool is_number(const std::string &str);
    };
}

#endif