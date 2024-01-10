## C++ Keywords

`C++` has over 90 [keywords](https://en.cppreference.com/w/cpp/keyword). These are words that are reserved and cannot be used for variables, function names etc. We have seen the use of `int` and `return` keywords.

Identifiers are names created by programmers, such as a variable names or built-in library objects such as `cout`, `cin` or namespaces etc.

## C++ Preprocessor

**Preprocessor examples**
```c
#include <iostream>
#include "myfile.h"
```

The `C++` [preprocessor](https://en.cppreference.com/w/cpp/preprocessor) is a program that processes source code before the compiler. 

- It strips all comments from the source file, and replaces a comment with a single space.

- It executes any preprocessor directives.
- It removes any preprocessor directives from the source code.

## Comments

**Single line comment**
```c
// This is a single line comment.
```

**Multiple line comment**
```c
/* 
This is 
a multiple
line comment.
*/
```

## The main() function

- Every `C++` program must have exactly 1 main() function. 

- This is the starting point of the program.

- return 0 indicates successful program execution

**main() versions**

```c
int main()
{
    // code
    return 0;
}
```

```c
int main(int argc, char *argv[])
{
    // code
    return  0;
}
```

## Namespaces

Namespaces are used to prevent naming conflicts. `std::cout` the programmer explicitly declares the namespace and object in their code.

**`cout` usage not using a namespace directive**
```c
std::cout << "Enter your favorite number between 1 and 100? ";
```

To save typing `std::cout` repeatedly, use a namespace directive.

Use all objects from the std(standard) namespace, **not recommended**.
```c
#include <iostream>

using namespace std;
```

Use only the objects declared from the std(standard) namespace.
```c
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
```

**`cout` usage using a namespace directive**
```c
cout << "Enter your favorite number between 1 and 100? ";
```