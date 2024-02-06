#include <iostream>

int main()
{

std::string unformatted_full_name {"StephenHawking"};
unformatted_full_name.insert(7, " ");
                
std::cout << unformatted_full_name << '\n'; // Stephen Hawking

    return 0;
}