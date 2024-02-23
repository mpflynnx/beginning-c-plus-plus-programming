#include <iostream>
#include <string>

std::string reverse_string(const std::string& str);

int main()
{

    std::string input = "Hello, World!";
    
    std::string reversed = reverse_string(input);

    std::cout << reversed << '\n';
    // reversed should be "!dlroW ,olleH"

    return 0;
}

/*
I'm not using pointers, as requested.
*/
std::string reverse_string(const std::string& str) {
    std::string reversed;

    size_t size{ str.length() }; // 13

    for (size_t i = 0; i < size; i++)
    {
        reversed += str[size -i -1];
    }

    return reversed;
}
