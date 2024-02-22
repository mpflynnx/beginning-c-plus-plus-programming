#include <iostream>
#include <vector>
#include <string>

void displayArray(const int* array, const int sentinel);

int main()
{

    int scores[] {99, 23, 45, 1, 456, -1};
    displayArray(scores, -1);

    return 0;
}

void displayArray(const int* array, const int sentinel)
{

    while (*array != sentinel)
        std::cout << *array++ << ' ';
    std::cout << '\n'; 

}