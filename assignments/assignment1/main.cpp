#include <iostream>
#include <string>

std::string getString();

int main()
{
    std::string userString{ getString() };
    
    size_t userStringLength{ userString.length() };

    int tipOffset{ 0 }; // pyramid tip offset

    for (char c : userString) {

        size_t leftPadding = userStringLength - tipOffset; // padding before chars printed

        while (leftPadding > 0) {
            std::cout << ' ';
            --leftPadding;
        }

        for (size_t i = 0; i < tipOffset; ++i) {
            std::cout << userString.at(i);
        }

        std::cout << c;

        // https://en.cppreference.com/w/cpp/types/size_t
        for (int j{ tipOffset - 1 }; j >= 0; --j) { 
            auto k = static_cast<size_t>(j);
            std::cout << userString.at(k);

        }

        std::cout << '\n';

        ++tipOffset;

    }

    return 0;
 }

std::string getString() {
    std::cout << "Enter a string: ";
    std::string userString;
    std::getline(std::cin >> std::ws, userString);
    return userString;
}