/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** Encryption
*/

#ifndef ENCRYPTION_HPP_
#define ENCRYPTION_HPP_

#include <iostream>
#include "IEncryptionMethod.hpp"

class Encryption : public IEncryptionMethod {
	public:
		explicit Encryption(IEncryptionMethod &encryptionMethod,
        void (IEncryptionMethod::*func)(char));
		~Encryption();
        void operator()(char c);
        static void encryptString(IEncryptionMethod &encryptionMethod,
            std::string const &toEncrypt) override;
        static void decryptString(IEncryptionMethod &encryptionMethod,
            std::string const &toDecrypt) override;

	protected:
	private:
        IEncryptionMethod &_encrypt_method;
        void (IEncryptionMethod::*_func)(char);
};

#endif