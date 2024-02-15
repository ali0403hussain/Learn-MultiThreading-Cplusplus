#include <iostream>
#include <thread>

/*! Hello Test class */
class Hello{
    private:
        std::string msg;
    public:

        /**
         * @brief Operator Overloaded
         * 
         * @param str 
         */
        void operator()(std::string str)
        {
            msg = str;
        }

        /**
         * @brief No args Constructor
         * 
         */
        Hello()
        {
            std::cout << "No args Constructor\n";
        }

        /**
         * @brief Overloaded Constructor
         * 
         * @param str 
         */
        Hello(std::string str)
        : msg{str}{
            std::cout << "Overloaded Constructor\n";
        }

        /**
         * @brief Destructor
         * 
         */
        ~Hello()
        {
            std::cout << "Destructor\n";
        }

        /**
         * @brief Get Method
         * 
         */
        void print()
        {
            std::cout <<msg <<std::endl;
        }
};

/**
 * @brief Function 
 * 
 * @param str 
 */
void function(std::string str)
{
    std::cout << str << std::endl;
}

int main()
{
    //Using Function Objects
    std::thread thrd1(Hello(),"From Thread function object");

    //Using Function Pointers
    //std::thread thrd2(function,"From Thread using Function pointer");

    // Using Lambda expression
    /*auto print = [](std::string str)
    {
        std::cout << str << std::endl;
    };
    std::thread thrd3(print,"From Thread using Lambda expression");*/

    //Using Member Function
    /*Hello Hello_obj("From Thread using member function");
    std::thread thrd4(&Hello::print, &Hello_obj);*/

    thrd1.join();
    //thrd2.join();
    //thrd3.join();
    //thrd4.join();
    
    return 0;
}