#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std::literals;

std::mutex mut1;
std::mutex mut2;

void funcA()
{
    std::cout << "Thread A trying to lock mutex 1\n";
    std::lock_guard<std::mutex> lck_gurd(mut1);
    std::cout << "Thread A locks mutex 1\n";
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread A trying to lock mutex 2\n";
    std::lock_guard<std::mutex> lck_gurd2(mut2);
    std::cout << "Thread A locks mutex 2\n";
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread A release all its locks\n";
}

void funcB()
{
    std::cout << "Thread B trying to lock mutex 2\n";
    std::lock_guard<std::mutex> lck_gurd(mut2);
    std::cout << "Thread B locks mutex 2\n";
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread B trying to lock mutex 1\n";
    std::lock_guard<std::mutex> lck_gurd2(mut1);
    std::cout << "Thread B locks mutex 1\n";
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread B release all its locks\n";
}

void funcB1()
{
    std::cout << "Thread B trying to lock mutex 1\n";
    std::lock_guard<std::mutex> lck_gurd(mut1);
    std::cout << "Thread B locks mutex 1\n";
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread B trying to lock mutex 2\n";
    std::lock_guard<std::mutex> lck_gurd2(mut2);
    std::cout << "Thread B locks mutex 2\n";
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread B release all its locks\n";
}

void DriverDeadlockOccurs()
{
    std::thread thrd1(funcA);
    std::thread thrd2(funcB);

    thrd1.join();
    thrd2.join();
}

void DriverDeadlockFix()
{
    std::thread thrd3(funcA);
    std::thread thrd4(funcB1);

    thrd3.join();
    thrd4.join();
}

int main()
{
    //DriverDeadlockOccurs();
    DriverDeadlockFix();

    return 0;
}