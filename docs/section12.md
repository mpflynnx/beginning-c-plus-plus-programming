## Section 12: Pointers and References

## Table of Contents

- [Pointers](#pointers)
- [Declaring pointers](#declaring-pointers)
- [Accessing pointer address](#accessing-pointer-address)
- [Dereferencing a pointer](#dereferencing-a-pointer)

- [External References](#external-references)

### Pointers
Further reading:
- [learncpp.com | Introduction to pointers](https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/)
- [C course notes | Pointers](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/pointers.md)

In modern C++, the pointers we are talking about here are sometimes called “raw pointers” or “dumb pointers”, to help differentiate them from “smart pointers” that were introduced into the language more recently.

**What is a Pointer?**
- pointers behave a lot like [lvalue references](https://www.learncpp.com/cpp-tutorial/lvalue-references/)
- A variable
    - whose value is a memory address
- What can be at the address?
    - Another variable
    - A function
- Pointers point to variables or functions?
- If x is an integer variable and it's value is 10 then I can declare a pointer that points to it
- To use the data that the pointer is pointing to you must know the type

**Why use Pointers?**
- Can't I just use the variable or function itself?
    - Yes, but not always
    - Yes, fundamental types are cheap to copy

- Pointers can be used inside functions to work on data that is out of scope.
- Pointers can work very efficiently with large arrays (no need to duplicate arrays in memory)
- We can allocate memory dynamically on the heap or free store.
    - This memory doesn't have a variable name.
    - The only way to get to it is via a pointer.

- With Object Oriented Programming, pointers are how polymorphism works.

- Whenever possible, we want to avoid making unnecessary copies of objects that are expensive to copy, especially when we will destroy those copies almost immediately.

- Can access specific addresses in memory
    - useful in embedded and systems applications

### Declaring pointers

Further reading:
- [learncpp.com | null pointers](https://www.learncpp.com/cpp-tutorial/null-pointers/)

Pointer types are declared using an asterisk (*).
Two ways are used to declare pointers.

`variable_type *pointer_name;`

`variable_type* pointer_name;`

**Best practice**
When declaring a pointer type, place the asterisk next to the variable_type.[<sup>[1]</sup>](#external-references)

The type of the pointer has to match the type of the object being pointed to or there will be a compiler error. C++ doesn't use untyped pointers like C.

```c
int* int_ptr; // uninitialised, contains garbage
double* double_ptr; // uninitialised, contains garbage
char* char_ptr; // uninitialised, contains garbage
std::string* string_ptr; // uninitialised, contains garbage
```

**Best practice**
Always initialise your pointers.[<sup>[1]</sup>](#external-references) Some compilers will not compile with uninitialised pointers. Value initialise your pointers (to be null pointers) if you are not initialising them with the address of a valid object.

```c
int main()
{

    int* ptr;        // an uninitialised pointer (holds a garbage address)
    int* ptr2{};     // value initialisation, nullptr or null pointer represents no address or zero
    int* ptr3{nullptr}; // nullptr keyword introduced in C++11 represents address zero

    return 0;
}
```

Use `nullptr` when you need a null pointer literal for initialisation, assignment, or passing a null pointer to a function.[<sup>[2]</sup>](#external-references)

Much like dereferencing a dangling (or wild) pointer leads to undefined behaviour, dereferencing a null pointer also leads to undefined behaviour. In most cases, it will crash your application.

The following program illustrates this, and will probably crash or terminate your application abnormally when you run it:

```c
#include <iostream>

int main()
{
    int* ptr {}; // Create a null pointer
    std::cout << *ptr << '\n'; // Dereference the null pointer

    return 0;
}
```

**Warning**
Whenever you are using pointers, you’ll need to be extra careful that your code isn’t dereferencing null or dangling pointers, as this will cause undefined behaviour (probably an application crash).

### Accessing pointer address
Since pointers hold addresses, when we initialise or assign a value to a pointer, that value has to be an address. Typically, pointers are used to hold the address of another variable (which we can get using the address-of operator (&)).

```c
#include <iostream>

int main()
{

    int* p {nullptr}; // initialised to 0

    std::cout << "Value of p is: "<< p << '\n'; // 0
    std::cout << "Address of p is: " << &p << '\n';
    std::cout << "size of p (bytes) is: " << sizeof p << '\n'; // 8 for 64 bit machine

    return 0;
}
```

**Output**
```bash
Value of p is: 0
Address of p is: 0xe1883ff8a8
size of p (bytes) is: 8
```

**Note:** The pointer is always a memory address. The size of a pointer is always 8 bytes (64bit machine) or 4 bytes (32bit machine).

For objects that use more than one byte of memory, address-of (&) will return the memory address of the first byte used by the object.

```c
#include <iostream>
#include <vector>

int main()
{

    std::vector <int> test_scores {100, 98, 89, 85, 93};
    std::vector <int> *pVec{&test_scores};

    std::cout << "Value of pVec is: "<< pVec << '\n';
    std::cout << "Address of test_scores is: " << &test_scores << '\n';
    std::cout << "Address of pVec is: " << &pVec << '\n';
    std::cout << "size of test_scores (bytes) is: " << sizeof test_scores << '\n';

    return 0;
}
```
**Output**
```bash
Value of pVec is: 0x3b8a9ff900
Address of test_scores is: 0x3b8a9ff900 // first byte
Address of pVec is: 0x3b8a9ff8f8
size of test_scores (bytes) is: 24
```

### Dereferencing a pointer

The dereference operator (*) (also occasionally called the indirection operator) returns the value at a given memory address as an lvalue.

Given a memory address, we can use the dereference operator (*) to get the value at that address (as an lvalue).

The address-of operator (&) and dereference operator (*) work as opposites: address-of gets the address of an object, and dereference gets the object at an address.

```c
int score {100}; // initialise score to 100.
int* score_ptr { &score }; // initialise int pointer to score memory address

std::cout << *score_ptr << '\n'; // dereference score_ptr gets 100

*score_ptr = 200; // change score via score_ptr

std::cout << *score_ptr << '\n'; // dereference score_ptr gets 200
std::cout << score << '\n'; // score updated 200
```

Example using C++ string vector
```c
#include <iostream>
#include <vector>
#include <string>

int main()
{

    // initialise a C++ string vector
    std::vector<std::string> stooges {"Larry", "Moe", "Curly"};
    
    // initialise a C++ string vector pointer to address of stooges vector
    std::vector<std::string>* vector_ptr {&stooges};

    // print first element of stooge vector
    // parentheses important, as .at(0) higher precedence than *vector_ptr
    std::cout << "First stooge: " << (*vector_ptr).at(0) << '\n';

    // print all stooge vector elements
    std::cout << "Stooges: ";
    for (auto stooge: *vector_ptr)
        std::cout << stooge << ' ';
    std::cout << '\n';

    return 0;
}
```

**Output**
```bash
First stooge: Larry
Stooges: Larry Moe Curly
```

## External References
- [udemy.com | Course content | Section 12: Pointers and References](https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/lecture/9535524#questions)
- [learncpp.com | Introduction to pointers](https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/)<sup>[1]</sup>
- [C course notes | Pointers](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/pointers.md)
- [learncpp.com | Lvalue references](https://www.learncpp.com/cpp-tutorial/lvalue-references/)
- [learncpp.com | null pointers](https://www.learncpp.com/cpp-tutorial/null-pointers/)<sup>[2]</sup>
- [learncpp.com | Pointers and const](https://www.learncpp.com/cpp-tutorial/pointers-and-const/)
