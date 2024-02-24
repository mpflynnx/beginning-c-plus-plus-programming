## Section 12: References

## Table of Contents

- [References](#references)
    - [What is a Reference?](#what-is-a-reference)
    - [Using references in range-based for loops](#using-references-in-range-based-for-loop)


### References

#### What is a Reference?

- An alias for a variable
- Must be initialised to a variable when declared
- Cannot be null
- Once initialised cannot be made to refer to a different variable
- Very useful as function parameters
- Thinks of a reference as a const pointer than automatically deferences 

#### Using references in range-based for loops

`str` is not a reference in the example below `str` is a copy, so the first range-based loop does nothing to the vector.

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

We should add the keyword `const` before `str` in the second range-based loop, as this loop is only outputting the vector. Adding `const` and then trying to update the reference will result in a compiler error.

```c
   for (auto const &str: stooges)
      std::cout << str << '\n';
```

Always use references in range-based for loops to save creating copies of array or vectors.



[Return to top](#table-of-contents)

## External References
- [udemy.com | Course content | Section 12: References](https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/lecture/9535548#questions)
- []()