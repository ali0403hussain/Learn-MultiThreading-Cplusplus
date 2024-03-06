# Mutex Unique Lock
## Why use of unique_lock if we have lock_guard ?
* lock_guard doesn't requires to unlock the mutex, due to which time waistage ocuurs. If we unlock lock_guard mutex explicit then due to the double occurance of unlock mutex occurs, one from the destructor of lock_guard. This causes crash of program.

## std::unique_lock
* The same basic features as std:lock_guard
    * Mutex data member
    * Constructor locks the mutex 
    * Destructor unlocks the mutex
* It also has an unlock() member function
    * We can call after the critical section
    * Avoids blocking  other threads while we execute non-critical section code
* If we don not call unlock(), the destructor will unlock the mutex
    * The lock ia always released

## std::unique_lock Constructor Options
* The default
    * Call the mutex's lock() member function
* Try to get the lock
    * Do not wait if unsuccessful
    * (Timed mutex) wait with a time-out if unsuccessful
* Do not lock the mutex
    * It will be locked later
    * Or the mutex is already locked
* std::try_to_lock
    * Calls the mutex try_lock() member function
    * The owns_lock() member function checks if mutex is locked
* std::defer_lock
    * Does not lock the mutex
    * Can lock it later by calling lock() member function
    * Or by passing the std::unique_lock object to std::lock()
* std::adopt_lock
    * Takes a mutex that is already locked
    * Avoids locking the mutex twice

## std::unique_lock and Move Semantics
* A std::unique_lock object cannot be copied
* It can be monved
    * The lock is transfered to another std::unique_lock object
    * Can only  be done within the same thread
* We can write a function that creates a lock object and return it
    * The function kcould lock different typs of mutex, depending on its arguments
    * Factory design pattern
## std::unique_lock vs std::lock_guard
* std::unique_lock is much more flexible, but
    * Requires slightly more storage
    * Is slightly slower
* Recommendations
    * Use lock_guard to lock a mutex for an entire scope
    * Use unique_lock if you need to unlock within the scope
    * Use unique_lock if you need the extra features.