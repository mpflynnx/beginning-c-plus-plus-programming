## Section 10: Characters and Strings

## Table of Contents
- [Character functions](#character-functions)
- [C-style Strings](#c-style-strings)
    - [cstring library](#cstring-library)
    - [Using C-style Strings exercise](/exercises/section10/Using%20C-style%20Strings%20Exercise/instructions.md)
    - [Using C-style Strings exercise (my solution)](/exercises/section10/Using%20C-style%20Strings%20Exercise/main.cpp)
    - [std::cin functions](#stdcin-functions)
- [C++ Strings](#c-strings)
    - [Declaring and initialising](#declaring-and-initialising)
    - [Assignment](#assignment)
    - [Concatenation](#concatenation)
    - [Accessing characters](#accessing-characters)
    - [Comparing strings](#comparing-strings)
    - [Substrings - substr()](#substrings---substr)
    - [Searching - find()](#searching---find)
    - [Removing - erase() and clear()](#removing---erase-and-clear)
    - [Find number of characters in string](#find-number-of-characters-in-string)
    - [Compound concatenation operator =+](#compound-concatenation-operator)


### Character functions

This header provides [functions](https://en.cppreference.com/w/cpp/string/byte#Functions) for working with characters. It comes from the C programming language. To use this functions with C++ you include the header `cctype.h`

```c
#include <cctype>
```
This header is part of the [null-terminated byte strings library](https://en.cppreference.com/w/cpp/string/byte).

### C-style Strings

C-style strings refer to the string usage of the C programming language also known as zero-terminated or null-terminated strings. 

`\0` null terminator is 1 bit.

```c
char my_name[] {"Frank"}; // Stored as Frank\0

char my_surname[8] {"Jones"}; // Stored as Jones\0\0\0

my_surname[5] = 's'; // Stored as Joness\0\0
```

#### cstring library
Functions that work with C-style strings are contained in the header [cstring](https://en.cppreference.com/w/cpp/header/cstring). Functions include those from the C programming language such as [strcpy](https://en.cppreference.com/w/cpp/string/byte/strcpy), [strcat](https://en.cppreference.com/w/cpp/string/byte/strcpy) and [strlen](https://en.cppreference.com/w/cpp/string/byte/strlen).

**Note:** Many functions in the cstring header are considered unsafe to use. For example, it is possible to concatenate using `strcat' to a string and on go over the char array size into the next memory location. It's recommended avoiding C style strings whenever possible. Use std::string whenever possible and the Microsoft recommended security enhancements to the C std lib when you absolutely must work with C strings.

Visual Studio 2022 we flag [unsafe C-style functions](https://stackoverflow.com/questions/936468/why-does-msvc-consider-stdstrcat-to-be-unsafe-c) and recommend alternatives such as `strcat_s`.

**Example**
```c
#include <cstring>
#include <iostream>

int main()
{

    char my_middle_name[8]; // Uninitialised, bad practice
    // my_middle_name = "David"; // Error, cannot do this, see below.

    strcpy(my_middle_name, "David"); // OK, but strcpy unsafe

    std::cout << my_middle_name;

    size_t length {strlen(my_middle_name)};
    std::cout << "Middle name length: " << length << '\n';

    return 0;
}
 ```

`strlen` returns a [size_t](https://en.cppreference.com/w/cpp/types/size_t) unsigned integer type, which is compatible with any operating system.

To convert null-terminated strings to other types, header [cstdlib](https://en.cppreference.com/w/cpp/header/cstdlib) is available.

### std::cin functions


`std::cin` contains a function called [getline()](https://en.cppreference.com/w/cpp/string/basic_string/getline). getline reads characters from an input stream and places them into a string, it ignores spaces in the input stream.

**Example**
```c
#include <cstring>
#include <iostream>

int main()
{

    char full_name[50];
    std::cout << "Enter your full name: ";
    std::cin.getline(full_name, 50);

    std::cout << full_name << '\n';

    return 0;
}
```

### C++ Strings

- std::string is a Class in the Standard Template Library (STL)

```c
#include <string>
```

- within the std namespace
- dynamic in size unlike C-style strings which are fixed
- works with input and output stream <<, >>
- many [useful member functions](https://en.cppreference.com/w/cpp/string/basic_string) (methods)
- can use familiar operators (+, = , <, > .. etc)
- can be converted to C-style strings if needed
- much safer built in bounds checking


#### Declaring and initialising
Initialiser syntax shown.

```c
#include <string>

...

std::string s1; // Empty, initialised by default
std::string s2 ("Frank"); // Frank (Converts C-style literal to C++ string)
std::string s3 {s2}; // creates a new copy of Frank in memory
std::string s4 {"Frank", 3}; // Fra
std::string s5 {s3, 0, 2}; // Fr, 0 is start index, 2 is length
std::string s6 (3, 'X'); // XXX, constructor syntax
```

#### Assignment

```c

std::string s1;
s1 = "C++ Rocks!"; // s1 grows dynamically as needed

std::string s2 {"Hello World!}; 
s2 = s1; // Copies s1 into s2;
```

#### Concatenation

```c
std::string part1 {"C++"};
std::string part2 {"is a powerful"};

std::string sentence;

sentence = part1 + " " + part2 + " language";
```

#### Accessing characters

Array syntax [] has no bounds checking (not recommended).

```c
std::string s2 {"Frank"};
std::cout << s2[0] << '\n'; // output: F
```

.at() performs bounds checking (recommended)

```c
std::string s2 {"Frank"};
std::cout << s2.at(0) << '\n'; // output: F 
```

Accessing string characters using a range-based for loop.
```c
std::string s1 {"Frank"};

for (char c: s1)
    std::cout << c << '\n';
```

**Output**
```bash
F
r
a
n
k
```

```c
std::string s1 {"Frank"};

for (int c: s1) // int type not char type
    std::cout << c << '\n';
```
**Output**
```bash
70 // Ascii int for F
114 // Ascii int for r
97 // Ascii int for a
110 // Ascii int for n
107 // Ascii int for k
0 // null character is not printable so will not appear here
```

#### Comparing strings

Can use operators ==, !=, >, >=, <, <= on C+=+ strings, but no C-style strings, unless comparing a C++ string to a C-style string

Object are compared character by character lexically. A is less than Z. A less than a. Capital letters first in ASCII table.

```c
string s1 {"Apple"}; // C++ string

s1 == "Apple"; // Returns true, "Apple" is a C-style string literal, and can be used in this case.
```

#### Substrings - substr()

[substr()](https://en.cppreference.com/w/cpp/string/basic_string/substr) extracts a substring from a C++ string.

```c
std::string s1 {"This is a test"};

std::cout << s1.substr(0,4); // This
std::cout << s1.substr(5,2); // is
std::cout << s1.substr(0,4); // test
```

#### Searching - find()
[find()](https://en.cppreference.com/w/cpp/string/basic_string/find) returns the start index of a substring.

```c
std::string s1 {"This is a test"};

std::cout << s1.find("This"); // index 0
std::cout << s1.find("is"); // index 2
std::cout << s1.find("test"); // index 10
std::cout << s1.find("is", 4); // starts at index 4 finds "is" at index 5
```

Checking for [npos](https://en.cppreference.com/w/cpp/string/basic_string/npos) to determine if string literal `"XXX"` is within C++ string `s1`.
```c

if (s1.find("XXX") == s1.npos)
    std::cout << "no 'XXX' in 's1'\n";
```

#### Removing - erase() and clear()

Removing a substring of characters using [erase()](https://en.cppreference.com/w/cpp/string/basic_string/erase) or [clear()](https://en.cppreference.com/w/cpp/string/basic_string/clear)

```c
std::string s1 {"This is a test"};
                
s1.erase(0, 5); // removes "this "
std::cout << s1 << '\n'; // s1 == "is a test"
s1.erase(5,4); // removes "test" from updated s1. 5 is start index, 4 num of chars
std::cout << s1 << '\n'; // s1 == "is a"

s1.clear(); // empties string s1
std::cout << s1 << '\n'; // s1 == ""
```

#### Find number of characters in string

Find the legth of a string using [size / length](https://en.cppreference.com/w/cpp/string/basic_string/size) functions.

```c
std::string s1 {"This is a test"};

// length()              
std::cout << s1.length() << '\n'; // 14 chars incl spaces

//size()
std::cout << s1.size() << '\n'; // 14 chars incl spaces
```

#### Compound concatenation operator

[operator +=](https://en.cppreference.com/w/cpp/string/basic_string/operator%2B%3D) appends additional characters to the string.

```c
std::string s1 {"This is a test"};

s1 += ". Honest." ;    
std::cout << s1 << '\n'; // This is a test. Honest.
```

## References
[Character functions using `<cctype>`](https://en.cppreference.com/w/cpp/string/byte#Functions)
[null-terminated byte strings library](https://en.cppreference.com/w/cpp/string/byte)
[C-style functions header `<cstring>`](https://en.cppreference.com/w/cpp/header/cstring)
[Standard library header `<cstdlib>`](https://en.cppreference.com/w/cpp/header/cstdlib)
[cin.getline()](https://en.cppreference.com/w/cpp/string/basic_string/getline)
[Why is strcat unsafe?](https://stackoverflow.com/questions/936468/why-does-msvc-consider-stdstrcat-to-be-unsafe-c)
[C++ string member functions](https://en.cppreference.com/w/cpp/string/basic_string)
[C++ string operation functions](https://en.cppreference.com/w/cpp/string/basic_string#Operations)