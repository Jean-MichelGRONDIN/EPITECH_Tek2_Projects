/*
** EPITECH PROJECT, 2020
** CCP
** File description:
** Plazza
*/

#include "plazza.hpp"
#include "Fork.hpp"

Plazza::Plazza(int ac, char** av)
{
    FileVector();
    if (ac != 4) {
        std::cerr << "bad arguments" << std::endl;
        exit(84);
    }
    _mul = atof(av[1]);
    _nb = atoi(av[2]);
    _msTime = atoi(av[3]);
    if (_mul == 0.0 || _mul < 0) {
        std::cerr << "Multiplier error" << std::endl;
        exit(84);
    }
    if (_nb <= 0) {
        std::cerr << "number of cooks error" << std::endl;
        exit(84);
    }
    if (_msTime <= 0) {
        std::cerr << "milliseconds error" << std::endl;
        exit(84);
    }
    std::cout << _mul << ' ' << _nb << ' ' << _msTime << std::endl;
    this->_manager = new kitchenManager(this->_mul, this->_nb, this->_msTime);
}

Plazza::~Plazza()
{
    delete this->_manager;
}

std::vector<std::string> Plazza::explode(std::string &s, char delim)
{
    std::vector<std::string> result;
    if (s[0] == ' ')
        s.erase(0, 1);
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim);)
        result.push_back(std::move(token));
    return result;
}

std::vector<std::string> Plazza::parseInput(std::string &input)
{
    std::vector<std::string> t;
    if (std::cin.eof() == 1) {
        remove("fifoFile.txt");
        exit(0);
    }
    t = Plazza::explode(input, ';');
    return (t);
}

void Plazza::FileVector()
{
    _NameP.push_back("regina");
    _NameP.push_back("americana");
    _NameP.push_back("margarita");
    _NameP.push_back("fantasia");
    _SizeP.push_back("S");
    _SizeP.push_back("M");
    _SizeP.push_back("L");
    _SizeP.push_back("XL");
    _SizeP.push_back("XXL");
}

bool Plazza::CheckInputName(std::vector<std::string> parse)
{
    for (long unsigned int j = 0; j < _NameP.size(); j++) {
        if (strcasecmp(parse[0].c_str(), _NameP[j].c_str()) == 0)
            return true;
    }
    std::cerr << ERR_INVAL << std::endl;
    return false;
}

bool Plazza::CheckInputSize(std::vector<std::string> parse)
{
    for (long unsigned int j = 0; j < _SizeP.size(); j++)
        if (strcasecmp(parse[1].c_str(), _SizeP[j].c_str()) == 0)
            return true;
    std::cerr << ERR_SIZE << std::endl;
    return false;
}

static bool strIsDigit(std::string str)
{
    for (long unsigned int i = 0; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return (false);
        }
    }
    return (true);
}

bool Plazza::CheckInputNum(std::vector<std::string> parse)
{
    if ((parse[2].length() == 2 || parse[2].length() == 3) &&
    std::tolower(parse[2][0]) == 'x' &&
    strIsDigit(parse[2].substr(1, parse[2].length() - 1)) == true)
        return true;
    std::cerr << ERR_QTY << std::endl;
    return false;
}

bool Plazza::CheckInput(std::vector<std::string> parse)
{
    std::vector<std::string> stock;
    for (long unsigned int i = 0; i < parse.size(); i++){

        stock = explode(parse[i], ' ');
        if (stock.size() == 3 && CheckInputName(stock) && CheckInputSize(stock)
        && CheckInputNum(stock))
            return true;
        if (stock.size() != 3) {
            std::cerr << ERR_CMD << std::endl;
        }
        stock.clear();
    }
    return false;
}

std::string Plazza::getInput()
{
    std::string order;
    std::vector<std::string> check;

    do {
        std::cout << "What is your order ?" << std::endl;
        std::getline(std::cin, order);
        check = parseInput(order);
    } while (!CheckInput(check));
    return (order);
}

void Plazza::reception()
{
    std::string order;
    std::vector<std::string> order_vector;
    std::vector<std::string> all_commands_vector;
    long unsigned int i = 0;

    std::cout << "Hi, Welcome to Epizza. We\'re sorry but due to our success, there\'ll be a bit of a wait." << std::endl;
    order = this->getInput();
    while (std::cin.eof() != 1) {
        try {
            order_vector = this->parseInput(order);
            for (i = 0 ; i < order_vector.size() ; i++) {
                for (int j = 0; j < atoi(explode(order_vector[i], ' ')[2].substr(1,
                    explode(order_vector[i], ' ')[2].length()).c_str()); j++) {
                        all_commands_vector.push_back(explode(order_vector[i], ' ')[0] + ' ' + explode(order_vector[i], ' ')[1] );
                    }
            }
            this->_manager->processThisOrder(all_commands_vector);
            all_commands_vector.clear();
        } catch(MyError const &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        order = this->getInput();
    }
}