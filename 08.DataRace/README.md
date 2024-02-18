# Data Race
Two or more threads access the same memory location. And atleast one of the threads modifies it. And the threads are not synchronized when they access the memory location.

* A "data race" occurs when
    - Two or more threads access the same memory location.
    - Ana at least one of the threads modifies it
    - Potentially confliticing accesses to the same memory location
* Only safe if the threads are synchronized
    - One thread accesses the memory location at a time
    - The other threads have to wait until it is safe for them to access it
    - In effect, the threads executr sequentially while they access it
* A data race cause undefined behaviour
    - The program is not guarantee to behave consistently

## Race Condition
* The outcome is affected by timing changes
    - e.g One client clears a database table
    - Another client inserts an entry into the same table
* A data race is a special case of a race condition
    - The outcome depends on when threads are scheduled to run.

## Mmeory location
* In C++ a memory location is a scalar object:
    - A built in variable
    - A pointer
    - An element in containers
* Or a scalar sub-object:
    - A struct or class member which is a scalar object
* Also an obsure case:
    - A series of contiguous bitfields within the same word.
    - Unless they contains a zero length bitfield

## Compound Objects
* C++ STL containers are memory locations
    - Multiple threads modifying the same object may conflict.
    - Should be synchronized
* For our own types, wecan choose the behaviour
    - Classes can provide their own synchronization
    - Easier to work with
    - Calling a sequence of members functions may be problematic
    - Usually better to implement them as  memory location

## Data Sharing between Threads
* The threads in a program share the same memory space
    - It is very easy to share data between the threads
* The only ewruirement is that the data is visible to the thread functions
    - Global or static variables, for global thread functions.
    - Static class members, for class member thread functions.
    - Local variable captured by lambda expression(by refernce)
* Threads interleave their execution
* Threads can interfere with each others actions
* Modifying shared data can cause data corruption
    - This is the main source of bugs in cocurrent programs
