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
            ALIEN,
            BUZZ,
            WOODY
        };
		explicit Toy();
		explicit Toy(int type, std::string name, const std::string file);
		explicit Toy(const Toy &obj);
		~Toy();
        int getType() const;
        std::string getName() const;
        void setName(std::string name);
        bool setAscii(const std::string file);
        std::string getAscii() const;
        virtual void speak(std::string statement);
		Toy &operator<<(std::string str);

	protected:
        std::string _name;
        int _type;
        Picture _picture;
	private:
};

std::ostream &operator<<(std::ostream &s, const Toy &obj);

#endif