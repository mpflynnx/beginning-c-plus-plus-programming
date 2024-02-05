#include <string>
#include <iostream>

int main()
{

    std::string s1 {"This is a test"};

    s1 += ". Honest." ;    
    std::cout << s1 << '\n'; // This is a test. Honest.

    return 0;
}
