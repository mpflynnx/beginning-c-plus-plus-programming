#include <cstring>
#include <iostream>
#include <string>

int main()
{

    char full_name[50];

    // std::string full_name;
    std::cout << "Enter your full name: ";
    std::cin.getline(full_name, 50);

    // getline(std::cin, full_name);

    std::cout << full_name << '\n';

    return 0;
}