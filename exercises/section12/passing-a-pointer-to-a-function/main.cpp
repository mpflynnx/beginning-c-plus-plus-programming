#include <iostream>

void multiply_with_pointer(int* ptr, int multiplier);

int main()
{
    int x{ 10 };
    int multiplier{ 10 };

    multiply_with_pointer(&x, multiplier);

    std::cout << x; // print x after call to function
    
    return 0;
}

void multiply_with_pointer(int* ptr, int multiplier) {
    *ptr = *ptr * multiplier;
}