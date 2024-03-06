#include "Classic_Singleton.h"

//Static member function to obtain Singleton object
Singleton* Singleton::get_Singleton()
{
    if(single == nullptr)
        single = new Singleton;
    return single;
}

Singleton::~Singleton()
{
    delete single;
}