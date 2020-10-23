/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** main
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

float fahren_to_cels(float f)
{
    float c;

    c = 5.0/9.0 * (f - 32);
    return (c);
}

float cels_to_fahren(float c)
{
    float f;

    f = c * (9.0/5.0) + 32;
    return (f);
}

void my_convert_temp(void)
{
    std::string type;
    float res;
    float n;

    std::cin>>n>>type;
    if(type == "Celsius") {
        res = cels_to_fahren(n);
        type = "Fahrenheit";
    } else if(type == "Fahrenheit") {
        res = fahren_to_cels(n);
        type = "Celsius";
    } else
        std::cerr<<"invalid input !!!"<<std::endl;
    std::cout<<std::setfill(' ')<<std::setw(16)
    <<std::setiosflags(std::ios::fixed)
    <<std::setprecision(3)<<res<<std::setfill(' ')
    <<std::setw(16)<<type<<std::endl;
}

int main(void)
{
    my_convert_temp();
    return (0);
}