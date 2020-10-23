/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** MyEventRecever
*/

#ifndef MYEVENTRECEVER_HPP_
#define MYEVENTRECEVER_HPP_

#include "IrrGui.hpp"
#include "IrrScean.hpp"
#include <memory>
#include "MySound.hpp"

class MyEventRecever : public irr::IEventReceiver{
    public:
        MyEventRecever(std::shared_ptr<IrrGui> irrGui, std::shared_ptr<IrrScean> irrScean);
        ~MyEventRecever();
        virtual bool OnEvent(const irr::SEvent& event) override;
    protected:
        std::shared_ptr<IrrGui> _irrGui;
        std::shared_ptr<IrrScean> _irrScean;
        MySound _sound;
    private:
};

#endif /* !MYEVENTRECEVER_HPP_ */
