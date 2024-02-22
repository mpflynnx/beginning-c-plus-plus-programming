#include <iostream>

void doubleValue(int* ptr); // note: ptr is a pointer to non-const in this example

int main()
{

    int x{ 5 };

    std::cout << "x = " << x << '\n';

    doubleValue(&x); // we're passing the address of x to the function

    std::cout << "x = " << x << '\n';

    int* ptr {&x}; 
    doubleValue(ptr); // here we're passing the pointer to the function

    std::cout << "x = " << x << '\n';

    return 0;
}

void doubleValue(int* ptr) // note: ptr is a pointer to non-const in this example
{
    *ptr *= 2; // double the value using *=
}