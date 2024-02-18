#include <iostream>
#include <thread>

void hello()
{
    static int thread_count = 1;
    std::cout << "Hello from thread " 
              << thread_count++
              << " With ID: "
              << std::this_thread::get_id()
              << std::endl;
}

int main()
{
    std::thread thrd1(hello);
    std::thread thrd2(hello);
    std::thread thrd3(hello);

    thrd1.join();
    thrd2.join();
    thrd3.join();
    
    return 0;
}