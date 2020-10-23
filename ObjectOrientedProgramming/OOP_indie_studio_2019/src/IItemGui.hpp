/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** IItemGui
*/

#ifndef IITEMGUI_HPP_
#define IITEMGUI_HPP_

class IItemGui {
    public:
        ~IItemGui() = default;
        virtual void onEvent() = 0;

    protected:
    private:
};

#endif /* !IITEMGUI_HPP_ */
