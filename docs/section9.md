## Section 9: Controlling program flow

### If statement

**Example**
```c
int age {17};

if (age >= 16)
    std::cout << "Yes - you can drive!";
```
**Output**
```bash
Yes - you can drive!
```

### If else statement

**Example**
```c
int age {14};

if (age >= 16){
    std::cout << "Yes - you can drive!";
} else {
    int n {16 - age};
    std::cout <<  "Sorry, come back in " << n  << " years";
}
```
**Output**
```bash
Sorry, come back in 2 years
```

### If else if

```c
int score = 74;

if (score >= 90)
    std::cout << 'A';
else if (score >= 80)
    std::cout << 'B';
else if (score >= 70)
    std::cout << 'C';   
else
    std::cout << 'F';
```

**Output**
```bash
C
```

### Nested If statement

**Example**
```c
int age {16};
bool has_car {false};

if (age >= 16) {
    if (has_car)
        std::cout << "Yes - you can drive!";
    else
        std::cout << "Sorry, you need to buy a car before you can drive!";
} else
    {
    int n {16 - age};
    std::cout <<  "Sorry, come back in " << n << " years and be sure you own a car when you come back.";
    }
```
**Output**
```bash
Sorry, you need to buy a car before you can drive!
```

### Switch statement

**Example**
```c
int day_code {4};

switch (day_code) {
    case 0:
        std::cout << "Sunday";
        break;
    case 1:
        std::cout << "Monday";
        break;
    case 2:
        std::cout << "Tuesday";
        break;
    case 3:
        std::cout << "Wednesday";
        break;
    case 4:
        std::cout << "Thursday";
        break;
    case 5:
        std::cout << "Friday";
        break;
    case 6:
        std::cout << "Saturday";
        break;
    default:
        std::cout << "Error - illegal day code";
}
```

**Output**
```bash
Thursday
```

### Conditional operator

Conditional operator `?:`

```bash
(cond_expr) ? expr1 : expr2

- cond_expr evaluates to a boolean expression.
- if cond_expr is true then value of expr1 is returned
- if cond_expr is false then value of expr2 is returned
```

- Similar to if-else
- Ternary operator
- Very useful when used inline
- Very easy to abuse.

**Example**
```c
int num1{23}, num2{66};

std::cout << "Largest: " << ( (num1 > num2) ? num1 : num2 ) << '\n';
std::cout << "Smallest: " << ( (num1 < num2) ? num1 : num2) << '\n';
```

**Output**
```bash
Largest: 66
Smallest: 23
```

### For loop

Example code that uses a for loop to calculate the sum of the odd integers from 1 to 15, inclusive.

**Example**
```c
int sum {};

for (unsigned i {0}; i <= 15; ++i)
{
    if ((i % 2) != 0)
        sum += i;
}

std::cout << "sum: " << sum;
```

**Output**
```bash
sum: 64
```

Example code looping through a vector of integers. See [range- based for loop](#range-based-for-loop), for cleaner alternative to this code for looping collections.

**Example**
```c
#include <iostream>
#include <vector>

int main()
{

    std::vector<int> nums { 10,20,30,40,50};

    for (unsigned i{0}; i< nums.size(); ++i)
    std::cout << nums[i] << '\n';
    
    return 0;
}
```
**Note:** `.size()` returns an `unsigned` integer. Therefore `i` is given type `unsigned` in the for loop.

**Output**
```bash
10
20
30
40
50
```

### Range-based for loop

Range-based for loops introduced in C++11. Provide a way to loop through a collection of elements, without the need to know the length of the collection, or need to keep track of indexes with additional variables.

```c
for (var_type var_name: sequence)
    statement; // can use var_name

for (var_type var_name: sequence) {
    statements; // can use var_name
}
```

Can use the `auto` keyword, the compiler will automatically detect the type, based on the collection.

```c
#include <iostream>
#include <vector>

int main()
{

    std::vector<int> nums { 10,20,30,40,50};

    for (auto num : nums)
        std::cout << num << '\n';
    
    return 0;
}
```

**Output**
```bash
10
20
30
40
50
```
Example code to determine how many elements in the vector are evenly divisible by either 3 or by  5

**Example**
```c
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec {1,3,5,15,16,17,18,19,20,21,25,26,27,30,50,55,56,58,100,200,300,400,500,600,700};
    
    int count {};
    for (auto i : vec) {
        if ( i % 3 == 0 || i % 5 == 0 )
            ++count; 
    }  
    
    std:: cout << count << " elements in the vector are evenly divisible by either 3 or by  5.";
    
    return 0;
}
```
**Output**
```bash
18 elements in the vector are evenly divisible by either 3 or by  5.
```



Example code with an initialiser list inside the for loop (not used often).

**Example**
```c
#include <iostream>

int main()
{

    for (auto num : { 10,20,30,40,50})
        std::cout << num << '\n';
    
    return 0;
}
```

**Output**
```bash
10
20
30
40
50
```

Example code iterating over a `C style` string, which is an array of characters.

**Example**
```c
#include <iostream>

int main()
{

    for (auto c: "Hello")
        std::cout << c;
    
    return 0;
}
```
**Output**
```bash
Hello
```

### While loop

```c
while (expression)
    statement;

while (expression) {
    statement(s);
}
```

**Example**
```c
int i {1};

while (i <= 5) {
    std::cout << i;
    ++i; // must increment i, to terminate loop
}
```
**Output**
```bash
12345
```

**Example**
```c
int i {1};

while (i <= 10) {
    if (i % 2 == 0)
        std::cout << i << '\n';
    ++i; // must increment i
}
```
**Output**
```bash
2
4
6
8
10
```

Example code looping over an array.

**Example**
```c
int scores [] {67,75,99,56};
int i {0};

while (i < 4) {
    std::cout << scores[i] << '\n';
    ++i; // must increment i
}
```

**Output**
```bash
67
75
99
56
```

Example code validating a user input. Note, the duplicated code outside and inside the loop. This example would be better suited for a [do-while loop](#do-while-loop).

```c
int number {0};
std::cout << "Enter an integer less than 100: ";
std::cin >> number;

while (number >= 100){
    std::cout << "Enter an integer less than 100: ";
    std::cin >> number;
}

std::cout << "Thanks, " << number << " is a good number.";

```
**Output**

```bash
Enter an integer less than 100: 101
Enter an integer less than 100: 3
Thanks, 3 is a good number.
```

### do-while loop