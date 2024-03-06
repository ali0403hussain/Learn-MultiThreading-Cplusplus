# Shared Data Initialization
## Shared Data
* Global variables
    * Accessible to all code in the program
* Static variables at namespace scope
    * Accessible to all code in the translation unit
* Class member which is declared static
    * Potentially accessible to code which calls its member functions
    * (if public, accessible to all code)
* Local variables which is declared static
    * Accessible to all code which calls that function
## Global, Static at namespace and static class data members
- All are initialized when the program starts.
- At that point, only one thread is running
- There cannot be a data race
## static Local variable
- Initialized after the program starts
- When the declaration is reached
```ruby
    void func() {
        ...
        //static local variable
        static std::string str("xyz");
        ...
    }
```
- Two or more threads may call the constructor concurrently
## Static Local variable initialization before C++11
- No langauge support
    * The behaviour was undefined
- Lock a mutex?
    * Required on every pass through the decleration
    * Very inefficient
## Static Local variable initialization in C++11
* The behaviour is now well defined
* Only one thread can initialize the variable
    * Any other thread that reaches the decleration is blocked
    * Must wait until the first thread has finished initializing the variable
    * The threads are synchronized by the implementation
    * No data race
* Subsequent modifications
    * The usual rules for shared data
    * There will be a data race, unless we protect against one

## Singleton Class
* Used to implement the Singleton design pattern
* A Singleton class has only a single instance
    * e.g a logger class that maintains an audit trail
* Its constructor is private
* The copy and move operators are deleted
    * The program cannot create more objects
* A static member function returns the unique instance
    * If the instance does not already exist, it is created and initialized
    * Otherwise the exisiting object is returned
## Classic Singleton Implementation
```ruby
    class Singleton {
        //Pointer to the unique instance
        static Singleton *single;
    public:
        //static member functions which returns the unique instance
        static Singleton* get_singleton() 
        {
            if(single == nullptr)
                single = new Singleton;
            return single;
        }
        // Copy and Move operators deleted.
    }
```
## C++ 11 Singleton Implementation
```ruby
    class Singleton {
        //Class functionality
    }

    Singleton& get_Singleton()
    {
        //Initialize by the first thread  that executes this code
        static Singleton single;
        return single;
    }
```
* The first thread to reach the defination creates the unique instance
    * Subsequent threads use the object created by the first thread.
    * The object remains in existance until the program terminates.
    