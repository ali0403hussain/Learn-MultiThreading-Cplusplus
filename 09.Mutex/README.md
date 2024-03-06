# Mutex
* Mutual Exclusion object
* We can use a mutex to implement locking
* A mutex has two stages
    - Locked
   * - Unlocked
* Exclusion
    - The mutex is used to exclude threads from the critical section
* Mutual
    - The threads agree to respect the mutex
* Locking
    - If the mutex is unlocked, a thread can enter the critical section.
    - If the mutex is locked, no thread can enter until it becomes unlocked.
    - A thread locks the mutex when it enters the critical section.
    - A thread unlocks the mutex when it leaves the critical section

## Critical Sections
If there are two trains using single track. One must be wait and stop for the other to pass.
* A region of code
* Must only be executed by one thread at a time
* Usually when accessing a shared resource
    - Shared data, network connection, hardware device
* The thread enters the critical section
    -  It starts executing the code in the critical section.
* The thread leaves the critical section
    - It has executed all the code in the critical section
## Linking Protocol
* One thread can enter the critical section
    - All the other threads are "locked out"
    - Only this thread can execute the code in the critical section
* The thread leaves the critical section
    - One of the other thread can now enter it.

## Thread Synchronization with Mutex
* Some threads A,B,C .. wish to enter a critical section
    - Thread A lock the Mutex
    - Thread A enters the critical section
    - Thread B, C,... wait until they can lock the mutex
    - Thread A leaves the critical section
    - Thread A unlocks the mutex
    - One of the threads B,C,... can now lock the mutex and enter the critical section
* The threads are synchronized
    - They canot interleave when they execute in the critical section
    - There is no data race
* Unlocking a mutex "publishes" any changes
    - Thread A modifies shared data
    - The new value is now available to other threads
    - It will be seen by the next thread which accesses the shared data
* A thread locks the mutex
    - It acquires exclusive access to the critical section
* The thread unlocks the mutex
    - It release exculsive access to the critical section
    - It also release the result of any modifications
    - The next thread that locks the mutex will acquire these results
* These acquire release semantics impose ordering on the threads
    - There is no data race
    - The shared data is always in a consistent state
## Mutex Class
* C++ 11 standard library provides an std::mutex class
    - Defined in <mutex>
* A mutex object must be visible in all task functions which uses it
* It must also be defined outside the task function
    - Global/static variable with global task function
    - Class data member with member task function
    - Variable captured by reference with lambda expression
### std::mutex interface
* Three main member functions:
    - lock()
        - Tries to lock the mutex
        - If not successful, waits until it locks the mutex
    - try_lock()
        - Tries to lock the mutex
        - Return immediately if not successful
        - Returns true if it locked the mutex
        - Return false if it could not lock the mutex
    - unlock()
        - Release the lock on the mutex