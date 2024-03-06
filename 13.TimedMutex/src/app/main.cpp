#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std::literals;

std::timed_mutex task_mutex;

void task1_timedMutex()
{
    std::cout << "Task1 trying to lock the mutex\n";
    task_mutex.lock();
    std::cout << "Task1 locks the mutex\n";
    std::this_thread::sleep_for(10s);
    std::cout << "Task1 unlocks the mutex\n";
    task_mutex.unlock();
}

void task2_timedMutex()
{
    std::this_thread::sleep_for(50ms);
    std::cout << "Task2 trying to lock the mutex\n";

    //Trying for 1s to lock the mutex
    while(!task_mutex.try_lock_for(1s))
    {
        std::cout << "Task2 could not lock the mutex\n";
    }
    std::cout << "Task2 has locked the mutex\n";
    std::this_thread::sleep_for(2s);
    std::cout << "Task2 unlock the mutex\n";
    task_mutex.unlock();
}

void task3_timedMutex()
{
    std::this_thread::sleep_for(10ms);
    std::cout << "Task3 trying to lock the mutex\n";
    auto deadline = std::chrono::system_clock::now() + 800ms;
    //Trying until deadline to lock the mutex
    while(!task_mutex.try_lock_until(deadline))
    {
        deadline = std::chrono::system_clock::now() + 800ms;
        std::cout << "Task3 could not lock the mutex\n";
    }
    std::cout << "Task3 has locked the mutex\n";
    std::this_thread::sleep_for(3s);
    std::cout << "Task3 unlock the mutex\n";
    task_mutex.unlock();
}

void task4_lock_guard()
{
    std::cout << "Task4 trying to lock the mutex\n";
    std::lock_guard<std::timed_mutex> lck_guard(task_mutex);
    std::cout << "Task4 locks the mutex\n";
    std::this_thread::sleep_for(10s);
    std::cout << "Task4 unlocks the mutex\n";
}

void task5_lock_guard()
{
    std::this_thread::sleep_for(50ms);
    std::cout << "Task5 trying to lock the mutex\n";

    std::unique_lock<std::timed_mutex> uniq_lck(task_mutex, std::defer_lock);
    //if std::defer_lock in above line is not used then there will be dead lock because 
    //in above line lock the mutex and then in the below line locks mutex again
    //Trying for 1s to lock the mutex
    while(!uniq_lck.try_lock_for(1s))
    {
        std::cout << "Task5 could not lock the mutex\n";
    }
    std::cout << "Task5 has locked the mutex\n";
    std::this_thread::sleep_for(2s);
    std::cout << "Task5 unlock the mutex\n";
}

void TimedMutexDriver()
{
    std::thread thrd1(task1_timedMutex);
    std::thread thrd2(task2_timedMutex);
    std::thread thrd3(task3_timedMutex);

    thrd1.join();
    thrd2.join();
    thrd3.join();
}

void TimedUniqueMutexDrive()
{
    std::thread thrd4(task4_lock_guard);
    std::thread thrd5(task5_lock_guard);

    thrd4.join();
    thrd5.join();

}

int main()
{
    TimedMutexDriver();
    TimedUniqueMutexDrive();

    return 0;
}