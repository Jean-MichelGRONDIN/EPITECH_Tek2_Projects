/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** libLoader
*/

#ifndef LIBLOADER_HPP_
#define LIBLOADER_HPP_

#include "./Dll.hpp"
#include "./ILib.hpp"
#include "./IGame.hpp"
#include "./includes.hpp"

template<typename T>
class libLoader
{
    public:
        libLoader(std::string &path)
        {
            this->_dllLib = new Dll<T>(path);
            this->_lib = this->_dllLib->getFunc();
            this->_name = path.substr(path.find_last_of('/') + 1);
        }

        ~libLoader()
        {
            delete this->_lib;
            delete this->_dllLib;
        }
        Dll<T>  *getDllLib()
        {
            return (this->_dllLib);
        }
        T   *getlib()
        {
            return (this->_lib);
        }
        std::string getName()
        {
            return (this->_name);
        }
        static std::vector<std::string> getAllLibsNames(std::string path)
        {
            std::vector<std::string> list;
            std::string tmp;

            for (const auto & entry : std::filesystem::directory_iterator(path)) {
                tmp = entry.path();
                tmp = tmp.substr(tmp.find_last_of('.'));
                if (tmp.compare(".so") == 0) {
                    list.push_back(entry.path());
                }
            }
            return (list);
        }
        static std::vector<std::shared_ptr<libLoader<T>>> getAllThisFolderLibs(
            std::string path)
        {
            std::vector<std::string> libsNames = getAllLibsNames(path);
            std::vector<std::shared_ptr<libLoader<T>>> res;

            for (auto name : libsNames) {
                res.push_back(std::shared_ptr<libLoader<T>>(new libLoader<T>(name)));
            }
            return (res);
        }
    private:
        Dll<T> *_dllLib;
        T   *_lib;
        std::string _name;
};


#endif