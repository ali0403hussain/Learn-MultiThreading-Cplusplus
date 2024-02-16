# Thread with Exception
* Each thread has its own execution stack.
* This stack is "unwound" when the thread throws an exception.
    - The destructor for all objects in scope are called.
    - The program moves up the thread's stack until it finds a suitable handler.
    - If no handler is found, the program is terminated.
* Other threads in the program cannot catch the exception
    - Including the parent thread and the main thread
* Exception can only be handled in the thread where they occur
    - Use a try/catch block in the normal way

## Detaching a Thread
* Instead of calling join(), we can call detach()
    - The parent thread will continue executing
    - The child thread will run until it completes
    - Or the program terminates
    - Analogous to a "daemon" process
        In multitasking computer operating systems, a daemon is a computer program that runs as a background process, rather than being under the direct control of an interactive user. Traditionally, the process names of a daemon end with the letter d, for clarification that the process is in fact a daemon, and for differentiation between a daemon and a normal computer program. For example, syslogd is a daemon that implements system logging facility, and sshd is a daemon that serves incoming SSH connections.
* When an execution thread is detached
    - The std::thread object is no longer associated with it
    - The destructor will not call std::terminate()
 ```                                                                                   
                                    join()                          detach()        
                                        |                               |             
                                        |                               |             
                                        |                               |             
                                        |                               |             
                                        .\                              |\            
                                        . \                             | \           
                                        .  \                            |  \          
                                        .   \                           |   \         
                                 Parent .    \   Child           Parent |    \  Child 
                                 Thread .     \  Thread          Thread |     \ Thread
                                        .     /                         |      |      
                                        .    /                          |      |      
                                        .   /                           |      |      
                                        .  /                            |      |      
                                        . /                             |      |      
                                        .v                              |      |      
                                        |                               |      |      
                                        |                               |      |      
                                        |                               |      |      
                                        |                               |      |      
                                        v                               v      v   
```
## Exception in Parent Thread
* The destructor are called for every object in scope
    - including std::thread's destructor
    - This checks whether join() or detach have been called
    - if neither, it calls std::terminate()
* We must either join() or detach() before thread is destroyed
    - In all paths through the code

## Problem with Thread Exception code 
As mentioned above the exception should be handles inside the thread where exception is thrown.
```ruby
try
    {
        std::thread thrd(hello, str);
        throw std::exception();
        thrd.join();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception Caught :" <<e.what() << '\n';
    }
```
If the exception is thrown in the above code then it will never execute the thrd.join which causes issue.

```ruby
try
    {
        std::thread thrd(hello, str);
        throw std::exception();
        thrd.join();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception Caught :" <<e.what() << '\n';
        thrd.join();
    }
```
In the above solution it will fix the problem but not in good way because we are using thread.join() in try block and as well as cath block. Better way is use RAII idom solution

### RAII solution
* A better solution is to use the RAII idiom
    - Wrap the std::thread object inside the class
    - The class's destructor calls join on the std::thread object
* An std::thread object can only be joined once
* The joinable() member function
    - Return false
    - If join() or detach() have already been called
    - Or if the thread object is not associated with an execution thread
    - Returns true if we nedd to call join()
The solution is present in the code section main.cpp