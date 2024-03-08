#include <iostream>
#include <thread>
#include <mutex>

class Test {
public:
    void func() {std::cout <<"Lazy Initialization Test\n";}
};

Test *ptest = nullptr;      //variable to be lazily initialized
std::mutex mut;

void process()
{
    std::unique_lock<std::mutex> uniq_lck(mut);
    if(!ptest) 
        ptest = new Test;   //Initialize it
    uniq_lck.unlock();
    ptest->func();          //Use it     
}

int main()
{
    //ptest->func();             //Pointer is empty we need to initialize it
    std::thread thrd(process);
    thrd.join();
    
    return 0;
}