/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture()
{
    this->data = "";
}

Picture::Picture(const std::string &file)
{
    std::string s;
    std::ifstream file_content;
    int a = 0;

    file_content.open(file.data());
    a = file_content.is_open();
    if(a == 0) {
        this->data = "ERROR";
    } else {
        while(getline(file_content, s)) {
        this->data += s + '\n';
        }
        file_content.close();
    }
}

Picture::Picture(const Picture &obj)
{
    this->data = obj.data;
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::string s;
    std::ifstream file_content;
    int a = 0;

    file_content.open(file.data());
    a = file_content.is_open();
    if(a == 0) {
        this->data = "ERROR";
        return (false);
    }
    while(getline(file_content, s)) {
        this->data += s + '\n';
    }
    file_content.close();
    return (true);
}