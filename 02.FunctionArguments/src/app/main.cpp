#include <iostream>
#include <thread>

using namespace std;

/*********************************************************
 * std::thread object owns the arguments
 * - lvalue arguments are passed by value
 * - rvalue arguments are passed by move
 * Using reference wrapper
*********************************************************/

/**
 * @brief Thread function with arguments
 * 
 * @param str 
 */
void ThreadSpeak(string str)
{
    cout << str ;
}

/**
 * @brief To pass by move we must provide rvalue
 * The argument must have a move constructor
 * 
 * @param str 
 */
void ThreadSpeak1(string &&str)
{
    cout << str ;
}

/**
 * @brief To pass by reference
 * Use reference wrapper
 * 
 * @param str 
 */
void ThreadSpeak2(string &str)
{
    cout << str ;
    str = "Hello Passing reference argument modified\n";
}

int main()
{
    //Passing lvalue argument
    /*
    thread thrd1(ThreadSpeak, "Hello Passing l value\n");
    thrd1.join();
    */

    //Passing rvalue argument
    /*
    string strthread {"Hello Passing rvalue\n"};
    thread thrd1(ThreadSpeak1, move(strthread));
    thrd1.join();
    std::cout <<"Is strthread empty :"<< (strthread.empty() ? "Yes" : "No") <<std::endl;
    */

    //Using Reference argument
    /*
    string strthread {"Hello Passing reference argument\n"};
    thread thrd1(ThreadSpeak2, ref(strthread));
    thrd1.join();
    cout << strthread ;
    */

    //Using Lambda expression by passing values
    
    string strthread {"Hello from Thread Using Lambda by passing values\n"};
    thread thrd1(
        [](string str){ 
                cout <<str ;
                str = "Hello from Thread Using Lambda by passing values modified\n";
            },strthread);
    thrd1.join();
    cout << strthread ;

    //Using Lambda expression Capture by reference
    /*
    string strthread {"Hello from Thread Using Lambda Capture by ref\n"};
    thread thrd1(
        [&strthread] {
            cout << strthread;
            strthread = "Hello from Thread Using Lambda Capture by ref modified\n";
        });
    thrd1.join();
    cout << strthread ;
    */

    return 0;
}