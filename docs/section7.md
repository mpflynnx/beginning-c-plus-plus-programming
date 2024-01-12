## Section7: Arrays and Vectors

### What is an Array?

- Compound data type or data structure
- Collection of elements
- All elements are of the same type
- Each element can be accessed directly
- Arrays are rarely used in modern C++, Vectors are preferred

### Declaring Arrays

**Uninitialised array declarations**
```c
int test_scores [5];
int high_score_per_level [10];

const int days_in_year {365};
double hi_temperatures [days_in_year];
```

**Initialised array declarations**
```c
int test_scores [5] {100,95,92,87,43};
int high_score_per_level [10] {3,5}; // 0 and 1 indexes initialised, remaining all set to 0.

int test_scores [5] {}; // sames as {0}

const int days_in_year {365};
double hi_temperatures [days_in_year] {0};

int another_array [] {1,2,3,4,5}; // size automatically calculated
```

### Accessing array elements

Access array elements using the subscript operator `[]`.

```c
int test_scores [] {100,95,92,87,43};

cout << "First score at index 0: " << test_scores[0] << endl;
cout << "Fifth score at index 4: " << test_scores[4] << endl;
```

### Changing array elements

```c
int test_scores [5] {100,95,92,87,43};

cin >> test_scores[0];
cin >> test_scores[1];
cin >> test_scores[2];
cin >> test_scores[3];
cin >> test_scores[4];

cin >> test_scores[5]; // out of bounds, may crash the program

test_scores[0] = 90; // assignment statement
```

### How does it work?
- The array name represents the first elements memory location (index 0)
= The [index] represents the offset from the start of the array
- No bounds checking it performed.

```c
int test_scores [5] {100,95,92,87,43};
cout << test_scores << endl; // Memory address 0x7ffc03d939b0
```

### Multidimensional arrays

```c
int movie_rating [3][4]; // 2D array, [3] rows, [4] columns, max 3*4 = 12 locations

int movie_rating [3][4]
{
    { 0, 4, 3, 5},
    { 2, 3, 3, 5},
    { 1, 4, 3, 5}
};
```

### Vectors

If the size of the required array cannot be determined, then there are two options.
- Pick an array size that is unlikely to be exceeded (wasteful)
- Use a dynamic array such as a vector

### What is a vector?

- Object orientated container in the C++ Standard Template Library
- An array that can grow and shrink in size at run time
- Provides similar semantics and syntax as arrays
- Very efficient
- Can provide bounds checking with the use of a function
- Can use lots of functions like, sort, reverse, find and more 
- Elements are all the same type
- Elements are initialised to zero

### Declaring a vector

- Different from an array, as a vector is an Object
- Included in the vector library
- vector type is part of the `std` namespace

**Declaring vectors using constructor initialisation ()**
```c
#include <vector>

using std::vector;

int main()
{
     vector <char> vowels (5); // Automatically set all 5 elements to 0

     vector <int> test_scores (10); // Automatically set all 10 elements to 0
}
```
**Initialising a vector**

```c
#include <vector>

using std::vector;

int main()
{
     vector <char> vowels {'a','e','i','o','u'};

     vector <int> test_scores {100, 98, 89, 85, 93};

    // vector element 365, initialised to 80
     vector <double> hi_temp (365, 80.0);
}
```

### Accessing vector elements - array syntax `[0]`

Identical to accessing arrays.
```c
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main()
{
     vector <int> test_scores {100, 98, 89, 85, 93};

     cout << "First score at index 0: " << test_scores[0] << endl;
     cout << "Fifth score at index 4: " << test_scores[4] << endl;

}
```
### Accessing vector elements - vector syntax `at()`

A vector is an object, `at` is a method. We can pass the method the index number using constructor syntax `()`.

```c
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main()
{
     vector <int> test_scores {100, 98, 89, 85, 93};

     cout << "First score at index 0: " 
          << test_scores.at(0) << endl;

     cout << "Fifth score at index 4: " 
          << test_scores.at(4) << endl;

}
```

### Changing the contents of vector elements - vector syntax `at()`
```c
vector <int> test_scores {100, 98, 89, 85, 93};

cin >> test_scores.at(0);
cin >> test_scores.at(1);
cin >> test_scores.at(2);
cin >> test_scores.at(3);
cin >> test_scores.at(4);

test_scores.at(0) = 90; // Assignment statement
```

### Growing a vector using method `push_back()`

A vector is an object, `push_back` is a method. We can pass the method the index number using constructor syntax `()`. The vector will automatically allocate the required space.

```c
vector <int> test_scores {100, 98, 89};

test_scores.push_back(85); // new element 3 = 85
test_scores.push_back(93); // new element 4 = 93

cout << "Fifth score at index 4: " 
<< test_scores.at(4) << endl; // 93
```

### Vector out of bounds checking