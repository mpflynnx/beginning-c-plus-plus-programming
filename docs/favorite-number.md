## Favourite number program

Here is a `C++` program, which prompts the user for their favourite number.

```c
#include <iostream>

int main() {

    int favorite_number;

    std::cout << "Enter your favorite number between 1 and 100? ";

    std::cin >> favorite_number;

    std::cout << "Amazing, that's my favorite number too!" << std::endl;

    std::cout << "No really, " << favorite_number << " is my favourite number." << std::endl; 

    return 0;
}
```

**Program breakdown**

```c
#include <iostream>
```
The line `#include <iostream>` is a preprocessor directive in `C++` that includes the standard input/output stream library. This library provides functionality for reading and writing data to the console. The `iostream` library is required if you want to use the `cin` and `cout` objects to read and write data to the console.

```c
int main() 
{
    // main function code here
}
```

The main function is the entry point to the program.

```c
    int favorite_number;
```
Here, we declare a new integer variable named `favourite_number`.

```c
std::cout << "Enter your favorite number between 1 and 100? ";
```

Use namespace `std`, `cout` object to output to the console, the text in double quotes.

Insertion operator `<<` is use to insert into `cout`.

```c
    std::cin >> favorite_number;
```
Here, we use `std` `cin` object to retrieve the console input and store it in variable named `favourite_number`.

```c
    std::cout << "Amazing, that's my favorite number too!" << std::endl;
```
As before, we output to console the text between double quotes, but insert to `cout` a new line, using the namespace `std`, `endl` object to output to the console.

```c
    std::cout << "No really, " << favorite_number << " is my favourite number." << std::endl; 
```

This time we insert the variable `favourite_number` to `cout`, then insert some more text then a end of line.

**Note:** As with other languages, we didn't needed to cast the integer variable to a string type or need to concatenate the variable within the string text.

```c
    return 0;
```

The main function must always return an integer. Returning a integer `0` indicates success of program execution.