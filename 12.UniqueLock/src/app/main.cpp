#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>

using namespace std::literals;

std::mutex task_mutex;

void task1(const std::string& str)
{
    for(int i = 0; i < 4; i++)
    {
        std::unique_lock<std::mutex> task1_unique_lock(task_mutex);
        std::cout << str[0] << str[1] << str[2]<<std::endl;
        task1_unique_lock.unlock();
        std::this_thread::sleep_for(10ms);
    } 
}

int main()
{
    std::thread thrd1(task1, "abc");
    std::thread thrd2(task1, "def");
    std::thread thrd3(task1, "ghi");

    thrd1.join();
    thrd2.join();
    thrd3.join();

    return 0;
}