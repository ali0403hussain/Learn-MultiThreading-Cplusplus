# C++ Thread std::thread Class
C++11 provided support for multithreading. We had to utilize the <pthreads> library or POSIX threads before C++11. This library worked as intended, however there were significant portability problems because it lacked a feature set supplied by a standard language. All of that was eliminated in C++ 11 and replaced with std::thread. The <thread> header file defines the thread classes and associated functions.
In C++, a single thread is represented by the thread class td::thread. All that is required to initiate a thread is to construct a new thread object and feed the code that is now running—that is, a callable object—into the object's constructor. A new thread is started after the object is created, and it will run the function mentioned in the callable. 
C++ Thread can be implemented in the following ways.
## Using Function Objects:
```ruby
class funct{
    funct();
    ~funct();
};
int main()
{
    funct funct_obj;
    std::thread thread_functor(funct_obj);
    return 0;
}
```
## Using Function pointers or Callable functions:
```ruby
void function(param)
{
    statement;
}
int main()
{
    std::thread thread_function(function,param);
    return 0;
}
```
## Using Lambda Expression:
An anonymous function object (also known as a closure) can be conveniently defined at the exact position where it is invoked or supplied as an argument to a function by using a lambda expression, often commonly referred to as a lambda. Lambdas are typically used to transmit a few lines of code to asynchronous functions or algorithms. 
```ruby
auto LambdaFunc = [](param)
{
    statement;
};

std::thread thread_lambda(fLambdaFunc,param);
```
## Using member function:
```ruby
class A{
    public:
        void funct(param)
        {
            statement;
        }
};
int main()
{
    A A_obj;
    std::thread thread_mem_func(&A::funct, &A_obj, param);
    return 0;
}
```
