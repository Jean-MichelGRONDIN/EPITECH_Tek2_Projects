/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** OneTime
*/

#ifndef ONETIME_HPP_
#define ONETIME_HPP_

#include <iostream>
#include "IEncryptionMethod.hpp"

class OneTime : public IEncryptionMethod {
	public:
		explicit OneTime(std::string key);
		~OneTime();
        void encryptChar(char plainchar);
		void decryptChar(char cipherchar);
		void reset();

	protected:
	private:
        std::string _key;
        size_t _index_crypt;
        size_t _index_uncrypt;
};

#endif