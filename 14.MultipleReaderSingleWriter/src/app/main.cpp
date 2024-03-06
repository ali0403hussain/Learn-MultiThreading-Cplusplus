#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

std::mutex mutx;

int shared_data = 0;

void write(const int thd)
{
    std::lock_guard<std::mutex> lck_gurd(mutx);
    std::cout << "Writer " <<thd <<" updating Value\n";
    //Start critical section
    ++shared_data;
    //End critical section
}

void read(const int thd)
{
    //std::lock_guard<std::mutex> lck_gurd(mutx);

    //Start critical section
    using namespace std::literals;
    std::cout << "Reader "<< thd << " Reading shared data : " << shared_data <<std::endl;
    std::this_thread::sleep_for(100ms);
    //End critical section
}

int main()
{
    std::vector<std::thread> threads;

    for(int i= 1; i < 21; ++i)
        threads.push_back(std::thread(read, i));

    threads.push_back(std::thread(write, 21));
    threads.push_back(std::thread(write, 22));

    for(int i= 23; i < 43; ++i)
        threads.push_back(std::thread(read, i));

    for(auto& thr : threads)
        thr.join();

    return 0;
}