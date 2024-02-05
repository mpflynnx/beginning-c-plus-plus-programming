## Section 9: Controlling program flow

## Table of Contents
- [If statement](/docs/section9.md#if-statement)
- [If else statement](/docs/section9.md#if-else-statement)
- [If else if](/docs/section9.md#if-else-if)
- [Nested If statement](/docs/section9.md#nested-if-statement)
- [Switch statement](/docs/section9.md#switch-statement)
- [Conditional operator](/docs/section9.md#conditional-operator)
- [For loop](/docs/section9.md#for-loop)
- [Range-based for loop](/docs/section9.md#range-based-for-loop)
- [While loop](/docs/section9.md#while-loop)
- [While loop exercise](/exercises/section9/While%20loop%20exercise/instructions.md)
- [While loop exercise (my solution)](/exercises/section9/While%20loop%20exercise/main.cpp)  
- [Do-while loop](/docs/section9.md#do-while-loop)
- [Do-while loop exercise](/exercises/section9/do-while%20loop%20exercise/instructions.md)
- [Do-while loop exercise (my solution)](/exercises/section9/do-while%20loop%20exercise/main.cpp) 
- [continue and break keywords](/docs/section9.md#continue-and-break-keywords)
- [Infinite loops](/docs/section9.md#infinite-loops)
- [Nested loops](/docs/section9.md#nested-loops)
- [Nested loop exercise](/exercises/section9/nested%20loop%20exercise/instructions.md)
- [Nested loop exercise (my solution)](/exercises/section9/nested%20loop%20exercise/main.cpp)
- [Section9: Challenge](/challenges/section9/section9-challenge/section9-challenge.txt)
- [Section9: Challenge (my solution)](/challenges/section9/section9-challenge/main.cpp)


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

for (unsigned i {0}; i <= 15; ++i) // Can use ++i, or i++, compiler will optimise for best option
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

Example code validating a user input. Note, the duplicated code outside and inside the loop.

**Example**
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

Example code validating a user input, using a boolean flag to reduce repeated code. This could be improved using a [do-while loop](#do-while-loop).

**Example**
```c
    bool done {false};
    int number{};

    while (!done){
        std::cout << "Enter an integer between 1 and 10: ";
        std::cin >> number;
        if (number <= 1 || number >= 10 )
            std::cout << "Out of range, try again." << '\n';
        else {
            std::cout << "Good choice!" << '\n';
            done = true;
        }
    }
```
**Output**
```bash
Enter an integer between 1 and 10: 10
Out of range, try again.
Enter an integer between 1 and 10: -8
Out of range, try again.
Enter an integer between 1 and 10: 2
Good choice!
```

### do-while loop

If you must run an iteration of a loop at least once then the do-while loop is recommended. 

```c
do {
    statements;
} while (expression);
```

Example code of a simple menu system using do-while loop and switch statement.

**Example**

```c
char selection{};

do {
    std::cout << "\n----------------" << '\n';
    std::cout << "1. Do this" << '\n';
    std::cout << "2. Do that" << '\n';
    std::cout << "3. Do the other" << '\n';
    std::cout << "Press (q)uit to quit." << '\n';
    std::cout << "\nEnter your selection: ";
    std::cin >> selection;

    switch (selection) {
        case '1':
            std::cout << "\nDoing this\n";
            break;
        case '2':
            std::cout << "\nDoing that\n";
            break;
        case '3':
            std::cout << "\nDoing the other\n";
            break;
        case 'q':
            std::cout << "\nQuitting the program.\n";
            break;
        case 'Q':
            std::cout << "\nQuitting the program.\n";
            break;
        default:
            std::cout << "\nError - illegal option.\n";
    }

} while (selection != 'q' && selection != 'Q');
```

**Output**

```bash

----------------
1. Do this
2. Do that
3. Do the other
Press (q)uit to quit.

Enter your selection: 1

Doing this

----------------
1. Do this
2. Do that
3. Do the other
Press (q)uit to quit.

Enter your selection: 2

Doing that

----------------
1. Do this
2. Do that
3. Do the other
Press (q)uit to quit.

Enter your selection: 3

Doing the other

----------------
1. Do this
2. Do that
3. Do the other
Press (q)uit to quit.

Enter your selection: 4

Error - illegal option.

----------------
1. Do this
2. Do that
3. Do the other
Press (q)uit to quit.

Enter your selection: q

Quitting the program.

```

### continue and break keywords

- continue keyword
    - no further statements in the body of the loop are executed
    - control immediately goes directly to the beginning of the loop for the next iteration

- break keyword
    - no further statements in the body of the loop are executed
    - loop is immediately terminated
    - control immediately goes to the statement following the loop construct

In the example code, a vector is looped and its index values printed (unless its value is -1) the loop continues until a value of -99 is seen in the vector, then the loop terminates.

**Example**

```c
std::vector<int> vec {1,2,-1,3,-1,-99,7,8,9};

for (auto num : vec) {
    if (num == -99) 
        break; // terminate at -99
    else if (num == -1)
        continue; // jump to start of loop
    else    
        std::cout << num << '\n'; // doesn't print -1
}     
```
**Output**
```bash
1
2
3
```

**Note** try not to use continue and break too much as it can lead to complex code that may be hard to understand.

### Infinite loops

- Loops whose condition expression always evaluates to true
- Usually this is unintended and a programmer error
- Can be used with break statements to control an infinite loop (bad practice)
- Sometimes infinite loops are exactly what is needed
    - Event loop in an event-driven program
    - Operating system

**Examples of infinite loops**
```c
for (;;)
    std::cout << "This will printed forever\n";

while (true)
    std::cout << "This will printed forever\n";

do {
    std::cout << "This will printed forever\n";
} while (true);
```
Example code of looping until an expected response is given from the user.

**Example**

```c
while (true) {
    char again {};
    std::cout << "Loop again? (Y/N): ";
    std::cin >> again;

    if (again == 'N' || again == 'n')
        break;
}
std::cout << "\nLoop terminated.\n";
```

**Output**
```bash
Loop again? (Y/N): y
Loop again? (Y/N): y
Loop again? (Y/N): y
Loop again? (Y/N): n

Loop terminated.
```

**Note** this code is not best practice. The loop should be more informative as to when the loop iterates. 

### Nested loops

- Loops nested are loops within another loop
- Can be many as many level deep as the program needs
- Very useful with multi-dimensional data structures
- Outer loop verses inner loop (inner loops loop faster)

In the example code, we have two loops which will display the multiplication tables up to 10.
**Example**
```c
for (int num1 {1}; num1 <=10; ++num1){
    for (int num2 {1}; num2 <=10; ++num2){
        std::cout << num1 
                << " * " 
                << num2 
                << "   = " 
                << num1 * num2 
                << '\n';
    }
    std::cout << "---------------" << '\n';
}
```
**Output**
```bash
1 * 1   = 1
1 * 2   = 2
1 * 3   = 3
1 * 4   = 4
1 * 5   = 5
1 * 6   = 6
1 * 7   = 7
1 * 8   = 8
1 * 9   = 9
1 * 10   = 10
---------------
2 * 1   = 2
2 * 2   = 4
2 * 3   = 6
2 * 4   = 8
2 * 5   = 10
2 * 6   = 12
2 * 7   = 14
2 * 8   = 16
2 * 9   = 18
2 * 10   = 20
---------------

...
...

9 * 1   = 9
9 * 2   = 18
9 * 3   = 27
9 * 4   = 36
9 * 5   = 45
9 * 6   = 54
9 * 7   = 63
9 * 8   = 72
9 * 9   = 81
9 * 10   = 90
---------------
10 * 1   = 10
10 * 2   = 20
10 * 3   = 30
10 * 4   = 40
10 * 5   = 50
10 * 6   = 60
10 * 7   = 70
10 * 8   = 80
10 * 9   = 90
10 * 10   = 100
---------------
```