/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** Cesar
*/

#ifndef CESAR_HPP_
#define CESAR_HPP_

#include <iostream>
#include "IEncryptionMethod.hpp"

class Cesar : public IEncryptionMethod {
	public:
		Cesar();
		~Cesar();
        void encryptChar(char plainchar);
		void decryptChar(char cipherchar);
		void reset();

	protected:
	private:
        int _shift_crypt;
        int _shift_uncrypt;
};

#endif