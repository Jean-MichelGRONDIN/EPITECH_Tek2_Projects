

#ifndef _DLL_HPP_
#define _DLL_HPP_

#include <dlfcn.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include "ILib.hpp"

template <typename T>
class Dll {
    public:
        Dll(std::string str)
        {
            T *(*pointer)();
            this->handle = dlopen(str.c_str(), RTLD_LAZY);
            pointer = (T * (*)()) dlsym(this->handle, "constuct");
            if (!pointer)
                std::cout << "stop" << std::endl;
            this->_func = pointer();
        }
        ~Dll()
        {
            dlclose(this->handle);
        }
        void *getHandle() const
        {
            return (this->handle);
        }
        T *getFunc() const
        {
            return (this->_func);
        }
    private :
        void *handle;
        T *_func;
};

#endif