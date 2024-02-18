#include <iostream>
#include <thread>

void Print(std::string str)
{
    for(auto alter: str)
        std::cout << alter <<"," ;
    std::cout << std::endl;
}

int main()
{
    std::thread thrd1(Print, "abcdefgh");
    std::thread thrd2(Print, "ijkl");
    std::thread thrd3(Print, "mnopqrstuv");

    thrd1.join();
    thrd2.join();
    thrd3.join();
    
    return 0;
}