#include <iostream>
#include <vector>
#include <string>

int main()
{

    // initialise a C++ string vector
    std::vector<std::string> stooges {"Larry", "Moe", "Curly"};
    
    // initialise a C++ string vector pointer to address of stooges vector
    std::vector<std::string> *vector_ptr {&stooges};

    // print first element of stooge vector
    std::cout << "First stooge: " << (*vector_ptr).at(0) << '\n';

    // print all stooge vector elements
    std::cout << "Stooges: ";
    for (auto stooge: *vector_ptr)
        std::cout << stooge << ' ';
    std::cout << '\n';

    return 0;
}