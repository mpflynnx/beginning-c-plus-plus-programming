## Section 12: Pointers and References

## Table of Contents

- [Pointers](#pointers)

- [External References](#external-references)

### Pointers
Further reading:
- [learncpp.com | Introduction to pointers](https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/)
- [C course notes | Pointers](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/pointers.md)

In modern C++, the pointers we are talking about here are sometimes called “raw pointers” or “dumb pointers”, to help differentiate them from “smart pointers” that were introduced into the language more recently.

**What is a Pointer?**
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

- Pointers can be used inside functions to work on data that is out of scope.
- Pointers can work very efficiently with large arrays (no need to duplicate arrays in memory)
- We can allocate memory dynamically on the heap or free store.
    - This memory doesn't have a variable name.
    - The only way to get to it is via a pointer.

- With Object Oriented Programming, pointers are how polymorphism works.

- Can access specific addresses in memory
    - useful in embedded and systems applications

## External References
- [udemy.com | Course content | Section 12: Pointers and References](https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/lecture/9535524#questions)
- [learncpp.com | Introduction to pointers](https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/)
- [C course notes | Pointers](https://github.com/mpflynnx/c-programming-for-beginners/blob/main/docs/pointers.md)