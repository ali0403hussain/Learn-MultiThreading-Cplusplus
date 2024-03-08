#include <iostream>
#include <thread>
#include <random>
#include <mutex>
#include <string>

//Thread-local random number engine
thread_local std::mt19937 mt_thread_local;

//Thread-global random number engine
std::mt19937 mt_thread_global;

std::mutex task_mutex;

void func_thread_local(const std::string& str)
{
    std::unique_lock<std::mutex> task1_unique_lock(task_mutex);
    for(auto alter : str)
        std::cout << alter ;
    std::cout << std::endl;
    std::uniform_real_distribution<double> dist(0,1);  //doubles in the range 0 to 1
    for(int i =0; i <10; i++)         //Generates 10 random numbers
        std::cout <<dist(mt_thread_local) <<",";
    std::cout << std::endl;
    task1_unique_lock.unlock();
}

void func_thread_global(const std::string& str)
{
    std::unique_lock<std::mutex> task1_unique_lock(task_mutex);
    for(auto alter : str)
        std::cout << alter ;
    std::cout << std::endl;
    std::uniform_real_distribution<double> dist(0,1);  //doubles in the range 0 to 1
    for(int i =0; i <10; i++)         //Generates 10 random numbers
        std::cout <<dist(mt_thread_global) <<",";
    std::cout << std::endl;
    task1_unique_lock.unlock();
}

int main()
{
    std::cout<<"Thread local causes local values so every thread has its own local values that must me same\n";
    std::thread thrd1(func_thread_local, "Thread 1's random values:");
    std::thread thrd2(func_thread_local, "Thread 2's random values:");

    thrd1.join();
    thrd2.join();

    std::cout<<"Thread global causes global values so every thread has its own unique values...\n", 
    std::cout<<"first 10 values by 1st thread and the next 10 values by the other thread\n";
    std::thread thrd3(func_thread_global, "Thread 3's random values:");
    std::thread thrd4(func_thread_global, "Thread 4's random values:");

    thrd3.join();
    thrd4.join();

    return 0;
}