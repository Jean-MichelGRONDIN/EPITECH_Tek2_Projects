/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <stack>
#include <stdexcept>

class Parser {
	public:
        void feed(const std::string &);
        int result() const;
        void reset();

	protected:
	private:
        size_t my_parser(std::string const &str, size_t i);
        int do_the_operation(char op);
        std::stack<char> _operators;
        std::stack<int> _numbers;
};

#endif