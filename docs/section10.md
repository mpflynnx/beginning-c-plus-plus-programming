## Section 10: Characters and Strings

## Table of Contents
- [Character functions](#character-functions)
- [C-style Strings](#c-style-strings)


### Character functions

This header provides [functions](https://en.cppreference.com/w/cpp/string/byte#Functions) for working with characters. It comes from the C programming language. To use this functions with C++ you include the header `cctype.h`

```c
#include cctype.h
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

Functions that work with C-style strings are contained in the header [cstring](https://en.cppreference.com/w/cpp/header/cstring). Functions include those from the C programming language such as [strcpy](https://en.cppreference.com/w/cpp/string/byte/strcpy), [strcat](https://en.cppreference.com/w/cpp/string/byte/strcpy) and [strlen](https://en.cppreference.com/w/cpp/string/byte/strlen).

**Example**
```c
#include <cstring>
#include <iostream>

int main()
{

    char my_middle_name[8]; // Uninitialised, bad practice
    // my_middle_name = "David"; // Error, cannot do this, see below.

    strcpy(my_middle_name, "David"); // OK

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




## References
[Character functions using `<cctype>`](https://en.cppreference.com/w/cpp/string/byte#Functions)
[null-terminated byte strings library](https://en.cppreference.com/w/cpp/string/byte)
[C-style functions header `<cstring>`](https://en.cppreference.com/w/cpp/header/cstring)
[Standard library header `<cstdlib>`](https://en.cppreference.com/w/cpp/header/cstdlib)
[cin.getline()](https://en.cppreference.com/w/cpp/string/basic_string/getline)