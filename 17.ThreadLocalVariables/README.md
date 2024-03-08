# Thread-local Variables
* C++ support thread-local variables
    - Same as static and global variables.
    - However, there is a separate object for each thread.
    - With a static variable, there is a single object which is shared by all threads.
* We use the thread_local keyword to declare them.
* Global variables or at namespace scope
* Data members of a class
* Local variables in a function
## Thread local variables lifetimes
* Global and namespace scope
    * Always constructed at or before the first use in a translation unit
    * It is safe to use them in dynamic libraries (DLLs)
* Local variables
    * Initlalized in the same way as static local variables
* In all cases
    * Destroyed when the thread comletes its execution
## Example
* We can make a random number engine thread-local
    * This gives each thread its own object
* This ensure that each thread generates the same sequence
    * Useful for testing
```ruby
//Thread-local random number engine
std::thread_local mt19937 mt;

void func()
{
    std::uniform_real_distribution<double> dist(0,1);  //doubles in the range 0 to 1

    for(int i =0; i <10; i++) //Generates 10 random numbers
        std::cout <<dist(mt) <",">;
}
```