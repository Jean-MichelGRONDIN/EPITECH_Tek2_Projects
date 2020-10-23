/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** Parser
*/

#include "Parser.hpp"

void Parser::feed(std::string const &str)
{
    size_t i = 0;

    if (!this->_numbers.empty())
        this->_operators.push('+');
    while (i < str.size())
        i += this->my_parser(str, i);
    while (!this->_operators.empty()) {
        this->_numbers.push(this->do_the_operation(this->_operators.top()));
        this->_operators.pop();
    }
}

size_t Parser::my_parser(std::string const &str, size_t i)
{
    size_t ret = 1;

    switch (str[i]) {
    case '+': case '-': case '*': case '/': case '%' : case '(':
        this->_operators.push(str[i]);
        break;
    case ')':
        while (this->_operators.top() != '(') {
            this->_numbers.push(this->do_the_operation(this->_operators.top()));
            this->_operators.pop();
        }
        this->_operators.pop();
        break;
    case ' ':
        break;
    default:
        this->_numbers.push(std::stoi(str.substr(i), &ret));
    }
    return (ret);
}

int Parser::result() const
{
    if (this->_numbers.empty())
        return (0);
    return (this->_numbers.top());
}

int Parser::do_the_operation(char op)
{
    int v_right;
    int v_left;

    v_right = this->_numbers.top();
    this->_numbers.pop();
    v_left = this->_numbers.top();
    this->_numbers.pop();
    switch (op)
    {
    case '+':
        return (v_left + v_right);
    case '-':
        return (v_left - v_right);
    case '*':
        return (v_left * v_right);
    case '/':
        return (v_left / v_right);
    case '%':
        return (v_left % v_right);
    default:
        throw std::exception();
    }
}

void Parser::reset()
{
    for(;!this->_numbers.empty();)
        this->_numbers.pop();
    for(;!this->_operators.empty();)
        this->_operators.pop();
}