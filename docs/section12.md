## Section 12: Pointers and References

## Table of Contents

- [Pointers](#pointers)
- [Declaring pointers](#declaring-pointers)
- [Accessing pointer address](#accessing-pointer-address)
- [Dereferencing a pointer](#dereferencing-a-pointer)
- [Dynamic Memory Allocation](#dynamic-memory-allocation)
    - [Using `new` to allocate storage](#using-new-to-allocate-storage)
    - [Using `delete` to deallocate storage](#using-delete-to-deallocate-storage)
    - [Allocate/deallocate storage for a C-style array](#allocatedeallocate-storage-for-a-c--style-array)
- [Relationship between arrays and pointers](#relationship-between-arrays-and-pointers)

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

### Dynamic Memory Allocation

Dynamic memory allocation is a way for running programs to request memory from the operating system when needed. This memory does not come from the program’s limited stack memory (1MB) -- instead, it is allocated from a much larger pool of memory managed by the operating system called the heap (aka free store). On modern machines, the heap can be gigabytes in size.[<sup>[3]</sup>](#external-references)

Further reading:
- [learncpp.com | Dynamic memory allocation with new and delete](https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/)

Allocating storage from the heap at runtime.

- We often don't know how much storage we need until we need it
- We can allocate storage for a variable at run time
- Recall C++ arrays
    - We had to provide the size at initialisation and it was fixed.
    - Unlike vectors which grow and shrink dynamically
- We can use pointers to access newly allocated heap storage
- accessing heap-allocated objects is generally slower than accessing stack-allocated objects
- you are responsible for requesting and disposing of dynamically allocated memory (to prevent memory leaks).
- If the pointer to the memory is altered, you lose access to the memory (memory leak)

#### Using `new` to allocate storage

To allocate a single variable dynamically, we use the scalar (non-array) form of the `new` operator:

```c
new int; // dynamically allocate an integer (and discard the result)
```

In the above case, we’re requesting an integer’s worth of memory from the operating system. The new operator creates the object using that memory, and then returns a pointer containing the address of the memory that has been allocated.

Most often, we’ll assign the return value to our own pointer variable so we can access the allocated memory later.

```c
int* int_ptr{ new int }; // dynamically allocate an integer and assign the address to ptr so we can access it later
```

We can then dereference the pointer to access the memory:
```c
*int_ptr = 7; // assign value of 7 to allocated memory
```

On very rare occasions using `new` will fail, for example if there is not heap memory available. By default, if new fails, a `bad_alloc` exception is thrown. An alternate form of `new` that can be used instead to tell `new` to return a null pointer if memory can’t be allocated. This is done by adding the constant `std::nothrow` between the new keyword and the allocation type:

```c
int* value { new (std::nothrow) int }; // value will be set to a null pointer if the integer allocation fails
```
Consequently, the best practice is to check all memory requests to ensure they actually succeeded before using the allocated memory.

#### Using `delete` to deallocate storage

```c
// assume int_ptr has previously been allocated with operator new
delete int_ptr; // return the memory pointed to by int_ptr to the operating system
int_ptr = nullptr; // set int_ptr to be a null pointer
```

If int_ptr is non-null, the dynamically allocated variable will be deleted. If it is null, nothing will happen.

**Best practices**
Set deleted pointers to nullptr unless they are going out of scope immediately afterward.

Deleting a null pointer is okay, and does nothing. There is no need to conditionalise your delete statements.

#### Allocate/deallocate storage for a C- style array

To allocate an array dynamically, we use the array form of new and delete (often called new[] and delete[]):

```c
#include <cstddef>
#include <iostream>

int main()
{
    std::cout << "Enter a positive integer: ";
    std::size_t length{};
    std::cin >> length;

    int* array{ new int[length]{} }; // use array new.  Note that length does not need to be constant!

    std::cout << "I just allocated an array of integers of length " << length << '\n';

    array[0] = 5; // set element 0 to value 5
    std::cout << "Element 0: " << array[0] << '\n';

    delete[] array; // use array delete to deallocate array

    // we don't need to set array to nullptr/0 here because it's going out of scope immediately after this anyway

    return 0;
}
```

Because we are allocating an array, C++ knows that it should use the array version of new instead of the scalar version of new. Essentially, the new[] operator is called, even though the [] isn’t placed next to the new keyword.

### Relationship between arrays and pointers

Further reading: -
- [C course notes | Pointer notation](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/pointer-notation.md)
- [learncpp.com | C-style array decay](https://www.learncpp.com/cpp-tutorial/c-style-array-decay/)
- [learncpp.com | Pointer arithmetic and subscripting](https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting/)

</p>

- The value of an array name is the address of the first element in the array.
- The value of a pointer address is an address.
- If the pointer points to the same data type as the array element then the pointer and array name can be used interchangeably (almost).

As shown below an array name decays to a pointer.
```c
#include <iostream>

int main()
{
    int scores[] {100, 95, 89};

    std::cout << "Memory address of first element of array: " << scores << '\n'; // array name is pointer
    std::cout << "First element of array: " << *scores << '\n'; // deference array name

    return 0;
}
```
**Output**
```bash
Memory address of first element of array: 0x16cffffe14
First element of array: 100
```

#### Subscript and offset notation equivalence

```c
int array_name[] {1,2,3,4,5};
int* pointer_name { array_name};
```

| Subscript Notation | Offset Notation
| --- | --- |
| array_name[index] | *(array_name + index)|
| pointer_name[index] | *(pointer_name + index)|

**Example using subscript notation with array name**
```c
int scores[] {100, 95, 89};

std::cout << "First element address: " << scores << '\n'; // no need for & here
std::cout << "First element of array: " << scores[0] << '\n'; // equivalent to scores + 0bytes
std::cout << "Second element address: " << &scores[1] << '\n'; // equivalent to scores + 4bytes(size of int) + 4bytes(size of int)
std::cout << "Second element of array: " << scores[1] << '\n'; // equivalent to scores + 4bytes(size of int)
std::cout << "Third element address: " << &scores[2] << '\n'; // equivalent to scores + 4bytes(size of int) + 4bytes(size of int)
std::cout << "Third element of array: " << scores[2] << '\n'; // equivalent to scores + 4bytes(size of int) + 4bytes(size of int)
```

**Output**
```bash
First element address: 0xd4b31ff874
First element of array: 100
Second element address: 0xd4b31ff878 // 4bytes larger than first element address
Second element of array: 95
Third element address: 0xd4b31ff87c // 8bytes larger than first element address
Third element of array: 89
```

**Example using pointer subscript notation with pointer name**
```c
int scores[] {100, 95, 89};

int* score_ptr{scores}; // no need for & address-of operator as scores decays to address

std::cout << "First element address: " << score_ptr << '\n';
std::cout << "First element of array: " << score_ptr[0] << '\n'; // equivalent to score_ptr + 0
std::cout << "Second element address: " << &score_ptr[1] << '\n'; // equivalent to score_ptr + 4bytes(size of int) + 4bytes(size of int)
std::cout << "Second element of array: " << score_ptr[1] << '\n'; // equivalent to score_ptr + 4bytes(size of int)
std::cout << "Third element address: " << &score_ptr[2] << '\n'; // equivalent to score_ptr + 4bytes(size of int) + 4bytes(size of int)
std::cout << "Third element of array: " << score_ptr[2] << '\n'; // equivalent to score_ptr + 4bytes(size of int) + 4bytes(size of int)
```

**Output**
```bash
First element address: 0xd4b31ff874
First element of array: 100
Second element address: 0xd4b31ff878 // 4bytes larger than first element address
Second element of array: 95
Third element address: 0xd4b31ff87c // 8bytes larger than first element address
Third element of array: 89
```

## External References
- [udemy.com | Course content | Section 12: Pointers and References](https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/lecture/9535524#questions)
- [learncpp.com | Introduction to pointers](https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/)<sup>[1]</sup>
- [C course notes | Pointers](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/pointers.md)
- [learncpp.com | Lvalue references](https://www.learncpp.com/cpp-tutorial/lvalue-references/)
- [learncpp.com | null pointers](https://www.learncpp.com/cpp-tutorial/null-pointers/)<sup>[2]</sup>
- [learncpp.com | Pointers and const](https://www.learncpp.com/cpp-tutorial/pointers-and-const/)
- [learncpp.com | Dynamic memory allocation with new and delete](https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/)<sup>[3]</sup>
- [learncpp.com | Dynamically allocating arrays](https://www.learncpp.com/cpp-tutorial/dynamically-allocating-arrays/)
- [C course notes | Pointer notation](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/pointer-notation.md)
- [learncpp.com | C-style array decay](https://www.learncpp.com/cpp-tutorial/c-style-array-decay/)
- [learncpp.com | Pointer arithmetic and subscripting](https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting/)
