/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Victim
*/

#ifndef VICTIM_HPP_
#define VICTIM_HPP_

#include <string>
#include <iostream>

class Victim {
	public:
		Victim(std::string name);
		~Victim();
		std::string getname() const;
        void getPolymorphed() const;

	protected:
	private:
        std::string _name;
};

std::ostream &operator<<(std::ostream &s, Victim obj);

#endif