#include <cstring>
#include <iostream>

int main()
{

    char full_name[50];
    std::cout << "Enter your full name: ";
    std::cin.getline(full_name, 50);

    std::cout << full_name << '\n';

    return 0;
}
