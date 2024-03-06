# Shared Mutex std::shared_mutex
* std::shared_mutex is defined in <shared_mutex> header
* It can be locked in two different ways
    * Exclusive lock
        - No other thread may acquire a lock
        - No other thread can enter a critical section
    * Shared Lock
        * Other threads may acquire a shared lock
        * They can execute critical sections concurrently
## Exclusive Lock
* std::lock_guard<std::shared_mutex>
* std::unique_lock<std::shared_mutex>
* Only this thread can execute a critical section
    * Other threads must wait until the thread release its exclusive lock
* It can only acquire an exclusive lock when the mutex is unlocked
    * If other threads have shared or exclusive locks
    * This thread must wait until all the locks are released
## Shared lock
* std::shared_lock<std::shared_mutex>
* A thread which has a shared lock can enter a crirical section
* It can only acquire a shared lock if there are no exclusive locks
    * if another thread has an exclusive lock
    * This thread must wait until the exclusive lock is released
## Note
Shared mutex needs C++17, for C++14 use std::shared_timed_mutex
## std::shared_mutex Member Functions
* Exclusive locking
    * lock()
    * try_lock()
    * unlock()
* Shared locking
    * lock_shared()
    * try_lock_shared()
    * unlock_shared()
## Data Race Avoidance
* The writer thread cannot get an exclusive lock
    * Until all other threads release their locks
    * Those threads have now left their critical sections
* The writer thread acquires an exclusive lock
    * It enters the critical sections
    * Reader threads cannot get a shared lock
    * Writer threads cannot get an exclusive lock
    * Until this therad release its lock
* The writer thread release its exclusive lock
    * it has now left its critical section
*  The reader thread cannot get a shared lock
    * Until a writer thread release its exclusive lock
    * The writer thread has now left its critical section
* The reader thread acquires a shared lock
    * It enters the critical section
    * Other reader threads can also get a shared lock
* There is no scenarion in which there is a data race
    * Reader and writer threads cannot interleave in a critical section
## Pros and Cons of std::shared_mutex
* Uses more memory than std::mutex
* Slower than std::mutex
* Best suited to situations where
    * Reader threads greatly outnumber writer threads
    * Read operation take a long time