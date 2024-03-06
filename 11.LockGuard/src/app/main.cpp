#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>

using namespace std::literals;

std::mutex task_mutex;

void task(const std::string& str)
{
    for(int i = 0; i < 4; i++)
    {
        try {
            task_mutex.lock();
            std::cout << str[0] << str[1] << str[2]<<std::endl;
            throw std::exception();
            task_mutex.unlock();
            std::this_thread::sleep_for(10ms);
        }
        catch (std::exception& exc)
        {
            std::cout<<"Exception caught:"<<exc.what() <<"\n";
        }
    }
}

void task1(const std::string& str)
{
    for(int i = 0; i < 4; i++)
    {
        try {
           
            std::lock_guard<std::mutex> task1_lock_guard(task_mutex);
            std::cout << str[0] << str[1] << str[2]<<std::endl;
            throw std::exception();
            std::this_thread::sleep_for(10ms);
        }
        catch (std::exception& exc)
        {
            std::cout<<"Exception caught:"<<exc.what() <<"\n";
        }
    }
}
void DriverFaultyCode()
{
    std::thread thrd1(task, "abc");
    std::thread thrd2(task, "def");
    std::thread thrd3(task, "ghi");

    thrd1.join();
    thrd2.join();
    thrd3.join();
}

void DriverBugFreeCode()
{
    std::thread thrd1(task1, "abc");
    std::thread thrd2(task1, "def");
    std::thread thrd3(task1, "ghi");

    thrd1.join();
    thrd2.join();
    thrd3.join();
}

int main()
{
    //DriverFaultyCode();  
    DriverBugFreeCode();

    return 0;
}