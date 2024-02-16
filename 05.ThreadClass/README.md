# Standard C++ thread class
## System thread Interface
* std::thread uses the system's thread implementation.
* We may need to use thread implementation directly.
* Some functionality is not available in standard C++.
    - Thread priority
        - Give a thread higher or lower share of processor time.
    - Thread affinity
        - "Pin" a thread on a specific processor core.
* Each execution thread has a "handle"
    - Used internally by the system's thread implementation.
    - Needed when making calls into the implementtaion's API.
* Returned by the native_handle() member function.
    - thr.native_handle()

## std::thread Features
* Implemented usin RAII
    - Similar to std::unique_ptr, std::fstream etc.
    - The constructor acquires a resource.
    - The destructor release the resource.
* An std::thread object has ownership of an execution thread
    - Only one object can be bound to an execution thread at a time.
## std::thread and Move Semantics
* Move only class
    - std::thread object cannot be copied.
* Move operations.
    - Transfer ownership of the execution thread.
    - The moved-form object is no longer associated with an execution thread.
## Pasing a std::thread Object
* Must use pass by move
    - Function taking a thread object as argument
        - void func(std::thread thr)
    - Pass a named object and use std::move()to cast it to rvalue.
        - std::thread thr(...)
        - func(std::move(thr))
    - Pass a temporary object
        - func(std::thread(...))
## Returning a std::thread Object
* The compiler will automatically move it for us
    ```ruby
        std::thread func(){
            std::thread thr(...);
            return thr;
        }
    ```
## Thread ID
* Each execution thread has a thread identifier.
    - Used internally by the systems implementation.
* Guaranteed to be unique
    - If two thread identifiers are equal, the related objects are identical
    - Could be used to store std::thread objects in associative containers
    - A new thread may get the ID of an earlier thread which has completed
    - Returns the identifier of the current thread
        std::this_thread::get_id()
    - Return the identifier associated with an std::thread object
```ruby
thr.get_id()
```
## Pausing Thread
* We can pause thread or make it "sleep"
    - std::this_thread::sleep_for()