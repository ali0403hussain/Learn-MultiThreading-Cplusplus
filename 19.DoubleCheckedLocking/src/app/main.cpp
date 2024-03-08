#include <iostream>
#include <thread>
#include <mutex>

//Lazy initialization (single-threaded)
class Test {
public:
    void func() 
    {
        std::cout << "Lazy Initialization\n ";
    }
};

class Test1 {
public:
    Test1()
    {
        std::cout << "Test constructor called\n";
    }
    void func() 
    {
        std::cout << "Lazy Initialization from Test1\n ";
    }
};

Test *ptest = nullptr;                  //variable to be lazily initialized
Test1 *ptest1 = nullptr;

std::mutex mut;

std::once_flag ptest1_flag;             //The flag stores synchronization data

void process()
{
    if(!ptest)                          //First time variable has been used
    {
        std::lock_guard lck_gurd(mut);
        ptest = new Test;               //Initialize it
    }
    ptest->func();                      //use ptest
    
}

void process1()
{
    if(!ptest)                          //First time variable has been used
    {
        std::lock_guard lck_gurd(mut);

        if(!ptest)
            ptest = new Test;               //Initialize it
    }
    ptest->func();                      //use ptest
    
}

void process2()
{
    //Pass a callable object which performs the initialization
    std::call_once(ptest1_flag, [](){
        ptest1 = new Test1;
        });
    ptest1->func();
}

void process3()
{
    static Test1 ptest1;
    ptest1.func();
}

void DriverLazyInitialization()
{
    std::thread thrd1(process);
    std::thread thrd2(process);

    thrd1.join();
    thrd2.join();
}

void DriverDoubledChecked()
{
    std::thread thrd3(process1);
    std::thread thrd4(process1);

    thrd3.join();
    thrd4.join();
}

void DriverUsingCallOnce()
{
    std::thread thrd5(process2);
    std::thread thrd6(process2);

    thrd5.join();
    thrd6.join();
}

void DriverCallOnceDoubleChecked()
{
    std::thread thrd7(process3);
    std::thread thrd8(process3);

    thrd7.join();
    thrd8.join();
}

int main()
{
    DriverLazyInitialization();
    DriverDoubledChecked();
    DriverUsingCallOnce();
    DriverCallOnceDoubleChecked();

    return 0;
}