# Timed Mutex std::timed_mutex
* Similar to std::mutex, but with extra member functions
    * try_lock_for()
        - Keep trying to lock the mutex for a specified duration
    * try_lock_until()
        - Keep trying to lock the mutex until a specified time
* These return bool
    * True if the mutex was locked
    * Otherwise false

## std::unique_lock
* std::unique_lock has memmber functions
    * try_lock_for()
    * try_lock_until()
* These are forwarded to the wrapped mutex
    * Will only compile if the mutex supports the operations
    
## std::chrono Clocks
* chrono::system_clock
    * Gets time from operating system 
    * May change erratically
    * Use it for time points
* chrono::steady_clock
    * Always increases steadily
    * Use it for measuring intervals
