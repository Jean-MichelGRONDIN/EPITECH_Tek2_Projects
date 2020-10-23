/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include <iostream>

class Character {
	public:
		Character(const std::string &name, int level);
		~Character();
        const std::string &getName() const;
        int getLvl() const;
        int getPv() const;
        int getPower() const;
        int CloseAttack();
        int RangeAttack();
        void Heal();
        void RestorePower();
        void TakeDamage(int damage);

	protected:
	private:
        std::string _name;
        int _level;
        int _pv;
        int _power;
        int _energy;
};

#endif