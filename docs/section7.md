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

int test_scores [5] {}; // same as {0}

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
- Must include the vector library. `#include <vector>`
- Must use vector type of the `std` namespace `using std::vector;`

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

- Arrays never do bound checking
- Many vector methods provide bounds checking
- An exception and error message is generated

```c
vector <int> test_scores {100, 98, 89};

test_scores.push_back(85);
test_scores.push_back(93);

cout << "Fifth score at index 5: " 
<< test_scores.at(5) << endl; // Invalid
```

```bash
Fifth score at index 4: terminate called after throwing an instance of 'std::out_of_range'
  what():  vector::_M_range_check: __n (which is 5) >= this->size() (which is 5)
```

### Checking the size of a vector

Check the size of a vector using `size()`
```c
vector <int> test_scores {100, 98, 89};
cout << "There are " << test_scores.size() << " scores in the vector." << endl;
```

```bash
There are 3 scores in the vector.
```

### Initialising and accessing 2D vectors

Initialise a 2D vector as shown. This is a vector of a vector.

```c
vector <vector<int>> movie_ratings 
{
     {1, 2, 3, 4},
     {1, 2, 4, 4},
     {1, 3, 4, 5}
};
```

Access a 2D vector using `.at()`

```c
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
     vector <vector<int>> movie_ratings 
     {
          {1, 2, 3, 4}, // 0 Row, Reviewer 1
          {1, 2, 4, 4}, // 1 Row, Reviewer 2
          {1, 3, 4, 5}  // 2 Row, Reviewer 3

     };

     cout << "\nReviewer 1 scores.\n";
     cout << movie_ratings.at(0).at(0) << endl;
     cout << movie_ratings.at(0).at(1) << endl;
     cout << movie_ratings.at(0).at(2) << endl;
     cout << movie_ratings.at(0).at(3) << endl;

     cout << "\nReviewer 2 scores.\n";
     cout << movie_ratings.at(1).at(0) << endl;
     cout << movie_ratings.at(1).at(1) << endl;
     cout << movie_ratings.at(1).at(2) << endl;
     cout << movie_ratings.at(1).at(3) << endl;

     cout << "\nReviewer 3 scores.\n";
     cout << movie_ratings.at(2).at(0) << endl;
     cout << movie_ratings.at(2).at(1) << endl;
     cout << movie_ratings.at(2).at(2) << endl;
     cout << movie_ratings.at(2).at(3) << endl;
     
     return 0;
}
```

**Output**
```bash

Reviewer 1 scores.
1
2
3
4

Reviewer 2 scores.
1
2
4
4

Reviewer 3 scores.
1
3
4
5
```