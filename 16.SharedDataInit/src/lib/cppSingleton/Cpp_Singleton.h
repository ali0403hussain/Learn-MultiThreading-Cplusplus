#ifndef _CPP_SINGLETON_H_INCLUDED
#define _CPP_SINGLETON_H_INCLUDED

#include <iostream>

class SingletonC {
public:
    //Copy and Move operators are deleted
    SingletonC(const SingletonC&) = delete;
    SingletonC& operator=(const SingletonC&) = delete;
    SingletonC(SingletonC&&) = delete;
    SingletonC& operator=(SingletonC&&) = delete;

    SingletonC() {std::cout << "Iniializing Singleton Cpp 11\n";}
};

//Function to obtain the Singleton object
SingletonC& get_SingletonC();

#endif