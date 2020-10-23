/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy()
{
    this->_type = BASIC_TOY;
    this->_name = "toy";
    this->_picture = Picture();
    this->_error = Error();
    this->_error.type = Toy::Error::ErrorType::UNKNOWN;
}

Toy::Toy(int type, std::string name, const std::string file)
{
    this->_type = type;
    this->_name = name;
    this->_picture = Picture(file);
    this->_error = Error();
    this->_error.type = Toy::Error::ErrorType::UNKNOWN;
}

Toy::Toy(const Toy &obj)
{
    this->_type = obj._type;
    this->_name = obj._name;
    this->_picture = Picture(obj._picture);
    this->_error = *new Toy::Error;
    this->_error.type = Toy::Error::ErrorType::UNKNOWN;
}

Toy::~Toy()
{
}

int Toy::getType() const
{
    return (this->_type);
}

std::string Toy::getName() const
{
    return (this->_name);
}

void Toy::setName(std::string name)
{
    this->_name = name;
}


bool Toy::setAscii(const std::string file)
{
    bool res = this->_picture.getPictureFromFile(file);
    if (res == false)
        this->_error.type = Toy::Error::ErrorType::PICTURE;
    return (res);
}

std::string Toy::getAscii() const
{
    return (this->_picture.data);
}

void Toy::speak(std::string statement)
{
    std::cout << this->_name << " \"" << statement << "\"" << std::endl;
}

Toy &Toy::operator<<(std::string str)
{
    this->_picture.data = str;
    return (*this);
}

bool Toy::speak_es(std::string statement)
{
    (void)statement;
    this->_error.type = Toy::Error::ErrorType::SPEAK;
    return (false);
}

Toy::Error::Error()
{
}

Toy::Error::~Error()
{
}

std::string Toy::Error::what()
{
    if (this->type == PICTURE)
        return ("bad new illustration");
    if (this->type == SPEAK)
        return ("wrong mode");
    return ("");
}

std::string Toy::Error::where()
{
    if (this->type == PICTURE)
        return ("setAscii");
    if (this->type == SPEAK)
        return ("speak_es");
    return ("");
}

Toy::Error Toy::getLastError()
{
    return (this->_error);
}

std::ostream &operator<<(std::ostream &s, const Toy &obj)
{
    s << obj.getName() << std::endl << obj.getAscii() << std::endl;
    return (s);
}