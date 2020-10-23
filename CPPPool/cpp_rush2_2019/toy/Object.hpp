/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <string>
#include <iostream>

class Object {
	public:
		Object();
		~Object();
        virtual void isTaken();
        virtual bool isWraped();
        void setWrap(bool);
	protected:
        std::string _title;
        bool is_wrap;
	private:
};

Object **MyUnitTests();

#endif /* !OBJECT_HPP_ */
