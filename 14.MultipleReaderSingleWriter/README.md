# Multiple Readers and Single Writer
* Financial data feed for infrequently traded stocks
    * Constantly accessed to get the latest price
    * The price rarely changes
* Audio/Video buffers in multimedia players
    * Constantly accessedto get the next frame
    * Occasionally updated with a block of data
* Shared data
    * Must protect against a data race

## Data Race
* It occurs when
    * Two or more threads access the same memory location
    * And atleast one of the thread modifies it
    * Potentially conflicting accesses to the same memory location
* Only safe if threads are synchronized
    * One thread accesses the memory location at a time
    * The other threads have to wait until it is safe for them to access it
    * In effect, the threads execute sequentially while they access it
* A data race causes undefined behaviour
    * The program is not guaranteed to behave consistently

## Multiple Reader, Single Writer
* Concurrent accesses.
* High probability of a reader and another reader
    * No locking required
* Low probability of a writer and a reader
    * Locking required
* Low probability of a writer and another writer
    * Locking required
* With std::mutex , all threads are synchronized
* They must execute their critical sections sequentially
* Loss of concurrency reduces performance

## Read-write Lock
* It would be useful to have "selective" locking
    * Lock when there is a thread which is writing.
    * Do not lock when there are only reading threads.
    * Often called a "read-write lock"