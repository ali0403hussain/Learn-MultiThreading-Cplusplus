#ifndef _SINGLETON_H_INCLUDED
#define _SINGLETON_H_INCLUDED

#include <iostream>

class Singleton {
    //Pointer to unique instance
    static Singleton *single;

    //Private constructor
    Singleton() {std::cout << "Initializing Singleton Classic\n";}

public:
    //Copy and Move operators are deleted
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    //static member function to obtain Singleton object
    static Singleton* get_Singleton();
    ~Singleton();
};

#endif