#include <iostream>

int main()
{

    char first_name[] {"Frank"};

    char* char_ptr1 {nullptr};
    char* char_ptr2 {nullptr};

    char_ptr1 = &first_name[0]; // equivalent to &first_name which is 'F'
    char_ptr2 = &first_name[4]; // 'k'

    std::cout << "In first name " 
              << first_name 
              << ", " 
              << *char_ptr2 
              << " is " 
              << (char_ptr2 - char_ptr1) 
              << " characters away from " 
              << *char_ptr1 
              << ".\n";

    return 0;
}