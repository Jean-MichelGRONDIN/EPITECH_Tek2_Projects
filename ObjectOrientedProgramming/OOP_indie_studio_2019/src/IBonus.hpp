#ifndef IBONUS_HPP_
#define IBONUS_HPP_

#include <memory>
#include <list>
#include <irrlicht.h>

class Player;

class IBonus {
public:
    virtual ~IBonus() = default;
    virtual void addBonusTo(std::shared_ptr<Player>) = 0;
};

#endif /* !IBONUS_HPP_ */
