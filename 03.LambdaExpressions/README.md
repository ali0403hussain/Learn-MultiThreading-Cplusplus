# Small Explanation about Lambda Expressions
Lambda expressions were added in C++ 11 to enable inline functions, which are useful for brief code segments that don't need names because they won't be repeated.
## Syntax:
```ruby
[ capture clause ] (parameters) -> return-type  
{   
   Statements; 
} 
```
Typically, the compiler evaluates the return-type in lambda expressions, so we don't need to explicitly declare it. You can also ignore the return type.  Nevertheless, the compiler is unable to infer the return type in some complex circumstances, such as conditional expressions, necessitating explicit specification. 
Because a lambda expression can access variables from the enclosing scope, it can be more powerful than a regular function. Three methods exist for us to extract foreign variables from the enclosing scope: 
      Capture by reference 
      Capture by value 
      Capture by both (mixed capture)
The syntax for encoding variables is: 
      [&] : capture all external variables by reference 
      [=] : capture all external variables by value 
      [a, &b] : capture a by value and b by reference
Only local variables can be accessed by a lambda that has an empty capture clause []. 

