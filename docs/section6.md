## Section6: Variables and Constants

### Declaring and initialising variables

### Naming variables
- Can contain letters, numbers and underscores, but no spaces

- Must begin with a letter or underscore(_)

- Cannot use C__ reserved keywords

- Cannot redeclare a name in the same scope

- C++ is case sensitive

### Variable naming style and best practice
Many companies have there own style guides. See the [Google C++ Style guide](https://google.github.io/styleguide/cppguide.html) as an example.

- Be consistent with your naming conventions
- myVariableName verses my_variable_name
- Avoid beginning names with underscores (_)
- Use meaningful names
- Not too long or too short
- Never use variables before initialising them
- Declare variables close to when you need them

### Initialising local variable examples

Local variables are scoped to a function.

```c
int age; // uninitialised, random value.
int age {0}; // best practice
int age = 21; // C language initialisation
int age (21); // Constructor initialisation
int age {21}; // C++11 list initialisation syntax (recommended)
```

### Example program using int type variables
```c
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{

    cout << "Enter the width of the room: ";
    int room_width {0};
    cin >> room_width;

    cout << "Enter the length of the room: ";
    int room_length {0};
    cin >> room_length;
    
    cout << "The area of the room is: " << room_width * room_length << endl;

    return 0;
}
```

**Output**
```bash
Enter the width of the room: 5
Enter the length of the room: 5
The area of the room is: 25
```

### Global variables

- Global variables are defined outside of a function and are automatically initialised.
- Global variables can be accessed or changed from any part of the program. (**Use them with caution**)
- Local variables are scoped to a function and take precedence over global variables if the names match.

### Built-in Primitive Types

- Sometimes called fundamental data types as they are implemented directly by the C++ language.

- Character types
- Integer types
    - signed and unsigned
- Floating-point types
- Boolean type

- Size and precision is often target machine and compiler-dependent
    - #include <climits>

### Types sizes
- Expressed in bits
- The more bits the more values that can be represented
- The more bits the more storage required

| **Size (in bits)** | **Representable Values** |
|--------------|--------------|
| 8 | 256 |
| 16 | 65536 |
| 32 | 2,147,483,647 |
| 64 | 18446744073709551615 |


### Character Types

- Used to represent single characters
- Wider types are used to represent wide character sets, used by different languages used around the world.

| **Type Name** | **Size / Precision** |
|--------------|--------------|
| char | Exactly one byte. At least 8 bits. |
| char16_t | At least 16 bits. |
| char32_t | At least 32 bits. |
| wchar_t | Can represent the largest available character set. |

**Char type example usage**
```c
char middle_initial {'J'}; // single quotes around character
```

### Integer Types
- Used to represent whole numbers
- Signed and unsigned versions

**Integer type example usage**
```c
unsigned short int exam_score {55}; // don't need to specify int 

unsigned short {55}; // same as above

int countries_represented {65}; // same as signed short

long people_in_london {7800000};

long long people_on_earth {7'600'000'000}; // C++14 allows ` to break up number

long long distance_to_alpha_centauri {9'461'000'000'000};
```

**Overflow error example**

Try to fit a long number into a `int`, will result in the following error.
```bash
main.cpp: In function ‘int main()’:
main.cpp:22:27: warning: overflow in conversion from ‘long int’ to ‘int’ changes value from ‘76000000000’ to ‘-1309411328’ [-Woverflow]
   22 |     int people_on_earth = 76000000000;
```

### Floating-point Types
- Used to represent non-integer numbers (real numbers)
- Represented by mantissa and exponent (scientific notation)
- Precision is the number of digits in the mantissa
- Precision and size are compilier dependent

| **Type Name** | **Size / Precision** |
|--------------|--------------|
| float | / 7 decimal digits |
| double | No less than float / 15 decimal digits |
| long double | No less than double / 19 decimal digits |

**Float type example usage**
```c
float car_payment {401.23};

double pi {3.14159};

long double large_amount {2.7e120};
```

### Boolean Type

- Used to represent true and false
- Zero is false
- Non-zero is true

| **Type Name** | **Size / Precision** |
|--------------|--------------|
| bool | Usually 8 bits, true or false (C++ keywords) |

**bool type example usage**
```c
bool game_over {false};
cout << "The value of game_over is " << game_over << endl; // Output: The value of game_over is 0
```

### Overflow examples

```c
1    short value1 {30000};
2    short value2 {1000};
3    short product {value1 * value2}; 
4    
5    cout << "The sum of" << value1 << " and " << value2 << " is " << product << endl;
```

The product of `value1` and `value2` will not fit into a `short`.
The IDE may flag the problem with line 3 before you attempt to compile. Compile will work with a warning as shown below. 

```bash
main.cpp: In function ‘int main()’:
main.cpp:42:23: warning: narrowing conversion of ‘(((int)value1) * ((int)value2))’ from ‘int’ to ‘short int’ [-Wnarrowing]
   42 |     short sum {value1 * value2};
```
Runtime error shown below.
```bash
The sum of30000 and 1000 is -15488
```

### sizeof operator
- The `sizeof` operator determines the size in bytes of a type or variable for the machine the program is run on.

**sizeof example usage**
```c
sizeof(int)
sizeof(double)
sizeof(some_variable_name)
sizeof some_variable_name // parenthesis optional for variables
```

```c
int int_size {sizeof(int)};
cout << "int size is " << int_size << " bytes" << endl;
```

**Output**
```bash
int size is 4 bytes
```

The `sizeof` operator gets it information from `<climits>` and `<cfloat>` include files.

`<climits>` for integral types.
'<cfloat>` for floating point types

These files also provide constants: -

- INT_MAX
- INT_MIN
- LONG_MIN
- LONG_MAX
- FLT_MIN
- FLT_MAX
- .. and many more

### Example usage of `sizeof` for integrals
```c
#include <iostream>
#include <climits> // wasn't needed, according to clangd (https://clangd.llvm.org/)

using std::cout;
using std::endl;

int main()
{
    cout << "sizeof information" << endl;
    cout << "================================" << endl;
    cout << "char:         " << sizeof(char) << " bytes." << endl;
    cout << "int:          " << sizeof(int) << " bytes." << endl;
    cout << "unsigned int: " << sizeof(unsigned int) << " bytes." << endl;
    cout << "short:        " << sizeof(short) << " bytes." << endl;
    cout << "long:         " << sizeof(long) << " bytes." << endl;
    cout << "long long:    " << sizeof(long long) << " bytes." << endl;
    
    return 0;
```
**64bit complier output**

```bash
sizeof information
================================
char:         1 bytes.
int:          4 bytes.
unsigned int: 4 bytes.
short:        2 bytes.
long:         8 bytes.
long long:    8 bytes.
```
### Example usage of `sizeof` for floats
```c
#include <iostream>
#include <climits> // wasn't needed according to clangd

using std::cout;
using std::endl;

int main()
{
    cout << "sizeof information" << endl;
    cout << "================================" << endl;
    cout << "float:       " << sizeof(float) << " bytes." << endl;
    cout << "double:      " << sizeof(double) << " bytes." << endl;
    cout << "long double: " << sizeof(long double) << " bytes." << endl;
    
    return 0;
}
```
**64bit complier output**

```bash
sizeof information
================================
float:       4 bytes.
double:      8 bytes.
long double: 16 bytes.
```

### Example usage of `<climits>` _MIN constants

```c
#include <iostream>
#include <climits>

using std::cout;
using std::endl;

int main()
{
    cout << "Minimum values:" << endl;
    cout << "char:      " << CHAR_MIN << endl;
    cout << "int:       " << INT_MIN << endl;
    cout << "short:     " << SHRT_MIN << endl;
    cout << "long:      " << LONG_MIN << endl;
    cout << "long long: " << LLONG_MIN << endl;
    return 0;
}
```

**64bit complier output**
```bash
Minimum values:
char:      -128
int:       -2147483648
short:     -32768
long:      -9223372036854775808
long long: -9223372036854775808
```

### Example usage of `<climits>` _MAX constants

```c
#include <iostream>
#include <climits>

using std::cout;
using std::endl;

int main()
{
    cout << "Maximum values:" << endl;
    cout << "char:      " << CHAR_MAX << endl;
    cout << "int:       " << INT_MAX << endl;
    cout << "short:     " << SHRT_MAX << endl;
    cout << "long:      " << LONG_MAX << endl;
    cout << "long long: " << LLONG_MAX << endl;
    return 0;
}
```

**64bit complier output**
```bash
Maximum values:
char:      127
int:       2147483647
short:     32767
long:      9223372036854775807
long long: 9223372036854775807
```

### Example usage of `sizeof` with variable names

```c
#include <iostream>

using std::cout;
using std::endl;

int main()
{

    cout << "size of using variable names" << endl;
    int age {21};
    cout << "age is " << sizeof(age) << " bytes." << endl;
    cout << "age is " << sizeof age << " bytes." << endl;

    double wage {22.35};
    cout << "wage is " << sizeof(wage) << " bytes." << endl;
    cout << "wage is " << sizeof wage << " bytes." << endl;
    
    return 0;
}
```
**64bit complier output**
```bash
size of using variable names
age is 4 bytes.
age is 4 bytes.
wage is 8 bytes.
wage is 8 bytes.
```

### What is a constant?

- Like C++ variables
- Have names
- Occupy storage
- Are usually typed
- Their value cannot change once declared

**Types of constants**
- Literal constants
- Declared constants ***(preferred over literal)**
    - const keyword
- Constant expressions
    - constexpr keyword
- Enumerated constants
    - enum keyword
- Defined constants
    - #define

### Literal constant examples

```c
x = 12;
y = 1.56;
name = "Frank";
middle_initial = 'J';
```

- Integer literal constants
    - 12 - an integer
    - 12U - an unsigned integer
    - 12L - a long integer
    - 12LL - a long long integer

- Floating-point literal constants
    - 12.1 - a double
    - 12.1F - a float
    - 12.L - a long double

- Character literal constants (escape codes)
    - \n    - newline
    - \r    - return
    - \t    - tab
    - \b    - backspace
    - \'    - single quote
    - \"    - double quote
    - \\    - backslash

```c
cout << "Hello\tthere\nmy friend\n";
```
**Output**
```bash
Hello   there
my friend
```
### Declared constants

Constants declared using `const` keyword.

```c
const double pi {3.1415926};

const int months_in_year {12};
```
Trying to update a constant.

```c
pi = 2.5; // compiler error
```
IDE warning: Cannot assign to variable 'pi' with const-qualified type

### Preprocessor defined constant
Don't use this in modern `C++`, this is `C` style.
```c
#define pi 3.1415926
```

