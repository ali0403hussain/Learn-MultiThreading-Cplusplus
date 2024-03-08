# Double Checked Locking
```ruby
//Lazy initialization (single-threaded)
class Test {
    //....
public:
    void func() {......}
};
Test *ptest = nullptr;  //variable to be lazily initialized

void process()
{
    if(!ptest)          //First time variable has been used
    {
        std::lock_guard lck_gurd(mut);
        ptest = new Test;   //Initialize it
    }
    //use ptest
}
```
* In the above Example in process if(!ptest) checks ptest.
* Then locks the mutex
* Another thread could interleave between these operations
    * Race condition
        - Thread A checks ptest, which is null
        - Thread B checks ptest, which is null
        - Thread B locks the mutex
        - Thread B initialize the ptest
        - Thread B unlocks the mutex
        - Thread A locks the mutex
        - Thread A initialize ptest
## Is that Not Enough ?
* There tis still a race condition
    - ptest = new Test;
* The initialization of ptest involves several operations
    * Allocate enough memory to store a Test object
    * Construct a Test object in the memory
    * Store the address in ptest
* C++ allows these to be performed in a different order, e.g
    * Allocate enough memory to store a Test object.
    * Store the address in ptest
    * Construct a Test object in the memory.
## Undefined behaviour
* Thread A checks ptest and locks the mutex
* Thread A allocates the memory and assigns to ptest
    * ptest = new sizeof(Test);
* However, it has not yet called the constructor
* Thread B checks ptest and it is not null
* Thread B does not lock the mutex
* Thread B jumps out of the if statement
* Thread B calls a member function of an uninitialized object
    * Undefined behaviour
## std::call_once
* One way to solve this is to use std::call_once()
    * A given function is only called once
    * It is done in one thread
    * The thread cannot be interrupted until the function call completes.
* We use it with a global instance of std::once_flag
* We pass the instance and the function to std::call_once()

## Doubled-checked Locking with std::call_once
* Threadsafe
* Less overhead than a mutex
* C++17 defines the order of initialization
    * Allocate enough memory to store a Test object
    * Construct a Test object in the memory
    * Store the address in ptest
        - ptest = new Test;
* Double-checked locking no longer cause a data race
## Conclusion
* Four ways to do thread safe lazy initialization
    * Naive use of a mutex
    * Use std::call_once()
    * Double-checked locking with a C++17 compiler or later
    * Meyers singleton with a static local variable
* Recommendations
    * Use Meyers singleton, if ptest is not required outside the function
    * Otherwise use std::call_once().
