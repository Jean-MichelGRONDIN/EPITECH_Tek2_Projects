/*
** EPITECH PROJECT, 2020
** Error
** File description:
** Plazza
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#define FIFO_FAILED "FIFO file creation failed"
#define FIFO_OPEN_FAILED "Cannot open FIFO file"
#define ERR_REMOVE "Remove file failed"
#define ERR_OPEN "Open failed"
#define ERR_WRITE "Write failed"
#define ERR_READ_FILE "Read error"
#define ERR_FORK "Fork failed"
#define FIFO_NAME "order"
#define ERR_INVAL "Invalid pizza name"
#define ERR_SIZE "Invalid pizza size"
#define ERR_QTY "Invalid quantity of pizza x1-99"
#define ERR_CMD "Invalid command"

#include <exception>
#include <iostream>

class MyError : public std::exception
{
    public:
        MyError(std::string);
        ~MyError();
        const char *what() const noexcept;

    private:
        std::string _message;
};

#endif /* !ERROR_HPP_ */
