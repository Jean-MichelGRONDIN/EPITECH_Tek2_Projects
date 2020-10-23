/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"
#include <string>
#include <iostream>
#include <fstream>

class Toy {
	public:
        enum {
            BASIC_TOY,
            ALIEN
        };
		Toy();
		Toy(int type, std::string name, const std::string file);
		Toy(const Toy &obj);
		~Toy();
        int getType() const;
        std::string getName() const;
        void setName(std::string name);
        bool setAscii(const std::string file);
        std::string getAscii() const;

	protected:
	private:
        std::string _name;
        int _type;
        Picture _picture;
};

#endif