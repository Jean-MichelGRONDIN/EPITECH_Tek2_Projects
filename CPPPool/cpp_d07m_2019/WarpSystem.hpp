/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

#include <string>
#include <iostream>

namespace WarpSystem
{
    class QuantumReactor
    {
        public:
            QuantumReactor();
            ~QuantumReactor();
            bool isStable ();
            void setStability(bool stability);

        private:
            bool _stability;
    };
    class Core
    {
        public:
            Core(QuantumReactor *coreReactor);
            ~Core();
            QuantumReactor *checkReactor();
        private:
            QuantumReactor *_coreReactor;
    };
}

#endif