## Reverse a std::string using Pointers

- [udemy.com | Reverse a std::string using Pointers](https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/quiz/5900290#questions)

Exercise: Reverse a std::string using Pointers

Specification:

Write a C++ function reverse_string that takes a std::string as input and returns a new std::string with the characters in reverse order. **The function should use pointers to perform the reversal**.

Function Signature:

```c
std::string reverse_string(const std::string& str);
```

Input:

- str: The input string.

Output:

- The function should return a new string with the characters of str reversed.

Example:

```c
std::string input = "Hello, World!";
std::string reversed = reverse_string(input);
 
// reversed should be "!dlroW ,olleH"
```

[Instructors solution](/exercises/section12/reverse-a-std-string-using-pointers/instructors-solution.md)