#include <iostream>
#include <thread>

using namespace std::literals;

/**
 * @brief Entry point Function for Threads
 * 
 * @param str 
 */
void hello(std::string str)
{
    std::this_thread::sleep_for(3s);
    std::cout << "Hello, From " << str <<std::endl;
}

/**
 * @brief Function that joins thread with entry point i.e hello function
 * 
 * @param str 
 * @return std::thread 
 */
std::thread EntryPoint(std::string str)
{
    std::thread thrd(hello, str);
    return thrd;
}

/**
 * @brief Method to Join Thread and get Thread info
 * This is done by Move 
 * @param thrd 
 */
void ThreadJoin(std::thread&& thrd)
{
    std::cout << "Thread have ID                :" << thrd.get_id() <<std::endl;
    std::cout << "Thread have Native Handle     :" << thrd.native_handle() <<std::endl;
    thrd.join();
    std::cout << "Thread handle after Execution :" << thrd.native_handle() <<std::endl;
}


int main()
{
    std::cout << "Main Thread has ID            :" << std::this_thread::get_id() <<std::endl;
    std::thread thr1 = EntryPoint("Thread 1:");
    ThreadJoin(std::move(thr1));

    return 0;
}