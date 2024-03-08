# Lazy Initialization
* Common pattern in functional programming.
* A variable is only initialized when it is first used
* This is useful when the variable is expensive to construct
    * e,g it sets up a network connection
* Can be used in multi-threaded code
    * But we need to avoid data races

```ruby
//Lazy initialization (single-threaded)
class Test {
    //....
public:
    void func() {......}
};
Test *ptest = nullptr;  //variable to be lazily initialized

void process()
{
    if(!ptest)              //First time variable has been used
        ptest = new Test;   //Initialize it 
    ptest->func();          //Use it
}
```
* This is not thread safe.
* Thread safe can be done using mutex.
* Every thread that calls process() locks the mutex
    * Locking the mutex blocks every other thread that calls process()
* The lock is only needed while ptest is being initialized
    * Once ptest has been initialized, locking the mutex is unnecessary
    * Causes a loss of performance
## Double-checked locking Algorithm
* More efficient version of thread safe lazy initialization
* If ptest is not initialized
    * Lock the mutex
    * if ptest is not initialized, initialize it
    * Unlock the mutex
    * Use ptest
* Otherwise
    * Use ptest
* ptest is checked twice (why?)
    * Answer will be in next section
