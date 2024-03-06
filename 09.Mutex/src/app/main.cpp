#include <iostream>
#include <thread>
#include <mutex>

using namespace std::literals;

//Global mutex object
std::mutex task_mutex;

void Print(std::string str)
{
    task_mutex.lock();

    for(auto alter: str)
        std::cout << alter <<"," ;
    std::cout << std::endl;

    task_mutex.unlock();
}

void func()
{
    std::cout << "Task trying to lock the mutex\n";
    while(!task_mutex.try_lock())
    {
        std::cout <<"Could not Lock mutex\n";
        std::this_thread::sleep_for(100ms);
    }
    std::cout <<"Mutex Locked Successful\n";
    std::cout <<"Hello from Task\n";
    for(int alter = 0; alter < 100; alter++)
        std::cout << alter << std::endl;
    task_mutex.unlock();
}

int main()
{
    std::thread thrd1(Print, "abcd");
    std::thread thrd(func);
    std::thread thrd2(Print, "efg");
    std::thread thrd3(Print, "hijklm");

    thrd1.join();
    thrd.join();
    thrd2.join();
    thrd3.join();
    
    return 0;
}