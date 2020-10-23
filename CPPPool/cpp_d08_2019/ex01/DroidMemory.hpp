/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <string>

class DroidMemory {
	public:
		DroidMemory();
		~DroidMemory();
        size_t getFingerprint();
        size_t getExp();
        void setFingerprint(size_t Fingerprint);
        void setExp(size_t Exp);
        void operator<<(size_t added_xp);
        void operator+=(DroidMemory &other);
        void operator+=(size_t added_xp);

	protected:
	private:
        size_t _Fingerprint;
        size_t _Exp;
};

void operator>>(size_t added_xp, DroidMemory &dm);


#endif