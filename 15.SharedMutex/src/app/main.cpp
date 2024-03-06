#include <iostream>
#include <thread>
#include <chrono>
#include <shared_mutex>
#include <chrono>
#include <vector>

std::shared_mutex smutx;

int shared_data = 0;

void write(const int thd)
{
    std::lock_guard<std::shared_mutex> lck_gurd(smutx);
    std::cout << "Writer " <<thd <<" updating Value\n";
    //Start critical section
    ++shared_data;
    //End critical section
}

void read(const int thd)
{
    std::shared_lock<std::shared_mutex> lck_gurd(smutx);

    //Start critical section
    using namespace std::literals;
    std::cout << "Reader "<< thd << " Reading shared data : " << shared_data <<std::endl;
    std::this_thread::sleep_for(400ms);
    //End critical section
}

int main()
{
    std::vector<std::thread> threads;

    for(int i= 1; i < 11; ++i)
        threads.push_back(std::thread(read, i));

    threads.push_back(std::thread(write, 11));
    threads.push_back(std::thread(write, 12));

    for(int i= 13; i < 43; ++i)
        threads.push_back(std::thread(read, i));

    for(auto& thr : threads)
        thr.join();

    return 0;
}

