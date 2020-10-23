/*
** EPITECH PROJECT, 2020
** cpp
** File description:
** Materials
*/

#ifndef MATERIALS_HPP_
#define MATERIALS_HPP_

#include <iostream>

class Materials {
	public:
		Materials(const std::string &type);
		~Materials();

		/* GETTERS */
		std::string getType() const;

		/* SETTERS */

		/* OTHERS */
	protected:
	private:
		std::string _type;
};

#endif /* !MATERIALS_HPP_ */
