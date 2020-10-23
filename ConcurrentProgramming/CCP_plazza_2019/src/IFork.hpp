/*
** EPITECH PROJECT, 2020
** interface
** File description:
** fork
*/

#ifndef IFORK_HPP_
#define IFORK_HPP_


class IFork {
    public:
        IFork();
        virtual ~IFork();
        virtual int getId() const = 0;
        virtual int getStatus() const = 0;
        virtual int DoFork() = 0;
        virtual void QuitProcess(int) const =  0;

    protected:

    private:
};

#endif /* !IFORK_HPP_ */
