## Section 12: References

## Table of Contents

- [What is a Reference?](#what-is-a-reference)
- [Using references in range-based for loops](#using-references-in-range-based-for-loops)
- [L-values](#l-values)
- [R-values](#r-values)
- [l-value references](#l-value-references)
- [When to use pointers verses reference parameters](#when-to-use-pointers-verses-reference-parameters)

### What is a Reference?

- An alias for a variable
- Must be initialised to a variable when declared
- Cannot be null
- Once initialised cannot be made to refer to a different variable
- Very useful as function parameters
- Thinks of a reference as a const pointer than automatically deferences 

Futher reading:
- [learncpp.com | Lvalue references](https://www.learncpp.com/cpp-tutorial/lvalue-references/)
### Using references in range-based for loops

`str` is not a reference in the example below. `str` is a copy, so the first range-based loop does nothing to the vector.

```c
#include <iostream>
#include <vector>
#include <string>

int main() {

   std::vector<std::string> stooges { "Larry", "Moe", "Curly"};

   for (auto str: stooges) // changes a copy of vector
      str = "Funny"; 

   for (auto str: stooges)
      std::cout << str << '\n';

   return 1;
}
```

**Output**
```bash
Larry
Moe
Curly
```

Changing `str` to `&str` in both ranged-based loop makes `str` a reference to the vector not a copy. This saves memory created copies, but allows the vector to be modifiable. 

Therefore the output will be

**Output**
```bash
Funny
Funny
Funny
```

We should add the keyword `const` before `&str` in the second range-based loop, as this loop is only required to output the vector. Adding `const` and then trying to update the reference will result in a compiler error.

```c
   for (auto const &str: stooges)
      std::cout << str << '\n';
```

Always use references in range-based for loops to save creating copies of array or vectors.

### L-values

Futher reading:
- [learncpp.com | Value categories (lvalues and rvalues)](https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/)
- [cppreference.com | Value categories](https://en.cppreference.com/w/cpp/language/value_category)

Used with r-values in more advanced programming techniques with C++.

Prior to C++11, there were only two possible value categories: l-value and r-value.

In C++11, three additional value categories (gl-value, pr-value, and x-value) were added to support a new feature called move semantics.

l-values:-
- are values that have names
- have an address that can be stored in a pointer
- can be modified if not made constant
- can appear on the left-hand and right-hand side of a assignment statement

```c
// l-value examples
int x {111};   // x is an l-value
x = 1000;      // x is modified
x = 1000 + 20;

std::string my_name; // my_name is an l-value;
my_name = "John";    // my_name is modified

// invalid l-values
100 = x;              // 100  is NOT an l-value
(1000 + 20) = x;      // (1000 + 20) is NOT an l-value
std::string my_name;
my_name = "John";
"John" = my_name; // "John" is NOT an l-value
```

### R-values

Anything that is  not a l-value is a r-value.

r-values are: -
- non-addressable and non-assignable
- on the right-hand side of an assignment expression
- a literal
- a temporary (created by the compiler) which is intended to be non-modifiable 

```c
// r-value examples
int x {111};   // 111 is an r-value
int y = x + 20; // (x +20) is an r-value

std::string my_name; 
my_name = "John";    // "Frank" is an r-value

int max = max(20,30); // max(20,30) is an r-value
```

r-values can be assigned to l-values explicitly.

```c
int x {100};
int y {0};

y = 111; // r-value 111 assigned to l-value y
x = x + y; // r-value (x+y) assigned to l-value x
```

**Key insight**

A rule of thumb to identify l-value and r-value expressions:

- L-value expressions are those that evaluate to variables or other identifiable objects that persist beyond the end of the expression.
- R-value expressions are those that evaluate to literals or values returned by functions/operators that are discarded at the end of the expression.

### l-value references

Commonly just called a reference since prior to C++11 there was only one type of reference.

Further reading:
- [learncpp.com | Lvalue references](https://www.learncpp.com/cpp-tutorial/lvalue-references/)

l-value references reference l-values.

```c
int x {111};

int& ref1 {x}; // ref1 is a reference to l-value x
ref1 = 1111;

int& ref2 = 100; // error 100 is an r-value
```

Take function `square` below, it expects a l-value
```c
int square(int &n) {
   return n*n;
}

int num {111};

square(num); // pass by reference num

square(5); // error as 5 cannot be referenced, it has no address (r-value)
```

### When to use pointers verses reference parameters

Further reading:
- [learncpp.com | Pass by lvalue reference](https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/)
- [learncpp.com | Pass by const lvalue reference](https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/)

Use pass-by-value when:
- The function does **not** modify the actual parameter
- the parameter is small and efficient to copy simple types (int, charm double etc)

Use pass-by-reference with a pointer when:
- the function **does** modify the actual parameter
- the parameter is expensive to copy (vectors, std::string, etc)
- its okay for the the pointer to be `nullptr` (references cannot be null)

Use pass-by-reference with pointer to `const` when:
- the function does **not** modify the actual parameter
- the parameter is expensive to copy
- its okay for the pointer to be `nullptr`

Use pass-by-reference with `const` pointer to `const` when:
- the function does **not** modify the actual parameter
- the parameter is expensive to copy
- the pointer will **not** be modified

Use pass-by-reference using a reference when:
- the function **does** modify the actual parameter
- the parameter is expensive to copy
- the parameter will never need to be `nullptr`

Use pass-by-reference using a `const` reference when:
- the function does **not** modify the actual parameter
- the parameter is expensive to copy
- the parameter will never need to be `nullptr`

[Return to top](#table-of-contents)

## External References
- [udemy.com | Course content | Section 12: References](https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/lecture/9535548#questions)
- [learncpp.com | Value categories (lvalues and rvalues)](https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/)
- [cppreference.com | Value categories](https://en.cppreference.com/w/cpp/language/value_category)
- [learncpp.com | Lvalue references](https://www.learncpp.com/cpp-tutorial/lvalue-references/)
- [learncpp.com | Pass by lvalue reference](https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/)
- [learncpp.com | Pass by const lvalue reference](https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/)