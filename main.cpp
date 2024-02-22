#include <iostream>
#include <vector>
#include <string>

void displayVector(const std::vector<std::string>* const vec );

int main()
{

    std::vector<std::string> stooges{"Curly", "Larry", "Moe"};

    displayVector(&stooges); // we're passing the address of stooges to the function

    return 0;
}

void displayVector(const std::vector<std::string>* const vec )
{

    for (auto str : *vec) // deference address pointer
        std::cout << str << ' ';
    std::cout << '\n';

}