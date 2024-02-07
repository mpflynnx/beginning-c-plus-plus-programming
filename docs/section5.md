## Section5: Structure of a C++ 

## Table of Contents
- [C++ Keywords](/docs/section5.md#c-keywords)
- [C++ Preprocessor](/docs/section5.md#c-preprocessor)
- [Comments](/docs/section5.md#comments)
- [The main() function](/docs/section5.md#the-main-function)
- [Namespaces](/docs/section5.md#namespaces)
- [Basic I/O using cin and cout](/docs/section5.md#basic-io-using-cin-and-cout)
- [cout and <<](/docs/section5.md#cout-and)
- [cin and >>](/docs/section5.md#cin-and)
- [cout examples](/docs/section5.md#cout-examples)
- [cout, cin example1 using integers](/docs/section5.md#cout-cin-example1-using-integers)
- [cout, cin example2 using integers](/docs/section5.md#cout-cin-example2-using-integers)
- [cout, cin example3 using integers](/docs/section5.md#cout-cin-example3-using-integers)
- [cout, cin example4 using doubles](/docs/section5.md#cout-cin-example4-using-doubles)
- [cout, cin example5 using integers and doubles](/docs/section5.md#cout-cin-example5-using-integers-and-doubles)

### C++ Keywords

`C++` has over 90 [keywords](https://en.cppreference.com/w/cpp/keyword). These are words that are reserved and cannot be used for variables, function names etc. We have seen the use of `int` and `return` keywords.

Identifiers are names created by programmers, such as a variable names or built-in library objects such as `cout`, `cin` or namespaces etc.

Identifiers cannot start with a number or have spaces.

### C++ Preprocessor

**Preprocessor examples**
```c
#include <iostream>
#include "myfile.h"
```

The `C++` [preprocessor](https://en.cppreference.com/w/cpp/preprocessor) is a program that processes source code before the compiler. 

- It strips all comments from the source file, and replaces a comment with a single space.

- It executes any preprocessor directives.
- It removes any preprocessor directives from the source code.

### Comments

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

### The main() function

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

For accepting arguments at program execution via command line.
```c
int main(int argc, char *argv[])
{
    // code
    return  0;
}
```

### Namespaces

Namespaces are used to prevent naming conflicts. `std::cout` the programmer explicitly declares the namespace `std` and object `count` for use in the source code.

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

Use only the objects used from the std(standard) namespace.
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

### Basic I/O using cin and cout

preprocessor `#include <iostream>` required.

`cout`, `cin`, `cerr` and `clong` are objects representing streams.

`cout`
- standard output stream
- to console

`cin`
- standard input stream
- default from keyboard, ignores whitespace

`<<`
- insertion operator
- output to stream

`>>`
- extraction operator
- input from stream

### cout and <<
- Insert the data variable into the `cout` stream
```c
cout << data;
```

- Can be chained
```c
cout << "data 1 is " << data1;
```

- Does not automatically add line breaks

```c
cout << "data 1 is " << data1 << endl>>;
cout << "data 1 is " << data1 << "\n">>;
```

`endl` will also flush the stream.

### cin and >>
- Extract data from `cin` stream based on data's type.

```c
cin >> data;
```
if `data` is an `integer` then an integer is stored.
if `data` is an `double` then a real number is stored.

- can be chained.
```c
cin >> data1 >> data2;
```

- New lines (pressing enter) terminate the extraction from cin.
- Spaces entered on console, will be ignored.

- It can fail if the type entered cannot be interpreted. For example `data` is of type `int`, but a `string` is entered on the console. `data` will have an undetermined value.

### cout examples

```c
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    cout << "Hello world!"; // No newline
    cout << "Hello world!" << endl;
    cout << "Hello "; // No newline
    cout << "world!" << endl;
    cout << "Hello" << " world!" << endl;
    cout << "Hello" << " world!\n"; // uses \n as newline
    cout << "Hello\nOut\nThere\n"; // uses \n aas newline

    return 0;
}
```

**Output**

```bash
Hello world!Hello world!
Hello world!
Hello world!
Hello world!
Hello
Out
There
```

### cout, cin example1 using integers

```c
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{

    int num1;
    cout << "Enter an integer: ";
    cin >> num1;
    cout << "You entered: " << num1 << endl;

    return 0;
}
```

**Output**
```bash
Enter an integer:                   7                 
You entered: 7
```
### cout, cin example2 using integers

```c
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{

    int num1;
    int num2;

    cout << "Enter an integer: ";
    cin >> num1;

    cout << "Enter a second integer: ";
    cin >> num2;

    cout << "You entered " << num1 << " and " << num2 << "." << endl;

    return 0;
}
```

**Output**
```bash
Enter an integer:     45
Enter a second integer:     23
You entered 45 and 23.
```

Here, `cin` is stored in a buffer, the buffer is not flushed, therefore the second integer is read from the buffer into `num2`, without the prompt being needed.

**Output**
```bash
Enter an integer:  23           99
Enter a second integer: You entered 23 and 99.
```

### cout, cin example3 using integers

Here, `cin` is chained to retrieve two integers from the buffer. This saves having to prompt the user multiple times.

```c
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{

    int num1;
    int num2;

    cout << "Enter two integers separated by a space: ";
    cin >> num1 >> num2; // cin chained
    cout << "You entered " << num1 << " and " << num2 << "." << endl;

    return 0;
}
```

**Output**
```bash
Enter two integers separated by a space:      34      78
You entered 34 and 78.
```
### cout, cin example4 using doubles

```c
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{

    double num3;

    cout << "Enter a double: ";
    cin >> num3;
    cout << "You entered " << num3 << endl;

    return 0;
}
```

Here, the user entered a space between the double, so only the first part of the number was stored.

**Output**
```bash
Enter a double:        45    .   78
You entered 45
```

**Output**
```bash
Enter a double: 45.6
You entered 45.6
```
Here, a integer was entered and a integer is displayed.

**Output**
```bash
Enter a double: 23
You entered 23
```

### cout, cin example5 using integers and doubles

```c
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{

    int num1;
    double num3;

    cout << "Enter an integer: ";
    cin >> num1;

    cout << "Enter a double: ";
    cin >> num3;

    cout << "The integer is: " << num1 << endl;
    cout << "And the double is: " << num3 << endl;

    return 0;
}
```

```bash
Enter an integer: 10
Enter a double: 12.5
The integer is: 10
And the double is: 12.5
```

Here, a integer `10` and a double `.5` is found in the input stream and stored without the prompt need for the double prompt.

```bash
Enter an integer: 10.5
Enter a double: The integer is: 10
And the double is: 0.5
```

Here, a string was entered not a integer, with unpredicted results.

```bash
Enter an integer: hello world
Enter a double: The integer is: 0
And the double is: 6.8991e-310
```

**Note:** In the real world `cin` would not be used to read numbers, a string would be read and then cast into a number.