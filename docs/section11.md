## Section 11: Functions

## Table of Contents

- [Standard Library functions](#standard-library-functions)
- [C language functions](#c-language-functions)
    - [Using Functions from the cmath Library exercise](/exercises/section11/using-functions-from-cmath-library-exercise/instructions.md)
    - [Using Functions from the cmath Library exercise (my solution)](/exercises/section11/using-functions-from-cmath-library-exercise/main.cpp)
    - [Functions and Prototypes - Converting Temperatures exercise](/exercises/section11/functions-and-prototypes-converting-temperatures/instructions.md)
    - [Functions and Prototypes - Converting Temperatures exercise (my solution)](/exercises/section11/functions-and-prototypes-converting-temperatures/main.cpp)
- [Default Argument Values](#default-argument-values)
    - [Using Default Argument Values exercise](/exercises/section11/using-default-argument-values-exercise/instructions.md)
    - [Using Default Argument Values exercise (my solution)](/exercises/section11/using-default-argument-values-exercise/main.cpp)
- [Function overloading](#function-overloading)
    - [Overloading function exercise - calculating area](/exercises/section11/overloading-functions-exercise/instructions.md)
    - [Overloading function exercise - calculating area (my solution)](/exercises/section11/overloading-functions-exercise/main.cpp)
- [Passing arrays to functions](#passing-arrays-to-functions)
    - [Passing Arrays to Functions exercise - Print a Guest List](/exercises/section11/passing-arrays-to-functions/instructions.md)
    - [Passing Arrays to Functions exercise - Print a Guest List (my solution)](/exercises/section11/passing-arrays-to-functions/main.cpp))
- [const parameters](#const-parameters)
- [Pass by reference](#pass-by-reference)
    - [Using Pass by Reference exercise - Print a Guest List](/exercises/section11/using-pass-by-reference-exercise/instructions.md)
    - [Using Pass by Reference exercise - Print a Guest List (my solution)](/exercises/section11/using-pass-by-reference-exercise/main.cpp)
- [Scope Rules](#scope-rules)
- [How do function calls work?](#how-do-function-calls-work)
- [inline Functions](#inline-functions)
- [Recursive Functions](#recursive-functions)
    - [Factorial recursion example code](/exercises/section11/recursion-factorial-example/main.cpp)
    - [Fibonacci recursion example code](/exercises/section11/recursion-fibonacci-example/main.cpp)
    - [Implementing a Recursive Function exercise - Sum of Digits](/exercises/section11/implementing-a-recursive-function-exercise/instructions.md)
    - [Implementing a Recursive Function exercise - Sum of Digits (my solution)](/exercises/section11/implementing-a-recursive-function-exercise/main.cpp)
    - [Implementing a Recursive Function exercise - Save a Penny](/exercises/section11/implementing-a-recursive-function-save-a-penny/instructions.md)
    - [Implementing a Recursive Function exercise - Save a Penny (my solution)](/exercises/section11/implementing-a-recursive-function-save-a-penny/main.cpp)
- [Section11: Challenge](/challenges/section11/section11-challenge/section11-challenge.md)
- [Section11: Challenge (my solution)](/challenges/section11/section11-challenge/main.cpp)

- [External References](#external-references)

### Standard Library functions
C++ has many built in functions contained in the [Standard Library](https://en.cppreference.com/w/cpp/header). No include statement needed, as these functions are global.

Many popular maths functions are contained in the [`<cmath>`](https://en.cppreference.com/w/cpp/header/cmath) header.

```c
#include <cmath>
```
Some functions from the C programming language are contained in [`<cstdlib>`](https://en.cppreference.com/w/cpp/header/cstdlib) header.
```c
#include <cstdlib>
```

Date and time functions exist in the [`<ctime>`](https://en.cppreference.com/w/cpp/header/ctime) header.

```c
#include <ctime>
```

Random number functions exist in the [`<random>`](https://en.cppreference.com/w/cpp/header/random) header.

```c
#include <random>
```

### C language functions
C++ functions are very similar to C language functions. See [my C course notes](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/functions.md) for basic C function explanations.

### Function Parameters and the return statement

Further reading: [learncpp.com - Introduction to function parameters and arguments](https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/)

### Default Argument Values

Further reading: [learncpp.com - Default arguments](https://www.learncpp.com/cpp-tutorial/default-arguments/)

- When a function is called all arguments must be supplied.
- Sometimes some arguments always have the same values.
- We can tell the compiler to use default values, if arguments are not supplied.
- Defaults values can be in the forward declaration (prototype) or  function definition (not both).
    - Best practice declare in forward declaration (prototype), especially one in a header file
    - must appear at the tail end of the parameter list
- Multiple default value can be declared
    - must appear consecutively at the tail end of the parameter list.

C++ does not (as of C++20) support a function call syntax such as print(,,3) (as a way to provide an explicit value for z while using the default arguments for x and y. This has two major consequences:

If a parameter is given a default argument, all subsequent parameters (to the right) must also be given default arguments.

### Function overloading
Further reading: [learncpp.com -  Introduction to function overloading](https://www.learncpp.com/cpp-tutorial/introduction-to-function-overloading/)

- multiple functions with the same name, can have different parameter lists
- abstraction same function behaviour
- a type of polymorphism (many forms for same concept)
    - a function with the same name can work with different data types to execute same behaviour.
- the compiler must be able to tell the functions apart based on the parameter lists and arguments supplied
- return type is not considered
- char types arguments are promoted to integers
- float types arguments are promoted to doubles
- C-style strings arguments are converted to C++ strings
- be careful with default arguments on mutliple overloaded functions, the compiler may not be able to determine the correct function to call

Multiple versions of the function prototype and definitions are required using different types and/or parameter lists.

C++ has [function templates](https://www.learncpp.com/cpp-tutorial/function-templates/). The template system was designed to simplify the process of creating functions (or classes) that are able to work with different data types.

### Passing arrays to functions

C-style arrays were inherited from the C language, and are built-in to the core language of C++ (unlike the rest of the array types, which are standard library container classes). This means we don’t need to #include a header file to use them.

Further reading:
- [C course notes - Functions and C-style arrays](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/functions.md#passing-arrays-to-functions)
- [C course notes - Printing a char array](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/strings.md#printing-a-char-array)
- [learnccp.com - Introduction to C-style arrays](https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/)

When passing arrays to functions, it is a good ideal to pass in the size of the array as type `size_t`. 

```c
void printArray(int arr[], size_t size); // prototype
```
### const parameters
- we can tell the compiler that a function parameters are constant (read only) using the `const` keyword.
- This is useful for functions that work with arrays and the array is not required to be modified.

```c
void printArray(const int arr[], size_t size); // prototype

int my_scores[] {100,98,90,86,84};
printArray(my_scores, 5);
```

### Pass by reference

- Use the address-of operator (&) before the parameter name to pass by reference. 
- Similar to passing arrays we **should** add the keyword `const` if the functions is not to update the argument.

```c
void printNum(const int &num); // prototype

int num {100};
printArray(num);
```

Further reading: 
- [learnccp.com - Pass by reference](https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/)
- [learnccp.com - Pass by const lvalue reference](https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/)

Alternatives:
- Pass by pointer also referred to as Pass by address.



Further reading:
- [C course notes - Pass by pointers](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/pass-by-pointer.md)
- [learnccp.com - Pass by address](https://www.learncpp.com/cpp-tutorial/pass-by-address/)

### Scope Rules

Further reading:
- [C course notes - Variable Scope](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/functions.md#variable-scope)
- [C course notes - Global Scope](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/global-scope-variables.md)
- [learncpp.com - Intro to local scope](https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/)
- [learncpp.com - Scope, Duration, and Linkage](https://www.learncpp.com/cpp-tutorial/compound-statements-blocks/)
- [learnccp.com - Static local variables](https://www.learncpp.com/cpp-tutorial/static-local-variables/)

### How do function calls work?

Function calls have a certain amount of overhead. Function calls use the stack memory in last in first out.

What typically happens when main calls a function func1 (or any function calls another)?
    There are other ways to achieve the same results.
    
    main:
        push space for the return value
        push space for the parameters
        push the return address
        transfer control to func1 (jmp)
    func1:
        push the address of the previous activation record
        push any register values that will need to be restored before returning to the caller
        perform the code in func1
        restore the register values
        restore the previous activation record (move the stack pointer)
        store any function result
        transfer control to the return address (jmp)
    main:
        pop the parameters
        pop the return value

### inline Functions

Compilers may optimise out functions that are simple. We can define functions as `inline` by using the `inline` keyword before the function return type, to force the compiler to optimise out the function.

Further reading:
- [learncpp.com - inline functions and variables](https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables/)

### Recursive Functions

Most recursive functions can be implemented with while loops initially. Then for certain solutions and the need for greater efficiency, recursive functions are recommended. 

Further reading: [C course notes - Recursion](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/recursion.md)

- [Factorial recursion example code](/exercises/section11/recursion-factorial-example/main.cpp)
- [Fibonacci recursion example code](/exercises/section11/recursion-fibonacci-example/main.cpp)

It is important that the recursive function can be exited.Every recursive function must have a base case.

**base case examples**
```c
    if (n == 0)
        return 0;
```

```c
    if (n <= 1)
        return n;	
```
## External References
- [udemy.com | Course content | Section 11: Functions](https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/lecture/9535496#questions/12997232)
- [cppreference.com | C++ Standard Library header files](https://en.cppreference.com/w/cpp/header)
- [cppreference.com | Standard library header `<cmath>`](https://en.cppreference.com/w/cpp/header/cmath)
- [cppreference.com | Standard library header `<cstdlib>`](https://en.cppreference.com/w/cpp/header/cstdlib)
- [cppreference.com | Standard library header `<ctime>`](https://en.cppreference.com/w/cpp/header/ctime)
- [cppreference.com | Standard library header `<random>`](https://en.cppreference.com/w/cpp/header/random)
- [learncpp.com | Global random numbers (Random.h)](https://www.learncpp.com/cpp-tutorial/global-random-numbers-random-h/)
- [C course notes |  C functions](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/functions.md)
- [learncpp.com | Introduction to functions](https://www.learncpp.com/cpp-tutorial/introduction-to-functions/)
- [learncpp.com | Default arguments](https://www.learncpp.com/cpp-tutorial/default-arguments/)
- [learncpp.com |  Introduction to function overloading](https://www.learncpp.com/cpp-tutorial/introduction-to-function-overloading/)
- [learnccp.com | function templates](https://www.learncpp.com/cpp-tutorial/function-templates/)
- [C course notes | Functions and C-style arrays](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/functions.md#passing-arrays-to-functions)
- [learnccp.com | Introduction to C-style arrays](https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/)
- [learnccp.com | Pass by reference](https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/)
- [learnccp.com | Pass by const lvalue reference](https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/)
- [C course notes |  Pass by pointers](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/pass-by-pointer.md)
- [learnccp.com | Pass by address](https://www.learncpp.com/cpp-tutorial/pass-by-address/)
- [C course notes | Variable Scope](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/functions.md#variable-scope)
- [C course notes | Global Scope](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/global-scope-variables.md)
- [learncpp.com | Intro to local scope](https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/)
- [learncpp.com | Scope, Duration, and Linkage](https://www.learncpp.com/cpp-tutorial/compound-statements-blocks/)
- [learnccp.com | Static local variables](https://www.learncpp.com/cpp-tutorial/static-local-variables/)
- [learncpp.com | inline functions and variables](https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables/)
- [programiz.com | Convert a given character to uppercase](https://www.programiz.com/cpp-programming/library-function/cctype/toupper)
