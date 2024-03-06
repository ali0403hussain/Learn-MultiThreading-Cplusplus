# Mutex Lock Guard

## Problem with DriverFaultyCode()
* When the exception is thrown:
    * The destructor called for all objects in scope.
    * The program flow jumps into the catch handler
    * The unlock call is never executed
    * The mutex remains locked
* All other threads which are waiting to lock the mutex are blocked
* If main() is joined on these blocked threads
    * main() will be blocked as well
    * The entire program is blocked

## Drawbacks of std::mutex
* Calling lock() requires a corresponding call to unlock()
    * If not, the mutex will remains locked after the thread exits.
* unlock() must always be called. even if
    * There are multiple paths through the critical sections
    * An exception is thrown
* Relies on the programmer to get it right
* For these reasons, we donot normally use std::mutex directly

## Mutex Wrapper Classes
* The C++ library provides mutex wrapper classes.
    * Classes with a mutex object as a private member
    * Defined in <mutex>
* These use RAII idiom for managing resources
    * In this case the recourse is a lock on a mutex
    * The constructor locks the mutex
    * The destructor unlocks the mutex
* We create the wrapper class on stack
    * The mutex will always be unlocked when the object goes out of scope
    * Including when an exception is thrown

## std::lock_guard
* std::lock guard is a very basic wrapper
    * Has a constructor and destructor only
* The constructor takes a mutex onject as argument
    * Initializes its member from the argument
    * Locks it
* The destructor unlocks the mutex member.
* std::lock_guard is a template class
    * Template parameter is the type of the mutex
    * std::lock_guard<std::mutex> my_lock_guard(task_mutex)
* In C++17, the compiler can deduce the mutex's type
    *  std::lock_guard my_lock_guard(task_mutex)
* We dont nedd to explicity lock the mutex
* Create an std::lock_guard object
* Pass the mutex to its constructor