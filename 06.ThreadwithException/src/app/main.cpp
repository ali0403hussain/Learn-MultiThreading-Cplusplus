#include <iostream>
#include <thread>

using namespace std::literals;

class thread_guard{
    std::thread thrd;
    public:
        explicit thread_guard(std::thread&& thr)                    //Move Constructor
        : thrd(std::move(thr)){

        }
        ~thread_guard()
        {
            if(thrd.joinable())
                thrd.join();
        }
        thread_guard(const thread_guard&) = delete;                 //Copy constructor should be deleted
        thread_guard& operator=(const thread_guard&) = delete;      //Operator oveloaded should be deleted
};

/**
 * @brief Entry point Function for Threads
 * 
 * @param str 
 */
void hello(std::string str)
{
    std::this_thread::sleep_for(2s);
    std::cout << "Hello, From " << str <<std::endl;
}

/**
 * @brief Method to show Thread Exception Problem
 * 
 * @param str
 * @param Excep 
 */
void ThreadExceptionProblem(std::string str, bool throwExcep)
{
    try
    {
        std::thread thrd(hello, str);
        if(throwExcep)
            throw std::exception();
        std::cout << "Thread have ID                :" << thrd.get_id() <<std::endl;
        std::cout << "Thread have Native Handle     :" << thrd.native_handle() <<std::endl;
        thrd.join();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception Caught :" <<e.what() << '\n';
    }
    
}

/**
 * @brief Method to show Thread Exception Problem
 * 
 * @param str
 * @param Excep 
 */
void ThreadExceptionProblemBadSolution(std::string str, bool throwExcep)
{
    std::thread thrd(hello, str); 

    try
    {
        if(throwExcep)
            throw std::exception();
        std::cout << "Thread have ID                :" << thrd.get_id() <<std::endl;
        std::cout << "Thread have Native Handle     :" << thrd.native_handle() <<std::endl;
        thrd.join();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception Caught :" <<e.what() << '\n';
        thrd.join();
    }
    
}

/**
 * @brief Thread Exception Method solution using RAII idiom
 * * The destructor are called in reverse order
 *      - The thread_guard's destructor is called first.
 *      - If necessary, it calls thr.join() and waits for the execution thread to finish
 *      - The thread_guard's std::thread member is then destroyed
 *      - It is not associated with the execution thread
 *      - Its destructor does not call std::terminate()
 * * This applies in normal execution
        - And when an execution is thrown
 * @param str 
 * @param Excep 
 */
void ThreadExceptionProblemGoodSolution(std::string str, bool throwExcep)
{
    try
    {
        std::thread thrd(hello, str);
        thread_guard tguard{std::move(thrd)};
        if(throwExcep)
            throw std::exception();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception Caught: "<< e.what() << '\n';
    }
}
int main()
{
    bool ThowException = false ;  //if this will set to true then the code will break
    ThreadExceptionProblem("Thread 1:", ThowException);

    //Solution which is bad because of using thread.join() two times
    ThreadExceptionProblemBadSolution("Thread 2:", ThowException);
    ThowException = true;
    ThreadExceptionProblemBadSolution("Thread 3:", ThowException);

    //Solution Good using RAII idiom
    ThreadExceptionProblemGoodSolution("Thread 4:", ThowException);
    ThowException = true;
    ThreadExceptionProblemGoodSolution("Thread 5:", ThowException);

    return 0;
}
