# Mutex Internally Synchronized Class
* Multiple threads accessing the same memory location
    * With modification
    * Must be synchronized to prevent a data race
* C++ STL containers needs to be externally synchronized
    * e.g by locking a mutex before calling a member function
* Our own types can provide internal synchronization
    * An std::mutex as a data member
    * The member functions lock the mutex before accessing the class's data.
    * They unlock the mutex after accesssing the class's data
## Wrapper for std::vector
* std::vector act as a memory location
    * We need to lock a mutex before calling its member functions.
* Alternatively wecould write an internally sychronized wrapper for it
* A class which
    * Has std::vector data member
    * Has std::mutex data member
    * Mmeber functions which lock the mutex before accessing the std::vector
    * Then unlock the mutex after accessing it
* An internally synchronized class