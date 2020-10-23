/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <string>
#include <iostream>

class Droid {
    public:
        Droid(std::string id = "");
        ~Droid();
        Droid(const Droid &other);
        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string *getStatus() const;
        void setId(std::string id);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);
        bool operator==(const Droid &other) const;
        bool operator!=(const Droid &other) const;
        void operator<<(size_t &to_load);
        void operator=(const Droid &other);

    private:
        std::string _id;
        size_t _energy;
        const size_t _attack;
        const size_t _toughness;
        std::string *_status;
};

std::ostream &operator<<(std::ostream &s, const Droid &d);


#endif