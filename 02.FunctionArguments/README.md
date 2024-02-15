# How to Pass Arguments in Thread Functions
We can pass arguments to the entry point functions.
```ruby
void hello(std::string str)
std::thread thrd(hello,"Hello");
```
## What are lvalue and rvalue?
An lvalue always has a defined region of storage, so you can take its address. An rvalue is an expression that is not an lvalue. Examples of rvalues include literals, the results of most operators, and function calls that return nonreferences. An rvalue does not necessarily have any storage associated with it.

* The std::thread object owns the arguments
    - lvalue arguments are passed by value
    - rvalue arguments are passed by move

### lvalue argument:
```ruby
void hello(std::string str)
std::thread thrd(hello,"Hello");
```
### rvalue argument:
-   After passing rvalue argument, the value will be modified.
```ruby
void hello(std::string&& str)
std::string str = "Hello";
std::thread thrd(hello,std::move(str));
```
## Reference Argument
* For reference argument we have to use a reference wrapper
* Use std::cref() for a constant reference
* We have to aware of dangling references.
