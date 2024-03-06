#include "Cpp_Singleton.h"

SingletonC& get_SingletonC()
{
    static SingletonC single;
    return single;
}