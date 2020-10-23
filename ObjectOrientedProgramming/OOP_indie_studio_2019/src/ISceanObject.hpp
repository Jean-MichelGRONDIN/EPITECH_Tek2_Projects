/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** ISceanObject
*/

#ifndef ISCEANOBJECT_HPP_
#define ISCEANOBJECT_HPP_

class ISceanObject {
    public:
        virtual ~ISceanObject() = default;
        virtual void update() = 0;
    protected:
    private:
};

#endif /* !ISCEANOBJECT_HPP_ */
