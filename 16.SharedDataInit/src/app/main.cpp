#include <iostream>
#include <thread>
#include <vector>
#include "Classic_Singleton.h"
#include "Cpp_Singleton.h"

Singleton* Singleton::single = nullptr;

void task()
{
    Singleton* single = Singleton::get_Singleton();
    std::cout << single <<std::endl;
}

void task1()
{
    SingletonC& single = get_SingletonC();
    std::cout << &single <<std::endl;
}

void DriverClassic()
{
    std::vector<std::thread> threads;

    for(int i = 0; i < 10; i++)
        threads.push_back(std::thread(task));

    for(auto& thr : threads)
        thr.join();
}

void DriverCpp()
{
    std::vector<std::thread> threads1;

    for(int i = 11; i < 21; i++)
        threads1.push_back(std::thread(task1));

    for(auto& thr : threads1)
        thr.join();
}

int main()
{
    DriverClassic();
    DriverCpp();

    return 0;
}