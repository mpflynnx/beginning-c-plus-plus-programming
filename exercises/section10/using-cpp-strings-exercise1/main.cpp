#include <iostream>
#include <string>

int main()
{
                                    // 0123456789x1234 index
    std::string unformatted_full_name{ "StephenHawking" };
    std::string first_name{ unformatted_full_name, 0, 7 }; // start index 0, no of chars 7 
    std::string last_name{ unformatted_full_name.substr(7,14) };
    std::string formatted_full_name = first_name + last_name;
    formatted_full_name.insert(7, 1, ' '); // insert 1 char ' ' at index 7

    std::cout << formatted_full_name << '\n';

    return 0;
}
