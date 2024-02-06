#include <iostream>

int main()
{

std::string s1 {"This is a test"};
std::string s2;
s2 = s1.substr(0,4); // This
std::cout << s1.substr(5,2); // is
std::cout << s1.substr(0,4); // test
                
std::cout << s2 << '\n'; // s1 == "is a test"

    return 0;
}