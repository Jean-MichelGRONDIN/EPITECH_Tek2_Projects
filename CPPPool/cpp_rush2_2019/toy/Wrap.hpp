/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Wrap
*/

#ifndef WRAP_HPP_
#define WRAP_HPP_

#include <iostream>
#include <string>
#include "Object.hpp"

class Wrap {
	public:
        typedef enum {
            OPEN,
            CLOSE,
            NONE,
            EMPTY,
            FULL
        } Status;
        Status status;
		Wrap();
		~Wrap();
        virtual bool WrapMeThat(Object *obj);
        virtual bool isOpen();
        virtual bool isClose();
        virtual bool isWraped();
        void CloseMe();
        void OpenMe();
	protected:
        bool is_open;
        bool is_wrap;
        bool is_close;
        Object *object;
	private:
};

#endif /* !WRAP_HPP_ */
